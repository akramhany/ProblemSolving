#include <iostream>

#define ll long long

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

int main()
{
  ll n;
  cin >> n;

  if (isPrime(n))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}