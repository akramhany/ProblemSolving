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

int main()
{
  ll a, b, c;

  cin >> a >> b >> c;

  if (c == 0)
  {
    if (a == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

    return (0);
  }

  double x = (double)(b - a) / (double)(c);

  if (x >= 0 && x - (ll)x < 1e-9)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}