#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include <map>

#include "macros.hpp"

class Cluster;

class Edge {
   private:
    uint _id;
    uint _fromClusterId;
    uint _toClusterId;
    uint _weight;

   public:
    Edge(uint fromClusterId, uint toClusterId);
    Edge(uint fromClusterId, uint toClusterId, uint weight);

    void addWeight();
    void addWeight(uint weight);

    uint getFromClusterId();
    uint getToClusterId();

    void setFromClusterId(uint id);
    void setToClusterId(uint id);

    uint id();
    uint weight();

    bool operator==(const Edge& edge) const;
    bool operator<(const Edge& edge) const;

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};

#endif  // EDGE_HPP
