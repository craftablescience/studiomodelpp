cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(studiomodelpp)
set(CMAKE_CXX_STANDARD 20)

option(STUDIOMODELPP_BUILD_TESTS "Build tests for studiomodelpp" OFF)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/thirdparty/bufferstream")

list(APPEND ${PROJECT_NAME}_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/internal/Helpers.h"

        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/math/Matrix.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/math/Quaternion.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/math/Vector.h"

        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/structs/MDL.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/structs/VTX.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/structs/VVD.h"

        "${CMAKE_CURRENT_SOURCE_DIR}/include/studiomodelpp/studiomodelpp.h"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/internal/Helpers.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/structs/MDL.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/structs/VTX.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/structs/VVD.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/studiomodelpp.cpp")
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE bufferstream)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(STUDIOMODELPP_BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0)
    FetchContent_MakeAvailable(googletest)
    enable_testing()

    set(STUDIOMODELPP_TEST_MODEL_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/test/res/")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/test/Config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/test/Config.h")

    add_executable(${PROJECT_NAME}test
            "${CMAKE_CURRENT_SOURCE_DIR}/test/Config.h.in"
            "${CMAKE_CURRENT_SOURCE_DIR}/test/Reader.cpp")
    target_link_libraries(${PROJECT_NAME}test PUBLIC ${PROJECT_NAME} gtest_main)

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}test)
endif()
