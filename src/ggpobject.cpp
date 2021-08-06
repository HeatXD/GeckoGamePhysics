#include "../include/ggpobject.h"

using namespace ggp;

void Object::AddShape(ShapeHandle shape)
{
    this->Shapes.insert(shape);
}

Body::Body(ObjectHandle self)
{
    this->_handle = self;
}

Body::Body(ObjectHandle self, Vec2 pos, Vec2 vel, Vec2 accel)
{
    this->_handle = self;
    this->Position = pos;
    this->Velocity = vel;
    this->Acceleration = accel;
}

Trigger::Trigger(ObjectHandle self)
{
    this->_handle = self;
}

Trigger::Trigger(ObjectHandle self, Vec2 position)
{
    this->_handle = self;
    this->Position = position;
}