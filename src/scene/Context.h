#pragma once

namespace nail {
    class Context {
    private:
        Context();
    public:
        void setup();
        static Context& instance() {
            static Context instance;
            return instance;
        }
    };
}