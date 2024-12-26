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

  int t;
  cin >> t;

  deque<int> dq;

  while (t--)
  {
    string op;
    cin >> op;

    if (op == "toFront")
    {
      string n;
      cin >> n;
      dq.push_front(stoi(n));
    }
    else if (op == "push_back")
    {
      string n;
      cin >> n;
      dq.push_back(stoi(n));
    }
    else if (op == "front")
    {
      if (dq.empty())
        cout << "No job for Ada?\n";
      else
      {
        cout << dq.front() << "\n";
        dq.pop_front();
      }
    }
    else if (op == "back")
    {
      if (dq.empty())
        cout << "No job for Ada?\n";
      else
      {
        cout << dq.back() << "\n";
        dq.pop_back();
      }
    }
    else if (op == "reverse")
    {
      reverse(dq.begin(), dq.end());
    }
  }
}