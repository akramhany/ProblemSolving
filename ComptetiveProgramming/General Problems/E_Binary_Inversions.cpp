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

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto & i : v)
      cin >> i;

    vector<int> z(n, 0);
    vector<int> o(n, 0);

    for (int i = 0; i < n; i++) {
      if (i != 0) {
        o[i] += o[i - 1];
      }
      if (v[i] == 1) {
        o[i]++;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if (i != n - 1) {
        z[i] += z[i + 1];
      }
      if (v[i] == 0) {
        z[i]++;
      }
    }

    ll max_inv = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == 1)
        max_inv += z[i];
    }


    ll inv = max_inv;
    for (int i = 0; i < n; i++) {
      ll cur_inv = inv;
      if (v[i] == 1) {
        cur_inv -= z[i];
        cur_inv += o[i] - 1;
      } else {
        cur_inv -= o[i];
        cur_inv += z[i] - 1;
      }

      max_inv = max(max_inv, cur_inv);
    }

    cout << max_inv << "\n";

  }
}