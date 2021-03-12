/*

Mihnea Maldaianu 2289803M

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include "include/graph.h"
using string = std::string;

int main()
{
    string line;
    int V, E;
    std::ifstream inputFile("inputNodes.txt");
    inputFile >> V >> E;
    Graph graph(V, E);
    std::vector<std::vector<int>> data;

    // Stage 1: read from file and generate vectors for each row
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            if (line.find("#") == 0)
                continue;

            std::vector<string> node_dist;
            std::vector<int> res;
            std::istringstream iss(line);
            for (std::string s; iss >> line;)
                node_dist.push_back(line);

            for (auto &w : node_dist)
            {
                if (w.compare("inf") != 0)
                    res.push_back(std::stoi(w));
                else
                    res.push_back(INT32_MAX);
            }
            data.push_back(res);
        }
        inputFile.close();
    }
    else
        std::cout << "Unable to open input file";

    // Stage 2: generate instances of edges to the current graph from Stage 1
    for (int i = 0; i < static_cast<int>(data.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(data[i].size()); j++)
        {
            if (data[i][j] == 0 || data[i][j] == INT32_MAX)
                continue;

            Edge *edge = new Edge(i - 1, j, data[i][j]);

            if (!graph.check_edge(edge))
                graph.add_edge(edge);
            else
                delete edge;
        }
    }
    graph.print_edges();
    std::cout << " " << graph.get_nr_edges();

    // Stage 3: Bellman Ford algorithm - no step backwards
    int src;
    std::cout << std::endl
              << "Please enter on which node you want to calculate. (0 to " << V - 1 << "): ";
    std::cin >> src;
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT32_MAX;
    dist[src] = 0;
    for (int i = 0; i < V ; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph.get_edge_at(j).source;
            int v = graph.get_edge_at(j).dest;
            int weight = graph.get_edge_at(j).weight;
            if (dist[u] != INT32_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;

            u = graph.get_edge_at(j).dest;
            v = graph.get_edge_at(j).source;
            weight = graph.get_edge_at(j).weight;
            if (dist[u] != INT32_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (auto &d : dist)
        std::cout << d<<std::endl;
}
