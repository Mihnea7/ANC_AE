#pragma once
#include "graph.h"
#include <fstream>
#include <sstream>

class NodeFactory
{
public:
    void generate_nodes(std::ifstream &, Graph &);
};