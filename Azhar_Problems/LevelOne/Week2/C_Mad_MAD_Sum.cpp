#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

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

ll solve(vector<ll> &v)
{
  ll n = v.size();
  ll totSum = 0;
  map<ll, ll> m;
  ll maxI = 0;

  for (ll i = 0; i < n; i++)
  {
    totSum += v[i];
    if (m.count(v[i]) == 0)
      m[v[i]] = 1;
    else
      m[v[i]]++;

    ll x = m[v[i]];
    if (x >= 2 && v[i] > maxI)
      maxI = v[i];
    v[i] = maxI;
  }

  return totSum;
}

int main()
{
  int t;
  cin >> t;

  int k = t;

  while (t--)
  {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v)
      cin >> i;

    ll totSum = solve(v);
    totSum += solve(v);

    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
      if (m.count(v[i]) == 0)
        m[v[i]] = 1;
      else
        m[v[i]]++;
    }

    for (ll i = n - 1; i > 0; i--)
    {
      if (m[v[i]] > 1)
      {
        totSum += (v[i] * (ll)abs(i - n));
      }
      else
      {
        totSum += v[i];
      }
    }

    cout << totSum << endl;
  }
}