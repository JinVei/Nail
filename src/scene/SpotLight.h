#pragma
#include "DirectionalLight.h"
#include "Movable.h"
#include "Attenuatable.h"

namespace nail {
    class SpotLight: public DirectionalLight, public Movable, public Attenuatable {
    private:
        float _outer_cutoff;
        float _inner_cutoff;
    public:
        SpotLight(wref<SceneManager> manager, vec3 direction, float phi, Color color): DirectionalLight(manager, direction, color) {
        }

        float getouterCutOff() {
            return _outer_cutoff;
        }
        void setouterCutOff(float cut_off) {
            _outer_cutoff = cut_off;
        }

        float getInnerCutOff() {
            return _inner_cutoff;
        }
        void setInnerCutOff(float cut_off) {
            _inner_cutoff = cut_off;
        }
        virtual LightType getLightType() override{
            return LightType::SPOT_LIGHT;
        }
    };
}