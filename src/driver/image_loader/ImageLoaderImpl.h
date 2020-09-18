#pragma once
#include "scene/ImageLoader.h"

namespace nail {
    class ImageDataImpl : public ImageData {
    private:
        String _path;
        int _width = 0;
        int _height = 0;
        int _channel = 0;
        const unsigned char* _image_data;
    public:
        ImageDataImpl(const unsigned char* image_data, String path, int width, int height, int channel);
        virtual ~ImageDataImpl();
        virtual const unsigned char* getData() override;
        virtual int getWidth() override;
        virtual int getHeight() override;
        virtual int getChannel() override;
        virtual String getPath() override;
    };

    class ImageLoaderImpl : public ImageLoader {
    public:
        ref<ImageData> load(const char* path) override;
    };
    
} // namespace nail
