#include "edge.hpp"

#include "cluster.hpp"

static uint idCounter = 0;

Edge::Edge(uint fromClusterId, uint toClusterId) : _fromClusterId(fromClusterId), _toClusterId(toClusterId), _id(idCounter++) {
    _weight = 1;
}

Edge::Edge(uint fromClusterId, uint toClusterId, uint weight) : Edge(fromClusterId, toClusterId) {
    _weight = weight;
}

void Edge::addWeight() { ++_weight; }

void Edge::addWeight(uint weight) { _weight += weight; }

uint Edge::getFromClusterId() {
    return _fromClusterId;
}

uint Edge::getToClusterId() {
    return _toClusterId;
}

void Edge::setFromClusterId(uint id) {
    _fromClusterId = id;
}

void Edge::setToClusterId(uint id) {
    _toClusterId = id;
}

uint Edge::id() { return _id; }

uint Edge::weight() { return _weight; }

void Edge::resetIds() {
    idCounter = 1;
}

bool Edge::operator==(const Edge& edge) const {
    return _fromClusterId == edge._fromClusterId && _toClusterId == edge._toClusterId;
}

bool Edge::operator<(const Edge& edge) const {
    return _weight > edge._weight;
}  // for std::set sort

std::ostream& operator<<(std::ostream& os, const Edge& edge) {
    return os << edge._fromClusterId << " " << edge._toClusterId << " " << edge._weight;
}