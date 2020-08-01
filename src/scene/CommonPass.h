#pragma once
#include "Pass.h"

namespace nail {
    class CommonPass : public Pass {
    private:
        std::vector<String> _diffuse_maps;
        std::vector<String> _specular_maps;
        std::vector<String> _normal_maps;
        std::vector<String> _height_maps;
    public:
        CommonPass() {
            _type = PassType::COMMON;
        }

        std::vector<String> getDiffuseMaps() {
            return _diffuse_maps;
        }

        std::vector<String> getSpecularMaps() {
            return _specular_maps;
        }

        std::vector<String> getNormalMaps() {
            return _normal_maps;
        }

        std::vector<String> getHeightMaps() {
            return _height_maps;
        }

        void setDiffuseMaps(const std::vector<String>& diffuse_maps) {
            _diffuse_maps = diffuse_maps;
        }

        void setSpecularMaps(const std::vector<String>& specular_maps) {
            _specular_maps = specular_maps;
        }

        void setNormalMaps(const std::vector<String>& normal_maps) {
            _normal_maps = normal_maps;
        }

        void setHeightMaps(const std::vector<String>& height_maps) {
            _height_maps = height_maps;
        }
    };
}