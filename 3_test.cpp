//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//// 顶点着色器设置
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//// 片段着色器设置
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//// 片段着色器1设置
//const char* fragmentShaderSource1 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f,1.1f, 0.f, 1.0f);\n"
//"}\n\0";
//
//
//
//
//int main()
//{
//    // 初始化glfw
//   // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
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
//        // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // 编译和生成着色器程序
//   // ------------------------------------
//   // 顶点着色器
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
//    // 片段着色器1和着色器程序1初始化
//    unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
//    glCompileShader(fragmentShader1);
//    // 检查片段着色器是否编译成功
//    glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    unsigned int shaderProgram1 = glCreateProgram();
//    glAttachShader(shaderProgram1, vertexShader);
//    glAttachShader(shaderProgram1, fragmentShader1);
//    glLinkProgram(shaderProgram1);
//
//    // 检查链接错误
//    glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    // 删除着色器
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader1);
//
//    // 顶点输入
//    float vertices[] = {
//        -0.25f, -0.5f, 0.0f, // left  
//         0.25f, -0.5f, 0.0f, // right 
//         0.25f,  0.5f, 0.0f,  // top   
//         0.75f, -0.5f, 0.0f, };
//
//
//    // 缓冲对象设置
//    unsigned int VAO, VBO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//
//    glGenBuffers(1,&VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//    //设置并激活顶点属性
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//
//    unsigned int VAO1, VBO1;
//    glGenVertexArrays(1, &VAO1);
//    glBindVertexArray(VAO1);
//
//    glGenBuffers(1, &VBO1);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//    //设置并激活顶点属性
//    GLintptr vertex_texcoord_offset = 3 * sizeof(float);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)vertex_texcoord_offset);
//    glEnableVertexAttribArray(0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
//        glBindVertexArray(VAO); // 看到我们只有一个 Vao的时候， 本来没有必要每次绑定它， 但我们会这样做， 以保持事情更有条理一点
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // 三角形选择填充还是线框模式
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glBindVertexArray(0); // 没有必要每次都解绑它
//
//
//        glUseProgram(shaderProgram1);
//        glBindVertexArray(VAO1); // 看到我们只有一个 Vao的时候， 本来没有必要每次绑定它， 但我们会这样做， 以保持事情更有条理一点
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // 三角形选择填充还是线框模式
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glBindVertexArray(0); // 没有必要每次都解绑它
//
//        // glfw: 交互双缓冲的前后缓冲，并轮询IO事件(按键鼠标等)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteVertexArrays(1, &VAO1);
//    glDeleteBuffers(1, &VBO1);
//    glDeleteProgram(shaderProgram);
//
//
//    glfwTerminate();
//    return 0;
//}
//
//
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//
