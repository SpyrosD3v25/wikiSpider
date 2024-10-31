#include "graph.h"
#include <vector>
#include <iostream>
#include <utility>


void Graph::add_node(Node nd) {
    nd.set_id(Graph::nodes.size());
    Graph::nodes.push_back(nd);
}

std::vector<Node>& Graph::get_nodes() {
	return Graph::nodes;
}

void Graph::add_edge(Node& from, Node& to) {
    from.add_neighbor(to);
    to.add_neighbor(from);
}

void Graph::print_graph() {
	for(auto u : nodes) {
        std::cout << u.get_pos()[0] << " " << u.get_pos()[1] << " " << u.get_pos()[2] << "\n";
	}
}	


