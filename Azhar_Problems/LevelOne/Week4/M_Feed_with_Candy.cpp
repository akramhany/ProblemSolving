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

int solve(vector<pair<int, int>> &v0, vector<pair<int, int>> &v1, int x, int type)
{
  priority_queue<pair<int, int>> pq0;
  priority_queue<pair<int, int>> pq1;

  int counter0 = 0, counter1 = 0;
  while (counter0 < v0.size() && v0[counter0].first <= x)
  {
    pq0.push(make_pair(v0[counter0].second, v0[counter0].first));
    counter0++;
  }
  while (counter1 < v1.size() && v1[counter1].first <= x)
  {
    pq1.push(make_pair(v1[counter1].second, v1[counter1].first));
    counter1++;
  }

  int res = 0;

  while(counter0 < v0.size() || counter1 < v1.size() || (!pq1.empty() || !pq0.empty()))
  {
    if (type == 0)
    {
      if (!pq0.empty())
      {
        x += pq0.top().first;
        pq0.pop();
        res++;
      }
      else
        return res;
      type = 1;
    }
    else
    {
      if (!pq1.empty())
      {
        x += pq1.top().first;
        pq1.pop();
        res++;
      }
      else
        return res;
      type = 0;
    }

    while (counter0 < v0.size() && v0[counter0].first <= x)
    {
      pq0.push(make_pair(v0[counter0].second, v0[counter0].first));
      counter0++;
    }
    while (counter1 < v1.size() && v1[counter1].first <= x)
    {
      pq1.push(make_pair(v1[counter1].second, v1[counter1].first));
      counter1++;
    }
  }

  return res;
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> v0;
  vector<pair<int, int>> v1;

  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0)
    {
      v0.push_back(make_pair(b, c));
    }
    else
    {
      v1.push_back(make_pair(b, c));
    }
  }

  sort(v0.begin(), v0.end());
  sort(v1.begin(), v1.end());

  int res0 = solve(v0, v1, x, 0);
  int res1 = solve(v0, v1, x, 1);


  cout << max(res0, res1) << "\n";
}