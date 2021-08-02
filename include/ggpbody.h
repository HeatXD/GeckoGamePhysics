#ifndef GGP_BODY_H
#define GGP_BODY_H

#include "ggpvec2.h"
#include "ggpshape.h"
#include "ggphandles.h"
#include <vector>

namespace ggp
{
    //! should not be used directly as an object
    struct Object
    {
        ObjectHandle Handle;
        std::vector<ShapeHandle> Shapes;

    private:
        Object(){};
    };

    struct Body : Object
    {
        Vec2 Position;
        Vec2 Velocity;
        Vec2 Acceleration;

        Body(ObjectHandle self);
        Body(ObjectHandle self, Vec2 position, Vec2 velocity, Vec2 acceleration);
    };

    struct Trigger : Object
    {
        Vec2 Position;

        Trigger(ObjectHandle self);
        Trigger(ObjectHandle self, Vec2 position);
    };
} // namespace ggp

#endif // GGP_BODY_H