#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

float ballX = 0.0f, ballY = 0.0f; // Ball position
float ballSpeed = 0.01f; // Ball speed

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) ballX -= ballSpeed;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) ballX += ballSpeed;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) ballY += ballSpeed;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) ballY -= ballSpeed;
}

void drawBall() {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(100); // 2*Pi
        float x = 0.05f * cosf(theta);
        float y = 0.05f * sinf(theta);
        glVertex2f(ballX + x, ballY + y);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow *window = glfwCreateWindow(800, 600, "Ball Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);
        drawBall();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
