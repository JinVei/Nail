#pragma
#include "DirectionalLight.h"
#include "Movable.h"
namespace nail {
    class SpotLight: public DirectionalLight, Movable {
    private:
        float _outer_cutoff;
        float _inner_cutoff;
    public:
        SpotLight(wref<SceneManager> owner, vec3 direction, float phi): DirectionalLight(owner,direction) {
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
    };
}