#ifndef GGP_ALGO_H
#define GGP_ALGO_H

#include "ggpshape.h"

namespace ggp
{
    namespace algo
    {
        bool RectVsRect(Rect *rectA, Rect *rectB);
        bool RectVsCircles(Rect *rect, Circle *circle);
        bool CircleVsCircle(Circle *circleA, Circle *circleB);
    } //namespace algo
} // namespace ggp

#endif //GGP_ALGO_H