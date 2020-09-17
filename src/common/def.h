#pragma once

#define CLASS_NON_COPYABLE(CLASS_NAME) \
CLASS_NAME& operator= (const CLASS_NAME& right) = delete;\
CLASS_NAME(const CLASS_NAME& right) = delete;

