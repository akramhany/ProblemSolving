#include <iostream>
#include <math.h>
#include <vector>
#include <map>

#define ll long long

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

void constructSieve(vector<int> &v, int n)
{
  v.resize(n + 1, 0);
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
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int min_cost = 0;
  if (a * m > b)
  {
    min_cost += ((n / m) * b);
    n = n % m;
    if (b < a * n)
      min_cost += (b);
    else
      min_cost += (a * n);
  }
  else
  {
    min_cost += (n * a);
  }

  cout << min_cost << endl;
}