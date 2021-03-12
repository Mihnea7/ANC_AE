#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include "edge.h"
class Graph
{
public:
    Graph(int V, int E);
    ~Graph();
    //void add_edge(int index, int source, int dest, int weight);
    void add_edge(Edge *edge);
    bool check_edge( Edge *other);
    void print_edges();
    int get_nr_edges() {return edges.size();}
    Edge& get_edge_at(int index) {return *edges[index];}

private:
    int V, E;
    std::vector<Edge*> edges;
};