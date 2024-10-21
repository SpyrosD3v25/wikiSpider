#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "node.h"
#include "edge.h"

class Graph {
private:
	std::vector<std::vector<Node>> adj_list;
    std::vector<Node>nodes;
    std::vector<Edge> edges;
	
public:
	void add_node(Node nd);
	const std::vector<Node>& get_nodes() const;
	
    void add_edge(Edge edge);
    const std::vector<Edge>& get_edges() const;

    void print_graph();	
};
#endif
