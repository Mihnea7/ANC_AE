#include "include/graph.h"

Graph::~Graph()
{
    for (auto *node : node_list)
    {
        delete node;
    }
    node_list.clear();
    node_list.resize(0);
    for (auto *node : deleted_list)
    {
        delete node;
    }
    deleted_list.clear();
    deleted_list.resize(0);
}

void Graph::add_node(Node *new_node)
{
    if (!is_in_graph(new_node))
        node_list.push_back(new_node);
}

void Graph::initialise(Node *source)
{
    source->set_distance(0);
    for (auto &node : node_list)
    {
        if (node->get_name().compare(source->get_name()))
        {
            node->set_distance(9000);
        }
    }
}

void Graph::print_all_node_names()
{
    for (auto &node : node_list)
    {
        std::cout << node->get_name() << " ";
    }
}

void Graph::update(Edge *edge, Node *source, Node *dest)
{
    if (edge->get_weight() != 90000)
    {
        int distance = std::min(dest->get_distance(), (source->get_distance() + edge->get_weight()));
        dest->set_distance(distance);
    }
}

void Graph::bellman_ford(Node *source, int iterations, int fail_prob)
{
    if (!source)
    {
        std::cout << "Could not find node! Exiting program.\n";
        return;
    }
    initialise(source);

    for (int i = 0; i < iterations; i++)
    {
        std::cout << "ITERATION " << i << "\n";
        int v1 = rand() % 100 + 1;
        if (v1 < fail_prob)
        {
            Node *random_node = get_random_node(node_list);
            Node *random_neighbour = get_random_node(random_node->get_neighbour_list());
            destroy_link(source, random_node, random_neighbour);
        }
        for (auto &node : node_list)
        {

            for (auto &edge : node->get_edge_list())
            {

                update(edge, edge->get_source(), edge->get_dest());
            }
        }
        print_nodes();
    }
}

void Graph::bellman_ford_sh(Node *source, int iterations, int fail_prob)
{
    if (!source)
    {
        std::cout << "Could not find node! Exiting program.\n";
        return;
    }
    initialise(source);
    int i = 0;
    while (i < iterations)
    {
        //randomly take down a link
        int v1 = rand() % 100 + 1;
        if (v1 < fail_prob)
        {
            Node *random_node = get_random_node(node_list);
            Node *random_neighbour = get_random_node(random_node->get_neighbour_list());
            destroy_link_sh(source, random_node, random_neighbour);
        }
        //simulate exchange between the neighbours of every node
        for (auto &node : node_list)
        {
            //calculate route to all nodes via neighbours
            neighbour_exchange(node, i, iterations);
        }
    }
}

void Graph::neighbour_exchange(Node *start, int &i, int max_iter)
{

    for (auto &node : start->get_neighbour_list())
    {
        if (i < max_iter)
        {
            std::cout << "Iteration " << i << "\n";
            print_nodes();
            ++i;
            for (auto &edge : node->get_edge_list())
            {

                update(edge, edge->get_source(), edge->get_dest());
            }
        }
    }
}

void Graph::print_nodes()
{
    for (auto &node : node_list)
    {
        std::cout << node->get_name() << " " << node->get_distance() << std::endl;
    }
    std::cout << "\n";
}

bool Graph::is_in_graph(Node *target_node)
{
    for (auto &node : node_list)
    {
        if (*node == target_node)
            return true;
    }
    return false;
}

size_t Graph::get_nr_edges()
{
    size_t sum = 0;
    for (auto &node : node_list)
    {

        sum += node->get_edge_list().size();
    }
    return sum;
}

Node *Graph::get_existing_node(std::string name)
{
    for (auto &node : node_list)
    {
        if (!node->get_name().compare(name))
            return node;
    }
    return nullptr;
}

void Graph::destroy_link_sh(Node *selected_source, Node *source, Node *dest)
{
    Edge *first_edge = source->get_edge_between_nodes(dest);
    Edge *second_edge = dest->get_edge_between_nodes(source);

    first_edge->set_weight(9000);
    second_edge->set_weight(9000);
    if (source != selected_source)
        source->set_distance(9000);
    if (dest != selected_source)
        dest->set_distance(9000);
    deleted_list.push_back(source);
    deleted_list.push_back(dest);
    std::cout << "Link between " << source->get_name() << " and " << dest->get_name() << " is down!\n";
}
void Graph::destroy_link(Node *selected_source, Node *source, Node *dest)
{
    Edge *first_edge = source->get_edge_between_nodes(dest);
    Edge *second_edge = dest->get_edge_between_nodes(source);

    source->remove_edge(first_edge);
    dest->remove_edge(second_edge);

    deleted_list.push_back(source);
    deleted_list.push_back(dest);
    std::cout << "Link between " << source->get_name() << " and " << dest->get_name() << " is down!\n";
}
Node *Graph::get_random_node(std::vector<Node *> node_vector)
{
    int random_index = rand() % node_vector.size();

    Node *random_node = node_vector[random_index];
    // if random node not in deleted list
    size_t counter = 0;
    while (std::find(deleted_list.begin(), deleted_list.end(), random_node) == deleted_list.end())
    {
        if (counter > node_vector.size())
            break;
        random_index = rand() % node_vector.size();
        random_node = node_vector[random_index];
        ++counter;
    }
    return random_node;
}