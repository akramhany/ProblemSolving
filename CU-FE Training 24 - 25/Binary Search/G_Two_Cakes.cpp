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

  int n;
  cin >> n;

  vector<vector<int>> v(n);
  for (int i = 0; i < n * 2; i++)
  {
    int x;
    cin >> x;
    x--;
    v[x].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    if (v[i][0] >= v[i][1])
      swap(v[i][0], v[i][1]);
  }
  
  ll res = 0;

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      res += (v[0][0] + v[0][1]);
    }
    else {
      res += abs(v[i][0] - v[i - 1][0]);
      res += abs(v[i][1] - v[i - 1][1]);
    }
  }

  cout << res << "\n";
}