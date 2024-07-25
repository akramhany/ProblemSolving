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

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      dq.push_back(k);
      pq.push(k);
    }

    int count = 1;

    while (dq[m] < pq.top())
    {
      if (dq.front() < pq.top())
      {
        dq.push_back(dq.front());
        dq.pop_front();
        if (m == 0)
          m = dq.size() - 1;
        else
          m--;
      }
      else
      {
        dq.pop_front();
        pq.pop();
        count++;
        m--;
      }
    }

    int j = 0;
    while (j < m)
    {
      if (dq[j] == dq[m])
        count++;
      j++;
    }

    cout << count << "\n";
  }
}