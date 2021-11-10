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
//    // ��ʼ��glfw
//// ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // �����������ɫ������
//    // ------------------------------------
//    // ������ɫ��
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
//
//    // ���ö������벢���ö�������
//    // ------------------------------------------------------------------
//    float vertices[] = {
//        // λ��              // ��ɫ
//         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
//        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����
//    };
//
//    // ��ʼ��VBO��VAO
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    // ���Ȱ󶨶����������
//    // Ȼ��󶨲����ö��㻺�����
//    // ������ö�������
//    glBindVertexArray(VAO);
//
//    //�󶨶��㻺�����VBO��ָ��Ŀ��λ��GL_ARRAY_BUFFER
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    // �����ڴ����ݿ������Դ��е�Ŀ��λ��
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // ���ö�����������
//    // λ������
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // ��ɫ����
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // �����������������ģ�
//    // ��������ָ�뺯���ĵ��ý�VBOʵ��������Ϊ�������Ե����󶥵㻺�����
//    // �����Խ����Ŀ��λ�ý��
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // �������Խ�VAOʵ���������󶨣���������VAO����ʵ�������ڱ�����VAO�����ģ���Ȼ���ٷ�����
//    // �޸�����VAO��ʱ��������Ҫ����ͨ������glBindVertexArray���а󶨡�һ�������������ֱ����Ҫ��ʱ��
//    // һ�㲻����VAO(s)�Ľ�������
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
//
//        glBindVertexArray(VAO); // ��������ֻ��һ�� Vao��ʱ�� ����û�б�Ҫÿ�ΰ����� �����ǻ��������� �Ա��������������һ��
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        // glBindVertexArray(0); // û�б�Ҫÿ�ζ������
//
//        // glfw: ����˫�����ǰ�󻺳壬����ѯIO�¼�(��������)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // ѡ���Բ����� �ͷŷ������Դ
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//
//    // glfw: ֹͣ��Ⱦ���������֮ǰ�����GLFW��Դ
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
