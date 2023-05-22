#include <iostream>

#include "callgraph.hpp"

CallGraph generateCallGraph();

int main(int argc, char *argv[]) {
    CallGraph cgraph = generateCallGraph();

    const Edge &edge = cgraph.getEdge(Vertex(1, 2), Vertex(3, 4));

    std::cout << edge.weight << std::endl;
    return 0;
}

CallGraph generateCallGraph() {
    CallGraph cgraph;

    cgraph.addVertex(Vertex(1, 2));
    cgraph.addVertex(Vertex(3, 4));

    cgraph.addEdge(Edge(Vertex(1, 2), Vertex(3, 4), 2));
    cgraph.addEdge(Edge(Vertex(1, 2), Vertex(3, 4), 3));

    return cgraph;
}
