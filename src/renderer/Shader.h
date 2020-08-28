#pragma once
namespace nail {
    class Shader {
    public:
        virtual ~Shader() {}
        virtual void use() = 0;
    };
}