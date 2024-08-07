#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <cstring>

#define ll long long
#define llu unsigned long long
#define lp(x, y) for (int i = x; i < y; i++)

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

bool sortF(pair<const string, int> a, pair<const string, int> b)
{
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  map<string, string> mp;

  while (m--)
  {
    string a, b;
    cin >> a >> b;
    mp[a] = b;
  }

  while (n--)
  {
    string s;
    cin >> s;

    if (s.length() <= mp[s].length())
      cout << s << " ";
    else
      cout << mp[s] << " ";
  }

  cout << "\n";
}