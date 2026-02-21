#include "../include/curves/Helix.h"

#include <stdexcept>
#include <cmath>
#include <numbers>

namespace curves {

    Helix::Helix(double radius, double step) : _radius(radius), _step(step) {
        if (_radius <= 0.0 || _step <= 0.0) {
            throw std::invalid_argument("Helix radius and step must be positive");
        }
    }

    Point3D Helix::getPoint(double t) const {
        return {
                _radius * std::cos(t),
                _radius * std::sin(t),
                _step * t / (2.0 * std::numbers::pi)
        };
    }

    Vector3D Helix::getDerivative(double t) const {
        return {
                - _radius * std::sin(t),
                _radius * std::cos(t),
                _step / (2.0 * std::numbers::pi)
        };
    }

}
