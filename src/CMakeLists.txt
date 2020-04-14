find_package(Magnum REQUIRED GL Sdl2Application AnyImageImporter)

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

find_package(MagnumPlugins REQUIRED AssimpImporter) # see below
add_executable(MyApplication MyApplication.cpp)

add_dependencies(MyApplication
        Magnum::AnyImageImporter
        MagnumPlugins::AssimpImporter)
target_link_libraries(MyApplication PRIVATE
        Magnum::AnyImageImporter
        MagnumPlugins::AssimpImporter
        Corrade::PluginManager
        Magnum::Application
        Magnum::GL
        Magnum::Trade
        Magnum::Magnum)
# Make the executable a default target to build & run in Visual Studio
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MyApplication)
