#pragma once
#include "Texture.h"

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

    };
}