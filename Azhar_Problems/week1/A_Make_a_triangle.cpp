#include <iostream>

using namespace std;

int main()
{
  int a, b, c;
  int x, y, z;

  cin >> a >> b >> c;

  if (a + b <= c)
    x = a, y = b, z = c;
  else if (a + c <= b)
    x = a, y = c, z = b;
  else if (b + c <= a)
    x = b, y = c, z = a;
  else
  {
    cout << "0" << endl;
    return (0);
  }

  cout << z - (x + y) + 1 << endl;
}