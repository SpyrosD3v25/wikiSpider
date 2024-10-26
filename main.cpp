#include <GL/glut.h>
#include "include/graphics.h"
#include "include/edge.h"
#include <iostream>
#include <vector>
#include "include/pos_gen.h"

void generate_new_node(Node src) {
    std::vector<int> pos = {0, 0, 0};
    src.set_pos(pos);
    
    Graph::add_node(src);

    std::vector<int> next_pos = pos_gen::genFrom(src);
    Node next;
    next.set_pos(next_pos);

    Graph::add_node(next);
   

    Edge edge;
    edge.from = src;
    edge.to = next;
    Graph::add_edge(edge);
}

void create_graph() {
    Node src;
    generate_new_node(src);    
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

