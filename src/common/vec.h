#pragma once
#include <glm/glm.hpp>
namespace nail {
    using Position = glm::vec3;
    using vec3 = glm::vec3;
    using vec4 = glm::vec4;
    using Color = glm::vec4;
    using mat4 = glm::mat4;

    enum class Axis {
        x, y, z,
    };

    struct Rectangle {
        float x, y; // left up
        float width, height;
    };
}