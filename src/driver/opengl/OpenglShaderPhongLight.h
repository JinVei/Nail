#pragma once

#include "OpenglShader.h"
#include "scene/Light.h"
#include "scene/IRenderable.h"
#include "scene/DirectionalLight.h"
#include "scene/PointLight.h"
#include "scene/SpotLight.h"

namespace nail {
    class OpenglShaderPhongLight : public OpenglShader {
    private:
        std::map<GUID, ref<Light>> _scene_lights;
        const int _vertex_pos_location = 0;
        const int _vertex_normal_location = 1;
        const int _vertex_texture_coord_location = 2;

        const int _tex_diffuse_loc = 1;
        const int _tex_specular_loc = 2;

        const int _LIGHT_TYPE_DIRECTION = 1;
        const int _LIGHT_TYPE_POINT = 2;
        const int _LIGHT_TYPE_SPOT = 3;

        uint64_t _max_light_num = 8;
        
        ConstString _uniform_name_mat4_model = "model";
        ConstString _uniform_name_mat4_view = "view";
        ConstString _uniform_name_mat4_projection = "projection";
        ConstString _uniform_name_vec3_view_pos = "viewPos";
        ConstString _uniform_name_int_lightArraylen = "lightArraylen";

        ConstString _uniform_name_material_tex_diffuse = "material.diffuseMap";
        ConstString _uniform_name_material_tex_specular = "material.specularMap";
        ConstString _uniform_name_material_light_diffuse = "material.diffuse_vec";
        ConstString _uniform_name_material_light_specular = "material.specular_vec";
        ConstString _uniform_name_material_light_ambient = "material.ambient_vec";

        ConstString _uniform_name_b_hasSpecularTex = "hasSpecularTex";

        ConstString _uniform_name_lights = "lights";
        ConstString _uniform_name_lights_int_lightType = "lights[%d].lightType";
        ConstString _uniform_name_lights_vec3_position = "lights[%d].position";
        ConstString _uniform_name_lights_vec3_direction = "lights[%d].direction";
        ConstString _uniform_name_lights_f_constant = "lights[%d].constant";
        ConstString _uniform_name_lights_f_linear = "lights[%d].linear";
        ConstString _uniform_name_lights_f_quadratic = "lights[%d].quadratic";
        ConstString _uniform_name_lights_f_cutOff = "lights[%d].cutOff";
        ConstString _uniform_name_lights_f_outerCutOff = "lights[%d].outerCutOff";


    protected:
        void setShaderLight(int idx, ref<DirectionalLight> light);
        void setShaderLight(int idx, ref<SpotLight> light);
        void setShaderLight(int idx, ref<PointLight> light);
        void setShaderLightType(int idx, int light_type);
        void setShaderLightDirection(int idx, vec3 light_dir);
        void setShaderLightPosition(int idx, vec3 pos);
        void setShaderLightConstant(int idx, float constant);
        void setShaderLightLinear(int idx, float linear);
        void setShaderLightQuadratic(int idx, float quadratic);
        void updateLight();
    public:
        void addSceneLight(ref<Light>);
        void delSceneLight(GUID);
        void setup(ref<Pass>, mat4 view_matrix, mat4 model_matrix,
                    mat4 projection_matrix, vec3 view_pos);
    };
}