#include "OpenglShaderPhongLight.h"
#include "scene/DirectionalLight.h"
#include "common/assert.h"
#include "OpenglTexture2D.h"

using namespace nail;

void OpenglShaderPhongLight::addSceneLight(ref<Light> light) {
    NAIL_ASSERT(light != nullptr);

    _scene_lights[light->getGUID()] = light;
    updateLight();
}

void OpenglShaderPhongLight::delSceneLight(GUID light_guid) {
    auto light = _scene_lights.find(light_guid);
    if (light != _scene_lights.end()) {
        _scene_lights.erase(light);
    }
    updateLight();
}

void OpenglShaderPhongLight::updateLight() {
    for(auto& light_pair : _scene_lights) {
        switch(light_pair.second->getLightType()) {
        case LightType::DIRECTIONAL_LIGHT:{
            auto dir_light = std::dynamic_pointer_cast<DirectionalLight>(light_pair.second);
            //setUniform()
            //TODO
            break;
        }
        case LightType::POINT_LIGHT:{
            break;
        }
        case LightType::SPOT_LIGHT:{
            break;
        }
        default:
            NAIL_ASSERT(false && "Unknow light type");
        }
    }
}

void OpenglShaderPhongLight::setup(ref<Pass> pass, mat4 model_matrix,
                                    mat4 view_matrix, mat4 projection_matrix, vec3 view_pos) {

    setUniform(String(_uniform_name_mat4_model), model_matrix);
    setUniform(String(_uniform_name_mat4_view), view_matrix);
    setUniform(String(_uniform_name_mat4_projection), projection_matrix);
    setUniform(String(_uniform_name_vec3_view_pos), view_pos);

    auto tex_diffuse = std::dynamic_pointer_cast<OpenglTexture2D>(pass->getTextureDiffuse());
    NAIL_ASSERT(tex_diffuse != nullptr);
    setUniform(String(_uniform_name_material_tex_diffuse), _tex_diffuse_loc);
    tex_diffuse->attachToLocaction(_tex_diffuse_loc);

    auto tex_specular = std::dynamic_pointer_cast<OpenglTexture2D>(pass->getTextureSpecular());
    NAIL_ASSERT(tex_specular != nullptr);
    setUniform(String(_uniform_name_material_tex_specular), _tex_specular_loc);
    tex_specular->attachToLocaction(_tex_specular_loc);

    setUniform(String(_uniform_name_material_light_diffuse), pass->getLightDiffuse());
    setUniform(String(_uniform_name_material_light_specular), pass->getLightSpecular());
    setUniform(String(_uniform_name_material_light_ambient), pass->getLightAmbient());
};


void OpenglShaderPhongLight::setupShaderLight(int idx, ref<DirectionalLight> light) {
    String uniform_lightType;
    uniform_lightType.resize(_uniform_name_lights_int_lightType.size() + 10);
    //TODO
     //snprintf()
    //setUniform(uniform_name, light->);

}

void OpenglShaderPhongLight::setupShaderLight(int idx, ref<SpotLight> light) {
    //TODO
}
void OpenglShaderPhongLight::setupShaderLight(int idx, ref<PointLight> light) {
    //TODO
}