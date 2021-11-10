//// �ο��� LearnOpenGL
//// https ://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/
//
//// ���ͼ����Ⱦ�����ǽ���3D���濪���Ļ���
//// OpenGLͼ����Ⱦ���ߣ�һ����Է�Ϊ�������֣�
//// ��һ����3D����תΪ2D����
//// �ڶ�����2D����תΪʵ������ɫ������(2D������2D������
//// ����ʵ����Ļ�ʹ��ڷֱ��ʵĽ���ֵ)
//
//// һ��ͼ����Ⱦ���ߣ�
//// 13D����������Ϊ�������Ƚ�����Ⱦ����
//// 2���붥����ɫ������3D����ת��Ϊ��һ����ʽ��3D����
//// 3�ٽ���ͼԪװ���У� ����ָ��ͼԪ����״
//// 4���뼸����ɫ����������������Ե���ͼԪ
//// 5�����դ���׶Σ�����ͼԪӳ��Ϊ������Ļ�ϵ����أ�֮������Ƭ�Σ������вü���ȥ��������Ⱦ��Χ�ڵ�Ƭ��
//// Note: OpenGL�е�һ��Ƭ����OpenGL��Ⱦһ�������������������
//// 6����Ƭ����ɫ��������Ƭ�ν�һ�����㣬�õ�ÿ���������յ���ɫ
//// 7Alpha���Ժͻ�ϣ� �õ�ÿ��Ƭ�����յ���ɫ�󣬻�Ҫ������ЩƬ�ζ�Ӧ����ȣ��Ӷ���������ص����⣬
//// �����Ƕ����أ����Ƕ�Ƭ�ν��л�ϣ�alphaֵ������һ�������͸����
//
//// ���Կ�����ͼ����Ⱦ���߷ǳ����ӣ��������ܶ�����õĲ��֡�Ȼ�������ڴ�������ϣ�
//// ����ֻ��Ҫ���ö����Ƭ����ɫ�������ˡ�������ɫ���ǿ�ѡ�ģ�ͨ��ʹ����Ĭ�ϵ���ɫ�������ˡ�
//
//// �������룺
//// ��gl��һ��3Dͼ�ο⣬����ָ�����������궼��3D����
//// ��gl����xyz�ϵ���ֵ��-1��1���ܴ�������׼���豸���꣬������Χ�����꽫�ᱻ�������߲ü�
//// �۶�����ɫ������ʹ�����3D���괦����ܱ�gl����ı�׼���豸����
//// �ܱ�׼���豸������Ż�任Ϊ��Ļ�ռ����꣬��һ����ͨ���ӿڱ任��ɵģ�����glViewport��
//// ��������Ļ�ռ����꽫�ᱻ�任��Ƭ�����뵽Ƭ����ɫ����
////
////
//
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//// ���ڱ仯�ͼ��������¼���Ӧ�Ļص���������
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// ���ں��ӿڴ�С����
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
//
//int main()
//{
//
//    // ��ʼ��glfw
//    // ------------------------------
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
//    // ���ô��ڳߴ�ı�Ļص����������Ե����ӿڴ�С
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
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
//        -0.5f, -0.5f, 0.0f, // left  
//         0.5f, -0.5f, 0.0f, // right 
//         0.0f,  0.5f, 0.0f  // top   
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
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//
//    // ���������
//    glEnableVertexAttribArray(0);
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
//
//// ���������ⲿ����: ��ѯ GLFW �Ƿ��а����¼�����
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: �Ƿ񴰿ڴ�С�����ı� (��Ϊ����ϵͳ�������û��Ĳ�����ɵ�) 
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // ����ĳ���ʹ�ô��ڴ�С�ı���ӿڴ�СҲ��֮�����仯
//    // ��Ҫָ�����ǣ��ӿڴ�СҪ�ȶ�Ӧ����Ĥ��Ļ���ڴ�ܶ࣬�����Ҫ�˽�һ������Ĥ��Ļ��ԭ��
//    glViewport(0, 0, width, height);
//}
