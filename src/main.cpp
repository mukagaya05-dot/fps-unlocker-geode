#include <Geode/Geode.hpp>
#include <Geode/modify/CCDirector.hpp>

using namespace geode::prelude;

class $modify(FPSUnlockerDirector, CCDirector) {
    void setAnimationInterval(double interval) {
        CCDirector::setAnimationInterval(1.0 / 300.0);
    }
};
