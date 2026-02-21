#include "../include/curves/CurveFactory.h"

#include "../include/curves/Circle.h"
#include "../include/curves/Ellipse.h"
#include "../include/curves/Helix.h"

#include <stdexcept>

namespace curves {

    std::shared_ptr <Curve> CurveFactory::createRandomCurve(std::mt19937 &gen) {
        std::uniform_int_distribution<> typeDist(0, 2);
        std::uniform_real_distribution<> radiusDist(1.0, 10.0);
        std::uniform_real_distribution<> stepDist(0.5, 5.0);

        switch (typeDist(gen)) {
            case 0:
                return std::make_shared<Circle>(radiusDist(gen));
            case 1:
                return std::make_shared<Ellipse>(radiusDist(gen), radiusDist(gen));
            case 2:
                return std::make_shared<Helix>(radiusDist(gen), stepDist(gen));
            default:
                throw std::logic_error("Unknown curve type");
        }
    }

}
