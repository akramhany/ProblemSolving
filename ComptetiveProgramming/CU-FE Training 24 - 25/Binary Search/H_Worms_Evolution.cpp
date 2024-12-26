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

int bs(vector<pair<int, int>> &v, int val) {
  int st = 0, end = v.size() - 1;
  while (st < end) {
    int mid = (st + end) / 2;
    if (v[mid].first == val)
      return mid;
    else if (v[mid].first > val)
      end = mid;
    else
      st = mid + 1;
  }

  if (v[st].first == val)
    return st;
  return -1;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<int, int>> v(n);
  int counter = 0;
  for (auto & i : v)
  {
    cin >> i.first;
    i.second = counter++;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int indx = bs(v, v[i].first + v[j].first);
      if (indx != -1) {
        cout << v[indx].second + 1 << " " << v[i].second + 1 << " " << v[j].second + 1 << "\n";
        return (0);
      }
    }
  }

  cout << "-1\n";
}