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

ll isPrimeRetNum(ll n)
{
  if (n == 2)
    return n;
  else if (n < 2 || n % 2 == 0)
    return n;

  for (ll i = 3; i * i <= n; i += 2)
  {
    if (n % i == 0)
      return i;
  }

  return n;
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

  while (t--) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto & i : v)
      cin >> i;

    int max_ele_indx = 0, sec_max_indx = 0;
    int max_val = v[0];
    for (int i = 0; i < n; i++) {
      if (v[i] > max_val)
      {
        max_val = v[i];
        max_ele_indx = i;
      }
    }

    v[max_ele_indx] *= -1;
    max_val = v[0];
    for (int i = 0; i < n; i++) {
      if (v[i] > max_val)
      {
        max_val = v[i];
        sec_max_indx = i;
      }
    }

    v[max_ele_indx] *= -1;

    for (int i = 0; i < n; i++) {
      if (i != max_ele_indx)
        cout << v[i] - v[max_ele_indx] << " ";
      else
        cout << v[i] - v[sec_max_indx] << " ";
    }

    cout << "\n";

  }
}