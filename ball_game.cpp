#include <GLFW/glfw3.h>
#include <iostream>

void drawBall(float x, float y) {
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int i = 0; i <= 360; i++) {
        float angle = 3.14159f * i / 180.0f;
        glVertex2f(cos(angle) * 0.1f, sin(angle) * 0.1f);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ball Game", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        drawBall(xpos / 800 * 2 - 1, 1 - ypos / 600 * 2);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
