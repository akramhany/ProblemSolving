#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <cstring>
#include <stack>
#include <queue>

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

  string s;

  while (cin >> s)
  {
    vector<vector<char>> mQ;
    int qIndx = 0;

    mQ.push_back(vector<char>());

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '[')
      {
        mQ.push_back(vector<char>());
        qIndx = mQ.size() - 1;
      }
      else if (s[i] == ']')
        qIndx = 0;
      else
      {
        mQ[qIndx].push_back(s[i]);
      }
    }

    for (int i = mQ.size() - 1; i >= 0; --i)
    {
      for (auto &ch : mQ[i])
        cout << ch;
    }

    cout << "\n";
  }
}