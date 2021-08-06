#ifndef GGP_OBJECT_H
#define GGP_OBJECT_H

#include "ggpvec2.h"
#include "ggpshape.h"
#include "ggphandles.h"
#include <set>

namespace ggp
{
    //! should not be instantiated. only the world is allowed to.
    struct Object
    {

        friend struct World;

        std::set<ShapeHandle> Shapes;

        Vec2 Position;

        void AddShape(ShapeHandle shape);

    protected:
        ObjectHandle _handle;
        // Objects can die by getting their handles moved to the graveyard
        // these handles will be reused for new Objects. Dead Objects are ingnored
        // in the simulation and cannot be used.
        // Objects die by calling the RemoveObjectfunction In the World struct.
        bool _isDead;
        // Disabeld Objects are ignored during the simulation.
        // These Objects can be re-enabled.
        bool _isDisabled;

        Object() : _handle(0), _isDead(false), _isDisabled(false){};
    };

    struct Body : Object
    {
        Vec2 Velocity;
        Vec2 Acceleration;

        Body(){};
        Body(ObjectHandle self);
        Body(ObjectHandle self, Vec2 pos, Vec2 vel, Vec2 accel);
    };

    struct Trigger : Object
    {

        Trigger(){};
        Trigger(ObjectHandle self);
        Trigger(ObjectHandle self, Vec2 position);
    };
} // namespace ggp

#endif // GGP_OBJECT_H