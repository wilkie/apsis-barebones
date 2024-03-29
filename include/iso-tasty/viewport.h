#ifndef APSIS_VIEWPORT_H
#define APSIS_VIEWPORT_H

#include "iso-tasty/renderer.h"
#include "iso-tasty/map.h"

#include "iso-tasty/primitives/camera.h"

#include "iso-tasty/primitives/fragment_shader.h"
#include "iso-tasty/primitives/vertex_shader.h"
#include "iso-tasty/primitives/vertex_array.h"
#include "iso-tasty/primitives/vertex_buffer.h"
#include "iso-tasty/primitives/unlinked_program.h"
#include "iso-tasty/primitives/program.h"
#include "iso-tasty/primitives/texture.h"

#include "iso-tasty/model/thing.h"

namespace Apsis {
  class Viewport {
  public:
    // Create a viewport of the world given a size
    Viewport(unsigned int width, unsigned int height);

    // Query the size of the viewport
    unsigned int width();
    unsigned int height();

    // Manipulate the viewport focus
    void move(double deltaX, double deltaZ);
    void rotate(double delta);
    void zoom(double factor);

    // Draws the world as seen by this viewport
    void draw(Renderer* renderer, Map* map);

  private:
    // The rotation of the world
    double _rotation;

    // The vector from the center of the world to the center of the viewport
    double _x;
    double _z;

    // The amount to zoom
    double _zoom;

    // The size of the viewport
    unsigned int _width;
    unsigned int _height;

    std::vector<Model::Thing> _things;
    std::vector<Primitives::Camera> _cameras;
  };
}

#endif