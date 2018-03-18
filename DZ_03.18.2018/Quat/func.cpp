#include "quat.h"
#include "func.h"

template <typename T>
quat<T> operator*(quat<T> &a, quat<T> &b)
{
    return quat<T>( a.X*b.X - a.Y*b.Y - a.Z*b.Z - a.W*b.W,
                    a.X*b.Y + b.X*a.Y + a.Z*b.W - b.Z*a.W,
                    a.X*b.Z + b.X*a.Z + a.W*b.Y - a.Y*b.W,
                    a.X*b.W + b.X*a.W + a.Y*b.Z - a.Z*b.Y);
};

template <typename T>
quat<T> operator+(quat<T> &a, quat<T> &b)
{
    return quat<T>( a.X + b.X,
                    a.Y + b.Y,
                    a.Z + b.Z,
                    a.W + b.W);
};
