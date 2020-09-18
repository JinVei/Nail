#include "OpenglShaderScreen.h"

using namespace nail;

void OpenglShaderScreen::setScreenTexture(GLuint tex_id) {
    setUniform(_uniform_name_tex_screen, _tex_screen_loc);
    glActiveTexture(GL_TEXTURE0 + _tex_screen_loc);
    glBindTexture(GL_TEXTURE_2D, tex_id);
}

void OpenglShaderScreen::apply(GLuint tex_id) {
    setScreenTexture(tex_id);
    OpenglShader::apply();
}