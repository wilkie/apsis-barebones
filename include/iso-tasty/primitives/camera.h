#ifndef APSIS_PRIMITIVES_CAMERA_H
#define APSIS_PRIMITIVES_CAMERA_H

#include <glm/glm.hpp>

#include <vector>

namespace Apsis {
  namespace Primitives {
    class Camera {
    public:
      /*
       *  Creates a camera at the given position looking at the given point and
       *    oriented the given direction with the given zoom.
       */
      Camera(glm::vec3& position, glm::vec3& target, glm::vec3& up);

      /*
       *  Return a reference to the view matrix.
       */
      glm::mat4& view();

      /*
       *  Return the position of the eye.
       */
      glm::vec3& eye();

    private:
      glm::vec3 _position;
      glm::vec3 _target;
      glm::vec3 _up;

      glm::mat4 _view;
    };
  }
}

#endif