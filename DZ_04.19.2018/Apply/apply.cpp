#include <iostream>

template <class FuncType, class FirstType, class ...ArgsType>
void Apply( FuncType Func, FirstType &First, ArgsType&... Args )
{
  Func(First);
  Apply(Func, Args...);
} /* End of 'Apply' function */

static void Kek(int &X)
{
  X *= 10;
}

void main( void )
{
  int x = 1, y = 2, z = 3, k = 4;

  Apply(Kek, x, y, z, k);

  std::cout << x << ' ' << y << ' ' << z << ' ' << k << std::endl;
  system("pause");
}
