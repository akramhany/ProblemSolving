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

ll bs(vector<ll> &v, ll val)
{
  ll left = 0, right = v.size() - 1;

  while (right - left > 1)
  {
    ll mid = (left + right) / 2;

    if (v[mid] == val)
      return mid;
    else if (v[mid] > val)
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
  }

  if (val >= v[right])
    return right;
  return left;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    ll sideLen = (n * 2) + 1;

    ll res = sideLen * 2 + (sideLen - 2) * 2;

    ll leftP = n, rightP = n;
    double x = sqrt(pow(leftP, 2) + pow(rightP, 2));
    bool first = true;

    while (x >= n + 1)
    {
      cout << "Left: " << leftP << ", x = " << x << endl;
      leftP--;
      if (first)
      {
        first = false;
        res -= 4;
      }
      else
        res -= 8;
      x = sqrt(pow(leftP, 2) + pow(rightP, 2));
    }

    cout << res << "\n";
  }
}