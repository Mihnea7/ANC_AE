#include "include/NodeFactory.h"

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
    NodeFactory node_factory;
    node_factory.generate_nodes(inputFile, graph);
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
}
