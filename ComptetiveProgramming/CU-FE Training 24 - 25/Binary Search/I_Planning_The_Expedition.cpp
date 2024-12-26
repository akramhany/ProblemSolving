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

int calculate(char dir, char c)
{
  if (c == dir)
    return 0;

  if (dir == 'L')
  {
    if (c == 'R')
      return 2;
    else
      return 1;
  }
  else if (dir == 'R')
  {
    if (c == 'L')
      return 2;
    else
      return 1;
  }
  else if (dir == 'U')
  {
    if (c == 'D')
      return 2;
    else
      return 1;
  }
  else
  {
    if (c == 'U')
      return 2;
    else
      return 1;
  }
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  int arr[101] = {0};
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    arr[x]++;
  }

  if (n > m) {
    cout << "0\n";
    return (0);
  }

  int st = 0, end = 1e9, res = -1;
  while (st < end - 1) {
    int mid = (st + end) / 2;
    int counter = 0;

    for (int i = 1; i <= 100; i++) {
      if (mid == 0) break;
      counter += (arr[i] / mid);
    }

    if (counter >= n) {
      st = mid;
    } else if (counter < n) {
      end = mid;
    }
  }

  if (res != -1)
  {
    cout << res << "\n";
    return(0);
  }
  int c = 0;
  for (int i = 1; i <= 100; i++) {
    c += (arr[i] / end);
  }
  if (c >= n)
    cout << end << "\n";
  else
    cout << st << "\n";
}