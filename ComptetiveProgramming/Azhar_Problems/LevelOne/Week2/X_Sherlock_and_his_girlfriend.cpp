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
  llu i = 2;

  while (i * i <= n)
  {
    if (v[i] == 0)
    {
      llu k = i * i;
      while (k <= n)
      {
        v[k] = 1;
        k += i;
      }
    }
    i++;
  }
}

int main()
{
  int n;
  cin >> n;
  n++;

  vector<int> v(100005, 0);
  sieve(v, 100005);

  if (n - 1 == 1 || n - 1 == 2)
    cout << "1\n";
  else
    cout << "2\n";

  for (int i = 2; i <= n; i++)
  {
    if (v[i] == 0)
      cout << "1" << " ";
    else
      cout << "2" << " ";
  }

  cout << "\n";
}