#include "../include/ggpbody.h"

using namespace ggp;

void Object::AddShape(ShapeHandle shape)
{
    this->Shapes.insert(shape);
}

Body::Body(ObjectHandle self)
{
    this->Handle = self;
}

Body::Body(ObjectHandle self, Vec2 pos, Vec2 vel, Vec2 accel)
{
    this->Handle = self;
    this->Position = pos;
    this->Velocity = vel;
    this->Acceleration = accel;
}

Trigger::Trigger(ObjectHandle self)
{
    this->Handle = self;
}

Trigger::Trigger(ObjectHandle self, Vec2 position)
{
    this->Handle = self;
    this->Position = position;
}