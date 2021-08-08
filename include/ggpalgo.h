#ifndef GGP_ALGO_H
#define GGP_ALGO_H

#include "ggpshape.h"
#include "ggpworld.h"

namespace ggp
{
    namespace algo
    {
        bool RectVsRect(World &world, Rect &rectA, Rect &rectB);
        bool RectVsCircles(World &world, Rect &rect, Circle &circle);
        bool CircleVsCircle(World &world, Circle &circleA, Circle &circleB);
    } //namespace algo
} // namespace ggp

#endif //GGP_ALGO_H