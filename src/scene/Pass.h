#pragma once

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
        //PassType _type;
    public:
        // PassType getPassType() {
        //     return _type;
        // }
        virtual ~Pass(){}

        String getDiffuseMaps() {
            return _diffuse_map_path;
        }

        String getSpecularMaps() {
            return _specular_map_path;
        }

        String getNormalMaps() {
            return _normal_map_path;
        }

        String getHeightMaps() {
            return _height_map_path;
        }

        void setDiffuseMaps(const String& diffuse_maps) {
            _diffuse_map_path = diffuse_maps;
        }

        void setSpecularMaps(const String& specular_maps) {
            _specular_map_path = specular_maps;
        }

        void setNormalMaps(const String& normal_maps) {
            _normal_map_path = normal_maps;
        }

        void setHeightMaps(const String& height_maps) {
            _height_map_path = height_maps;
        }
    };
}