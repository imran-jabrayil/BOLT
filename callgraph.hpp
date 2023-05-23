#ifndef CALLGRAPH_HPP
#define CALLGRAPH_HPP

#include <map>
#include <set>

#include "macros.hpp"

class Edge;
class Cluster;

class CallGraph {
   private:
    std::set<uint> _clusters;
    std::set<Edge> _edges;

   public:
    void addCluster(Cluster &cluster);
    void addEdge(Edge &edge);

    const std::set<Edge> &getEdges() const;
    std::vector<uint> getOrder();
};

#endif  // CALLGRAPH_HPP
