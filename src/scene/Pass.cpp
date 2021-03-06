#include "Pass.h"

using namespace nail;


String Pass::getDiffuseMaps() {
    return _diffuse_map_path;
}

String Pass::getSpecularMaps() {
    return _specular_map_path;
}

String Pass::getNormalMaps() {
    return _normal_map_path;
}

String Pass::getHeightMaps() {
    return _height_map_path;
}

void Pass::setDiffuseMaps(const String& diffuse_maps) {
    _diffuse_map_path = diffuse_maps;
}

void Pass::setSpecularMaps(const String& specular_maps) {
    _specular_map_path = specular_maps;
}

void Pass::setNormalMaps(const String& normal_maps) {
    _normal_map_path = normal_maps;
}

void Pass::setHeightMaps(const String& height_maps) {
    _height_map_path = height_maps;
}

void Pass::setTextureDiffuse(ref<Texture> tex) {
    _textures_diffuse = tex;
}

void Pass::setTextureSpecular(ref<Texture> tex) {
    _textures_specular = tex;
}

void Pass::setTextureNormal(ref<Texture> tex) {
    _textures_normal = tex;
}

void Pass::setTextureHeight(ref<Texture> tex) {
    _textures_height = tex;
}

ref<Texture> Pass::getTextureDiffuse() {
    return _textures_diffuse;
}

ref<Texture> Pass::getTextureSpecular() {
    return _textures_specular;
}

ref<Texture> Pass::getTextureNormal() {
    return _textures_normal;
}

ref<Texture> Pass::getTextureHeight() {
    return _textures_height;
}


void Pass::setShininess(float shininess) {
    _shininess = shininess;
}

float Pass::getShininess() {
    return _shininess;
}

void Pass::setLightAmbient(vec3 ambient) {
    _light_ambient = ambient;
}

void Pass::setLightDiffuse(vec3 diffuse) {
    _light_diffuse = diffuse;
}

void Pass::setLightSpecular(vec3 specular) {
    _light_specular = specular;
}

vec3 Pass::getLightAmbient() {
    return _light_ambient;
}

vec3 Pass::getLightDiffuse() {
    return _light_diffuse;
}

vec3 Pass::getLightSpecular() {
    return _light_specular;
}