#include "include/node.h"

Node::Node(std::string node_name) : name(node_name) {}

Node::~Node()
{
    for (auto &node : neighbour_list)
    {
        delete node;
    }

    for (auto &edge : edge_list)
    {
        delete edge;
    }
}

bool Node::operator==(Node *other)
{
    if (!this->get_name().compare(other->get_name()))
        return true;
    return false;
}

void Node::add_neighbour(Node *new_node)
{
    neighbour_list.push_back(new_node);
}

void Node::add_edge(Edge *new_edge)
{
    edge_list.push_back(new_edge);
}

void Node::remove_edge(Edge *edge)
{
    auto edge_index = std::find(edge_list.begin(), edge_list.end(), edge);
    if (edge_index != edge_list.end())
    {
        edge_list.erase(edge_index);
        std::cout << "Edge removed successfully.\n";
    }
}

bool Node::is_in_edge(Edge *target_edge)
{
    for (auto &edge : edge_list)
    {
        if (edge == target_edge)
            return true;
    }
    return false;
}

Edge *Node::get_edge_between_nodes(Node *dest)
{
    if (!dest)
        return nullptr;
    for (auto &edge : edge_list)
    {
        if (edge->get_dest() == dest)
            return edge;
    }
    return nullptr;
}