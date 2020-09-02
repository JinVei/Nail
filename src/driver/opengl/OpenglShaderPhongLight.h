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

        const int LIGHT_TYPE_DIRECTION = 1;
        const int LIGHT_TYPE_POINT = 2;
        const int LIGHT_TYPE_SPOT = 3;
        
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

        ConstString _uniform_name_lights = "lights";
        ConstString _uniform_name_lights_int_lightType = "lights[%s].lightType";
        ConstString _uniform_name_lights_vec3_position = "lights[%s].position";
        ConstString _uniform_name_lights_vec3_direction = "lights[%s].direction";
        ConstString _uniform_name_lights_f_constant = "lights[%s].constant";
        ConstString _uniform_name_lights_f_linear = "lights[%s].linear";
        ConstString _uniform_name_lights_f_quadratic = "lights[%s].quadratic";
        ConstString _uniform_name_lights_f_cutOff = "lights[%s].cutOff";
        ConstString _uniform_name_lights_f_outerCutOff = "lights[%s].outerCutOff";

    protected:
        void setupShaderLight(int idx, ref<DirectionalLight> light);
        void setupShaderLight(int idx, ref<SpotLight> light);
        void setupShaderLight(int idx, ref<PointLight> light);
    public:
        void addSceneLight(ref<Light>);
        void delSceneLight(GUID);
        void updateLight();
        void setup(ref<Pass>, mat4 view_matrix, mat4 model_matrix,
                    mat4 projection_matrix, vec3 view_pos);
    };
}