#include "../include/ggpworld.h"

namespace ggp
{
    World::World()
    {
        // Set Counters
        this->_counters[0] = 1;
        this->_counters[1] = 1;
    }

    void World::ShapeSetGlobalPosition(ShapeHandle handle, Vec2 globalPosition)
    {
        // Get The shape
        Shape *s = GetShape(handle);
        // Get Parent
        Object *obj = GetObject(s->_parent);
        //check if parent is not NULL
        if (obj != nullptr)
        {
            //set global position
            Vec2 diff = obj->Position - globalPosition;
            s->LocalPosition += diff;
        }
    }

    Vec2 World::ShapeGetGlobalPosition(ShapeHandle handle)
    {
        // Get The shape
        Shape *s = GetShape(handle);
        // Get Parent
        Object *obj = GetObject(s->_parent);
        //check if parent is not NULL
        if (obj != nullptr)
        {
            //return global position
            return s->LocalPosition + obj->Position;
        }
        // return empty vector
        return Vec2();
    }

    void World::Step(fix16 dt)
    {
    }

    ObjectHandle World::AddObject(Object &obj)
    {
        ObjectHandle oh = 0;
        // Check if there is a handle available
        // If there are handles use one of them and remove it from the set
        // Otherwise create a handle based of the counter and increase the counter
        if (this->_deadObjects.empty())
        {
            oh = this->_counters[0];
            Object newObj;
            newObj = obj;
            newObj._handle = oh;
            this->_objects.insert(this->_objects.begin() + oh, newObj);
            this->_counters[0]++;
        }
        else
        {
            // Get first element from graveyard set
            std::set<ObjectHandle>::iterator i = this->_deadObjects.begin();
            oh = *i++;
            // Add New object to position of the dead object
            Object newObj;
            newObj = obj;
            newObj._handle = oh;
            this->_objects.insert(this->_objects.begin() + oh, newObj);
            // Remove first element from graveyard set
            // Since it has been reused
            this->_deadObjects.erase(0);
        }
        // return handle
        return oh;
    }

    Object *World::GetObject(ObjectHandle handle)
    {
        return &this->_objects[handle];
    }

    void World::RemoveObject(ObjectHandle handle)
    {
        this->_objects[handle]._isDead = true;
        this->_deadObjects.insert(handle);
    }

    ShapeHandle World::AddShape(Shape &shape)
    {
        ShapeHandle sh = 0;
        // Check if there is a handle available
        // If there are handles use one of them and remove it from the set
        // Otherwise create a handle based of the counter and increase the counter
        if (this->_deadShapes.empty())
        {
            sh = this->_counters[1];
            Shape newShape;
            newShape = shape;
            newShape._handle = sh;
            this->_shapes.insert(this->_shapes.begin() + sh, newShape);
            this->_counters[1]++;
        }
        else
        {
            // Get first element from graveyard set
            std::set<ShapeHandle>::iterator i = this->_deadShapes.begin();
            sh = *i++;
            // Add New Shape to position of the dead Shape
            Shape newShape;
            newShape = shape;
            newShape._handle = sh;
            this->_shapes.insert(this->_shapes.begin() + sh, newShape);
            // Remove first element from graveyard set
            // Since it has been reused
            this->_deadShapes.erase(0);
        }
        //return handle
        return sh;
    }

    Shape *World::GetShape(ShapeHandle handle)
    {
        return &this->_shapes[handle];
    }

    void World::RemoveShape(ShapeHandle handle)
    {
        this->_shapes[handle]._isDead = true;
        this->_deadShapes.insert(handle);
    }
};