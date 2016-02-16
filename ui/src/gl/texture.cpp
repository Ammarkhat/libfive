#include "ao/ui/gl/texture.hpp"

void toDepthTexture(const DepthImage& img, GLuint tex)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4); // Floats are 4-byte aligned
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32F, img.rows(), img.cols(),
            0, GL_DEPTH_COMPONENT, GL_FLOAT, img.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void toNormalTexture(const NormalImage& img, GLuint tex)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4); // Int32s are 4-byte aligned
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.rows(), img.cols(),
            0, GL_RGBA, GL_UNSIGNED_BYTE, img.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}