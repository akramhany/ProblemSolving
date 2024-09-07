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

int calculate(char dir, char c)
{
  if (c == dir)
    return 0;

  if (dir == 'L')
  {
    if (c == 'R')
      return 2;
    else
      return 1;
  }
  else if (dir == 'R')
  {
    if (c == 'L')
      return 2;
    else
      return 1;
  }
  else if (dir == 'U')
  {
    if (c == 'D')
      return 2;
    else
      return 1;
  }
  else
  {
    if (c == 'U')
      return 2;
    else
      return 1;
  }
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n;
  cin >> n;

  string s;
  cin >> s;

  ll targetX, targetY;
  cin >> targetX >> targetY;

  if ((abs(targetX) + abs(targetY) > s.size()) || ((targetX + targetY) % 2 != s.size() % 2))
  {
    cout << "-1\n";
    return(0);
  }

  ll initX = 0, initY = 0;
  for (auto & i : s)
  {
    if (i == 'R')
      initX++;
    else if (i == 'L')
      initX--;
    else if (i == 'U')
      initY++;
    else if (i == 'D')
      initY--;
  }

  ll reqMovesX = abs(targetX - initX), reqMovesY = abs(targetY - initY);

  char dirX, dirY;
  if (targetX > initX)
    dirX = 'R';
  else if (targetX < initX)
    dirX = 'L';
  else
    dirX = '.';
  if (targetY > initY)
    dirY = 'U';
  else if (targetY < initY)
    dirY = 'D';
  else
    dirY = '.';

  ll res = -1;

  ll st = 0, end = n;
  while (st < end)
  {
    ll segLen = (st + end) / 2;
    ll countOfFree = 0, minCountOfFree = -1;
    ll reqMoves = reqMovesX + reqMovesY;

    int i = 0;
    
    while (i < segLen)
    {
      if (s[i] != dirX && s[i] != dirY)
      {
        countOfFree++;
      }      
      i++;
    }

    if (countOfFree >= reqMoves && countOfFree % 2 == 0)
    {
      if (segLen < res)
        res = segLen;
    }

    int j = 0;
    while (i < n)
    {
      if (s[j] != dirX && s[j] != dirY)
        countOfFree--;
      if (s[i] != dirX && s[i] != dirY)
        countOfFree++;

      if (countOfFree >= reqMoves && countOfFree % 2 == 0)
      {
        if (countOfFree < minCountOfFree || minCountOfFree == -1)
          minCountOfFree = countOfFree;
        if (segLen < res)
          res = segLen;
      }
      i++, j++;
    }

    if (minCountOfFree)
    {
      st = segLen + 1;
    }
    else
    {
      if (res == -1 || segLen < res)
      {
        res = segLen;
      }
      end = segLen;
    }
  }

  cout << res << "\n";
}