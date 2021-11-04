
// 代码来自learnOpenGL实例代码
// https://learnopengl-cn.github.io/01%20Getting%20started/03%20Hello%20Window/
// 头文件添加glad和glfw
// 库文件链接了glfw3.lib和opengl32.lib
// 需要将glfw3.dll加入exe所在文件夹下，或者放入环境变量中
// 如果提示link error，glad_glViewport 等无法解析，请将glad.c加入项目源文件中
//

// glad的头文件一定要在glfw之前被包含
// glfw提供渲染的上下文，提供窗口，处理用户输入
// glad 提供渲染函数的各函数指针地址，可以产看glad.h查看，很多都是宏定义
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main(int* argc, int** argv)
{
    // 初始化glfw和opengl核心架构模式
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //创建openGL窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 使得当前上下文与当前的窗口绑定
    glfwMakeContextCurrent(window);

    // 再调用任何opengl函数之前，应该先初始化glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //设置视口大小
    glViewport(0, 0, 800, 600);

    // 窗口尺寸改变时，改变视口大小的回调函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        // 处理输入
        processInput(window);

        // 渲染
       // ------
        // 状态设置函数
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // 状态使用函数
        glClear(GL_COLOR_BUFFER_BIT);

        // 交换颜色缓冲，使用双缓冲模式，
        // 前缓冲保存最终输出的图像
        // 后缓冲使用渲染指令进行绘制
        // 双缓冲模式使得窗口的前后缓冲得以快速交换，
        // 相比与单缓冲，需要一遍绘制，一遍刷新输出，出现闪烁等问题的概率更小，真实感更强
        glfwSwapBuffers(window);

        // 函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、
        //更新窗口状态，并调用对应的回调函数
        glfwPollEvents();
    }

    // 释放/删除之前的分配的所有资源
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

