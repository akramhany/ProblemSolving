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
  bool containZero = false, isEven = false;
  int sum = 0;

  for (int i = 0; i < s.length(); i++)
  {
    int num = s[i] - '0';

    if (num == 0 && !containZero)
      containZero = true;
    else if (num % 2 == 0)
      isEven = true;

    sum += num;
  }

  if (sum % 3 == 0 && containZero && isEven)
    cout << "red" << endl;
  else
    cout << "cyan" << endl;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    string s;
    cin >> s;
    solve(s);
  }
}