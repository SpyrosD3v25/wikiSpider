#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <array>
#include <vector>

class Node
{
	private:	
    int id;
    std::array<int, 3> pos;
    std::vector<Node> neighbors;

	public:
 	const int& get_id() const;
	void set_id(const int& _id);   

	const std::array<int, 3>& get_pos() const;
	void set_pos(const std::array<int, 3>& _pos);

    const std::vector<Node>& get_neighbors() const;
    void set_neighbors(const std::vector<Node>& _neighbors);
    void add_neighbor(const Node& nd);
    void remove_neighbor(const Node& nd);

    bool operator==(const Node& other) const { return get_id() == other.get_id(); }
};

#endif
