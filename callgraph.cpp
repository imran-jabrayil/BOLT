#include "callGraph.hpp"

#include <cassert>

#include "cluster.hpp"
#include "edge.hpp"

CallGraph::CallGraph() {
    Cluster::resetIds();
    Edge::resetIds();
}

void CallGraph::addCluster(Cluster &cluster) {
    Cluster::addCluster(cluster);
    _clusters.insert(cluster.id());
}

void CallGraph::addEdge(Edge &edge) {
    for (auto iter = _edges.begin(); iter != _edges.end(); ++iter) {
        if (*iter == edge) {
            Edge &foundEdge = const_cast<Edge&>(*iter);
            foundEdge.addWeight(edge.weight());
            return;
        }
    }

    _edges.insert(edge);
    _clusters.insert(edge.getFromClusterId());
    _clusters.insert(edge.getToClusterId());
}

const std::set<Edge> &CallGraph::getEdges() const { return _edges; }

std::vector<uint> CallGraph::getOrder() {
    while (!_edges.empty()) {
        Edge clusterEdge = *_edges.begin();

        uint fromId = clusterEdge.getFromClusterId();
        uint toId = clusterEdge.getToClusterId();

        Cluster *from = Cluster::getClusterById(fromId);
        assert(from != nullptr);

        Cluster *to = Cluster::getClusterById(toId);
        assert(to != nullptr);

        for (uint id : to->getVertexIds())
            Cluster::addVertex(from->id(), id);
        _edges.erase(_edges.begin());

        for (auto iter = _edges.begin(); iter != _edges.end(); ) {
            Edge edge = *iter;
            if (fromId == edge.getToClusterId() && toId == edge.getFromClusterId()) {
                iter = _edges.erase(iter);
                continue;
            }

            if (edge.getToClusterId() == toId) {
                edge.setToClusterId(fromId);
                iter = _edges.erase(iter);
                addEdge(edge);
            } else if (edge.getFromClusterId() == toId) {
                edge.setFromClusterId(fromId);
                iter = _edges.erase(iter);
                addEdge(edge);
            } else {
                ++iter;
            }
        }

        _clusters.erase(toId);
    }

    std::vector<uint> order;

    for (uint clusterId : _clusters) {
        Cluster *cluster = Cluster::getClusterById(clusterId);
        assert(cluster != nullptr);

        for (uint id : cluster->getVertexIds()) order.push_back(id);
    }

    return order;
}
