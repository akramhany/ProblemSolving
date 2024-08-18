#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <cstring>

#define ll long long
#define llu unsigned long long
#define lp(x, y) for (int i = x; i < y; i++)

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

  int n, k;
  cin >> n >> k;

  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    mp[x] = i;
  }

  if (mp.size() < k)
  {
    cout << "NO\n";
  }
  else
  {
    cout << "YES\n";
    for (auto & i : mp)
    {
      if (k-- == 0)
        break;
      cout << i.second + 1 << " ";
    }
    cout << "\n";
  }
}