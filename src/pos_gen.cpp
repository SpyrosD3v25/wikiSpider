#include "node.h"
#include "graph.h"
#include "pos_gen.h"
#include "graphics.h"
#include <cstdlib>  
#include <ctime>   
#include <iostream>
#include <vector>
#include <cmath>

int pos_gen::max_length = 7;
int pos_gen::max_dir = 6;

int pos_gen::getRandomLength() { return std::rand() % pos_gen::max_length + 1; }

int pos_gen::getRandomDir() { return std::rand() % pos_gen::max_dir + 1; }

std::array<int, 3> pos_gen::genFrom(Graph graph, Node src) {
    std::srand(std::time(NULL));

    int length = getRandomLength();
    int dir = getRandomDir();

    std::array<int, 3> next_pos = src.get_pos();
    float curClosestPos;

    do {
        switch (dir) {
            case 1:
                next_pos[0] -= length;
                break;
            case 2:
                next_pos[0] += length;
                break;
            case 3:
                next_pos[1] -= length;
                break;
            case 4:
                next_pos[1] += length;
                break;
            case 5:
                next_pos[2] -= length;
                break;
            case 6:
                next_pos[2] += length;
                break;
        }
        curClosestPos = getClosestPos(graph, next_pos);
    }while(curClosestPos < 1.0f);

    return next_pos;
}
//PQ = d = √ [(x2 – x1)2 + (y2 – y1)2 + (z2 – z1)2].
float d(std::array<int, 3> from, std::array<int, 3>to) {
    return sqrt( pow( abs(static_cast<double>(from[0] - to[0])  ), 2) 
               + pow( abs(static_cast<double>(from[1] - to[1])  ), 2) 
               + pow( abs(static_cast<double>(from[2] - to[2])  ), 2
           ));
}

float pos_gen::getClosestPos(Graph graph, std::array<int, 3> pos) {
    float ans = INF;

    for (auto a : graph.get_nodes()) {
        if (a.get_pos() == pos) { continue; }  
        float dist = d(a.get_pos(), pos);
        ans = std::min(ans, dist);
    } 
    //std::cout << ans;
    return ans;
}
