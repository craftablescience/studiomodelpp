#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "../math/Matrix.h"
#include "../math/Quaternion.h"
#include "../math/Vector.h"
#include "Generic.h"

namespace studiomodelpp::MDL {

struct Bone {
	enum Flags : int {
		FLAG_NONE = 0,
		// todo(flags): Bone
	};

	// int nameIndex;
	std::string name;

	int parent;
	int boneController[6];
	Vector3 position;
	Quaternion rotationQuat;
	Vector3 rotationEuler;
	Vector3 positionScale;
	Vector3 rotationScale;
	Matrix<3,4> poseToBose;
	Quaternion alignment;
	Flags flags;
	int procType;
	int procIndex;
	int physicsBone;

	//int surfacePropNameIndex;
	std::string surfacePropName;

	int contents;

	//int _unused0[8];
};

struct BoneController {
	int bone;
	int type;
	float start;
	float end;
	int rest;
	int inputField;

	//int _unused0[8];
};

struct HitboxSet {
	//int nameIndex;
	std::string name;

	//int hitboxCount;
	//int hitboxIndex;
	std::vector<BBox> hitboxes;
};

/*
struct AnimDesc {
	enum Flags : int {
		FLAG_NONE = 0,
		// todo(flags): AnimDesc
	};

	//int basePointer;

	//int nameIndex;
	std::string name;
	float fps;

	Flags flags;

	int frameCount;

	//int movementCount;
	//int movementIndex;

	//int _unused0[6];

	//int animBlock;
	//int animIndex;

	//int ikRuleCount;
	//int ikRuleIndex;

	//int animBlockIKRuleIndex;

	//int localHierarchyIndexCount;
	//int localHierarchyIndex;

	//int sectionIndex;
	//int sectionFrames;

	//short zeroFrameSpan;
	//short zeroFrameCount;
	//int zeroFrameIndex;
	//float zeroFrameStallTime;
};

struct SequenceDesc {
	enum Flags : int {
		FLAG_NONE = 0,
		// todo(flags): SequenceDesc
	};

	//int basePointer;

	//int labelIndex;
	//int activityLabelIndex;

	Flags flags;

	//int activity;
	//int activityWeight;

	//int eventCount;
	//int eventIndex;

	Vector3 boundingBoxMin;
	Vector3 boundingBoxMax;

	int blendCount;

	int animIndexIndex;

	int movementIndex;

	int groupSize[2];
	int paramIndex[2];
	float paramStart[2];
	float paramEnd[2];
	int paramParent;

	float fadeInTime;
	float fadeOutTime;

	int localEntryNode;
	int localExitNode;

	int nodeFlags;

	float entryPhase;
	float exitPhase;

	float lastFrame;

	int nextSequence;
	int pose;

	int ikRuleCount;

	//int autoLayerCount;
	//int autoLayerIndex;

	int weightListIndex;

	int poseKeyIndex;

	//int ikLockCount;
	//int ikLockIndex;

	//int keyValueIndex;
	//int keyValueSize;

	int cyclePoseIndex;

	//int _unused0[7];
};
*/

struct Material {
	enum Flags : int {
		FLAG_NONE = 0,
		// todo(flags): Material (Texture in MDL)
	};

	//int nameIndex;
	std::string name;

	Flags flags;

	//int used; // No idea what this is
	//int _unused0[13];
};

struct MDL {
	[[nodiscard]] bool open(const std::byte* data, std::size_t size);

	enum Flags : int {
		FLAG_NONE                           = 0,
		FLAG_AUTOGENERATED_HITBOX           = 1 <<  0,
		FLAG_FORCE_OPAQUE                   = 1 <<  2,
		FLAG_TRANSLUCENT_TWO_PASS           = 1 <<  3,
		FLAG_STATIC_PROP                    = 1 <<  4,
		FLAG_HAS_SHADOW_LOD                 = 1 <<  6,
		FLAG_USE_SHADOW_LOD_MATERIALS       = 1 <<  8,
		FLAG_OBSOLETE                       = 1 <<  9,
		FLAG_NO_FORCED_FADE                 = 1 << 11,
		FLAG_FORCE_PHONEME_CROSSFADE        = 1 << 12,
		FLAG_CONSTANT_DIRECTIONAL_LIGHT_DOT = 1 << 13,
		FLAG_FLEXES_CONVERTED               = 1 << 14,
		FLAG_BUILT_IN_PREVIEW_MODE          = 1 << 15,
		FLAG_DO_NOT_CAST_SHADOWS            = 1 << 17,
		FLAG_CAST_TEXTURE_SHADOWS           = 1 << 18,
	};

	//int id;
	int version;
	int checksum;

	//char name[64];
	std::string name;
	//int dataLength;

	Vector3 eyePosition;
	Vector3 illuminationPosition;
	Vector3 hullMin;
	Vector3 hullMax;
	Vector3 viewBBoxMin;
	Vector3 viewBBoxMax;

	Flags flags;

	//int boneCount;
	//int boneOffset;
	std::vector<Bone> bones;

	//int boneControllerCount;
	//int boneControllerOffset;
	std::vector<BoneController> boneControllers;

	//int hitboxCount;
	//int hitboxOffset;
	std::vector<HitboxSet> hitboxSets;

	//int localAnimationCount;
	//int localAnimationOffset;

	//int localSequenceCount;
	//int localSequenceOffset;

	int activityListVersion;
	int eventsIndexed;

	//int materialCount;
	//int materialOffset;
	std::vector<Material> materials;

	//int materialDirCount;
	//int materialDirOffset;
	std::vector<std::string> materialDirectories;

	//int skinReferenceCount;
	//int skinReferenceFamilyCount;
	//int skinReferenceIndex;

	//int bodyPartCount;
	//int bodyPartOffset;

	//int attachmentCount;
	//int attachmentOffset;

	//int localNodeCount;
	//int localNodeIndex;
	//int localNodeNameIndex;

	//int flexDescCount;
	//int flexDescIndex;

	//int flexControllerCount;
	//int flexControllerIndex;

	//int flexRulesCount;
	//int flexRulesIndex;

	//int ikChainCount;
	//int ikChainIndex;

	//int mouthsCount;
	//int mouthsIndex;

	//int localPoseParamCount;
	//int localPoseParamIndex;

	//int surfacePropertyIndex;

	//int keyValueIndex;
	//int keyValueCount;

	//int ikLockCount;
	//int ikLockIndex;

	//float mass;
	//int contentsFlags;

	//int includeModelCount;
	//int includeModelIndex;

	//int virtualModel;

	//int animationBlocksNameIndex;

	//int animationBlocksCount;
	//int animationBlocksIndex;

	//int animationBlockModel;

	//int boneTableNameIndex;

	//int vertexBase;
	//int offsetBase;

	//std::byte directionalDotProduct;

	//unsigned char rootLOD;
	//unsigned char numAllowedRootLODs;

	//std::byte _unused0;
	//int _unused1;

	//int flexControllerUICount;
	//int flexControllerUIIndex;

	//float vertAnimFixedPointScale;
	//int _unused2;

	// todo: header 2
	//int header2Offset;

	//int _unused3;
};

} // namespace studiomodelpp
