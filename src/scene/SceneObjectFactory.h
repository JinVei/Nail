#pragma once
#include "common/ref.h"
#include "SceneObject.h"

namespace nail {
    class SceneObjectFactory {
    private:
        wref<SceneManager> _manager;
    public:
        SceneObjectFactory(wref<SceneManager> manager) {
            _manager = manager;
        }

        wref<SceneManager> getManager() {
            return _manager;
        }

        ref<SceneObject> create(ParamList param_list) {
            return createImpl(param_list);
        }
        virtual ref<SceneObject> createImpl(ParamList param_list) = 0;
    };
}