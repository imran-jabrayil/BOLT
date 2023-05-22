#include "Vertex.hpp"

bool Vertex::operator==(const Vertex &vertex) const {
    return klassId == vertex.klassId && methodId == vertex.methodId;
}

bool Vertex::operator<(const Vertex &vertex) const {
    return klassId < vertex.klassId ||
           klassId == vertex.klassId && methodId < vertex.methodId;
}
