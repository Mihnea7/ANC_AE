#include "include/node.h"

Node::Node(std::string nName, std::vector<int> nDist) : name(nName), dist(nDist) { }
Node::~Node() { std::cout << "Deleted node " << name << std::endl; }