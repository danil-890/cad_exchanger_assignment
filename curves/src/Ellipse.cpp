#include "../include/curves/Ellipse.h"

#include <stdexcept>
#include <cmath>

namespace curves {

    Ellipse::Ellipse(double rx, double ry) : _rx(rx), _ry(ry) {
        if (_rx <= 0.0 || _ry <= 0.0) {
            throw std::invalid_argument("Ellipse radius must be positive");
        }
    }

    Point3D Ellipse::getPoint(double t) const {
        return {
                _rx * std::cos(t),
                _ry * std::sin(t),
                0.0
        };
    }

    Vector3D Ellipse::getDerivative(double t) const {
        return {
                -_rx * std::sin(t),
                _ry * std::cos(t),
                0.0
        };
    }

}