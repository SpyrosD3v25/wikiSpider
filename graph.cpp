#include "graph.h"
#include <vector>
#include <iostream>
#include <utility>

void Graph::add_node(Node nd) {
    nodes.push_back(nd);	
}

const std::vector<Node>& Graph::get_nodes() const {
	return nodes;
}

void Graph::add_edge(Edge edge) {
    edges.push_back(edge);
}

const std::vector<Edge>& Graph::get_edges() const {
    return edges;
}

void Graph::print_graph() {
	for(auto u : nodes) {
		std::cout << "dick";
	}
}	
	
