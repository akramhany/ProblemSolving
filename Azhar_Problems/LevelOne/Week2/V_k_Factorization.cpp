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

void sieve(vector<int> &v, int n)
{
  v[0] = v[1] = 0;
  int i = 2;

  while (i * i <= n)
  {
    if (v[i] == 0)
    {
      int k = i * i;
      while (k <= n)
      {
        if (v[k] == 0)
          v[k] = i;
        k += i;
      }
    }
    i++;
  }
}

int main()
{
  int n, k;
  cin >> n >> k;

  k--;

  vector<int> v(n + 1, 0);
  sieve(v, n);

  vector<int> result;

  while (n > 0)
  {
    if (k == 0)
    {
      result.push_back(n);
      for (auto &i : result)
        cout << i << " ";
      return (0);
    }

    if (v[n] == 0)
    {
      cout << "-1\n";
      return (0);
    }
    result.push_back(v[n]);
    n = n / v[n];
    k--;
  }
}