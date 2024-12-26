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

int getNumOfPrimeFactors(vector<int> &v, int num)
{
  map<int, int> mp;

  while (v[num] != 0)
  {
    mp[v[num]] = true;
    num = num / v[num];
  }

  mp[num] = true;

  return mp.size();
}

bool isAlmostPrime(vector<int> &v, int num)
{
  if (getNumOfPrimeFactors(v, num) == 2)
    return true;
  return false;
}

int main()
{
  int n;
  cin >> n;

  vector<int> v;
  constructSieve(v, n);

  int res = 0;

  for (int i = 1; i <= n; i++)
  {
    if (isAlmostPrime(v, i))
      res++;
  }

  cout << res << endl;
}