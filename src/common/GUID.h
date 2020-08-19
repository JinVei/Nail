#pragma once

namespace nail {
typedef long GUID;
    struct GuidCreatetor {
        static GUID create() {
            static guid = 0;
            return guid++;
        }
    };
}