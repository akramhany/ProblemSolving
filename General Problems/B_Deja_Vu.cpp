#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <cstring>
#include <stack>
#include <queue>

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

  ll arr[31] = {0};

  for (int i = 0; i < 31; i++)
    arr[i] = pow(2, i);

  while (t--)
  {
    int n, q;
    cin >> n >> q;

    vector<ll> v(n);

    for (auto &i : v)
      cin >> i;

    int minV = 1e9;

    for (int i = 0; i < q; i++)
    {
      int x;
      cin >> x;

      if (x < minV)
      {
        minV = x;
        for (int i = 0; i < n; i++)
        {
          if (v[i] % arr[minV] == 0)
            v[i] += arr[minV - 1];
        }
      }
    }

    for (auto &i : v)
      cout << i << " ";

    cout << "\n";
  }
}