#ifndef CAD_EXCHANGER_ELLIPSE_H
#define CAD_EXCHANGER_ELLIPSE_H

#include "Curve.h"

namespace curves {

    class Ellipse final : public Curve {
    public:
        explicit Ellipse(double rx, double ry);

        [[nodiscard]]
        double getRadius() const;

        [[nodiscard]]
        Point3D getPoint(double t) const override;

        [[nodiscard]]
        Vector3D getDerivative(double t) const override;

    private:
        double _rx;
        double _ry;
    };

}

#endif //CAD_EXCHANGER_ELLIPSE_H
