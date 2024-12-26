#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <cstring>

#define ll long long
#define llu unsigned long long

using namespace std;

bool isPrime(ll n)
{
  if (n == 2)
    return true;
  else if (n < 2 || n % 2 == 0)
    return false;

  for (ll i = 3; i * i <= n; i += 2)
  {
    if (n % i == 0)
      return false;
  }

  return true;
}

ll sumDivisors(ll n)
{
  ll sum = 0;

  for (ll i = 1; i * i <= n; i++)
  {
    if (i * i == n)
    {
      sum += i;
    }
    else if (n % i == 0)
    {
      sum += i;
      sum += (n / i);
    }
  }

  return sum;
}

// a must be the bigger number
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

// a must be the bigger number
ll lcm(ll a, ll b)
{
  return (ll)(a * b) / gcd(a, b);
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n, s, m;
    cin >> n >> s >> m;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
      int a, b;
      cin >> a >> b;

      v.push_back(make_pair(a, b));
    }

    int x = 0;
    bool canShower = false;

    for (int i = 0; i < n; i++)
    {
      if (v[i].first - x >= s)
      {
        canShower = true;
        break;
      }

      x = v[i].second;
    }

    if (canShower)
      cout << "YES\n";
    else
    {
      if (m - x >= s)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}