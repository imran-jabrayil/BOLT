#ifndef EDGE_HPP
#define EDGE_HPP

#include "macros.hpp"
#include "vertex.hpp"

class Edge {
public:
    Vertex src;
    Vertex dest;
    uint weight;

    Edge(const Vertex &src, const Vertex &dest, uint weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }

    bool operator==(const Edge &edge) const { return src == edge.src && dest == edge.dest; }
    bool operator<(const Edge &edge)  const { 
        return src < edge.src || 
               src == edge.src && dest < edge.dest || 
               src == edge.src && dest == edge.dest && weight < edge.weight; 
    }
};

#endif // EDGE_HPP
