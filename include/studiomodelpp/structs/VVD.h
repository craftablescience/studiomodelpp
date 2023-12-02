#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../math/Vector.h"

namespace studiomodelpp::VVD {

constexpr int ROOT_LOD = 0;
constexpr int MAX_LOD_COUNT = 8;
//constexpr int MAX_BONES_PER_VERTEX = 3;

struct Fixup {
	int LOD;
	int sourceVertexID;
	int vertexCount;
};

// todo(vvd): bone weight
/*
struct BoneWeight {
	//float weight[MAX_BONES_PER_VERTEX];
    std::vector<float> weight;
	//char bone[MAX_BONES_PER_VERTEX];
	//char boneCount;
    std::vector<char> bone;
};
*/

struct Vertex {
	//BoneWeight boneWeight;
	Vector3 position;
	Vector3 normal;
	Vector2 uv;

	Vector4 tangent; // Taken from tangents data section
};

struct VVD {
	bool open(const std::byte* data, std::size_t size, int mdlVersion, int mdlChecksum);

	//int id;
	int version;
	//int checksum;
	int numLODs;
	//int numVerticesInLOD[MAX_LOD_COUNT];
	std::array<int, MAX_LOD_COUNT> numVerticesInLOD;
	//int fixupsCount;
	//int fixupsOffset;
	std::vector<Fixup> fixups;
	//int verticesOffset;
	std::vector<Vertex> vertices;
	//int tangentsOffset;
};

} // namespace studiomodelpp::VVD