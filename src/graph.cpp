#include "include/graph.h"

Graph::Graph() :V(0), E(0) {}

Graph::~Graph()
{
    for (auto &node : nodes)
    {
        delete node;
    }
}

void Graph::add_node(Node *node)
{
    nodes.push_back(node);
    V +=1;
}

void Graph::add_edge(Edge *edge)
{
    edges.push_back(edge);
    E +=1;
}

void Graph::print()
{
    for (auto node : nodes)
    {
        std::cout << node->name << " ";
        for (auto i : node->dist)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}
