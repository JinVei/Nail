#pragma once

namespace nail {
    enum class PassType {
        DEFAULT,
        COMMON,
    };

    class Pass {
    protected:
        PassType _type;
    public:
        PassType getPassType() {
            return _type;
        } 
    };
}