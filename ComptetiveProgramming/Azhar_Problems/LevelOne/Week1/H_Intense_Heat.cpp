#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#define ll long long

int main()
{
  int n, k;
  std::cin >> n >> k;

  std::vector<int> v(n + 1);

  for (int i = 1; i <= n; i++)
    std::cin >> v[i];

  for (int i = 1; i <= n; i++)
    v[i] += v[i - 1];

  double maxHeat = 0;

  for (int j = k; j <= n; j++)
  {
    for (int i = 0; i <= n - j; i++)
    {
      double currentHeat = (v[i + j] - v[i]) / (double)(j);
      maxHeat = currentHeat > maxHeat ? currentHeat : maxHeat;
    }
  }

  std::cout << std::setprecision(18) << maxHeat << std::endl;
}