//// 参考： LearnOpenGL
//// https ://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/
//
//// 理解图像渲染管线是进行3D界面开发的基础
//// OpenGL图像渲染管线，一般可以分为两个部分：
//// 第一：把3D坐标转为2D坐标
//// 第二：把2D坐标转为实际有颜色的像素(2D像素是2D坐标在
//// 考虑实际屏幕和窗口分辨率的近似值)
//
//// 一个图像渲染管线：
//// 13D顶点数据作为输入首先进入渲染管线
//// 2进入顶点着色器：将3D顶点转换为另一个形式的3D顶点
//// 3再进入图元装配中： 产生指定图元的形状
//// 4进入几何着色器：构造具有新特性的新图元
//// 5进入光栅化阶段：将新图元映射为最终屏幕上的像素，之后生成片段，并进行裁剪，去除不再渲染范围内的片段
//// Note: OpenGL中的一个片段是OpenGL渲染一个像素所需的所有数据
//// 6进入片段着色器：基于片段进一步计算，得到每个像素最终的颜色
//// 7Alpha测试和混合： 得到每个片段最终的颜色后，还要考虑这些片段对应的深度，从而考虑深度重叠问题，
//// 到底是丢弃呢，还是对片段进行混合，alpha值定义了一个物体的透明度
//
//// 可以看到，图形渲染管线非常复杂，它包含很多可配置的部分。然而，对于大多数场合，
//// 我们只需要配置顶点和片段着色器就行了。几何着色器是可选的，通常使用它默认的着色器就行了。
//
//// 顶点输入：
//// ①gl是一个3D图形库，其中指定的所有坐标都是3D坐标
//// ②gl仅当xyz上的数值在-1到1才能处理，即标准化设备坐标，其他范围的坐标将会被丢弃或者裁剪
//// ③顶点着色器将会使输入的3D坐标处理成能被gl处理的标准化设备坐标
//// ④标准化设备坐标接着会变换为屏幕空间坐标，这一步是通过视口变换完成的（基于glViewport）
//// ⑤所得屏幕空间坐标将会被变换成片段输入到片段着色器中
////
////
//
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//// 窗口变化和键盘输入事件对应的回调函数声明
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// 窗口和视口大小设置
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
//
//int main()
//{
//
//    // 初始化glfw
//    // ------------------------------
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
//    // 设置窗口尺寸改变的回调函数，用以调整视口大小
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
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
//        -0.5f, -0.5f, 0.0f, // left  
//         0.5f, -0.5f, 0.0f, // right 
//         0.0f,  0.5f, 0.0f  // top   
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
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//
//    // 激活顶点属性
//    glEnableVertexAttribArray(0);
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
//
//// 处理所有外部输入: 查询 GLFW 是否有按键事件发生
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: 是否窗口大小发生改变 (因为操作系统或者是用户的操作造成的) 
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // 下面的程序，使得窗口大小改变后，视口大小也随之发生变化
//    // 需要指出的是，视口大小要比对应视网膜屏幕窗口大很多，这个需要了解一下视网膜屏幕的原理
//    glViewport(0, 0, width, height);
//}
