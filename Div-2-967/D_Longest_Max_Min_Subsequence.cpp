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
    for (auto & i : v)
    {
      cin >> i;
      mp[i]++;
    }

    vector<int> res;
    int i = 0;
    set<int> s;
    while (i < n)
    {
      while (i < n && mp[v[i]] > 1)
      {
        s.insert(v[i]);
        
        mp[v[i]]--;
        i++;
      }

      if (mp[v[i]] == 0)
      {
        i++;
        continue;
      }

      while (!s.empty())
      {
        if ((res.size() + 1) % 2 == 0) //even
        {
          int val = *(s.begin());
          if (val < v[i])
          {
            res.push_back(val);
            mp[val] = 0;
          }
          else if (val > v[i])
          {
            mp[v[i]] = 0;
            break;
          }
          else
          {
            
          }
          s.erase(s.find(val));
        }
        else
        {
          int val = *(s.rbegin());
          if (val >= v[i])
          {
            res.push_back(val);
            mp[val] = 0;
          }
          else
          {
            mp[v[i]] = 0;
            break;
          }
          s.erase(s.find(val));
        }
      }

      res.push_back(v[i]);
      s.clear();
      i++;
    }

    cout << res.size() << "\n";
    for (auto & i : res)
      cout << i << " ";
    cout << "\n";
  }
}