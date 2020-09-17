#include "OpenglShaderPhongLight.h"
#include "scene/DirectionalLight.h"
#include "common/assert.h"
#include "OpenglTexture2D.h"

using namespace nail;

void OpenglShaderPhongLight::addSceneLight(ref<Light> light) {
    NAIL_ASSERT(light != nullptr);

    _scene_lights.push_back(light);
    updateLight();
}

void OpenglShaderPhongLight::setSceneLights(std::list<ref<Light>> lights) {
    _scene_lights = lights;
    updateLight();
}

void OpenglShaderPhongLight::delSceneLight(GUID light_guid) {
    for(auto it=_scene_lights.begin(); it != _scene_lights.end(); ) {
        if ((*it)->getGUID() == light_guid) {
            it = _scene_lights.erase(it);
        } else {
            it++;
        }
    }
    updateLight();
}

void OpenglShaderPhongLight::updateLight() {
    int i=0;
    auto light_it = _scene_lights.begin();
    for (i=0; i<_max_light_num && light_it != _scene_lights.end(); i++, light_it++){
        switch((*light_it)->getLightType()) {
        case LightType::DIRECTIONAL_LIGHT:{
            auto dir_light = std::dynamic_pointer_cast<DirectionalLight>(*light_it);
            setShaderLight(i, dir_light);
            continue;
        }
        case LightType::POINT_LIGHT:{
            auto point_light = std::dynamic_pointer_cast<PointLight>(*light_it);
            setShaderLight(i, point_light);
            continue;
        }
        case LightType::SPOT_LIGHT:{
            auto spot_light = std::dynamic_pointer_cast<SpotLight>(*light_it);
            setShaderLight(i, spot_light);
            continue;
        }
        default:
            NAIL_ASSERT(false && "Unknow light type");
        }
    }

    setUniform(_uniform_name_int_lightArraylen, i);
}

void OpenglShaderPhongLight::setup(ref<Pass> pass, mat4 model_matrix,
                                    mat4 view_matrix, mat4 projection_matrix, vec3 view_pos) {

    setUniform(_uniform_name_mat4_model, model_matrix);
    setUniform(_uniform_name_mat4_view, view_matrix);
    setUniform(_uniform_name_mat4_projection, projection_matrix);
    setUniform(_uniform_name_vec3_view_pos, view_pos);

    auto tex_diffuse = std::dynamic_pointer_cast<OpenglTexture2D>(pass->getTextureDiffuse());
    NAIL_ASSERT(tex_diffuse != nullptr);
    setUniform(_uniform_name_material_tex_diffuse, _tex_diffuse_loc);
    tex_diffuse->attachToLocaction(_tex_diffuse_loc);

    auto tex_specular = std::dynamic_pointer_cast<OpenglTexture2D>(pass->getTextureSpecular());
    if(tex_specular != nullptr) {
        setUniform(_uniform_name_material_tex_specular, _tex_specular_loc);
        tex_specular->attachToLocaction(_tex_specular_loc);
        setUniform(_uniform_name_b_hasSpecularTex, true);
    } else {
        setUniform(_uniform_name_b_hasSpecularTex, false);
    }

    setUniform(_uniform_name_material_light_diffuse, pass->getLightDiffuse());
    setUniform(_uniform_name_material_light_specular, pass->getLightSpecular());
    setUniform(_uniform_name_material_light_ambient, pass->getLightAmbient());
    setUniform(_uniform_name_material_shininess, pass->getShininess());
};

void OpenglShaderPhongLight::setShaderLightType(int idx, int light_type) {
    String uniform_lightType;
    size_t str_ize = _uniform_name_lights_int_lightType.size() + 10;

    uniform_lightType.resize(str_ize);
    snprintf(&uniform_lightType[0],
            str_ize, 
            _uniform_name_lights_int_lightType.data(),
            idx);
    setUniform(uniform_lightType, light_type);
}

