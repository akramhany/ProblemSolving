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

  int q;
  cin >> q;

  deque<int> dq;

  while (q--)
  {
    string op;
    cin >> op;

    if (op == "push_front")
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
      cout << dq.front() << endl;
    }
    else if (op == "back")
    {
      cout << dq.back() << endl;
    }
    else if (op == "pop_front")
    {
      dq.pop_front();
    }
    else if (op == "pop_back")
    {
      dq.pop_back();
    }
    else if (op == "print")
    {
      string n;
      cin >> n;

      int indx = stoi(n);
      cout << dq[indx - 1] << endl;
    }
  }
}