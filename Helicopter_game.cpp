#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

struct Helicopter {
    float x, y;
    float dx, dy;
    float rotation;

    Helicopter() : x(0.0f), y(0.0f), dx(0.0f), dy(0.0f), rotation(0.0f) {}

    void update(float dt) {
        x += dx * dt;
        y += dy * dt;
    }

    void draw() {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);

        // Helicopter body
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.1f, -0.05f);
        glVertex2f(0.1f, -0.05f);
        glVertex2f(0.1f, 0.05f);
        glVertex2f(-0.1f, 0.05f);
        glEnd();

        // Helicopter rotor
        glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.05f);
        glVertex2f(0.2f, 0.05f);
        glEnd();

        glPopMatrix();
    }
};

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Helicopter Game", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    Helicopter helicopter;
    float gravity = -0.001f;

    while (!glfwWindowShouldClose(window)) {
        float dt = 0.016f; // Fixed time step for simplicity
        float acceleration = 0.001f;

        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            helicopter.dy += acceleration;
        } else {
            helicopter.dy += gravity;
        }

        helicopter.update(dt);

        glClear(GL_COLOR_BUFFER_BIT);

        helicopter.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
