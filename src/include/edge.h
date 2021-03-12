#pragma once
#include <iostream>
class Edge
{
public:
    Edge(int, int, int);
    bool operator==(const Edge &other);
    int source, dest, weight;
};