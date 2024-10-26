#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "node.h"
#include "edge.h"

class Graph {
public:
	static std::vector<std::vector<Node>> adj_list;
    static std::vector<Node>nodes;
    static std::vector<Edge> edges;
	
	static void add_node(Node nd);
	static std::vector<Node>& get_nodes();
	
    static void add_edge(Edge edge);
    static std::vector<Edge>& get_edges();

    static void print_graph();	
};
#endif
