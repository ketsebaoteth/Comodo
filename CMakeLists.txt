cmake_minimum_required(VERSION 3.15)
project(comodo)

set(CMAKE_CXX_STANDARD 17)

# ImGui source files
file(GLOB IMGUI_SRC
    "include/external/imgui/*.cpp"
    "include/external/imgui/backends/imgui_impl_glfw.cpp"
    "include/external/imgui/backends/imgui_impl_opengl3.cpp"
)

# All project source files under src (recursively)
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Create executable
add_executable(comodo
    ${SRC_FILES}
    ${IMGUI_SRC}
)

# Include directories
target_include_directories(comodo PRIVATE
    include/external/imgui
    include/external/imgui/backends
    include/external/glfw/include
    include/external/stb
    include/internal         # Stable include path for your engine headers
    src                      # Optional: for local includes during prototyping
)

# Link GLFW and OpenGL
find_package(OpenGL REQUIRED)
add_subdirectory(include/external/glfw)

target_link_libraries(comodo
    glfw
    OpenGL::GL
)
