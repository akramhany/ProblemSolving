#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

bool isDivInt(int a, int b)
{
  double div = float(a) / b;
  if (div - (a / b) < 1e-9)
    return true;
  return false;
}

int calculateSum(int n)
{
  return n * (n + 1) / 2;
}

int main()
{
  int n;
  cin >> n;

  vector<ll> v(n);
  map<ll, int> m;

  for (auto &i : v)
  {
    cin >> i;
    auto it = m.find(i);
    if (it == m.end())
    {
      m[i] = 0;
    }
    m[i] += 1;
  }

  int max = -1, min = 1e9;

  for (auto i : v)
  {
    if (i < min)
      min = i;
    if (i > max)
      max = i;
  }

  ll sum = min + max;
  ll res = 0;

  for (int i = 0; i < v.size(); i++)
  {
    ll val = sum - v[i];
    if (val == v[i])
    {
      res += calculateSum(m[v[i]] - 1);
      m[v[i]] = 0;
      continue;
    }
    if (m.find(val) != m.end())
    {
      res += (m[val] * m[v[i]]);
      m[v[i]] = 0;
    }
  }

  cout << res << endl;
}