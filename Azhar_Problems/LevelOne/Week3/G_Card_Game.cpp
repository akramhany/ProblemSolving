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

  string m, a, r;
  cin >> m >> a >> r;

  queue<char> mS;
  queue<char> mA;
  queue<char> mR;

  for (int i = 0; i < m.length(); i++)
    mS.push(m[i]);
  for (int i = 0; i < a.length(); i++)
    mA.push(a[i]);
  for (int i = 0; i < r.length(); i++)
    mR.push(r[i]);

  char currentTurn = 'm';

  while (true)
  {
    if (currentTurn == 'm')
    {
      if (mS.empty())
      {
        cout << "M\n";
        return (0);
      }

      currentTurn = mS.front();
      mS.pop();
    }
    else if (currentTurn == 'a')
    {
      if (mA.empty())
      {
        cout << "A\n";
        return (0);
      }
      currentTurn = mA.front();
      mA.pop();
    }
    else if (currentTurn == 'r')
    {
      if (mR.empty())
      {
        cout << "R\n";
        return (0);
      }
      currentTurn = mR.front();
      mR.pop();
    }
  }
}