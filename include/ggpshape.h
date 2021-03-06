#ifndef GGP_SHAPE_H
#define GGP_SHAPE_H

#include "ggpvec2.h"
#include "ggphandles.h"

namespace ggp
{
    class Rect;
    class Circle;

    //! should not be instantiated by anything else then the World.
    class Shape
    {
    public:
        friend class World;
        Vec2 LocalPosition;

        ShapeHandle GetHandle(){ return _handle;};

        virtual bool TestCollision(Shape *shape) { return false; };
        virtual bool CheckCollision(Rect *rect) { return false; };
        virtual bool CheckCollision(Circle *cicle) { return false; };

        virtual ~Shape() = default;

    protected:
        ObjectHandle _parent;
        ShapeHandle _handle;
        // Shapes can die by getting their handles moved to the graveyard
        // these handles will be reused for new Shapes. Dead Shapes are ingnored
        // in the simulation and cannot be used.
        bool _isDead;
        // Disabeld Shapes are ignored during the simulation.
        // These Shapes can be re-enabled.
        bool _isDisabled;

        Shape() : _parent(0), _handle(0), _isDead(false), _isDisabled(false){};
    };

    class Rect : public Shape
    {
    public:
        Vec2 Size;

        Rect(){};
        Rect(ObjectHandle parent, ShapeHandle self);
        Rect(ObjectHandle parent, ShapeHandle self, Vec2 position, Vec2 size);

        bool TestCollision(Shape *shape) override
        {
            return shape->CheckCollision(this);
        };

        bool CheckCollision(Rect *rect) override;
        bool CheckCollision(Circle *circle) override;
    };

    class Circle : public Shape
    {
    public:
        fix16 Radius;

        Circle();
        Circle(ObjectHandle parent, ShapeHandle self);
        Circle(ObjectHandle parent, ShapeHandle self, Vec2 position, float radius);
        Circle(ObjectHandle parent, ShapeHandle self, Vec2 position, fix16 radius);

        bool TestCollision(Shape *shape) override
        {
            return shape->CheckCollision(this);
        };

        bool CheckCollision(Rect *rect) override;
        bool CheckCollision(Circle *circle) override;
    };
} // namespace ggp

#endif // GGP_SHAPE_H