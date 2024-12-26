#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

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

void getDivisors(llu n, vector<llu> &v)
{
  v.push_back(1);

  if (n != 1)
    v.push_back(n);

  for (llu i = 2; i * i <= n; i++)
  {
    if (i * i == n)
      v.push_back(i);
    else if (n % i == 0)
    {
      v.push_back(i);
      v.push_back(n / i);
    }
  }

  sort(v.begin(), v.end());
}

int main()
{
  llu n, k;
  cin >> n >> k;

  vector<llu> v;
  getDivisors(n, v);

  if (k > v.size())
    printf("-1\n");
  else
    printf("%llu\n", v[k - 1]);
}