#pragma once
#include "../CommonHeader.h"

class VertexArray
{
    public:

        VertexArray();
        ~VertexArray();

        void setVertexData(const std::vector<float>& vertices, int stride);
        void setIndexData(const std::vector<unsigned int>& indices);

        void draw();

        private:
        GLuint VAO, VBO, EBO;
        bool hasEBO = false;
        GLsizei indexCount = 0;
        GLsizei vertexCount = 0;

};
