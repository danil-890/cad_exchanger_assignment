#ifndef CAD_EXCHANGER_ASSIGNMENT_CURVEFACTORY_H
#define CAD_EXCHANGER_ASSIGNMENT_CURVEFACTORY_H

#include <memory>
#include <random>

namespace curves {

    class Curve;

    class CurveFactory {
    public:
        static std::shared_ptr<Curve> createRandomCurve(std::mt19937 &gen);
    };

}


#endif //CAD_EXCHANGER_ASSIGNMENT_CURVEFACTORY_H
