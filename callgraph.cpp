#include "callGraph.hpp"

#include "Cluster.hpp"
#include "Edge.hpp"

void CallGraph::addCluster(Cluster &cluster) {
    Cluster::addCluster(cluster);
    _clusters.insert(cluster.id());
}

void CallGraph::addEdge(Edge &edge) {
    for (auto iter = _edges.begin(); iter != _edges.end(); ++iter) {
        Edge &found = const_cast<Edge &>(*iter);
        if (found == edge) {
            found.addWeight(edge.weight());
            return;
        }
    }

    _edges.insert(edge);
    _clusters.insert(edge.getClusterFrom().id());
    _clusters.insert(edge.getClusterTo().id());
}

const std::set<Edge> &CallGraph::getEdges() const { return _edges; }
