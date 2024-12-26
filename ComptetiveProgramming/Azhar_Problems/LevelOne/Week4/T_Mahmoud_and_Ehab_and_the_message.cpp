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

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, k, m;
  cin >> n >> k >> m;

  vector<string> v(n);
  for (auto & i : v)
    cin >> i;

  vector<int> val(n);
  for (auto & i : val)
    cin >> i;

  map<string, int> mp;
  vector<vector<pair<int, int>>> groups(k);

  for (int i = 0; i < k; i++)
  {
    int num;
    cin >> num;

    for (int j = 0; j < num; j++)
    {
      int x;
      cin >> x;

      mp[v[x - 1]] = i;
      groups[i].push_back(make_pair(val[x - 1], x));
    }

    sort(groups[i].begin(), groups[i].end());
  }

  ll res = 0;
  for (int i = 0; i < m; i++)
  {
    string s;
    cin >> s;

    int group = mp[s];
    int minV = groups[group][0].first;
    
    res += minV;
  }

  cout << res << "\n";
}