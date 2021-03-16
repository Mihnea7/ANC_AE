#pragma once
class Edge;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "edge.h"
class Node
{
public:
    Node(std::string name);
    ~Node();
    void add_neighbour(Node *);
    void add_edge(Edge *);
    void remove_edge(Edge *);
    std::string get_name() { return name; }
    int get_distance() { return distance; }
    void set_distance(int new_dist) { distance = new_dist; }
    std::vector<Node *> get_neighbour_list() { return neighbour_list; }
    std::vector<Edge *> get_edge_list() { return edge_list; }
    bool operator==(Node *other);
    bool is_in_edge(Edge *);
    Edge* get_edge_between_nodes(Node*);

private:
    std::string name;
    std::vector<Edge *> edge_list;
    std::vector<Node *> neighbour_list;
    int distance;
};