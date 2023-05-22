#ifndef CALLGRAPH_HPP
#define CALLGRAPH_HPP

#include <vector>
#include <set>
#include "macros.hpp"
#include "vertex.hpp"
#include "edge.hpp"

class CallGraph {
public:
    std::set<Vertex> _vertexes;
    std::set<Edge> _edges;

    Vertex *findVertex(const Vertex &vertex);
    Edge *findEdge(const Edge &edge);
public:
    CallGraph() {}
    CallGraph(const CallGraph &callGraph) {
        _vertexes = callGraph._vertexes;
        _edges = callGraph._edges;
    }

    CallGraph(CallGraph &&callGraph) {
        _vertexes = callGraph._vertexes;
        _edges = callGraph._edges;
    }

    void addVertex(const Vertex &vertex);
    void addEdge(const Edge &edge);
    const Edge &getEdge(const Vertex &from, const Vertex &to);
};


#endif // CALLGRAPH_HPP
