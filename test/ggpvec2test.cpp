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
    SUBCASE("Add Operation Vector2+Int"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase + 10;
        CHECK(vNew.X == ggp::fix16{11});
        CHECK(vNew.Y == ggp::fix16{12});
    }
    SUBCASE("Add Operation Vector2+=Int"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v += 11;
        CHECK(v.X == ggp::fix16{12});
        CHECK(v.Y == ggp::fix16{15});
    }
    SUBCASE("Add Operation Vector2+fix16"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase + ggp::fix16{8};
        CHECK(vNew.X == ggp::fix16{9});
        CHECK(vNew.Y == ggp::fix16{10});
    }
    SUBCASE("Add Operation Vector2+=fix16"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v += ggp::fix16{12};
        CHECK(v.X == ggp::fix16{13});
        CHECK(v.Y == ggp::fix16{16});
    }
    SUBCASE("Add Operation Vector2+Vector2"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase + ggp::Vec2(6.5f,7.2f);
        CHECK(vNew.X == ggp::fix16{7.5});
        CHECK(vNew.Y == ggp::fix16{9.2});
    }
    SUBCASE("Add Operation Vector2+=Vector2"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v += ggp::Vec2(34.5f,20.23f);
        CHECK(v.X == ggp::fix16{35.5});
        CHECK(v.Y == ggp::fix16{24.23});
    }
}

TEST_CASE("Testing Subtractive Vector2 Operations"){
    SUBCASE("Add Operation Vector2-Int"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase - 10;
        CHECK(vNew.X == ggp::fix16{-9});
        CHECK(vNew.Y == ggp::fix16{-8});
    }
    SUBCASE("Add Operation Vector2-=Int"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v -= 11;
        CHECK(v.X == ggp::fix16{-10});
        CHECK(v.Y == ggp::fix16{-7});
    }
    SUBCASE("Add Operation Vector2-fix16"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase - ggp::fix16{8};
        CHECK(vNew.X == ggp::fix16{-7});
        CHECK(vNew.Y == ggp::fix16{-6});
    }
    SUBCASE("Add Operation Vector2-=fix16"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v -= ggp::fix16{12};
        CHECK(v.X == ggp::fix16{-11});
        CHECK(v.Y == ggp::fix16{-8});
    }
    SUBCASE("Add Operation Vector2-Vector2"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase - ggp::Vec2(6.5f,7.2f);
        CHECK(vNew.X == ggp::fix16{-5.5});
        CHECK(vNew.Y == ggp::fix16{-5.2});
    }
    SUBCASE("Add Operation Vector2-=Vector2"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v -= ggp::Vec2(34.5f, 20.23f);
        CHECK(v.X == ggp::fix16{-33.5});
        CHECK(v.Y == ggp::fix16{-16.23});
    }
}

TEST_CASE("Testing Vector2 Multiplication Operations"){
    SUBCASE("Add Operation Vector2*Int"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase * 10;
        CHECK(vNew.X == ggp::fix16{10});
        CHECK(vNew.Y == ggp::fix16{20});
    }
    SUBCASE("Add Operation Vector2*=Int"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v *= 11;
        CHECK(v.X == ggp::fix16{11});
        CHECK(v.Y == ggp::fix16{44});
    }
    SUBCASE("Add Operation Vector2*fix16"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase * ggp::fix16{8};
        CHECK(vNew.X == ggp::fix16{8});
        CHECK(vNew.Y == ggp::fix16{16});
    }
    SUBCASE("Add Operation Vector2*=fix16"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v *= ggp::fix16{12};
        CHECK(v.X == ggp::fix16{12});
        CHECK(v.Y == ggp::fix16{48});
    }
    SUBCASE("Add Operation Vector2*Vector2"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase * ggp::Vec2(6.5f,7.2f);
        CHECK(vNew.X == ggp::fix16{6.5});
        CHECK(vNew.Y == ggp::fix16{14.4});
    }
    SUBCASE("Add Operation Vector2*=Vector2"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v *= ggp::Vec2(34.5f, 20.25f);
        CHECK(v.X == ggp::fix16{34.5});
        CHECK(v.Y == ggp::fix16{81});
    }
}

TEST_CASE("Testing Vector2 Division Operations"){
    SUBCASE("Add Operation Vector2/Int"){
        ggp::Vec2 vBase = ggp::Vec2(34, 204);
        ggp::Vec2 vNew = vBase / 10;
        CHECK(vNew.X == ggp::fix16{3.4});
        CHECK(vNew.Y == ggp::fix16{20.4});
    }
    SUBCASE("Add Operation Vector2/=Int"){
        ggp::Vec2 v = ggp::Vec2(234, 114);
        v /= 10;
        CHECK(v.X == ggp::fix16{23.4});
        CHECK(v.Y == ggp::fix16{11.4});
    }
    SUBCASE("Add Operation Vector2/fix16"){
        ggp::Vec2 vBase = ggp::Vec2(1, 2);
        ggp::Vec2 vNew = vBase / ggp::fix16{2};
        CHECK(vNew.X == ggp::fix16{0.5});
        CHECK(vNew.Y == ggp::fix16{1});
    }
    SUBCASE("Add Operation Vector2/=fix16"){
        ggp::Vec2 v = ggp::Vec2(6, 12);
        v /= ggp::fix16{12};
        CHECK(v.X == ggp::fix16{0.5});
        CHECK(v.Y == ggp::fix16{1});
    }
    SUBCASE("Add Operation Vector2/Vector2"){
        ggp::Vec2 vBase = ggp::Vec2(10, 20);
        ggp::Vec2 vNew = vBase / ggp::Vec2(20,100);
        CHECK(vNew.X == ggp::fix16{0.5});
        CHECK(vNew.Y == ggp::fix16{0.2});
    }
    SUBCASE("Add Operation Vector2/=Vector2"){
        ggp::Vec2 v = ggp::Vec2(1, 4);
        v /= ggp::Vec2(40, 20);
        CHECK(v.X == ggp::fix16{0.025});
        CHECK(v.Y == ggp::fix16{0.2});
    }
}

TEST_CASE("Testing Vec2 to Vec2f conversion function"){
    ggp::Vec2 v = ggp::Vec2(12.25f, 432.654f);
    ggp::Vec2f vNew = v.ToFloatVector();
    CHECK(vNew.X == 12.25f);
    CHECK(vNew.Y == 432.654f);
}