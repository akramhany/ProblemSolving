#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

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

void solve(string s)
{
  for (int i = 0; i < s.length(); i++)
  {
    for (int j = 0; j < s.length(); j++)
    {
      for (int k = 0; k < s.length(); k++)
      {
        string num = "";
        num += s[i];
        if (j != i)
          num = num + s[j];
        if (k != i && k != j)
          num = num + s[k];
        int n = stoi(num);
        if (n % 8 == 0)
        {
          cout << "YES" << endl;
          cout << n << endl;
          return;
        }
      }
    }
  }

  cout << "NO" << endl;
}

int main()
{
  string s;
  cin >> s;

  solve(s);
}