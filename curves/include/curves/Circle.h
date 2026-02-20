#ifndef CAD_EXCHANGER_CIRCLE_H
#define CAD_EXCHANGER_CIRCLE_H

#include "Curve.h"

namespace curves {

    class Circle final : public Curve {
    public:
        explicit Circle(double radius);

        [[nodiscard]]
        double getRadius() const;

        [[nodiscard]]
        Point3D getPoint(double t) const override;

        [[nodiscard]]
        Vector3D getDerivative(double t) const override;

    private:
        double _radius;
    };

}


#endif //CAD_EXCHANGER_CIRCLE_H
