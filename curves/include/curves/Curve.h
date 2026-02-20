#ifndef CAD_EXCHANGER_CURVE_H
#define CAD_EXCHANGER_CURVE_H

#include "Point3D.h"

namespace curves {
    class Curve {
    public:
        virtual ~Curve() = default;

        [[nodiscard]]
        virtual Point3D getPoint(double t) const = 0;

        [[nodiscard]]
        virtual Vector3D getDerivative(double t) const = 0;
    };
}

#endif //CAD_EXCHANGER_CURVE_H