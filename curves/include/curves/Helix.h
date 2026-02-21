#ifndef CAD_EXCHANGER_ASSIGNMENT_HELIX_H
#define CAD_EXCHANGER_ASSIGNMENT_HELIX_H

#include "Curve.h"

namespace curves {

    class Helix final : public Curve {
    public:
        Helix(double radius, double step);

        [[nodiscard]]
        Point3D getPoint(double t) const override;

        [[nodiscard]]
        Vector3D getDerivative(double t) const override;
    private:
        double _radius;
        double _step;
    };

}


#endif //CAD_EXCHANGER_ASSIGNMENT_HELIX_H
