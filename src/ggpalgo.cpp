#include "../include/ext/fpm/math.hpp"
#include "../include/ggpalgo.h"

namespace ggp
{
    bool algo::RectVsRect(World &world, Rect &rectA, Rect &rectB)
    {
        // get global coordinates
        Vec2 rectAPos = world.ShapeGetGlobalPosition(rectA.GetHandle());
        Vec2 rectBPos = world.ShapeGetGlobalPosition(rectB.GetHandle());
        // are the sides touching each other?
        if (abs(rectAPos.X - rectBPos.X) > (rectA.Size.X / 2) + (rectB.Size.X / 2))
            return false;
        if (abs(rectAPos.Y - rectBPos.Y) > (rectA.Size.Y / 2) + (rectB.Size.Y / 2))
            return false;
        // collision!
        return true;
    }

    bool algo::RectVsCircles(World &world, Rect &rect, Circle &circle)
    {
        // get global coordinates
        Vec2 rectPos = world.ShapeGetGlobalPosition(rect.GetHandle());
        Vec2 circlePos = world.ShapeGetGlobalPosition(circle.GetHandle());
        // change rect position for easier calculations
        rectPos.X -= rect.Size.X / 2;
        rectPos.Y -= rect.Size.Y / 2;
        // temporary variables to set edges for testing
        fix16 testX = circlePos.X;
        fix16 testY = circlePos.Y;
        // which edge is closest?
        // testX
        if (circlePos.X < rectPos.X)
            testX = rectPos.X;
        else if (circlePos.X > rectPos.X + rect.Size.X)
            testX = rectPos.X + rect.Size.X;
        // testY
        if (circlePos.Y < rectPos.Y)
            testY = rectPos.Y;
        else if (circlePos.Y > rectPos.Y + rect.Size.Y)
            testY = rectPos.Y + rect.Size.Y;
        // get distance from closest edges
        fix16 dx = circlePos.X - testX;
        fix16 dy = circlePos.Y - testY;
        fix16 dist = sqrt(dx * dx + dy * dy);
        // if the distance is less than or equals the radius, collision!
        return (dist <= circle.Radius);
    }

    bool algo::CircleVsCircle(World &world, Circle &circleA, Circle &circleB)
    {
        // get global coordinates
        Vec2 circleAPos = world.ShapeGetGlobalPosition(circleA.GetHandle());
        Vec2 circleBPos = world.ShapeGetGlobalPosition(circleB.GetHandle());
        // get distance between the circle's centers
        // use the Pythagorean Theorem to compute the distance
        fix16 dx = circleAPos.X - circleBPos.X;
        fix16 dy = circleAPos.Y - circleBPos.Y;
        fix16 dist = sqrt(dx * dx + dy * dy);
        // if the distance is less than or equals the sum of the circle's
        // radii, the circles are touching!
        return (dist <= circleA.Radius + circleB.Radius);
    }
};