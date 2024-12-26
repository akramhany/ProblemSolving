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
 
  int maxScore = -1e9;
 
  map<int, int> temp;
  map<string, pair<int, int>> mp;
  map<int, int> temptemp;
 
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
 
    int score;
    cin >> score;
 
    if (score < 0)
    {
      if (temp.count(mp[s].first) != 0)
      {
        int x = temp[mp[s].first];
        if (x > 1)
          temp[mp[s].first]--;
        else if (x == 1)
        {
          temp.erase(temp.find(mp[s].first));
        }
 
        temptemp[mp[s].first]--;
      }
    }
 
    mp[s].first += score;
    temp[mp[s].first]++;
    temptemp[mp[s].first]++;

    mp[s].second = temptemp[mp[s].first];
  }
 
  auto it = temp.rbegin();
  string k;
  int order = -1e9;
 
  for (auto & i : mp)
  {
    if (i.second.first == it->first)
    {
      if (i.second.second > order)
      {
        order = i.second.second;
        k = i.first;
      }
    }
  }
 
  cout << k << "\n";
}