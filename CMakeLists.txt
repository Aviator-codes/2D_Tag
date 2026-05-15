cmake_minimum_required(VERSION 4.1)
project(main)

add_executable( main
    src/main.cpp
    src/glad.c
    src/UI/ui.cpp
    src/Game/game.cpp
    src/Entity/entity.cpp
    src/Renderer/renderer.cpp
    src/shaders/shader.cpp
    src/stb_image.cpp
    src/log/log.cpp
    src/Textures/texture.cpp
    src/ImGui/imgui_demo.cpp
    src/ImGui/imgui_draw.cpp
    src/ImGui/imgui_impl_glfw.cpp
    src/ImGui/imgui_impl_opengl3.cpp
    src/ImGui/imgui_tables.cpp
    src/ImGui/imgui_widgets.cpp
    src/ImGui/imgui.cpp
)

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/src/ImGui/ ${CMAKE_SOURCE_DIR}/dependencies/include)

target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/libs/libglfw3.a)