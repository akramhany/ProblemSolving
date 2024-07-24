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

int main()
{
  char x, y;
  cin >> x >> y;

  int n;
  cin >> n;

  n %= 4;

  char arr[] = {'<', '^', '>', 'v'};

  if (n == 0 || n == 2)
    cout << "undefined" << endl;
  else
  {
    int indx = -1;
    if (x == arr[0])
      indx = 0;
    else if (x == arr[1])
      indx = 1;
    else if (x == arr[2])
      indx = 2;
    else if (x == arr[3])
      indx = 3;

    indx += n;
    indx %= 4;

    if (arr[indx] == y)
      cout << "cw" << endl;
    else
      cout << "ccw" << endl;
  }
}