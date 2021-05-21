#pragma once
#include <iostream>
#include "edge.h"
#include <algorithm>
class Graph
{
public:
    ~Graph();
    void add_node(Node *);
    void print_all_node_names();
    void bellman_ford(Node *, int, int);
    void bellman_ford_sh(Node *, int, int);
    bool is_in_graph(Node *);
    size_t get_node_size() { return node_list.size(); }
    size_t get_nr_edges();
    Node *get_existing_node(std::string);
    void destroy_link(Node*, Node *, Node *);
    void destroy_link_sh(Node *, Node *, Node *);


private:
    std::vector<Node *> node_list;
    std::vector<Node *> deleted_list;
    void initialise(Node *);
    void update(Edge *, Node *, Node *);
    void print_nodes();
    void neighbour_exchange(Node *, int &, int);
    void neighbour_exchange(Node*);
    Node* get_random_node(std::vector<Node *>);
};
