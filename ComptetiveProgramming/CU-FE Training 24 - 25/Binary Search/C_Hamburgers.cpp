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

  string s;
  cin >> s;

  ll ingreds[3] = {0};
  for (auto & i : s)
    if (i == 'B')
      ingreds[0]++;
    else if (i == 'S')
      ingreds[1]++;
    else
      ingreds[2]++;
  
  ll aval[3];
  ll prices[3];

  for (int i = 0; i < 3; i++)
    cin >> aval[i];
  for (int i = 0; i < 3; i++)
    cin >> prices[i];

  ll m;
  cin >> m;

  ll res = -1;

  ll st = 0, end = 1e16;
  while (st < end)
  {
    ll mid = (st + end) / 2;
    ll money = m;
    int ind = 0;
    for (int i = 0; i < 3; i++)
    {
      if (ingreds[i] == 0)
        continue;
      ll x = aval[i] / ingreds[i];
      if (x < mid)
      {
        ll midReq = mid * ingreds[i];
        ll totAval = aval[i] + money / prices[i];
        if (totAval < midReq)
        {
          ind = -1;
          break;
        }
        if (aval[i] >= midReq)
          continue;
        midReq -= aval[i];
        money = ((money / prices[i]) - midReq) * prices[i] + money % prices[i];
      }
    }

    if (ind == -1)
    {
      end = mid;
      continue;
    }

    res = max(res, mid);
    if (money != 0)
    {
      st = mid + 1;
    }
    else
      break;
  }

  cout << res << "\n";
}