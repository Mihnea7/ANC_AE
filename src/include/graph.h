#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include "node.h"
#include "edge.h"
class Graph
{
    public:
    Graph();
    ~Graph();
    void add_node(Node *node);
    void add_edge(Edge *edge);
    void print();

    private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    int V, E;
};