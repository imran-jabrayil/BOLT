#include <iostream>

#include "Cluster.hpp"
#include "Edge.hpp"
#include "callGraph.hpp"

CallGraph generateCallGraph();

int main(int argc, char *argv[]) {
    CallGraph cgraph = generateCallGraph();

    const std::set<Edge> &edges = cgraph.getEdges();
    for (auto iter = edges.begin(); iter != edges.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
    return 0;
}

CallGraph generateCallGraph() {
    CallGraph cgraph;

    Cluster &cluster1 = Cluster::addVertex(1);
    Cluster &cluster2 = Cluster::addVertex(2);
    Cluster &cluster3 = Cluster::addVertex(3);
    Cluster &cluster4 = Cluster::addVertex(4);

    Edge edge1{cluster1, cluster2};
    Edge edge2{cluster1, cluster2, 4};
    Edge edge3{cluster3, cluster4, 3};
    Edge edge4{cluster4, cluster2, 2};

    cgraph.addEdge(edge1);
    cgraph.addEdge(edge2);
    cgraph.addEdge(edge3);
    cgraph.addEdge(edge4);

    return cgraph;
}