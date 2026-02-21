#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <numbers>
#include <random>

#include "curves/CurveFactory.h"
#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Helix.h"

using namespace curves;

int main() {
    double t = std::numbers::pi / 4.0;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::shared_ptr<Curve>> curves;

    curves.push_back(std::make_shared<Circle>(5.0));
    curves.push_back(std::make_shared<Ellipse>(2.0, 1.0));
    curves.push_back(std::make_shared<Helix>(2.0, 1.0));

    for (int i = 0; i < 15; ++i) {
        curves.push_back(CurveFactory::createRandomCurve(gen));
    }

    for (const auto &curve: curves) {
        auto p = curve->getPoint(t);
        auto d = curve->getDerivative(t);

        std::cout << "Point: (" << p.x << ", " << p.y << ", " << p.z << ")\n";

        std::cout << "Derivative: (" << d.x << ", " << d.y << ", " << d.z << ")\n\n";
    }

    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto &curve: curves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }

    std::sort(circles.begin(), circles.end(),
              [](const auto &a, const auto &b) {
                  return a->getRadius() < b->getRadius();
              });

    double totalRadius = std::accumulate(
            circles.begin(),
            circles.end(),
            0.0,
            [](double sum, const auto &c) {
                return sum + c->getRadius();
            });

    std::cout << "Total sum of radii: " << totalRadius << "\n";

    return 0;
}