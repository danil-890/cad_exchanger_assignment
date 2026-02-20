#include "../include/curves/Circle.h"

#include <stdexcept>
#include <cmath>

namespace curves {

    Circle::Circle(double radius) : _radius(radius) {
        if (_radius <= 0.0) {
            throw std::invalid_argument("Circle radius must be positive");
        }
    }

    double Circle::getRadius() const {
        return this->_radius;
    }

    Point3D Circle::getPoint(double t) const {
        return {
                _radius * std::cos(t),
                _radius * std::sin(t),
                0.0
        };
    }

    Vector3D Circle::getDerivative(double t) const {
        // x(t) = r * cos(t) -> x'(t) = -r * sin(t)
        // y(t) = r * sin(t) -> y'(t) = r * cos(t)
        return {
                -_radius * std::sin(t),
                _radius * std::cos(t),
                0.0
        };
    }

}