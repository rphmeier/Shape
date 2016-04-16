#pragma once

#include <memory>
#include <glbinding/gl/gl.h>

#include "sprite.h"
#include "texture.h"

namespace Game {
namespace Graphics {

/// Compile a shader program.
gl::GLuint compile_shader(const char* vertex_src, const char* fragment_src);

}
}