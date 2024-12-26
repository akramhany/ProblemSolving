#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
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

bool solve(string &s, int x)
{
  string s1, s2;
  bool f = false, sec = false;
  if (x == 0)
  {
    s1 = "AB";
    s2 = "BA";
  }
  else
  {
    s1 = "BA";
    s2 = "AB";
  }

  for(int i = 0; i < s.size() - 1; i++)
  {
    string k = s.substr(i, 2);
    if (k == s1 && !f)
    {
      i++;
      f = true;
    }
    else if (k == s2 && f && !sec)
    {
      i++;
      sec = true;
      break;
    }
  }

  return f && sec;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n;
  cin >> n;

  ll ser = 0, dem = 0;
  deque<int> dq;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    dq.push_back(x);
  }

  int turn = 0;

  while (!dq.empty())
  {
    if (turn == 0)
    {
      if (dq.front() > dq.back())
      {
        ser += dq.front();
        dq.pop_front();
      }
      else
      {
        ser += dq.back();
        dq.pop_back();
      }
      turn = 1;
    }
    else
    {
      if (dq.front() > dq.back())
      {
        dem += dq.front();
        dq.pop_front();
      }
      else
      {
        dem += dq.back();
        dq.pop_back();
      }
      turn = 0;
    }
  }

  cout << ser << " " << dem << "\n";
}