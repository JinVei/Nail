#pragma once
#include "common/ref.h"
#include "SceneObject.h"

namespace nail {
    class SceneObjectFactoty {
    public:
        ref<SceneObject> create(ParamList param_list) {
            return createImpl(param_list);
        }
        virtual ref<SceneObject> createImpl(ParamList param_list) = 0;
    };
}