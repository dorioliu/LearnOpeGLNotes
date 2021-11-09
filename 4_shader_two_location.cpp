//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//#include <cmath>
//
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos, 1.0);\n"
//"   ourColor = aColor;\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"in vec3 ourColor;\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(ourColor, 1.0);\n"
//"}\n\0";
//
//
//
//int main()
//{
//    // 初始化glfw
//// ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    // 创建窗口
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    // 使得当前上下文与当前的窗口对应起来
//    glfwMakeContextCurrent(window);
//
//    // glad: 加载gl对应的函数指针地址
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // 编译和生成着色器程序
//    // ------------------------------------
//    // 顶点着色器
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    // 检查顶点着色器编译是否成功
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // 片段着色器
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//    // 检查片段着色器是否编译成功
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    // 链接着色器，生成着色器程序
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    // 检查链接错误
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    // 删除着色器
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//
//    // 设置顶点输入并配置顶点属性
//    // ------------------------------------------------------------------
//    float vertices[] = {
//        // 位置              // 颜色
//         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
//        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
//    };
//
//    // 初始化VBO和VAO
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    // 首先绑定顶点数组对象
//    // 然后绑定并设置顶点缓冲对象
//    // 最后设置顶点属性
//    glBindVertexArray(VAO);
//
//    //绑定顶点缓冲对象VBO到指定目标位置GL_ARRAY_BUFFER
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    // 设置内存数据拷贝到显存中的目标位置
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // 设置顶点链接属性
//    // 位置属性
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // 颜色属性
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // 下面这个操作是允许的，
//    // 顶点属性指针函数的调用将VBO实例对象作为顶点属性的捆绑顶点缓冲对象，
//    // 随后可以将其从目标位置解绑
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // 随后，你可以将VAO实例对象解除绑定，这样，该VAO对象实例不至于被其他VAO所更改（虽然很少发生）
//    // 修改其他VAO的时候，总是需要首先通过调用glBindVertexArray进行绑定。一般情况，并不是直接需要的时候
//    // 一般不进行VAO(s)的解绑操作。
//    glBindVertexArray(0);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        // 处理窗口glfw的输入
//        // -----
//        processInput(window);
//
//        // 进行渲染
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // 绘制三角形
//        glUseProgram(shaderProgram);
//
//        glBindVertexArray(VAO); // 看到我们只有一个 Vao的时候， 本来没有必要每次绑定它， 但我们会这样做， 以保持事情更有条理一点
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        // glBindVertexArray(0); // 没有必要每次都解绑它
//
//        // glfw: 交互双缓冲的前后缓冲，并轮询IO事件(按键鼠标等)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // 选择性操作： 释放分配的资源
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//
//    // glfw: 停止渲染并清除所有之前分配的GLFW资源
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//
//}
//
//
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
