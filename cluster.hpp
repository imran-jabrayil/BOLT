#ifndef CLUSTER_HPP
#define CLUSTER_HPP

#include <map>
#include <vector>

#include "macros.hpp"

class Cluster {
   private:
    uint _id;
    std::vector<uint> _vertexIds;
    Cluster(uint id, uint vertexId);

   public:
    static void addVertex(uint clusterId, uint vertexId);
    static Cluster &addVertex(uint vertexId);

    static void addCluster(Cluster &cluster);

    const std::vector<uint> &getVertexIds();

    uint id();
    static Cluster *getClusterById(uint id);
    static std::map<uint, Cluster> getClusters();

    static void resetIds();

    bool operator==(const Cluster &cluster) const;
};

#endif  // CLUSTER_HPP
