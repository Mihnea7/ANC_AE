#pragma once
class Node;
#include "node.h"
#include <iostream>
class Edge
{
public:
    Edge(Node *, Node *, int);
    ~Edge() = default;
    Node *get_source() { return source; }
    Node *get_dest() { return dest; }
    int get_weight() { return weight; }
    void set_weight(int weight) { this->weight = weight; }
    void set_source(Node *source) { this->source = source; }
    void set_dest(Node *dest) { this->dest = dest; }
    bool operator==(Edge &);
    void print();

private:
    Node *source;
    Node *dest;
    int weight;
};