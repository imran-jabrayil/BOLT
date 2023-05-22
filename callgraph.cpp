#include "callgraph.hpp"
#include <cassert>

Vertex *CallGraph::findVertex(const Vertex &vertex) {
    for (auto iter = _vertexes.begin(); iter != _vertexes.end(); ++iter) {
        Vertex &result = const_cast<Vertex &>(*iter);
        if (result == vertex)
            return &result;
    }
    return nullptr;
}

Edge *CallGraph::findEdge(const Edge &edge) {
    for (auto iter = _edges.begin(); iter != _edges.end(); ++iter) {
        Edge &result = const_cast<Edge &>(*iter);
        if (result == edge)
            return &result;
    }
    return nullptr;
}

void CallGraph::addEdge(const Edge &edge) {
    Edge *found = findEdge(edge);
    if (found != nullptr) {
        found->weight += edge.weight;
    } else {
        _edges.insert(edge);
    }
}

void CallGraph::addVertex(const Vertex &vertex) {
    Vertex *found = findVertex(vertex);
    if (found == nullptr)
        _vertexes.insert(vertex);
}

const Edge &CallGraph::getEdge(const Vertex &from, const Vertex &to) {
    const Edge edge(from, to, 1);
    Edge *found = findEdge(edge);
    assert(found != nullptr);
    return *found;
}