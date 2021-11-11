//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#include "shader_s.h"
//#include <iostream>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//
//float deltaTime = 0.0f; // 当前帧与上一帧的时间差
//float lastFrame = 0.0f; // 上一帧的时间
//
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // build and compile our shader zprogram
//    // ------------------------------------
//    Shader ourShader("7.1.texture.vs", "7.1.texture.fs");
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    float vertices[] = {
//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//    //unsigned int indices[] = {
//    //    0, 1, 3, // first triangle
//    //    1, 2, 3  // second triangle
//    //};
//
//    glm::vec3 cubePositions[] = {
//  glm::vec3(0.0f,  0.0f,  -1.0f),
//  glm::vec3(2.0f,  5.0f, -15.0f),
//  glm::vec3(-1.5f, -2.2f, -2.5f),
//  glm::vec3(-3.8f, -2.0f, -12.3f),
//  glm::vec3(2.4f, -0.4f, -3.5f),
//  glm::vec3(-1.7f,  3.0f, -7.5f),
//  glm::vec3(1.3f, -2.0f, -2.5f),
//  glm::vec3(1.5f,  2.0f, -2.5f),
//  glm::vec3(1.5f,  0.2f, -1.5f),
//  glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//
//
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    //glGenBuffers(1, &EBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    /* glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
//
//     // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // color attribute
//   /* glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);*/
//    // texture coord attribute
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//
//    // load and create a texture 
//    // -------------------------
//    // 创建第一个纹理
//    unsigned int texture1;
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // 设置环绕方式
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // 设置滤波方式
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // 加载纹理图像
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    // 创建第二个纹理
//    unsigned int texture2;
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // 设置环绕方式
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    // 设置滤波方式
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // 加载纹理图像
//    unsigned char* data1 = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
//    if (data1)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data1);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data1);
//
//    // 将片段着色器中的纹理采样器的位置值设置在相应的纹理单元处
//    // 不要忘记在设置uniform变量之前激活着色器程序！
//    ourShader.use();
//    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0); // 手动设置
//    ourShader.setInt("texture2", 1); // 或者使用着色器类设置
//
//    glEnable(GL_DEPTH_TEST); // 使能谁都测试
//
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//      
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // 清除颜色，以及深度缓冲，深度缓冲存储在Z片段中
//
//        //激活纹理单元0， 并将纹理对象1绑定到纹理单元0上
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture1);
//        //激活纹理单元1， 并将纹理对象2绑定到纹理单元1上
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        // render container
//        ourShader.use();
//
//        /* glm::mat4 model = glm::mat4(1.0f);
//         model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//
//         int modelLoc1 = glGetUniformLocation(ourShader.ID, "model");
//         glUniformMatrix4fv(modelLoc1, 1, GL_FALSE, glm::value_ptr(model));*/
//
//         // create transformations
//        //glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//        glm::mat4 projection = glm::mat4(1.0f);
//        projection = glm::perspective(glm::radians(60.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//        // pass transformation matrices to the shader
//        ourShader.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
//        //ourShader.setMat4("view", view);
//
//
//        glBindVertexArray(VAO);
//        for (unsigned int i = 0; i < 10; i++)
//        {
//           /* float radius = 10.0f;
//            float camX = sin(glfwGetTime()) * radius;
//            float camZ = cos(glfwGetTime()) * radius;
//            glm::mat4 view = glm::mat4(1.0f);
//            view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));*/
//            glm::mat4 view = glm::mat4(1.0f);
//            view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//            
//            ourShader.setMat4("view", view);
//
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//            float angle = 20.0f * (i + 1);
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//            
//          ourShader.setMat4("model", model);
//
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//        }
//        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//       
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteBuffers(1, &EBO);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    float cameraSpeed = 2.5 * deltaTime;
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        cameraPos += cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        cameraPos -= cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}