#include <iostream>
#include <vector>
#include <map>

#define ll long long

int main()
{
  int n;
  std::cin >> n;

  std::vector<int> v(n);

  for (auto &i : v)
  {
    std::cin >> i;
  }

  std::map<int, int> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (i == j)
        continue;

      int sum = v[i] + v[j];
      if (m.count(sum) == 1)
      {
        m[sum]++;
      }
      else
      {
        m[sum] = 1;
      }
    }
  }

  int res = -1;
  for (auto it : m)
  {
    if (it.second > res)
      res = it.second;
  }

  std::cout << res << std::endl;
}