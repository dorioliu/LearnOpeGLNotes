
// ��������learnOpenGLʵ������
// https://learnopengl-cn.github.io/01%20Getting%20started/03%20Hello%20Window/
// ͷ�ļ����glad��glfw
// ���ļ�������glfw3.lib��opengl32.lib
// ��Ҫ��glfw3.dll����exe�����ļ����£����߷��뻷��������
// �����ʾlink error��glad_glViewport ���޷��������뽫glad.c������ĿԴ�ļ���
//

// glad��ͷ�ļ�һ��Ҫ��glfw֮ǰ������
// glfw�ṩ��Ⱦ�������ģ��ṩ���ڣ������û�����
// glad �ṩ��Ⱦ�����ĸ�����ָ���ַ�����Բ���glad.h�鿴���ܶ඼�Ǻ궨��
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main(int* argc, int** argv)
{
    // ��ʼ��glfw��opengl���ļܹ�ģʽ
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //����openGL����
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // ʹ�õ�ǰ�������뵱ǰ�Ĵ��ڰ�
    glfwMakeContextCurrent(window);

    // �ٵ����κ�opengl����֮ǰ��Ӧ���ȳ�ʼ��glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //�����ӿڴ�С
    glViewport(0, 0, 800, 600);

    // ���ڳߴ�ı�ʱ���ı��ӿڴ�С�Ļص�����
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        // ��������
        processInput(window);

        // ��Ⱦ
       // ------
        // ״̬���ú���
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // ״̬ʹ�ú���
        glClear(GL_COLOR_BUFFER_BIT);

        // ������ɫ���壬ʹ��˫����ģʽ��
        // ǰ���屣�����������ͼ��
        // �󻺳�ʹ����Ⱦָ����л���
        // ˫����ģʽʹ�ô��ڵ�ǰ�󻺳���Կ��ٽ�����
        // ����뵥���壬��Ҫһ����ƣ�һ��ˢ�������������˸������ĸ��ʸ�С����ʵ�и�ǿ
        glfwSwapBuffers(window);

        // ���������û�д���ʲô�¼�������������롢����ƶ��ȣ���
        //���´���״̬�������ö�Ӧ�Ļص�����
        glfwPollEvents();
    }

    // �ͷ�/ɾ��֮ǰ�ķ����������Դ
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

