#include "include/graph.h"
#include <fstream>
#include <sstream>
void read_node_edges(std::ifstream &, Graph &);

int main()
{
    std::string fileName;
    std::cout << "Please type in the name of the input file (include extension too): \n";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);
    if (!inputFile.good())
    {
        std::cout << "File does not exist; exiting program\n";
        return -1;
    }
    std::string target;
    Graph graph;

    read_node_edges(inputFile, graph);
    std::cout << "Number of nodes: " << graph.get_node_size() << std::endl;
    std::cout << "Number of edges: " << graph.get_nr_edges() / 2 << std::endl;

    std::cout << "Select which node/vertex you would like to calculate distances for : " << std::endl;
    std::cout << "Available nodes: ";
    graph.print_all_node_names();
    std::cout << "\n";
    std::cin >> target;
    Node *source_node = graph.get_existing_node(target);

    std::cout << "\n";

    int iters;
    std::cout << "How many iterations would you like the algorithm to run for? \n";
    std::cin >> iters;

    std::cout << "\n";

    int fail_prob;
    std::cout << "Enter the probability that a link will fail at random? (0 - 100) \n";
    std::cin >> fail_prob;

    std::cout << "\n";

    char split_horizon;
    std::cout << "Turn on split horizon functionality? (Y/n) \n";
    std::cin >> split_horizon;
    std::cout << "\n";

    switch (split_horizon)
    {
    case 'Y':
        graph.bellman_ford_sh(source_node, iters, fail_prob);
        break;
    case 'n':
        graph.bellman_ford(source_node, iters, fail_prob);
        break;
    }

    std::cout << "\n \n";
    std::cout << "The program will terminate once you press any key...\n";
    system("PAUSE");
}

void read_node_edges(std::ifstream &inputFile, Graph &graph)
{
    std::string line;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            if (line.find("#") == 0)
                continue;

            std::vector<std::string> params;
            std::istringstream iss(line);
            for (std::string s; iss >> line;)
                params.push_back(line);

            Node *source = graph.get_existing_node(params[0]);
            Node *dest = graph.get_existing_node(params[1]);

            if (source == nullptr && dest == nullptr)
            {
                source = new Node(params[0]);
                dest = new Node(params[1]);
                graph.add_node(source);
                graph.add_node(dest);
                source->add_edge(new Edge(source, dest, std::stoi(params[2])));
                source->add_neighbour(dest);
                dest->add_edge(new Edge(dest, source, std::stoi(params[2])));
                dest->add_neighbour(source);
            }
            else if (source && dest == nullptr)
            {
                dest = new Node(params[1]);
                graph.add_node(dest);
                source->add_edge(new Edge(source, dest, std::stoi(params[2])));
                source->add_neighbour(dest);
                dest->add_edge(new Edge(dest, source, std::stoi(params[2])));
                dest->add_neighbour(source);
            }
            else if (source == nullptr && dest)
            {
                source = new Node(params[0]);
                graph.add_node(source);
                source->add_edge(new Edge(source, dest, std::stoi(params[2])));
                source->add_neighbour(dest);
                dest->add_edge(new Edge(dest, source, std::stoi(params[2])));
                dest->add_neighbour(source);
            }
            else if (source && dest)
            {
                graph.add_node(source);
                graph.add_node(dest);
                source->add_edge(new Edge(source, dest, std::stoi(params[2])));
                source->add_neighbour(dest);
                dest->add_edge(new Edge(dest, source, std::stoi(params[2])));
                dest->add_neighbour(source);
            }
        }
        std::cout << "Read from file successfully!" << std::endl;
        inputFile.close();
    }
}