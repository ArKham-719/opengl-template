#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

#include"headerfiles/shaderClass.h"
#include"headerfiles/VBO.h"
#include"headerfiles/EBO.h"
#include"headerfiles/VAO.h"



#define H 800
#define W 800


int main() {
    //glfw initialize
    if(!glfwInit())
    {
        std::cout << "opengl glfw fail to initialize\n";
        glfwTerminate();
        return -1;        
    }
    //tell the glfw to which opengl verion we are using
    //in this case we are using 3 the major verion and 3 the minor verion opengl 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

    //which profile we are using compaitable or core  we are using core
    // which mean we are using only modren feature 
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


    
    GLfloat vertices[] =
    {
        /* -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,//lower left conner
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,//lower right connor
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,//upper connor
        -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
        0.5f / 2,  0.5f * float(sqrt(3)) / 6 , 0.0f,//Inner right
        0.0f , -0.5 * float(sqrt(3)) / 3 , 0.0f // Inner down */

        -0.5f,-0.5f,0.0, //lower left coonor
        -0.5f,0.5f,0.0, //lower right connor
        0.5f,0.5f,0.0, //upper right
        0.5f,-0.5f,0.0 // upper left
        
    };

    GLuint indicies[] =
    {
        /* 0,3,5, // lower right triangle
        3,2,4, // lower left triangle
        5,4,1 // upper triangle*/
        0,1,2, //upper left triangle
        2,3,0 //lower right triangle
    };
    //create window with 800 width and 800 heaght with title and null fullscren
    GLFWwindow* window = glfwCreateWindow(W,H,"first window",NULL,NULL);
    if(window == NULL )//Error check if it created or not if not then terminate 
    {
        std::cout << "WIndow failed to create\n";
        glfwTerminate();
        return -1;
    }

    //introduce the window into current context
    glfwMakeContextCurrent(window);

    //load glad so it can configure the basic configurations
    gladLoadGL();

    //specifiy the viewport of opengl in the window
    //in this case the viewport  goes from  x = 0 , y = 0 to x = 800 , y = 800
    glViewport(0,0,W,H);

    Shader shaderProgram("Shaders/default.vert","Shaders/default.frag");
    
    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indicies, sizeof(indicies));
    
    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    //EBO1.Unbind();
    
  
    
    //cleer bg color to this  r g b a 
    glClearColor(.07f,.13f,.17f,.1f);

    //clean the back buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //swap the back buffer with front buffer
    glfwSwapBuffers(window);

    //main loop
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(.07f,.13f,.17f,.1f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        //bind the VAO so opengl know how to use it
        VAO1.Bind();
        //Draw the triangle using gl_triangle as primitive
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);
        //event poll
        glfwPollEvents();
    }



    //delete all the Objects 
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();  
    
    //Destroy the window
    glfwDestroyWindow(window);
    //Terminate the glfw
    glfwTerminate();
    return 0;

}
