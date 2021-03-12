#include "include/edge.h"
Edge::Edge(int s, int d, int w) : source(s), dest(d), weight(w) {};

bool Edge::operator==(const Edge &other)
{
    return ((this->source == other.dest && this->dest == other.source && this->weight == other.weight) ||
    (this->source == other.source && this->dest == other.dest && this->weight == other.weight));
}