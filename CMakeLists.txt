cmake_minimum_required(VERSION 3.3)

project(MxEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MXENGINE_BUILD_SAMPLES "build sample projects" ON)
option(MXENGINE_BUILD_SHIPPING OFF)

if(MXENGINE_BUILD_SHIPPING)
    set(CMAKE_BUILD_TYPE "Release")
    add_compile_definitions(MXENGINE_SHIPPING)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/MP")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options("/MDd")
        add_compile_options("/Zi")
    else()
        add_compile_options("/MD")
    endif()
endif()

set(MxEngine_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MxEngine_CMAKE_UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_subdirectory(src)

if (MXENGINE_BUILD_SAMPLES)
    add_subdirectory(samples/SandboxApplication)
    add_subdirectory(samples/OfflineRendererSample)
    add_subdirectory(samples/PhysicsSample)
    add_subdirectory(samples/ProjectTemplate)
    add_subdirectory(samples/SoundSample)
    add_subdirectory(samples/VRCameraSample)
    add_subdirectory(samples/GrassSample)
    add_subdirectory(samples/FluidSimulation)
    add_subdirectory(samples/Sponza)
endif()