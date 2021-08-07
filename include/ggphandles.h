#ifndef GGP_HANDLES_H
#define GGP_HANDLES_H

#include <stdint.h>
// these handles essentially point to the index in the vector where the Object is stored 
namespace ggp
{
    using ShapeHandle = uint32_t;
    using ObjectHandle = uint32_t;
}

#endif // GGP_HANDLES_H
