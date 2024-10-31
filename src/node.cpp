#include "node.h"
#include <array>
#include <iostream>
#include <vector>

const int& Node::get_id() const {
    return id;
}

void Node::set_id(const int& _id) {
    id = _id;
}

const std::array<int, 3>& Node::get_pos() const {
	return pos;
}

void Node::set_pos(const std::array<int, 3>& _pos) {
	pos = _pos;
}

const std::vector<Node>& Node::get_neighbors() const {
    return neighbors;
}

void Node::set_neighbors(const std::vector<Node>& _neighbors) {
    neighbors = _neighbors;
}

void Node::add_neighbor(const Node& nd) {
    neighbors.push_back(nd);
}

void Node::remove_neighbor(const Node& nd) {
    for(size_t i = 0; i < neighbors.size(); i++){
        if(neighbors[i] == nd) {
            neighbors.erase(neighbors.begin()+i);
        }
    }
}
