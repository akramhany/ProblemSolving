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

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  ll n, k;

  cin >> n >> k;

  vector<ll> req(n);
  for (auto & i : req)
    cin >> i;

  vector<ll> avail(n);
  for (auto & i : avail)
    cin >> i;

  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<>> pq;
  for (ll i = 0; i < n; i++)
  {
    pq.push(make_pair(avail[i] / req[i], make_pair(req[i], avail[i])));
  }

  ll minV = avail[0] / req[0];
  while (k > 0 && !pq.empty())
  {
    pair<ll, int> p = pq.top().second;
    pair<ll, pair<int, int>> pp = pq.top();
    pq.pop();
    ll x = p.first - p.second % p.first;
    if (x <= k)
    {
      k -= x;
      pp.first++;
      pp.second.second += x;
      pq.push(pp);
    }
    else
      break;

    minV = min(pp.first, pq.top().first);
  }

  cout << minV << "\n";
}