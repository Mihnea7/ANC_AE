#include "include/graph.h"

Graph::Graph(int nV, int nE) : V(nV), E(nE) {}

Graph::~Graph()
{
    //delete edges;
    for (auto &edge : edges)
    {
        delete edge;
    }
}

/* void Graph::add_edge(int index, int source, int dest, int weight)
{
    edges[index].source = source;
    edges[index].dest = dest;
    edges[index].weight = weight;
} */

void Graph::add_edge(Edge *edge)
{
    edges.push_back(edge);
}

bool Graph::check_edge(Edge *other)
{
    for (auto &edge : edges)
    {
        if (*other == *edge)
            return true;
    }
    return false;
}

void Graph::print_edges()
{
    for (auto &edge : edges)
    {
        std::cout << std::endl<< edge->source << " " << edge->dest << " " << edge->weight;
    }
    std::cout<<std::endl;
}
