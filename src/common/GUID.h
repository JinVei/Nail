#pragma once

namespace nail {
typedef long GUID;
    struct GuidCreatetor {
        static GUID create() {
            static long guid = 0;
            return guid++;
        }
    };
}