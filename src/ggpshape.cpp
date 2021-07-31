#include "../include/ggpshape.h"
#include <iostream>

using namespace ggp;

Rect::Rect(ObjectHandle parent, ShapeHandle self)
{
    this->Parent = parent;
    this->Handle = self;
}

Rect::Rect(ObjectHandle parent, ShapeHandle self, Vec2 position, Vec2 size)
{
    this->Parent = parent;
    this->Handle = self;
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
    this->Parent = parent;
    this->Handle = self;
}

Circle::Circle(ObjectHandle parent, ShapeHandle self, Vec2 position, float radius)
{
    this->Parent = parent;
    this->Handle = self;
    this->LocalPosition = position;
    this->Radius = fix16{radius};
}

Circle::Circle(ObjectHandle parent, ShapeHandle self, Vec2 position, fix16 radius)
{
    this->Parent = parent;
    this->Handle = self;
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