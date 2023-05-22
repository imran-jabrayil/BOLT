#include "callgraph.hpp"
#include <cassert>

Vertex *CallGraph::findVertex(const Vertex &vertex) {
    for (uint i = 0; i < _vertexes.size(); ++i)
        if (_vertexes[i] == vertex)
            return &_vertexes[i];
    return nullptr;
}

Edge *CallGraph::findEdge(const Edge &edge) {
    for (uint i = 0; i < _edges.size(); ++i)
        if (_edges[i] == edge)
            return &_edges[i];
    return nullptr;
}

void CallGraph::addEdge(const Edge &edge) {
    Edge *found = findEdge(edge);
    if (found != nullptr) {
        found->weight += edge.weight;
    } else {
        _edges.push_back(edge);
    }
}

void CallGraph::addVertex(const Vertex &vertex) {
    Vertex *found = findVertex(vertex);
    if (found == nullptr)
        _vertexes.push_back(vertex);
}

const Edge &CallGraph::getEdge(const Vertex &from, const Vertex &to) {
    const Edge edge(from, to, 1);
    Edge *found = findEdge(edge);
    assert(found != nullptr);
    return *found;
}