#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

#include "macros.hpp"

class Cluster;

class Edge {
   private:
    Cluster& _from;
    Cluster& _to;
    uint _weight;

   public:
    Edge(Cluster& from, Cluster& to);
    Edge(Cluster& from, Cluster& to, uint weight);

    void addWeight();
    void addWeight(uint weight);

    Cluster& getClusterFrom();
    Cluster& getClusterTo();

    uint weight();
    bool operator==(const Edge& edge) const;
    bool operator<(const Edge& edge) const;

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};

#endif  // EDGE_HPP
