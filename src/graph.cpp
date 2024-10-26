#include "graph.h"
#include <vector>
#include <iostream>
#include <utility>

std::vector<std::vector<Node>> Graph::adj_list = {{}};
std::vector<Node> Graph::nodes = {};
std::vector<Edge> Graph::edges = {};

void Graph::add_node(Node nd) {
    Graph::nodes.push_back(nd);	
}

std::vector<Node>& Graph::get_nodes() {
	return Graph::nodes;
}

void Graph::add_edge(Edge edge) {
    edges.push_back(edge);
}

std::vector<Edge>& Graph::get_edges() {
    return Graph::edges;
}

void Graph::print_graph() {
	for(auto u : Graph::nodes) {
		std::cout << "dick";
	}
}	
	
