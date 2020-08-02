#pragma once
#include "Resource.h"
#include "common/ref.h"

namespace nail {
    class ResourceManager {
    protected:
        ref<Resource> getResource(String name) {
            auto rs = _resource_pool.find(name);
            if (rs == _resource_pool.end()) {
                return nullptr;
            }
            return rs->second;
        }

        bool saveResource(String name, ref<Resource> rs) {
            _resource_pool[name] = rs;
            return true;
        }

        bool delResource(String name) {
            _resource_pool.erase(name);
            return true;
        }

        virtual ~ResourceManager() {}
    private:
        std::map<String,ref<Resource>> _resource_pool;
    };
}