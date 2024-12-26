
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

  while (t--)
  {
    int n;
    cin >> n;

    map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      mp[v[i]] = i;
    }

    vector<bool> aval(n, true);
    for (int i = 1; i <= n; i++)
    {
      int indx = mp[i] - 1;
      while (indx >= 0 && aval[indx] && v[indx] > v[indx + 1]) {
        mp[v[indx]] = indx + 1;
        mp[v[indx + 1]] = indx;
        swap(v[indx], v[indx + 1]);
        aval[indx] = false;
        indx--;
      }
    }

    for (auto & i : v)
      cout << i << " ";

    cout << "\n";
  }
}