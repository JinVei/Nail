#pragma once
#include "common/ref.h"
#include <string>

namespace nail {
    class Resource {
    private:
        String _name;
        uint64_t _guid;
    public:
        Resource() {
            static uint64_t rs_id = 0;
            _guid = rs_id++;
        }
        virtual ~Resource() {}
        String getName() {
            return _name;
        }
        void setName(String name) {
            _name = name;
        }
        uint64_t getGUID() {
            return _guid;
        }
    };
    using ResourcePtr = ref<Resource>;

    template<typename T>
    class ResourceWrapper : public Resource {
        T _real_data;
    public:
        explicit ResourceWrapper(T real_data) {
            _real_data = real_data;
        }

        T& get() {
            return _real_data;
        }
    };
}