cmake_minimum_required(VERSION 3.20)
project(sana VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

add_executable(sana src/main.cpp)
target_compile_features(sana PRIVATE cxx_std_17)
target_link_libraries(sana PRIVATE glfw)


