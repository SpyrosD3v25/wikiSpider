#include <GL/glut.h>
#include "graphics.h"
#include "edge.h"
#include <iostream>
#include <vector>

void create_graph() {
    Node nd, nd2;
    std::vector<int> pos = {2, 0, 0};
    std::vector<int> pos2 = {4, 0, 0};
    nd.set_pos(pos);
    nd2.set_pos(pos2);
    Graphics::graph.add_node(nd);
    Graphics::graph.add_node(nd2);

   Edge edge;
   edge.from = nd;
   edge.to = nd2;

   Graphics::graph.add_edge(edge);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    create_graph();
    Graphics::initialize();



    // OpenGL main loop
    glutDisplayFunc(Graphics::display);
    glutReshapeFunc(Graphics::reshape);
    //glutKeyboardFunc(Graphics::awaitKeyboard);
    glutMainLoop();  
    return 0;
}

