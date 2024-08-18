
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
    ll n, m, k;
    cin >> n >> m >> k;

    ll x;
    cin >> x;
    vector<ll> v(x);
    for (auto & i : v)
      cin >> i;

    sort(v.begin(), v.end());

    ll res = 0;
    vector<ll> z((n + 1) * (m + 1));
    for (ll i = 1; i <= n; i++)
    {
      for (ll j = 1; j <= m; j++)
      {
        ll indx = (i - 1) * m + j;
        ll val1 = min(min(k, n - k + 1), (min(abs(i - n), abs(i - 1)) + 1));
        ll val2 = min((min(abs(j - m), abs(j - 1)) + 1), min(k, m - k + 1));
        z[indx] = val1 * val2;
      }
    }

    sort(z.begin(), z.end());

    int i = v.size() - 1, j = z.size() - 1;
    while (x--)
    {
      res += (v[i] * z[j]);
      i--, j--;
    }

    cout << res << "\n";
  }
}
