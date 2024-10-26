#include "graphics.h"
#include "node.h"
#include "graph.h"
#include "camera.h"
#include "screen.h"
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <vector>

/* Camera */
float Camera::posX = 0.0f;
float Camera::posY = 0.0f;
float Camera::posZ = 12.0f;
float Camera::dirX = 0.0f;
float Camera::dirY = 0.0f;
float Camera::dirZ = -1.0f;
float Camera::pitch = 0.0f;
float Camera::yaw = 0.0f;

/* Input */
bool Graphics::keyStates[256] = {false};
int Graphics::lastMousePosX = 960;
int Graphics::lastMousePosY = 540;

/* Screen */
int Screen::width = 1920;
int Screen::height = 1080;
std::string Screen::title = "wikispider";
std::vector<float> Screen::color = {0.0, 0.0, 0.0, 1.0};

void Graphics::initialize() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(Screen::width, Screen::height); 
    glutCreateWindow(Screen::title.c_str()); 

    glEnable(GL_DEPTH_TEST); 
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);
    glClearColor(
            Screen::color[0],
            Screen::color[1],
            Screen::color[2],
            Screen::color[3]);  
    glutWarpPointer(lastMousePosX, lastMousePosY);


    glutKeyboardFunc(Graphics::handleKeyPress);
    glutKeyboardUpFunc(Graphics::handleKeyRelease);
    glutPassiveMotionFunc(Graphics::mouseMotion);
    glutIdleFunc(Graphics::updateCamera);
}

void Graphics::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(Camera::pitch, 1.0f, 0.0f, 0.0f);
    glRotatef(Camera::yaw, 0.0f, 1.0f, 0.0f);

    gluLookAt(Camera::posX, Camera::posY, Camera::posZ, 
              Camera::posX + Camera::dirX, Camera::posY + Camera::dirY, Camera::posZ + Camera::dirZ, 
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
    const std::vector<Node>& nodes = Graph::get_nodes();
    for (const Node& node : nodes) {
        drawNode(node);
    }

    const std::vector<Edge>& edges = Graph::get_edges();
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
        Camera::posZ -= 0.05f;
    }
    if (keyStates['s']) {
        Camera::posZ += 0.05f;
    }
    if (keyStates['a']) {
        Camera::posX -= 0.05f;
    }
    if (keyStates['d']) {
        Camera::posX += 0.05f;
    }
    if (keyStates[' ']) {
        Camera::posY += 0.05f;
    }
    if (keyStates['x']) {
        Camera::posY -= 0.05f;
    }
    glutPostRedisplay();
}

void Graphics::mouseMotion(int x, int y) {
    int deltaX = x - lastMousePosX; 
    int deltaY = y - lastMousePosY; 

    Camera::yaw += deltaX * 0.1f; 
    Camera::pitch += deltaY * 0.1f; 

    if (Camera::pitch > 89.0f) Camera::pitch = 89.0f;
    if (Camera::pitch < -89.0f) Camera::pitch = -89.0f;

    lastMousePosX = x; 
    lastMousePosY = y;

    glutPostRedisplay(); 
}

