#pragma once
#include "Mesh.h"
namespace nail {
    class CommonMesh : public Mesh{
    private:
        ref<VertexData> _vertex_date;
        ref<Material> _material;
    public:
        ref<VertexData> getVertexData() override {
            return _vertex_date;
        }
        void setVertexData(ref<VertexData> vertex_data) override {
            _vertex_date = vertex_data;
        }
        ref<Material> getMaterial() override {
            return _material;
        }
        void setMaterial(ref<Material> material) override {
            _material = material;
        }
    };
}