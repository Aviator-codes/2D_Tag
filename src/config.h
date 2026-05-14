#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
typedef uint32_t uint;

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "log/log.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>

void glfwErrorCallback(int error, const char* description);