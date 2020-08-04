#pragma once
#include "common/ref.h"
#include "Resource.h"
namespace nail {
    class ImageData : public Resource{
    public:
        virtual ~ImageData(){}
        virtual const unsigned char* get() = 0;
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual int getChannel() = 0;
        virtual String getPath() = 0;
    };

    class ImageLoader {
    public:
        virtual ~ImageLoader(){}
        virtual ref<ImageData> load(const char* path) = 0;
    };
}