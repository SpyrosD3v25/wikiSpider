#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "graph.h"
#include "node.h"
#include "edge.h"
#include "camera.h"

class Graphics {
public:
    static void initialize();
    static void display();
    static void reshape(int width, int height); 
    static void drawNode(const Node& node);
    static void drawEdge(Edge edge);
    static void drawGraph();
    static void handleKeyPress(unsigned char key, int x, int y);
    static void handleKeyRelease(unsigned char key, int x, int y);
    static void updateCamera();
    static void mouseMotion(int x, int y);

    static bool keyStates[256];
    static int lastMousePosX, lastMousePosY;
};

#endif

