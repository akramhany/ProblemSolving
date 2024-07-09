#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

int main()
{
  int n, k;
  std::cin >> n >> k;

  std::vector<int> v(n);

  for (auto &i : v)
    std::cin >> i;

  int mod[101] = {0};

  for (auto i : v)
  {
    mod[i % k]++;
  }

  int res = 0;

  res += mod[0] / 2;

  for (int i = 1; i <= k / 2; i++)
  {
    if (k % 2 == 0 && i == k / 2)
      res += std::min(mod[i], mod[k - i]) / 2;
    else
      res += std::min(mod[i], mod[k - i]);
  }

  std::cout << res * 2 << std::endl;
}