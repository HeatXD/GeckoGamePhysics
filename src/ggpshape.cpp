#include "../include/ggpshape.h"
#include "../include/ggpalgo.h"
#include <iostream>

namespace ggp
{

    // void Shape::SetGlobalPosition(World *world, Vec2 globalPosition)
    // {
    //     Object *obj = world->GetObject(this->_parent);
    //     //check if parent is not NULL
    //     if (obj != nullptr)
    //     {
    //         //set global position
    //         Vec2 diff = obj->Position - globalPosition;
    //         this->LocalPosition += diff;
    //     }
    // }

    // Vec2 Shape::GetGlobalPosition(World *world)
    // {
    //     Object* obj = world->GetObject(this->_parent);
    //     //check if parent is not NULL
    //     if (obj != nullptr)
    //     {
    //         //return global position
    //         return this->LocalPosition + obj->Position;
    //     }
    //     // return empty vector
    //     return Vec2();
    // }

    Rect::Rect(ObjectHandle parent, ShapeHandle self)
    {
        this->_parent = parent;
        this->_handle = self;
    }

    Rect::Rect(ObjectHandle parent, ShapeHandle self, Vec2 position, Vec2 size)
    {
        this->_parent = parent;
        this->_handle = self;
        this->LocalPosition = position;
        this->Size = size;
    }

    bool Rect::CheckCollision(Rect *rect)
    {
        std::cout << "RECT X RECT\n";
        return true;
    }

    bool Rect::CheckCollision(Circle *circle)
    {
        std::cout << "RECT X CIRCLE\n";
        return true;
    }

    Circle::Circle(ObjectHandle parent, ShapeHandle self)
    {
        this->_parent = parent;
        this->_handle = self;
    }

    Circle::Circle(ObjectHandle parent, ShapeHandle self, Vec2 position, float radius)
    {
        this->_parent = parent;
        this->_handle = self;
        this->LocalPosition = position;
        this->Radius = fix16{radius};
    }

    Circle::Circle(ObjectHandle parent, ShapeHandle self, Vec2 position, fix16 radius)
    {
        this->_parent = parent;
        this->_handle = self;
        this->LocalPosition = position;
        this->Radius = radius;
    }

    bool Circle::CheckCollision(Rect *rect)
    {
        std::cout << "CIRCLE X RECT\n";
        return true;
    }

    bool Circle::CheckCollision(Circle *circle)
    {
        std::cout << "CIRCLE X CIRCLE\n";
        return true;
    }
};