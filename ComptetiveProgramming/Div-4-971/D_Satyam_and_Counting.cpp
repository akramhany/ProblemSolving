
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
#define pii pair<int , int>
#define lp(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vpi vector<pii>
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e4+5
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;
#define oo 1e18

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

    set<pair<int, int>> s0;
    set<pair<int, int>> s1;

    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;

      if (y == 0)
      {
        s0.insert(make_pair(x, y));
      }
      else
      {
        s1.insert(make_pair(x, y));
      }
    }

    if (s1.size() == 0 || s0.size() == 0)
    {
      cout << "0\n";
      continue;
    }

    ll res = 0;
    for (auto & p0 : s0)
    {
      pair<int, int> p1 = make_pair(p0.first, 1);
      if (s1.count(p1) == 1)
      {
        res += s0.size() - 1;
      }
    }
    
    for (auto & p1 : s1)
    {
      pair<int, int> p0 = make_pair(p1.first, 0);
      if (s0.count(p0) == 1)
      {
        res += s1.size() - 1;
      }
    }

    auto it = s0.begin();
    it++;
    for (; it != s0.end(); it++)
    {
      it--;
      auto itP = it++;
      it++;
      auto itT = it--;

      if (it->first - itP->first == 2)
      {
        int xx = (it->first + itP->first) / 2;
        if (s1.count(make_pair(xx, 1)) == 1)
          res++;
      }
      else if (itT != s0.end() && (itT->first - itP->first) == 2)
      {
        int xx = (itT->first + itP->first) / 2;
        if (s1.count(make_pair(xx, 1)) == 1)
          res++;
      }
    }

    it = s1.begin();
    it++;
    for (; it != s1.end(); it++)
    {
      it--;
      auto itP = it++;
      it++;
      auto itT = it--;

      if (it->first - itP->first == 2)
      {
        int xx = (it->first + itP->first) / 2;
        if (s0.count(make_pair(xx, 0)) == 1)
          res++;
      }
      else if (itT != s1.end() && (itT->first - itP->first) == 2)
      {
        int xx = (itT->first + itP->first) / 2;
        if (s0.count(make_pair(xx, 0)) == 1)
          res++;
      }
    }

    cout << res << "\n";
  }
}