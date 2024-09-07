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

ll isPrimeRetNum(ll n)
{
  if (n == 2)
    return n;
  else if (n < 2 || n % 2 == 0)
    return n;

  for (ll i = 3; i * i <= n; i += 2)
  {
    if (n % i == 0)
      return i;
  }

  return n;
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

bool validate(vector<ll> &v, ll k, ll c, ll d) {
  ll currentCoins = 0;
  while (d) {
    ll counter = k;
    ll i = v.size() - 1;
    currentCoins += v[i];
    i--;
    d--;
    while (counter && d) {
      if (i >= 0)
        currentCoins += v[i--];
      counter--, d--;
    }
  }

  return currentCoins >= c;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> v(n);
    ll sum = 0, x = 0;
    for (auto & i : v)
    {
      cin >> i;
      if (x < d) {
        sum += i;
        x++;
      }
    }

    sort(v.begin(), v.end());
    if (v[v.size() - 1] * d < c) {
      cout << "Impossible\n";
      continue;
    }
    else if (v[v.size() - 1] >= c || sum >= c) {
      cout << "Infinity\n";
      continue;
    }

    ll l = 0, r = 1e9;
    ll res = -1;
    while (l <= r) {
      ll mid = (l + r) / 2;
      bool isV = validate(v, mid, c, d);
      if (isV) {
        l = mid + 1;
        res = max(res, mid);
      } else {
        r = mid - 1;
      }
    }

    if (res == 1e9)
      cout << "Infinity\n";
    else
      cout << res << "\n";
    
  }
}