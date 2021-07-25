#ifndef GGP_VEC2_H
#define GGP_VEC2_H

#include "ggpfixed.h"

namespace ggp{

    // Should only be used for visualization purposes
    struct Vec2f
    {
        float X,Y;
    };
    
    struct Vec2
    {
        fix16 X,Y;

        Vec2();
        Vec2(int _x,int _y);
        Vec2(fix16 _x,fix16 _y);
        Vec2(float _x,float _y);

        // Should only be used for visualization purposes
        Vec2f ToFloatVector();

        Vec2 operator*(int num);
        Vec2 operator/(int num);
        Vec2 operator+(int num);
        Vec2 operator-(int num);
        Vec2& operator+=(int num);
        Vec2& operator-=(int num);
        Vec2& operator*=(int num);
        Vec2& operator/=(int num);

        Vec2 operator*(fix16 num);
        Vec2 operator/(fix16 num);
        Vec2 operator+(fix16 num);
        Vec2 operator-(fix16 num);
        Vec2& operator+=(fix16 num);
        Vec2& operator-=(fix16 num);
        Vec2& operator*=(fix16 num);
        Vec2& operator/=(fix16 num);

        Vec2 operator*(const Vec2& v);
        Vec2 operator/(const Vec2& v);
        Vec2 operator+(const Vec2& v);
        Vec2 operator-(const Vec2& v);
        Vec2& operator+=(const Vec2& v);
        Vec2& operator-=(const Vec2& v);
        Vec2& operator*=(const Vec2& v);
        Vec2& operator/=(const Vec2& v);
    };
}

#endif // GGP_VEC2_H