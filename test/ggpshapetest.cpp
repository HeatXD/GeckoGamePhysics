#include "../include/ext/doctest/doctest.h"
#include "../include/ggpshape.h"
#include "../include/ggpobject.h"

TEST_CASE("Testing TestCollision"){
    ggp::Rect r1 = ggp::Rect(1,1);
    ggp::Rect r2 = ggp::Rect(2,2);
    ggp::Circle c1 = ggp::Circle(1,2);
    ggp::Circle c2 = ggp::Circle(2,3);

    r1.TestCollision(&r2);
    r2.TestCollision(&c1);
    c1.TestCollision(&c2);
    c2.TestCollision(&r1);
}