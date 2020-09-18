#include "OpenglFrameBuffer.h"
#include "common/assert.h"

using namespace nail;


OpenglFrameBuffer::OpenglFrameBuffer(float width, float height) {
    glGenFramebuffers(1, &_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, _fbo);

    glGenTextures(1, &_tbo);
    glBindTexture(GL_TEXTURE_2D, _tbo);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _tbo, 0); 
    glBindTexture(GL_TEXTURE_2D, 0);

    glGenRenderbuffers(1, &_rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, _rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    NAIL_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

OpenglFrameBuffer::~OpenglFrameBuffer() {
    glDeleteFramebuffers(1, &_fbo);
    glDeleteRenderbuffers(1,&_rbo);
    glDeleteRenderbuffers(1,&_tbo);
}

void OpenglFrameBuffer::apply() {
    glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
}

void OpenglFrameBuffer::unapply() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

GLuint OpenglFrameBuffer::getTbo() {
    return _tbo;
}