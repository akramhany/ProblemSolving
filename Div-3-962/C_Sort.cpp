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

int arr1[200005][26];
int arr2[200005][26];

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n, q;
    cin >> n >> q;

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < 26; i++)
    {
      arr1[0][i] = 0;
      arr2[0][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 26; j++)
      {
        arr1[i + 1][j] = arr1[i][j];
        if (j == (s1[i] - 'a'))
          arr1[i + 1][j]++;

        arr2[i + 1][j] = arr2[i][j];
        if (j == (s2[i] - 'a'))
          arr2[i + 1][j]++;
      }
    }

    while (q--)
    {
      int l, r;
      cin >> l >> r;

      int diffChars = 0;
      for (int i = 0; i < 26; i++)
      {
        int x = arr1[r][i] - arr1[l - 1][i];
        int y = arr2[r][i] - arr2[l - 1][i];

        diffChars += (x - y) > 0 ? (x - y) : 0;
      }

      cout << diffChars << "\n";
    }
  }
}