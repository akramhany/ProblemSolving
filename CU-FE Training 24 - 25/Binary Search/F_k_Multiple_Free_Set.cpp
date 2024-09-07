#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
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

int calculate(char dir, char c)
{
  if (c == dir)
    return 0;

  if (dir == 'L')
  {
    if (c == 'R')
      return 2;
    else
      return 1;
  }
  else if (dir == 'R')
  {
    if (c == 'L')
      return 2;
    else
      return 1;
  }
  else if (dir == 'U')
  {
    if (c == 'D')
      return 2;
    else
      return 1;
  }
  else
  {
    if (c == 'U')
      return 2;
    else
      return 1;
  }
}

int bs(vector<ll> &v, ll val)
{
  ll st = 0, end = v.size() - 1;
  ll res = -1;
  while (st < end)
  {
    ll mid = (st + end) / 2;
    if (v[mid] > val) {
      end = mid;
    }
    else if (v[mid] < val) {
      st = mid + 1;
    }
    else {
      return mid;
    }
  }

  if (v[st] > val)
    return st - 1;
  return st;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (auto & i : v)
    cin >> i;

  sort(v.begin(), v.end());
  set<int> s;
  vector<int> result;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (s.count(v[i]))
      continue;

    if (v[i] % k == 0) {
      s.insert(v[i] / k);
    }
    result.push_back(v[i]); 
  }

  cout << result.size() << "\n";
}