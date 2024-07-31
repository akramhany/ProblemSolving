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
    int n;
    cin >> n;

    vector<ll> v(n + 2);
    for (int i = 1; i <= n; i++)
      cin >> v[i];

    v[n + 1] = v[0] = -1;

    stack<ll> st;

    ll maxH = 0;

    for (ll i = 0; i <= n + 1; i++)
    {
      while (!st.empty() && v[i] < v[st.top()])
      {
        ll val = v[st.top()];
        st.pop();
        ll h = ((i - 1) - st.top()) * val;
        maxH = h > maxH ? h : maxH;
      }
      st.push(i);
    }

    cout << maxH << "\n";
  }
}