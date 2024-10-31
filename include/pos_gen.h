#ifndef POS_GEN_H
#define POS_GEN_H

#include "node.h"
#include "graph.h"
#include <vector>
#include <array>

const int INF = 0x3f3f3f3f;

class pos_gen {
public:
    static std::array<int, 3> genFrom(Graph graph, Node nd);
    static float getClosestPos(Graph graph, std::array<int, 3> pos);
    static int max_length;
    static int max_dir;
    static int getRandomLength();
    static int getRandomDir();
};

#endif 
