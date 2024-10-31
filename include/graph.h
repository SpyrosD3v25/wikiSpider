#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "node.h"

class Graph {
public:
    std::vector<Node>nodes;
	
	void add_node(Node nd);
	std::vector<Node>& get_nodes();
	
    void add_edge(Node& from, Node& to);
    std::vector<Node>& get_edges();

    void print_graph();	
};
#endif
