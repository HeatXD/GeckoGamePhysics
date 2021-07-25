#include "../include/ext/doctest/doctest.h"
#include "../include/ggpvec2.h"

TEST_CASE("Init Vector2 No Params"){
    ggp::Vec2 v1;
    ggp::Vec2 v2 = ggp::Vec2();
    ggp::fix16 zero{0};

    CHECK(v1.X == zero);
    CHECK(v1.Y == zero);
    CHECK(v2.X == zero);
    CHECK(v2.Y == zero);
}

TEST_CASE("Init Vector2 With Params"){
    SUBCASE("Init With Int"){
        ggp::Vec2 vInt = ggp::Vec2(1, 4);
        CHECK(vInt.X == ggp::fix16{1});
        CHECK(vInt.Y == ggp::fix16{4});
    }
    SUBCASE("Init With Float"){
        ggp::Vec2 vFloat = ggp::Vec2(1.3f, 5.9f);
        CHECK(vFloat.X == ggp::fix16{1.3f});
        CHECK(vFloat.Y == ggp::fix16{5.9f});
    }
    SUBCASE("Init With Fix16"){
        ggp::Vec2 vFix = ggp::Vec2(ggp::fix16{2.55}, ggp::fix16{6.75});
        CHECK(vFix.X == ggp::fix16{2.55});
        CHECK(vFix.Y == ggp::fix16{6.75});
    }
}

TEST_CASE("Testing Additive Vector2 Operations"){
    FAIL("Not Yet Implemented");
}

TEST_CASE("Testing Subtractive Vector2 Operations"){
    FAIL("Not Yet Implemented");
}

TEST_CASE("Testing Vector2 Multiplication Operations"){
    FAIL("Not Yet Implemented");
}

TEST_CASE("Testing Vector2 Division Operations"){
    FAIL("Not Yet Implemented");
}