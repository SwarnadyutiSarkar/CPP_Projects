#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

float ballRadius = 0.5f;
glm::vec3 ballPosition(0.0f, 0.0f, 0.0f);
glm::vec3 ballVelocity(0.0f, 0.0f, 0.0f);
float gravity = -9.81f;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void update(float deltaTime) {
    // Update ball position based on velocity
    ballPosition += ballVelocity * deltaTime;

    // Apply gravity to the ball
    ballVelocity.y += gravity * deltaTime;

    // Check collision with floor
    if (ballPosition.y - ballRadius < 0.0f) {
        ballPosition.y = ballRadius;
        ballVelocity.y = -ballVelocity.y;  // Bounce
    }
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up view and projection matrices
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 2.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);

    // Render ball
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, ballPosition);
    model = glm::scale(model, glm::vec3(ballRadius));
    // Set up shader and pass view, projection, and model matrices
    // Draw ball using OpenGL

    // Swap buffers and poll events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "3D Bounce Ball Game", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    float lastFrameTime = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        float currentFrameTime = glfwGetTime();
        float deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;

        update(deltaTime);
        render();
    }

    glfwTerminate();
    return 0;
}
