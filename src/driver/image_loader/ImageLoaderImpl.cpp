#include "ImageLoaderImpl.h"
#include "stb_image/stb_image.h"

using namespace nail;


ImageDataImpl::ImageDataImpl(const unsigned char* image_data, String path, int width, int height, int channel) : _image_data(image_data) {
    _path = path;
    _width = width;
    _height = height;
    _channel =channel;
}

ImageDataImpl::~ImageDataImpl() {
    stbi_image_free((void*)_image_data);
}

const unsigned char* ImageDataImpl::getData() {
    return _image_data;
}

int ImageDataImpl::getWidth() {
    return _width;
}

int ImageDataImpl::getHeight() {
    return _height;
}

int ImageDataImpl::getChannel() {
    return _channel;
}

String ImageDataImpl::getPath() {
    return _path;
}

ref<ImageData> ImageLoaderImpl::load(const char* path) {
    stbi_set_flip_vertically_on_load(true);
    int width, height,  channel;
    unsigned char *image_data = stbi_load(path, &width, &height, &channel, 0);
    if (image_data == nullptr) {
        return nullptr;
    }
    auto image_data_ptr = ref<ImageDataImpl>(new ImageDataImpl(image_data, String(path), width, height, channel));
    return image_data_ptr;
}