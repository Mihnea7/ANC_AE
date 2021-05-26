#include "include/NodeFactory.h"

void NodeFactory::generate_nodes(std::ifstream &inputFile, Graph &graph)
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