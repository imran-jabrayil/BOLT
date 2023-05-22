#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "macros.hpp"

class Vertex {
public:
    uint klassId;
    uint methodId;

    Vertex() {
        klassId = 0;
        methodId = 0;
    }

    Vertex(uint klassId, uint methodId) {
        this->klassId = klassId;
        this->methodId = methodId;
    }

    Vertex(const Vertex &vertex) {
        klassId = vertex.klassId;
        methodId = vertex.methodId;
    }

    bool operator==(const Vertex &vertex) const { return klassId == vertex.klassId && methodId == vertex.methodId; }
    bool operator<(const Vertex &vertex)  const { 
        return klassId < vertex.klassId || 
               klassId == vertex.klassId && methodId < vertex.methodId; 
    }
};

#endif // VERTEX_HPP
