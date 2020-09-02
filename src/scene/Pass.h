#pragma once
#include "Texture.h"
#include "common/vec.h"

namespace nail {
    // enum class PassType {
    //     DEFAULT,
    //     COMMON,
    // };

    class Pass {
    protected:
        String _diffuse_map_path;
        String _specular_map_path;
        String _normal_map_path;
        String _height_map_path;

        ref<Texture> _textures_diffuse;
        ref<Texture> _textures_specular;
        ref<Texture> _textures_normal;
        ref<Texture> _textures_height;

        float     _shininess;
        vec3 _light_ambient = vec3(1.0f);
        vec3 _light_diffuse = vec3(1.0f);
        vec3 _light_specular = vec3(1.0f);
        //PassType _type;
    public:
        // PassType getPassType() {
        //     return _type;
        // }
        virtual ~Pass(){}

        String getDiffuseMaps();
        String getSpecularMaps();
        String getNormalMaps();
        String getHeightMaps();

        void setDiffuseMaps(const String& diffuse_maps);
        void setSpecularMaps(const String& specular_maps);
        void setNormalMaps(const String& normal_maps);
        void setHeightMaps(const String& height_maps);

        void setTextureDiffuse(ref<Texture>);
        void setTextureSpecular(ref<Texture>);
        void setTextureNormal(ref<Texture>);
        void setTextureHeight(ref<Texture>);

        ref<Texture> getTextureDiffuse();
        ref<Texture> getTextureSpecular();
        ref<Texture> getTextureNormal();
        ref<Texture> getTextureHeight();

        void setShininess(float shininess);
        float getShininess();
        void setLightAmbient(vec3 ambient);
        void setLightDiffuse(vec3 diffuse);
        void setLightSpecular(vec3 specular);
        vec3 getLightAmbient();
        vec3 getLightDiffuse();
        vec3 getLightSpecular();
    };
}