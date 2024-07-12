#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#define ll long long

int main()
{
  std::string s;
  std::cin >> s;

  int m;
  std::cin >> m;

  std::vector<std::pair<ll, ll>> v(s.size());
  v[0] = std::pair<ll, ll>({0, 0});

  for (int i = 1; i < s.size(); i++)
  {
    v[i] = v[i - 1];
    if (s[i] == s[i - 1])
    {
      if (s[i] == '.')
        v[i].first++;
      else
        v[i].second++;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int l, r;
    std::cin >> l >> r;

    l--, r--;

    ll res = (v[r].first - v[l].first) + (v[r].second - v[l].second);

    std::cout << res << std::endl;
  }
}