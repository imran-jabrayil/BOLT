#include "cluster.hpp"

static uint idCounter = 1;
static std::map<uint, Cluster> clusters;

Cluster::Cluster(uint id, uint vertexId) {
    _id = id;
    _vertexIds.push_back(id);
}

void Cluster::addVertex(uint clusterId, uint vertexId) {
    auto iter = clusters.find(clusterId);
    if (iter == clusters.end()) {
        addVertex(vertexId);
    } else {
        Cluster &cluster = iter->second;
        cluster._vertexIds.push_back(vertexId);
    }
}

Cluster &Cluster::addVertex(uint vertexId) {
    uint id = idCounter++;
    clusters.insert(std::make_pair(id, Cluster(id, vertexId)));
    return clusters.find(id)->second;
}

void Cluster::addCluster(Cluster &cluster) {
    if (clusters.find(cluster._id) == clusters.end())
        clusters.insert(std::make_pair(cluster._id, cluster));
}

uint Cluster::id() { return _id; }

Cluster *Cluster::getClusterById(uint id) {
    auto iter = clusters.find(id);
    if (iter == clusters.end()) return nullptr;

    return &iter->second;
}

std::map<uint, Cluster> Cluster::getClusters() { return clusters; }

const std::vector<uint> &Cluster::getVertexIds() { return _vertexIds; }

void Cluster::resetIds() {
    idCounter = 1;
    clusters.clear();
}

bool Cluster::operator==(const Cluster &cluster) const {
    return _id == cluster._id;
}
