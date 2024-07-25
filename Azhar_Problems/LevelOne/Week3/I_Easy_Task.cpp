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

  int n, m;
  cin >> n >> m;

  deque<int> dq;

  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    dq.push_back(k);
  }

  bool isReversed = false;

  while (m--)
  {
    int op;
    cin >> op;

    if (op == 1)
    {
      isReversed = !isReversed;
    }
    else
    {
      int d, val;
      cin >> d >> val;

      if (d == 1 && !isReversed)
        dq.push_front(val);
      else if (d == 1 && isReversed)
        dq.push_back(val);
      else if (d == 2 && !isReversed)
        dq.push_back(val);
      else if (d == 2 && isReversed)
        dq.push_front(val);
    }
  }

  cout << dq.size() << "\n";
  if (isReversed)
    reverse(dq.begin(), dq.end());
  for (auto &i : dq)
    cout << i << " ";
  cout << "\n";
}