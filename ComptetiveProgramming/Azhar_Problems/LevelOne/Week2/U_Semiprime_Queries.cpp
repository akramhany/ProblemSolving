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

bool sieve_arr[2000005];
int arrr[2000005];

void sieve(bool arr[], int n)
{
  arr[0] = arr[1] = false;
  int i = 2;

  while (i * i <= n)
  {
    if (arr[i])
    {
      int k = i * i;
      while (k <= n)
      {
        arr[k] = false;
        k += i;
      }
    }
    i++;
  }
}

int main()
{
  int q;
  cin >> q;

  memset(sieve_arr, true, 2000005);

  sieve(sieve_arr, 2000004);

  vector<int> v;

  for (int i = 1; i < 2000003; i++)
  {
    if (sieve_arr[i])
      v.push_back(i);
  }

  memset(arrr, 0, 2000005);

  for (int i = 0; i < v.size(); i++)
  {
    for (int j = i; j < v.size(); j++)
    {
      ll prod = (ll)(v[i]) * (ll)(v[j]);
      if (prod >= 2000005)
        break;
      arrr[prod] = 1;
    }
  }

  for (int i = 1; i < 2000005; i++)
  {
    arrr[i] += arrr[i - 1];
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;

    if (l == 0)
      cout << arrr[r] << "\n";
    else
      cout << arrr[r] - arrr[l - 1] << "\n";
  }
}