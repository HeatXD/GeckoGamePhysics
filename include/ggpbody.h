#ifndef GGP_BODY_H
#define GGP_BODY_H

#include "ggpvec2.h"
#include "ggpshape.h"
#include "ggphandles.h"
#include <set>

namespace ggp
{
    //! should not be instantiated
    struct Object
    {
        ObjectHandle Handle;
        std::set<ShapeHandle> Shapes;
        // Objects can die by getting their handles moved to the graveyard
        // these handles will be reused for new Objects. Dead Objects are ingnored
        // in the simulation and cannot be used.
        bool IsDead;
        // Disabeld Objects are ignored during the simulation.
        // These Objects can be re-enabled.
        bool IsDisabled;

        Vec2 Position;

        void AddShape(ShapeHandle shape);

    protected:
        Object() : IsDead(false), IsDisabled(false){};
    };

    struct Body : Object
    {
        Vec2 Velocity;
        Vec2 Acceleration;

        Body(ObjectHandle self);
        Body(ObjectHandle self, Vec2 pos, Vec2 vel, Vec2 accel);
    };

    struct Trigger : Object
    {
        Trigger(ObjectHandle self);
        Trigger(ObjectHandle self, Vec2 position);
    };
} // namespace ggp

#endif // GGP_BODY_H