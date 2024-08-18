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

    vector<int> v(n);
    map<int, vector<int>> vMp;
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      vMp[v[i]].push_back(i);
    }

    int m;
    cin >> m;

    while (m--)
    {
      map<char, vector<int>> sMp;
      string s;
      cin >> s;

      if (s.size() != v.size())
      {
        cout << "NO\n";
        continue;;
      }

      for (int i = 0; i < s.size(); i++)
      {
        sMp[s[i]].push_back(i);
      }

      if (vMp.size() != sMp.size())
      {
        cout << "NO\n";
        continue;;
      }

      bool isYes = true;

      for (auto & i : vMp)
      {
        char x = s[i.second[0]];
        
        for (int j = 0; j < i.second.size(); j++)
        {
          if (s[i.second[j]] != x)
          {
            isYes = false;
            break;
          }
        }
        if (!isYes)
          break;
      }

      if (!isYes)
      {
        cout << "NO\n";
        continue;;
      }

      for (auto & i : sMp)
      {
        int x = v[i.second[0]];
        
        for (int j = 0; j < i.second.size(); j++)
        {
          if (v[i.second[j]] != x)
          {
            isYes = false;
            break;
          }
        }
        if (!isYes)
          break;
      }

      if (!isYes)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
}