void OpenglShaderPhongLight::setShaderLightDirection(int idx, vec3 light_dir) {
    String uniform_lightDir;
    size_t str_ize = _uniform_name_lights_vec3_direction.size() + 10;
    uniform_lightDir.resize(str_ize);

    snprintf(&uniform_lightDir[0],
            str_ize, 
            _uniform_name_lights_vec3_direction.data(),
            idx);

    setUniform(uniform_lightDir, light_dir);
}

void OpenglShaderPhongLight::setShaderLightPosition(int idx, vec3 pos) {
    String uniform_lightPos;
    size_t str_ize = _uniform_name_lights_vec3_position.size() + 10;
    uniform_lightPos.resize(str_ize);

    snprintf(&uniform_lightPos[0],
            str_ize, 
            _uniform_name_lights_vec3_position.data(),
            idx);

    setUniform(uniform_lightPos, pos);
}

void OpenglShaderPhongLight::setShaderLightConstant(int idx, float constant) {
    String uniform_light_constant;
    size_t str_ize = _uniform_name_lights_f_constant.size() + 10;
    uniform_light_constant.resize(str_ize);

    snprintf(&uniform_light_constant[0],
            str_ize, 
            _uniform_name_lights_f_constant.data(),
            idx);

    setUniform(uniform_light_constant, constant);
}

void OpenglShaderPhongLight::setShaderLightLinear(int idx, float linear) {
    String uniform_name;
    size_t str_ize = _uniform_name_lights_f_linear.size() + 10;
    const char* format_str = _uniform_name_lights_f_linear.data();
    uniform_name.resize(str_ize);

    snprintf(&uniform_name[0],
            str_ize, 
            format_str,
            idx);

    setUniform(uniform_name, linear);
}

void OpenglShaderPhongLight::setShaderLightQuadratic(int idx, float quadratic) {
    String uniform_name;
    size_t str_ize = _uniform_name_lights_f_quadratic.size() + 10;
    const char* format_str = _uniform_name_lights_f_quadratic.data();
    uniform_name.resize(str_ize);

    snprintf(&uniform_name[0],
            str_ize, 
            format_str,
            idx);

    setUniform(uniform_name, quadratic);
}

void OpenglShaderPhongLight::setShaderLightColor(int idx, vec3 color) {
    String uniform_name;
    size_t str_ize = _uniform_name_lights_vec3_color.size() + 10;
    const char* format_str = _uniform_name_lights_vec3_color.data();
    uniform_name.resize(str_ize);

    snprintf(&uniform_name[0], str_ize,  format_str, idx);

    setUniform(uniform_name, color);
}

void OpenglShaderPhongLight::setShaderLight(int idx, ref<DirectionalLight> light) {
    setShaderLightType(idx, _LIGHT_TYPE_DIRECTION);
    setShaderLightDirection(idx, light->getDirection());
    setShaderLightColor(idx, light->getColor());
}

void OpenglShaderPhongLight::setShaderLight(int idx, ref<SpotLight> light) {
    setShaderLightType(idx, _LIGHT_TYPE_SPOT);
    setShaderLightColor(idx, light->getColor());
    setShaderLightDirection(idx, light->getDirection());
    setShaderLightPosition(idx, light->getPosition());
    setShaderLightConstant(idx, light->getConstant());
    setShaderLightLinear(idx, light->getLinear());
    setShaderLightQuadratic(idx, light->getQuadratic());
}

void OpenglShaderPhongLight::setShaderLight(int idx, ref<PointLight> light) {
    setShaderLightType(idx, _LIGHT_TYPE_POINT);
    setShaderLightColor(idx, light->getColor());
    setShaderLightPosition(idx, light->getPosition());
    setShaderLightConstant(idx, light->getConstant());
    setShaderLightLinear(idx, light->getLinear());
    setShaderLightQuadratic(idx, light->getQuadratic());
}
