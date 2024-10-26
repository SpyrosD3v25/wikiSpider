#ifndef POS_GEN_H
#define POS_GEN_H

#include "node.h"
#include <vector>

const int INF = 0x3f3f3f3f;

class pos_gen {
public:
    static std::vector<int> genFrom(Node nd);
    static float getClosestPos(std::vector<int> pos);
    static int max_length;
    static int max_dir;
    static int getRandomLength();
    static int getRandomDir();
};

#endif 
