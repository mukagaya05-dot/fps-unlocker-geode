#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(FPSUnlockerPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        auto manager = GameManager::get();

        // Request 1000 FPS from Geometry Dash's own FPS system.
        manager->m_customFPSTarget = 1000.f;
        manager->updateCustomFPS();

        log::info("FPS Unlocker: requested 1000 FPS");

        return true;
    }

    void onQuit() {
        auto manager = GameManager::get();

        // Restore the normal 120 FPS target when leaving a level.
        manager->m_customFPSTarget = 120.f;
        manager->updateCustomFPS();

        PlayLayer::onQuit();
    }
};
