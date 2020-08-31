#include "OpenglShaderPhongLight.h"
#include "scene/DirectionalLight.h"

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

void OpenglShaderPhongLight::setup(ref<IRenderable> renderable, mat4 model_matrix,
                                    mat4 view_matrix, mat4 projection_matrix, vec3 camare_pos) {

};