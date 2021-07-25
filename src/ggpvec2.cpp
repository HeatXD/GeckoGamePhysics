#include "../include/ggpvec2.h"

using namespace ggp;

Vec2::Vec2() : X(0), Y(0){};

Vec2::Vec2(fix16 x, fix16 y)
{
    this->X = x;
    this->Y = y;
}

Vec2::Vec2(int x, int y)
{
    this->X = fix16{x};
    this->Y = fix16{y};
}

Vec2::Vec2(float x, float y)
{
    this->X = fix16{x};
    this->Y = fix16{y};
}

Vec2 Vec2::operator*(fix16 num)
{
    Vec2 vec;
    vec.X = this->X * num;
    vec.Y = this->Y * num;
    return vec;
}

Vec2 Vec2::operator*(int num)
{
    Vec2 vec;
    vec.X = this->X * num;
    vec.Y = this->Y * num;
    return vec;
}

Vec2 Vec2::operator*(const Vec2 &v)
{
    Vec2 vec;
    vec.X = this->X * v.X;
    vec.Y = this->Y * v.Y;
    return vec;
}

Vec2 Vec2::operator/(const Vec2 &v)
{
    Vec2 vec;
    vec.X = this->X / v.X;
    vec.Y = this->Y / v.Y;
    return vec;
}

Vec2 Vec2::operator/(fix16 num)
{
    Vec2 vec;
    vec.X = this->X / num;
    vec.Y = this->Y / num;
    return vec;
}

Vec2 Vec2::operator/(int num)
{
    Vec2 vec;
    vec.X = this->X / num;
    vec.Y = this->Y / num;
    return vec;
}

Vec2 Vec2::operator+(const Vec2 &v)
{
    Vec2 vec;
    vec.X = this->X + v.X;
    vec.Y = this->Y + v.Y;
    return vec;
}

Vec2 Vec2::operator+(fix16 num)
{
    Vec2 vec;
    vec.X = this->X + num;
    vec.Y = this->Y + num;
    return vec;
}

Vec2 Vec2::operator+(int num)
{
    Vec2 vec;
    vec.X = this->X + num;
    vec.Y = this->Y + num;
    return vec;
}

Vec2 Vec2::operator-(const Vec2 &v)
{
    Vec2 vec;
    vec.X = this->X - v.X;
    vec.Y = this->Y - v.Y;
    return vec;
}

Vec2 Vec2::operator-(fix16 num)
{
    Vec2 vec;
    vec.X = this->X - num;
    vec.Y = this->Y - num;
    return vec;
}
Vec2 Vec2::operator-(int num)
{
    Vec2 vec;
    vec.X = this->X - num;
    vec.Y = this->Y - num;
    return vec;
}

Vec2 &Vec2::operator+=(const Vec2 &v)
{
    this->X += v.X;
    this->Y += v.Y;
    return *this;
}

Vec2 &Vec2::operator+=(fix16 num)
{
    this->X += num;
    this->Y += num;
    return *this;
}

Vec2 &Vec2::operator+=(int num)
{
    this->X += num;
    this->Y += num;
    return *this;
}

Vec2 &Vec2::operator-=(const Vec2 &v)
{
    this->X -= v.X;
    this->Y -= v.Y;
    return *this;
}

Vec2 &Vec2::operator-=(fix16 num)
{
    this->X -= num;
    this->Y -= num;
    return *this;
}

Vec2 &Vec2::operator-=(int num)
{
    this->X -= num;
    this->Y -= num;
    return *this;
}

Vec2 &Vec2::operator*=(const Vec2 &v)
{
    this->X *= v.X;
    this->Y *= v.Y;
    return *this;
}

Vec2 &Vec2::operator*=(fix16 num)
{
    this->X *= num;
    this->Y *= num;
    return *this;
}

Vec2 &Vec2::operator*=(int num)
{
    this->X *= num;
    this->Y *= num;
    return *this;
}

Vec2 &Vec2::operator/=(const Vec2 &v)
{
    this->X /= v.X;
    this->Y /= v.Y;
    return *this;
}

Vec2 &Vec2::operator/=(fix16 num)
{
    this->X /= num;
    this->Y /= num;
    return *this;
}

Vec2 &Vec2::operator/=(int num)
{
    this->X /= num;
    this->Y /= num;
    return *this;
}
// Should only be used for visualization purposes
Vec2f Vec2::ToFloatVector()
{
    Vec2f ret;
    ret.X = static_cast<float>(this->X);
    ret.Y = static_cast<float>(this->Y);
    return ret;
}