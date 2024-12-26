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

bool beginsWith(string a, string b)
{
  if (a > b)
    return false;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
      return false;
  }

  return true;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n, m, k;
    cin >> n >> m >> k;


    k--;

    vector<int> v(n);
    for (auto & i : v)
      cin >> i;

    if (m == 1)
    {
      cout << v[k] << "\n";
      continue;
    }
    priority_queue<int> tempPQ;
    for (int i = 0; i <= max(k, m - 1); i++)
    {
      tempPQ.push(v[i]);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = max(0, k - m + 1); i <= max(k, m - 1); i++)
    {
      pq.push(tempPQ.top());
      tempPQ.pop();
    }

    for (int i = max(k, m - 1) + 1; i <= min(m + k - 1, n - 1); i++)
    {
      pq.pop();
      pq.push(v[i]);
    }

    int x = n - k;
    while (m - x > 0)
    {
      pq.pop();
      x++;
    }

    cout << pq.top() << "\n";
  }
}