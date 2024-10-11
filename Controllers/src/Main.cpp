#include <GLFW/glfw3.h>
#include <GL/gl.h>

int main() {
    // Ініціалізація GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Створення вікна
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL 2D на Linux", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Зробити контекст вікна поточним
    glfwMakeContextCurrent(window);

    // Головний цикл
    while (!glfwWindowShouldClose(window)) {
        // Очищення екрану
        glClear(GL_COLOR_BUFFER_BIT);

        // Малювання простого трикутника
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(0.5f, -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.0f, 0.5f);
        glEnd();

        // Обмін буферів
        glfwSwapBuffers(window);

        // Обробка подій
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
