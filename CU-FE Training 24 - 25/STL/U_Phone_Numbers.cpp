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

bool beginsWith(string a, string b)
{
  if (a > b)
    return false;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
      return false;
  }

  return true;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n;
  cin >> n;

  map<string, vector<string>> mp;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    int num;
    cin >> num;

    for (int j = 0; j < num; j++)
    {
      string k;
      cin >> k;
      reverse(k.begin(), k.end());

      mp[s].push_back(k);
    }
    sort(mp[s].begin(), mp[s].end());
  }

  cout << mp.size() << "\n";

  for (auto & i : mp)
  {
    vector<string> res;
    for (int j = 0; j < i.second.size() - 1; j++)
    {
      if (!beginsWith(i.second[j], i.second[j + 1]))
      {
        res.push_back(i.second[j]);
      }
    }
    res.push_back(i.second[i.second.size() - 1]);
    cout << i.first << " " << res.size() << " ";
    for (auto & st : res)
    {
      reverse(st.begin(), st.end());
      cout << st << " ";
    }
    cout << "\n";
  }
}