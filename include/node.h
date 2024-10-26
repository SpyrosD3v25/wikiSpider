#ifndef NODE_H
#define NODE_H
#include <vector>

class Node
{
	private:	
	std::vector<int>pos;

	public:
	const std::vector<int>& get_pos() const;
	void set_pos(const std::vector<int>& _pos);
};

#endif
