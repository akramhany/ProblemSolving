#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int n, m;

  cin >> n >> m;

  double minKiloPrice = 1e9;
  while (n--)
  {
    double a, b;
    cin >> a >> b;

    if (a / b < minKiloPrice)
      minKiloPrice = a / b;
  }

  cout << setprecision(9) << minKiloPrice * m << endl;
}