
#pragma once
#include <memory>

namespace nail {

template<typename Ty>
using ref = std::shared_ptr<Ty>;

}