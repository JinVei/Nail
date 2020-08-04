#pragma once
#include "Resource.h"
#include "ImageLoader.h"

namespace nail {
    class Texture: public Resource {
        friend class TextureFactory;
    public:
        enum class TextureType {
            TEXTURE_2D,
            SKY_BOX,
        };
    private:
        uint64_t _width;
        uint64_t _height;
        uint64_t _channel;
        TextureType _type;
    protected:
        virtual bool load(ref<ImageData> data) = 0;
    public:
        virtual ~Texture() {}
        void setWidth(uint64_t width) {
            _width = width;
        }

        void setHeight(uint64_t height) {
            _height = height;
        }

        void setChannel(uint64_t channel) {
            _channel = channel;
        }

        void setType(TextureType type) {
            _type = type;
        }

        uint64_t getWith() {
            return _width;
        }

        uint64_t getHeight() {
            return _height;
        }

        uint64_t getChannel() {
            return _channel;
        }

        TextureType getType() {
            return _type;
        }

        virtual bool isLoad() = 0;
    };
}