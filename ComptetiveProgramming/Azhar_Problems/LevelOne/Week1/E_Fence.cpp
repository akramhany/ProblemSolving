#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

int main()
{
  int n, k;
  std::cin >> n >> k;

  std::vector<int> v(n + 1);
  v[0] = 0;

  for (int i = 1; i <= n; i++)
    std::cin >> v[i];

  for (int i = 1; i <= n; i++)
    v[i] += v[i - 1];

  int minSum = 1e9, indx = -1;

  for (int i = 0; i <= n - k; i++)
  {
    if (v[i + k] - v[i] < minSum)
    {
      minSum = v[i + k] - v[i];
      indx = i + 1;
    }
  }

  std::cout << indx << std::endl;
}