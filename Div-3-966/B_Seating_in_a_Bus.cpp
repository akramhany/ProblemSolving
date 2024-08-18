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

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto & i : v)
      cin >> i;

    vector<int> seats(n, 0);
    seats[v[0] - 1] = 1;

    bool isYes = true;

    for (int i = 1; i < n; i++)
    {
      int indx = v[i] - 1;
      if (indx == 0 && seats[indx + 1] == 0)
      {
        isYes = false;
        break;
      }
      else if (indx == n - 1 && seats[indx - 1] == 0)
      {
        isYes = false;
        break;
      }
      else if (seats[indx + 1] == 0 && seats[indx - 1] == 0)
      {
        isYes = false;
        break;
      }

      seats[indx] = 1;
    }

    if (isYes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}