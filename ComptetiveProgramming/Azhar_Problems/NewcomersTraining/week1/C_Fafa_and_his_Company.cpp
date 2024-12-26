#include <iostream>
#include <iomanip>

using namespace std;

bool isDivInt(int a, int b)
{
  double div = float(a) / b;
  if (div - (a / b) < 1e-9)
    return true;
  return false;
}

int main()
{
  int n;
  cin >> n;

  int res = 0;
  for (int i = 1; i <= n / 2; i++)
  {
    if (isDivInt(n, i) && (n / i) > 1)
      res++;
  }

  cout << res << endl;
}