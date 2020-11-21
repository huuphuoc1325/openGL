#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define HEIGH 728
#define WIDTH 1024

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGH, "game", nullptr, nullptr);
    if(window == nullptr){
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glViewport(0, 0, WIDTH, HEIGH);

    //vertex datahttps://github.com/huuphuoc1325/openGL.git
    GLfloat verticies[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    // Game Loop
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
    if(key == GLFW_KEY_ESCAPE){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}