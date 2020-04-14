#include <Corrade/PluginManager/PluginManager.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Trade/AbstractImporter.h>
#include <cassert>

using namespace Magnum;

class MyApplication: public Platform::Application {
    public:
        explicit MyApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
};

MyApplication::MyApplication(const Arguments& arguments): Platform::Application{arguments} {
    /* TODO: Add your initialization code here */
    /* Load a scene importer plugin */
    PluginManager::Manager<Trade::AbstractImporter> manager;
    auto loadState = manager.load("AssimpImporter");
    assert(loadState == Corrade::PluginManager::LoadState::Loaded || loadState == Corrade::PluginManager::LoadState::Static);
    Corrade::Containers::Pointer<Trade::AbstractImporter> importer = manager.instantiate("AssimpImporter");
}

void MyApplication::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

    /* TODO: Add your drawing code here */

    swapBuffers();
}

MAGNUM_APPLICATION_MAIN(MyApplication)
