#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "macros.hpp"

struct Vertex {
    uint klassId;
    uint methodId;

    bool operator==(const Vertex &vertex) const;
    bool operator<(const Vertex &vertex) const;
};

#endif  // VERTEX_HPP
