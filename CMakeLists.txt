cmake_minimum_required(VERSION 3.14...3.31)
project(
    cyengine
    LANGUAGES CXX C
)

## Enable decentralized package loading
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

## Install glfw
FetchContent_Declare(
    glfw3
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    )
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable( glfw3 )
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog/
    GIT_TAG v1.15.3
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    )
FetchContent_MakeAvailable( spdlog )

## Declare the engine library
add_library( cyengine STATIC
    src/GraphicsManager.cpp
    src/Types.h
    src/Engine.h
    )
set_target_properties( cyengine PROPERTIES CXX_STANDARD 20 )
## Declare our engine's header path.
## This allows targets that depend on the engine to #include them.
target_include_directories( cyengine PUBLIC src )
add_executable( helloworld demo/helloworld.cpp )
set_target_properties( helloworld PROPERTIES CXX_STANDARD 20 )
add_custom_target( run_helloworld helloworld USES_TERMINAL )
target_link_libraries( helloworld PRIVATE cyengine )
target_link_libraries( cyengine PUBLIC glfw )
target_link_libraries( cyengine PRIVATE spdlog::spdlog )