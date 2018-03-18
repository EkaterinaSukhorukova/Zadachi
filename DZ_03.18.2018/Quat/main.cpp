#include "quat.h"
#include "func.h"
template <typename T>

int main
{
quat a(1, 2, 3, 4);
quat b(5, 6, 7, 8);

cout << operator*(&a, &b);
cout << operator+(&a, &b);

return 0;
}
