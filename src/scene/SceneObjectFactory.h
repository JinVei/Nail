#pragma once
#include "common/ref.h"
#include "SceneObject.h"

namespace nail {
    class SceneObjectFactory {
    private:
        wref<SceneManager> _owner;
    public:
        SceneObjectFactory(wref<SceneManager> owner) {
            _owner = owner;
        }

        wref<SceneManager> getManager() {
            return _owner;
        }

        ref<SceneObject> create(ParamList param_list) {
            return createImpl(param_list);
        }
        virtual ref<SceneObject> createImpl(ParamList param_list) = 0;
    };
}