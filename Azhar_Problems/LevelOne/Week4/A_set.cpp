#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
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

  int q;
  cin >> q;

  set<int> st;

  while (q--)
  {
    string s;
    int n;
    cin >> s >> n;

    if (s == "insert")
      st.insert(n);
    else if (s == "find")
    {
      if (st.find(n) != st.end())
        cout << "found\n";
      else
        cout << "not found\n";
    }
    else if (s == "lower_bound")
    {
      auto it = st.lower_bound(n);
      if (it != st.end())
        cout << *it << "\n";
      else
        cout << "-1\n";
    }
    else if (s == "upper_bound")
    {
      auto it = st.upper_bound(n);
      if (it != st.end())
        cout << *it << "\n";
      else
        cout << "-1\n";
    }
  }
}