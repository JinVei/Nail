#include "OpenglFrameBuffer.h"
#include "common/assert.h"

using namespace nail;


OpenglFrameBuffer::OpenglFrameBuffer(float width, float height) {
    glGenFramebuffers(1, &_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, _fbo);

    glGenRenderbuffers(1, &_rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, _rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);

    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _rbo);

    NAIL_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);

    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

OpenglFrameBuffer::~OpenglFrameBuffer() {
    glDeleteFramebuffers(1, &_fbo);
    glDeleteRenderbuffers(1,&_rbo);
}

void OpenglFrameBuffer::apply() {
    glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
}

void OpenglFrameBuffer::unapply() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}