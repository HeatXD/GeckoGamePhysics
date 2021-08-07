#ifndef GGP_WORLD_H
#define GGP_WORLD_H

#include <vector>
#include <set>

#include "ggphandles.h"
#include "ggpvec2.h"
#include "ggpobject.h"
#include "ggpshape.h"

namespace ggp
{
    class World
    {
    public:
        World();

        ObjectHandle AddObject(Object &obj);
        Object *GetObject(ObjectHandle handle);
        void RemoveObject(ObjectHandle handle);

        ShapeHandle AddShape(Shape &shape);
        Shape *GetShape(ShapeHandle handle);
        void RemoveShape(ShapeHandle handle);

        Vec2 ShapeGetGlobalPosition(ShapeHandle handle);
        void ShapeSetGlobalPosition(ShapeHandle handle, Vec2 globalPosition);

        void Step(fix16 dt);

    private:
        // Counters to track where in the vector the next Item should be stored
        // Counters[0] == Objects
        // Counters[1] == Shapes
        uint32_t _counters[2];
        // Where the objects are stored
        std::vector<Object> _objects;
        std::vector<Shape> _shapes;
        // Graveyards for dead objects and shapes
        // Dead item handles will be reused for new items
        std::set<ObjectHandle> _deadObjects;
        std::set<ShapeHandle> _deadShapes;
    };

} // namespace ggp

#endif //GGP_WORLD_H