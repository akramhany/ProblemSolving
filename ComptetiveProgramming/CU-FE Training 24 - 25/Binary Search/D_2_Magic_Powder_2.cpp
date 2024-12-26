#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
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

  ll n, k;

  cin >> n >> k;

  vector<ll> req(n);
  for (auto & i : req)
    cin >> i;

  vector<ll> avail(n);
  for (auto & i : avail)
    cin >> i;

  ll res = -1;

  ll st = 0, end = 1e18;
  while (st < end)
  {
    ll mid = (st + end) / 2;
    ll mPow = k;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
      ll x = avail[i] / req[i];
      if (x < mid)
      {
        ll allAv = avail[i] + mPow;
        if (allAv / req[i] < mid)
        {
          ind = -1; //make it smaller.
          break;
        }
        mPow = abs(mid * req[i] - allAv);
      }
    }

    if (ind == -1)
    {
      end = mid;
      continue;
    }

    res = max(res, mid);
    if (mPow != 0)
    {
      st = mid + 1;
    }
    else
      break;
  }

  cout << res << "\n";
}