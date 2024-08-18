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

  string home, away;
  cin >> home >> away;

  int n;
  cin >> n;

  map<int, int> homeM, awayM;

  for (int i = 0; i < n; i++)
  {
    int time;
    cin >> time;

    char team;
    cin >> team;

    int num;
    cin >> num;

    char card;
    cin >> card;

    if (team == 'h')
    {
      if (card == 'y')
      {
        if (homeM.count(num) == 1 && homeM[num] == 1)
        {
          homeM[num]++;
          cout << home << " " << num << " " << time << "\n";
        }
        else if (homeM.count(num) == 0)
        {
          homeM[num] = 1;
        }
      }
      else
      {
        if (homeM.count(num) == 0 || homeM[num] == 1)
          cout << home << " " << num << " " << time << "\n";
        homeM[num] = 2;
      }
    }
    else if (team == 'a')
    {
      if (card == 'y')
      {
        if (awayM.count(num) == 1 && awayM[num] == 1)
        {
          awayM[num]++;
          cout << away << " " << num << " " << time << "\n";
        }
        else if (awayM.count(num) == 0)
        {
          awayM[num] = 1;
        }
      }
      else
      {
        if (awayM.count(num) == 0 || awayM[num] == 1)
          cout << away << " " << num << " " << time << "\n";
        awayM[num] = 2;
      }
    }
  }
}