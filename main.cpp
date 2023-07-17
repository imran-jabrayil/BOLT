#include <iostream>
#include <map>

#include "callgraph.hpp"
#include "cluster.hpp"
#include "edge.hpp"

CallGraph generateCallGraph1();
CallGraph generateCallGraph2();

int main(int argc, char *argv[]) {
    {
        std::cout << "\tTest case 1" << std::endl;
        CallGraph callGraph = generateCallGraph1();

        auto order = callGraph.getOrder();
        std::cout << "Order: ";
        for (uint id : order) std::cout << id << " ";
        std::cout << std::endl;
    }

    {
        std::cout << "\tTest case 2" << std::endl;
        CallGraph callGraph = generateCallGraph2();

        auto order = callGraph.getOrder();
        std::cout << "Order: ";
        for (uint id : order) std::cout << id << " ";
        std::cout << std::endl;
    }

    return 0;
}

CallGraph generateCallGraph1() {
    CallGraph callGraph;

    Cluster &cluster1 = Cluster::addVertex(1);
    Cluster &cluster2 = Cluster::addVertex(2);
    Cluster &cluster3 = Cluster::addVertex(3);
    Cluster &cluster4 = Cluster::addVertex(4);

    Edge edge1{cluster1.id(), cluster3.id(), 30};
    Edge edge2{cluster2.id(), cluster3.id(), 40};
    Edge edge3{cluster3.id(), cluster4.id(), 20};
    Edge edge4{cluster4.id(), cluster2.id(), 50};

    callGraph.addEdge(edge1);
    callGraph.addEdge(edge2);
    callGraph.addEdge(edge3);
    callGraph.addEdge(edge4);

    return callGraph;
}

CallGraph generateCallGraph2() {
    CallGraph callGraph;

    Cluster &cluster1 = Cluster::addVertex(1);
    Cluster &cluster2 = Cluster::addVertex(2);
    Cluster &cluster3 = Cluster::addVertex(3);
    Cluster &cluster4 = Cluster::addVertex(4);

    Edge edge1{cluster1.id(), cluster2.id(), 100};
    Edge edge2{cluster1.id(), cluster3.id(), 40};
    Edge edge3{cluster2.id(), cluster3.id(), 30};
    Edge edge4{cluster3.id(), cluster4.id(), 90};

    callGraph.addEdge(edge1);
    callGraph.addEdge(edge2);
    callGraph.addEdge(edge3);
    callGraph.addEdge(edge4);

    return callGraph;
}