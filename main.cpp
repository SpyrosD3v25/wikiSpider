#include "include/graphics.h"
#include "include/pos_gen.h"
#include "include/graph.h"
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <array>

void create_graph() {
    /* 
       Example of creating a graph
       A node src at position (0,0,0)
       A node next at a position randomly generated
       Printing the graph
       Displaying the graph usign OPENGL
    */

    Graph graph;

    Node src;
    std::array<int, 3> pos = {0, 0, 0};
    src.set_pos(pos);
    graph.add_node(src);

    Node next;
    std::array<int, 3> next_pos = pos_gen::genFrom(graph, src);
    next.set_pos(next_pos);
    graph.add_node(next);
    graph.print_graph();
    Graphics::graphs.push_back(graph);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    create_graph();
    Graphics::initialize();

    glutDisplayFunc(Graphics::display);
    glutReshapeFunc(Graphics::reshape);
    glutMainLoop();  
    return 0;
}
/*
   Fix id generation and update
   Input handling should not be on the Graphics class
   Node should hold properties for its graphic representation as well
   An edge could be bidrectional
   Show the direction of edges

   implement algorithms on the graph class
   implement the algorithm representation by changing the color of nodes
   hovering the mouse over a node could give some detail about it
*/
