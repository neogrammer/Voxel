//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include "G.hpp"
//#include <iostream>
//#include <Shader.hpp>
//#define _USE_MATH_DEFINES
//#include <math.h>
//void processInput(GLFWwindow* window);
//
//double lastX{};
//double lastY{};
//double elapsed{};
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//    // Get the primary monitor
//    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
//
//    // Get the video mode for the monitor
//    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
//    double oldRight = G::WND_WIDTH;
//    double oldBottom = G::WND_HEIGHT;
//
//    double ratioX = G::WND_WIDTH / 1920.0;
//    double ratioY = G::WND_HEIGHT / 1080.0;
//
//    double newWindowSizeX = ratioX * mode->width;
//    double newWindowSizeY = ratioY * mode->height;
//
//    lastX = newWindowSizeX / 2.0;
//    lastY = newWindowSizeY / 2.0;
//
//    G::WND_WIDTH = (int)newWindowSizeX;
//    G::WND_HEIGHT = (int)newWindowSizeY;
//
//    double newRight = G::WND_WIDTH;
//    double newBottom = G::WND_HEIGHT;
//
//
//    GLFWwindow* window = glfwCreateWindow((int)newWindowSizeX, (int)newWindowSizeY, "Voxel", NULL, NULL);
//
//    if (window == NULL)
//    {
//        std::cout << "Unable to create the GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    gladLoadGL();
//    glfwSwapInterval(1);
//
//    glViewport(0, 0, G::WND_WIDTH, G::WND_HEIGHT);
//
//    glfwSetWindowPos(window, int((mode->width / 2.0) - (G::WND_WIDTH / 2.0)), int((mode->height / 2.0) - (G::WND_HEIGHT / 2.0)));
//
//    // create the shader for the cube object
//    Shader shaderP{ "assets/shaders/cubeStd/cubeStd.vert","assets/shaders/cubeStd/cubeStd.frag" };
//   
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    float vertices[] = {
//         0.5f,  0.5f, 0.5f, 1.f, 0.f, 0.f, 1.f, // top right
//         0.5f, -0.5f, 0.5f, 1.f, 1.f, 0.f, 1.f,  // bottom right
//        -0.5f, -0.5f, 0.5f, 1.f, 0.f, 1.f, 1.f, // bottom left
//        -0.5f,  0.5f, 0.5f, 0.f, 1.f, 0.f, 1.f,   // top left 
//         0.5f,  0.5f, -.5f, 0.f, 1.f, 1.f, 1.f,  // top right back
//         0.5f, -0.5f, -.5f, 0.f, 0.f, 1.f, 1.f,  // bottom right back
//        -0.5f, -0.5f, -.5f, 1.f, 1.f, 1.f, 1.f,  // bottom left back
//        -0.5f,  0.5f, -.5f, 0.f, 0.f, 0.f, 1.f  // top left back
//    };
//    unsigned int indices[] = {  // note that we start from 0!
//        0, 1, 3,  // first Triangle
//        1, 2, 3,   // second Triangle
//
//        4, 5, 0,  // first Triangle
//        5, 1, 0,   // second Triangle
//
//        7, 6, 4,  // first Triangle
//        6, 5, 4,   // second Triangle
//
//        3, 2, 7,  // first Triangle
//        2, 6, 7,   // second Triangle
//
//        4, 0, 7,  // first Triangle
//        0, 3, 7,   // second Triangle
//
//        1, 5, 2,  // first Triangle
//        5, 6, 2   // second Triangle
//    };
//
//
//
//    // load data into the GPU
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//
//    shaderP.use();
//
//    float angle = 0.f;
//
//    GLfloat matrix[16] = { 0, };
//    matrix[0] = 1.0f; matrix[1] = 0.f; matrix[2] = 0.f; matrix[3] = 0.f;
//    matrix[4] = 0.0f; matrix[5] = 1.f; matrix[6] = 0.f; matrix[7] = 0.f;
//    matrix[8] = 0.0f; matrix[9] = 0.f; matrix[10] = 1.f; matrix[11] = 0.f;
//    matrix[12] = 0.0f; matrix[13] = 0.f; matrix[14] = 0.f; matrix[15] = 1.f;
//
//    GLint location;
//
//    location = glGetUniformLocation(shaderP.ID, "matrix");
//    glUniformMatrix4fv(location, 1, GL_FALSE, matrix);
//
//
//    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
//    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//    glBindVertexArray(0);
//    glEnable(GL_DEPTH_TEST);
//
//    // uncomment this call to draw in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    float startAngle = 0.f;
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        processInput(window);
//
//        angle = ((float)((int)(glfwGetTime() * 100.0) % 360) * ((float)M_PI / 180.f));
//        matrix[5] = cos(angle); matrix[6] = -sin(angle);
//        matrix[9] = sin(angle); matrix[10] = cos(angle);;
//
//        // render
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // draw our first triangle
//        // use the shader and bind the correct VAO then draw by using indices
//        shaderP.use();
//        glUniformMatrix4fv(location, 1, GL_FALSE, matrix);
//        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//        //glDrawArrays(GL_TRIANGLES, 0, 6);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//        // glBindVertexArray(0); // no need to unbind it every time 
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
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
//    shaderP.destroy();
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
//}

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <Shader.hpp>
#include <Camera.hpp>
#include <Model.hpp>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        std::cout << "shit!" << std::endl;
    }
    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

   

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

     //tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


   
    // glad: load all OpenGL function pointers
    // ---------------------------------------
   

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------
    Shader ourShader("assets/shaders/stdShader/stdShader.vert" + '\0', "assets/shaders/stdShader/stdShader.frag" + '\0');

    // load models
    // -----------
    Model ourModel("assets/models/backpack/backpack.obj");


    // draw in wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.6f, 0.95f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // don't forget to enable shader before setting uniforms
        ourShader.use();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}