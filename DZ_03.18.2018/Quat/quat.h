template <typename T>
struct quat
{
    quat(T x, T y, T z, T w) : X(x), Y(y), Z(z), W(w)
    {};
    quat(quat &a) : X(a.X), Y(a.Y), Z(a.Z), W(a.W)
    {};

    T norm()
    {
        return sqrt(X*X + Y*Y + Z*Z + W*W);
    };

    friend quat operator*(quat &a, quat &b);
    friend quat operator+(quat &a, quat &b);


    T X, Y, Z, W;
};
