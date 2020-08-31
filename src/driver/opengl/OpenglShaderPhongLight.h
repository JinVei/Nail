#pragma once

#include "OpenglShader.h"
#include "scene/Light.h"
#include "scene/IRenderable.h"

namespace nail {
    class OpenglShaderPhongLight : public OpenglShader {
    private:
        std::map<GUID, ref<Light>> _scene_lights;
        const int _vertex_pos_location = 0;
        const int _vertex_normal_location = 1;
        const int _vertex_texture_coord_location = 2;
    public:
        void addSceneLight(ref<Light>);
        void delSceneLight(GUID);
        void updateLight();
        void setup(ref<IRenderable>, 
                    mat4 model_matrix, mat4 view_matrix,
                    mat4 projection_matrix, vec3 camare_pos);
    };
}