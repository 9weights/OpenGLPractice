#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
class Shader
{
public:
    unsigned int programID{};
    Shader(const char* vertexPath, const char* fragmentPath)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try 
        {
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();		
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode   = vShaderStream.str();
            fragmentCode = fShaderStream.str();		
        }
        catch(std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        // 2. Compile the source code
        unsigned int vertexShaderID{};
        vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShaderID, 1, &vShaderCode, NULL);
        glCompileShader(vertexShaderID);
        checkCompileStatus(vertexShaderID, "vertex");
        unsigned int fragmentShaderID{};
        glCreateShader(fragmentShaderID);
        glShaderSource(fragmentShaderID, 1, &vShaderCode, NULL);
        glCompileShader(fragmentShaderID);
        checkCompileStatus(fragmentShaderID, "fragment");

        // 3. Link objects
        programID = glCreateProgram();
        glAttachShader(programID, vertexShaderID);
        glAttachShader(programID, fragmentShaderID);
        glLinkProgram(programID);
        checkLinkStatus(programID, "program");
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
    }

    void checkCompileStatus(unsigned int sourceID, const std::string type)
    {
        int success{};
        char infoLog[512];
        glGetShaderiv(sourceID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(sourceID, 512, NULL, infoLog);
            std::cout << type << " compilation failed \n" << infoLog << "\n";
        }
    }
    void checkLinkStatus(unsigned int programID, const std::string type)
    {
        int success{};
        char infoLog[512];
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(programID, 512, NULL, infoLog);
            std::cout << type << " linking failed \n" << infoLog << "\n";
        }
    }
    void uniformstuff()
    {

    }



};
