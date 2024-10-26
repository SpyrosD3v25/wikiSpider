#include <vector>
#include <iostream>
#include "node.h"


const std::vector<int>& Node::get_pos() const
{
	return pos;
}

void Node::set_pos(const std::vector<int>& _pos)
{
	pos = _pos;
}

