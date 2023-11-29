#include <studiomodelpp/structs/VVD.h>

#include <studiomodelpp/internal/BufferStream.h>

using namespace studiomodelpp::VVD;
using namespace studiomodelpp::internal;

constexpr int VVD_ID = 'I' + ('D' << 8) + ('S' << 16) + ('V' << 24);

bool VVD::open(const std::byte* data, std::size_t size, int mdlChecksum) {
	BufferStream stream{data, size};

	int id = stream.read<int>();
	if (id != VVD_ID) {
		return false;
	}

	stream.read(this->version);

	int checksum = stream.read<int>();
	if (checksum != mdlChecksum) {
		return false;
	}

	stream.read(this->numLODs);
	stream.read(this->numVerticesInLOD);

	int fixupsCount = stream.read<int>();
	int fixupsOffset = stream.read<int>();
	int verticesOffset = stream.read<int>();
	int tangentsOffset = stream.read<int>();

	std::size_t numTotalVertices = 0;
	for (int i : this->numVerticesInLOD) {
		numTotalVertices += i;
	}

	stream.seek(verticesOffset);
	stream.read(this->vertices, numTotalVertices);

	stream.seek(tangentsOffset);
	for (std::size_t i = 0; i < numTotalVertices; i++) {
		this->vertices[i].tangent = stream.read<Vector4>();
	}

	stream.seek(fixupsOffset);
	stream.read(this->fixups, fixupsCount);

	return true;
}
