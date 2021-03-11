#pragma once
#include <string>
#include <iostream>
#include <vector>
class Node
{
    friend class Graph;

private:
    std::string name;
    std::vector<int> dist;

public:
    Node(std::string name, std::vector<int> dist);
    ~Node();
    std::string get_name() { return name; };
};