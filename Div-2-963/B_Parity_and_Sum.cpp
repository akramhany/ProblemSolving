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
 
    vector<ll> v(n);
    ll max_odd = -1;
    for (auto & i : v)
    {
      cin >> i;
      if (i % 2 != 0 && i > max_odd)
        max_odd = i;
    }
 
    if (max_odd == -1)
    {
      cout << "0\n";
      continue;
    }
 
    sort(v.begin(), v.end());
    
    ll res = 0;
    int i = 0;

    while (i < v.size() && v[i] <= max_odd)
    {
      if (v[i] % 2 == 0)
      {
        res++;
        max_odd += v[i];
      }
      i++;
    }
 
    if (i < v.size())
      res += (v.size() - i) + 1;
 
    cout << res << "\n";
  }
}