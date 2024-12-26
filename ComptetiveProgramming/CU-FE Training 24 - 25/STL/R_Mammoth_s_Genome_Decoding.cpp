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

  int n;
  cin >> n;

  string s;
  cin >> s;

  map<char, int> mp;
  mp['A'] = 0;
  mp['C'] = 0;
  mp['G'] = 0;
  mp['T'] = 0;

  int qmNum = 0;
  int maxChar = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '?') 
      qmNum++;
    else
    {
      mp[s[i]]++;
      if (mp[s[i]] > maxChar)
        maxChar = mp[s[i]];
    }
  }

  for (auto & i : mp)
  {
    qmNum -= (maxChar - i.second);
  }

  if (qmNum < 0 || qmNum % 4 != 0)
  {
    cout << "===\n";
    return (0);
  }

  char arr[] = {'A', 'C', 'G', 'T'};
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?')
    {
      if (mp['A'] < maxChar)
      {
        s[i] = 'A';
        mp['A']++;
      }
      else if (mp['C'] < maxChar)
      {
        s[i] = 'C';
        mp['C']++;
      }
      else if (mp['G'] < maxChar)
      {
        s[i] = 'G';
        mp['G']++;
      }
      else if (mp['T'] < maxChar)
      {
        s[i] = 'T';
        mp['T']++;
      }
      else
      {
        s[i] = arr[j];
        j = (j + 1) % 4;
      }
    }

  }
  cout << s << "\n";
}