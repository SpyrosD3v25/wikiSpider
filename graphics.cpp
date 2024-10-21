#include "graphics.h"
#include "node.h"
#include "graph.h"
#include <GL/glut.h>
#include <iostream>


Graph Graphics::graph;
float Graphics::camPosX = 0.0f;
float Graphics::camPosY = 0.0f;
float Graphics::camPosZ = 5.0f;  // Camera starts 5 units away from the scene

float Graphics::camDirX = 0.0f;
float Graphics::camDirY = 0.0f;
float Graphics::camDirZ = -1.0f; // Looking forward
bool Graphics::keyStates[256] = {false};
int Graphics::lastMousePosX = 960;
int Graphics::lastMousePosY = 540;
float Graphics::camYaw = 0.0f;
float Graphics::camPitch = 0.0f;

void Graphics::initialize() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080); //hardcoded values 
    glutCreateWindow("wikispider"); //hardcoded values

    glEnable(GL_DEPTH_TEST); 
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);
    glClearColor(0.0, 0.0, 0.0, 1.0);  //hardcoded values
    glutWarpPointer(lastMousePosX, lastMousePosY);

    glutKeyboardFunc(Graphics::handleKeyPress);
    glutKeyboardUpFunc(Graphics::handleKeyRelease);
    glutPassiveMotionFunc(Graphics::mouseMotion);
    glutIdleFunc(Graphics::updateCamera);
}

void Graphics::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(camPitch, 1.0f, 0.0f, 0.0f);
    glRotatef(camYaw, 0.0f, 1.0f, 0.0f);

    gluLookAt(camPosX, camPosY, camPosZ, 
              camPosX + camDirX, camPosY + camDirY, camPosZ + camDirZ, 
              0.0, 1.0, 0.0); 

    drawGraph();

    glutSwapBuffers();
}

void Graphics::reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)width / (float)height;
    gluPerspective(45.0, aspect, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graphics::drawNode(const Node& node) {
    const std::vector<int>& pos = node.get_pos();
    glPushMatrix();
    glTranslatef(pos[0], pos[1], pos[2]);
    glutSolidSphere(0.2, 100, 100); //hardcoded values here must change
    glPopMatrix();
}

void Graphics::drawEdge(Edge edge) {
    const std::vector<int>& posFrom = edge.from.get_pos();
    const std::vector<int>& posTo = edge.to.get_pos();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex3f(posFrom[0], posFrom[1], posFrom[2]);
    glVertex3f(posTo[0], posTo[1], posTo[2]);

    glEnd();
}

void Graphics::drawGraph() {
    const std::vector<Node>& nodes = Graphics::graph.get_nodes();
    for (const Node& node : nodes) {
        drawNode(node);
    }

    const std::vector<Edge>& edges = Graphics::graph.get_edges();
    for (const Edge& edge : edges) {
        drawEdge(edge);
    }
}

void Graphics::handleKeyPress(unsigned char key, int x, int y) {
    keyStates[key] = true;
}

void Graphics::handleKeyRelease(unsigned char key, int x, int y) {
    keyStates[key] = false;
}

void Graphics::updateCamera() {
    if (keyStates['w']) {
        camPosZ -= 0.05f;
    }
    if (keyStates['s']) {
        camPosZ += 0.05f;
    }
    if (keyStates['a']) {
        camPosX -= 0.05f;
    }
    if (keyStates['d']) {
        camPosX += 0.05f;
    }
    if (keyStates[' ']) {
        camPosY += 0.05f;
    }
    if (keyStates['x']) {
        camPosY -= 0.05f;
    }
    glutPostRedisplay();
}

void Graphics::mouseMotion(int x, int y) {
    int deltaX = x - lastMousePosX; 
    int deltaY = y - lastMousePosY; 

    camYaw += deltaX * 0.1f; 
    camPitch += deltaY * 0.1f; 

    if (camPitch > 89.0f) camPitch = 89.0f;
    if (camPitch < -89.0f) camPitch = -89.0f;

    lastMousePosX = x; 
    lastMousePosY = y;

    glutPostRedisplay(); 
}

