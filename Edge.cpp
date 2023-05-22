#include "Edge.hpp"

#include "Cluster.hpp"

Edge::Edge(Cluster& from, Cluster& to) : _from(from), _to(to) { _weight = 1; }

Edge::Edge(Cluster& from, Cluster& to, uint weight) : Edge(from, to) {
    _weight = weight;
}

void Edge::addWeight() { ++_weight; }

void Edge::addWeight(uint weight) { _weight += weight; }

Cluster& Edge::getClusterFrom() { return _from; }

Cluster& Edge::getClusterTo() { return _to; }

uint Edge::weight() { return _weight; }

bool Edge::operator==(const Edge& edge) const {
    return _from.id() == edge._from.id() && _to.id() == edge._to.id();
}

bool Edge::operator<(const Edge& edge) const {
    return _weight > edge._weight;
}  // for std::set sort

std::ostream& operator<<(std::ostream& os, const Edge& edge) {
    return os << edge._from.id() << " " << edge._to.id() << " " << edge._weight;
}