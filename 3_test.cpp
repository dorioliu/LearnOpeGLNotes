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
//// ������ɫ������
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//// Ƭ����ɫ������
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//// Ƭ����ɫ��1����
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
//    // ��ʼ��glfw
//   // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//    // ��������
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    // ʹ�õ�ǰ�������뵱ǰ�Ĵ��ڶ�Ӧ����
//    glfwMakeContextCurrent(window);
//
//    // glad: ����gl��Ӧ�ĺ���ָ���ַ
//        // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // �����������ɫ������
//   // ------------------------------------
//   // ������ɫ��
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    // ��鶥����ɫ�������Ƿ�ɹ�
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // Ƭ����ɫ��
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//    // ���Ƭ����ɫ���Ƿ����ɹ�
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    // ������ɫ����������ɫ������
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    // ������Ӵ���
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    // ɾ����ɫ��
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    // Ƭ����ɫ��1����ɫ������1��ʼ��
//    unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
//    glCompileShader(fragmentShader1);
//    // ���Ƭ����ɫ���Ƿ����ɹ�
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
//    // ������Ӵ���
//    glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    // ɾ����ɫ��
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader1);
//
//    // ��������
//    float vertices[] = {
//        -0.25f, -0.5f, 0.0f, // left  
//         0.25f, -0.5f, 0.0f, // right 
//         0.25f,  0.5f, 0.0f,  // top   
//         0.75f, -0.5f, 0.0f, };
//
//
//    // �����������
//    unsigned int VAO, VBO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//
//    glGenBuffers(1,&VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//    //���ò����������
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
//    //���ò����������
//    GLintptr vertex_texcoord_offset = 3 * sizeof(float);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)vertex_texcoord_offset);
//    glEnableVertexAttribArray(0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        // ������glfw������
//        // -----
//        processInput(window);
//
//        // ������Ⱦ
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // ����������
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO); // ��������ֻ��һ�� Vao��ʱ�� ����û�б�Ҫÿ�ΰ����� �����ǻ��������� �Ա��������������һ��
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // ������ѡ����仹���߿�ģʽ
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glBindVertexArray(0); // û�б�Ҫÿ�ζ������
//
//
//        glUseProgram(shaderProgram1);
//        glBindVertexArray(VAO1); // ��������ֻ��һ�� Vao��ʱ�� ����û�б�Ҫÿ�ΰ����� �����ǻ��������� �Ա��������������һ��
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // ������ѡ����仹���߿�ģʽ
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glBindVertexArray(0); // û�б�Ҫÿ�ζ������
//
//        // glfw: ����˫�����ǰ�󻺳壬����ѯIO�¼�(��������)
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
