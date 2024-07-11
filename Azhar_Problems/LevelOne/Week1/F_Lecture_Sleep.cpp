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

  std::vector<int> x(n + 1);
  x[0] = 0;

  for (int i = 1; i <= n; i++)
    std::cin >> x[i];

  std::vector<int> m(n + 1);
  m[0] = 0;

  int maxT = 0;
  for (int i = 1; i <= n; i++)
  {
    if (x[i] == 0)
      m[i] = v[i];
    else
      m[i] = 0;

    m[i] += m[i - 1];
    maxT += (v[i] * x[i]);
  }

  int maxV = 0, maxIndx = -1;

  for (int i = 0; i <= n - k; i++)
  {
    // std::cout << v[i + k] - v[i] << std::endl;
    if (m[i + k] - m[i] > maxV)
    {
      maxV = m[i + k] - m[i];
      maxIndx = i + 1;
    }
  }

  for (int i = maxIndx; i < maxIndx + k; i++)
  {
    if (x[i] == 0)
      maxT += v[i];
  }

  std::cout << maxT << std::endl;
}