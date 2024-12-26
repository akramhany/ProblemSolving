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


bool sortF(const pair<int, string> &p1, const pair<int, string> &p2)
{
  if (p1.first == p2.first) {
    // for (int i = 0; i < min(p1.second.length(), p2.second.length()); i++)
    // {
    //   if (p1.second[i] != p2.second[i])
    //     return p1.second[i] < p2.second[i];
    // }

    return p1.second >= p2.second;
  }
  return p1.first < p2.first;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  string myName;
  cin >> myName;

  int m;
  cin >> m;

  map<string, int> mp;

  while (m--)
  {
    string n1, t, n2;
    cin >> n1 >> t;
    
    if (t == "posted" || t == "commented")
    {
      string o;
      cin >> o;
      cin >> n2;    

      n2 = n2.substr(0, n2.length() - 2);
    }
    else
    {
      cin >> n2;    

      n2 = n2.substr(0, n2.length() - 2);
    }

    if (t == "posted")
    {
      if (n1 == myName)
        mp[n2] += 15;
      else if (n2 == myName)
        mp[n1] += 15;
      else
      {
        mp[n1] += 0;
        mp[n2] += 0;
      }
    }
    else if (t == "commented")
    {
      if (n1 == myName)
        mp[n2] += 10;
      else if (n2 == myName)
        mp[n1] += 10;
      else
      {
        mp[n1] += 0;
        mp[n2] += 0;
      }
    }
    else if (t == "likes")
    {
      if (n1 == myName)
        mp[n2] += 5;
      else if (n2 == myName)
        mp[n1] += 5;
      else
      {
        mp[n1] += 0;
        mp[n2] += 0;
      }
    }


    string temp;
    cin >> temp;
  }

    vector<pair<int, string>> v;

    for (auto & i : mp)
    {
      v.push_back(make_pair(i.second, i.first));
    }

    sort(v.begin(), v.end(), sortF);

  for (int i = v.size() - 1; i >= 0; i--)
  {
    if (v[i].second != myName)
      cout << v[i].second << "\n";
  }
}