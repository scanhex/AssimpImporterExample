cmake_minimum_required(VERSION 3.4)
project(MyApplication)

set(BUILD_PLUGINS_STATIC ON)
set(BUILD_STATIC_PIC ON)
set(BUILD_STATIC ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

# Remove these lines if you have installed SDL2 globally, make sure you have this directory otherwise
if (MSVC)
    set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/SDL2-MSVC ${CMAKE_PREFIX_PATH})
else()
    set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/SDL2-2.0.10 ${CMAKE_PREFIX_PATH})
endif()


add_subdirectory(corrade EXCLUDE_FROM_ALL)
set(WITH_SDL2APPLICATION ON)
set(WITH_ANYIMAGEIMPORTER ON CACHE BOOL "" FORCE)
add_subdirectory(magnum EXCLUDE_FROM_ALL)

set(WITH_STBIMAGEIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_TINYGLTFIMPORTER ON CACHE BOOL "" FORCE)

# Add Assimp with unwanted parts disabled, help Magnum find everything needed
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assimp/include CACHE STRING "" FORCE)
set(ASSIMP_LIBRARY_DEBUG assimp CACHE STRING "" FORCE)
set(ASSIMP_LIBRARY_RELEASE assimp CACHE STRING "" FORCE)
# The following is important to avoid Assimp appending `d` to all your
# binaries. You need Assimp >= 5.0.0 for this to work, also note that after
# 5.0.1 this option is prefixed with ASSIMP_, so better set both variants.
set(INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)
set(ASSIMP_INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
add_subdirectory(assimp EXCLUDE_FROM_ALL)
add_library(Assimp::Assimp ALIAS assimp)

set(WITH_ASSIMPIMPORTER ON CACHE BOOL "" FORCE)
add_subdirectory(magnum-plugins EXCLUDE_FROM_ALL)

add_subdirectory(src)
