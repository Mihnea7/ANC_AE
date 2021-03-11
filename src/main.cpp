/*

Mihnea Maldaianu 2289803M

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <limits>
#include "include/node.h"
#include "include/graph.h"
using string = std::string;

int main()
{
    string line;
    Graph graph;
    int V, E;
    std::ifstream inputFile("inputNodes.txt");
    if (inputFile.is_open())
    {
        //inputFile >> V >> E;
        //std::cout<<V<<" "<<E<<std::endl;
        while (getline(inputFile, line))
        {
            std::vector<std::string> node_params;
            std::istringstream iss(line);
            for (std::string s; iss >> line;)
                node_params.push_back(line);

            std::string name = node_params[0];
            std::vector<int> dist;
            for (int i = 1; i < static_cast<int>(node_params.size()); i++)
            {
                if (node_params[i].compare("inf") != 0)
                    dist.push_back(std::stoi(node_params[i]));
                else dist.push_back(INT32_MAX);
            }
            Node *node = new Node(name, dist);
            graph.add_node(node);
        }
        inputFile.close();
    }
    else
        std::cout << "Unable to open input file";

    graph.print();

}
