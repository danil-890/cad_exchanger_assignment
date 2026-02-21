add_library(curves STATIC
        src/Circle.cpp
        src/Ellipse.cpp
        src/Helix.cpp
        src/CurveFactory.cpp
)

target_include_directories(curves
        PUBLIC include
)