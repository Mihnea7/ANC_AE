#include "include/edge.h"

Edge::Edge(Node *src, Node *dst, int w) : source(src), dest(dst), weight(w) {}

Edge::~Edge()
{
    delete source;
    delete dest;
}

bool Edge::operator==(Edge &other)
{
    if (this->get_source() == other.get_source() && this->get_dest() == other.get_dest() && this->get_weight() == other.get_weight())
        return true;
    return false;
}
void Edge::print()
{
    std::cout << "Source: " << source->get_name() << " Destination: " << dest->get_name() << " Weight: " << weight << std::endl;
}