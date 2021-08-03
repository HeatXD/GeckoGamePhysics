#ifndef GGP_WORLD_H
#define GGP_WORLD_H

#include "ggpbody.h"

namespace ggp
{
    struct World
    {
        // Counters to track where in the vector the next Item should be stored
        // Counters[0] == Objects 
        // Counters[1] == Shapes 
        uint32_t Counters[2];
        // Where the objects are stored
        std::vector<Object> Objects;
        std::vector<Shape> Shapes;
        // Graveyards for dead objects and shapes
        // Dead item handles will be reused for new items
        std::set<ObjectHandle> DeadObjects;
        std::set<ShapeHandle> DeadShapes;
    };
    
} // namespace ggp

#endif //GGP_WORLD_H