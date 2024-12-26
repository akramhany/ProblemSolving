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

  while (t--) {
    ll n, m;
    cin >> n >> m;

    vector<set<ll>> v(n);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;

      for (int j = 0; j < k; j++) {
        ll x;
        cin >> x;
        v[i].insert(x);
      }
    }

    ll max_mex = -1;
    for (int i = 0; i < n; i++) {
      ll mex1 = -1, mex2 = -1;
      ll counter = 0;

      for (auto & s : v[i]) {
        while (s != counter) {
          if (mex1 == -1)
            mex1 = counter;
          else {
            mex2 = counter;
            break;
          }
          counter++;
        }
        if (mex2 != -1)
          break;
        counter++;
      }

      if (mex1 == -1 && mex2 == -1)
        mex2 = *(v[i].rbegin()) + 2;
      else if (mex2 == -1)
        mex2 = *(v[i].rbegin()) + 1;
      max_mex = max(max_mex, mex2);
    }

    ll res = 0;
    if (m > max_mex) {
      res = max_mex * (max_mex + 1) + ((m * (m + 1) / 2) - (max_mex * (max_mex + 1) / 2));
    } else {
      res = max_mex * (m + 1);
    }

    cout << res << "\n";
  }
}


      // ll mex1=-1, mex2=-1;

      // for (int j = 0; j < v[i].size() - 1; j++) {
      //   ll diff = v[i][j + 1] - v[i][j];
      //   if (diff == 1 || diff == 0)
      //     continue;
      //   else if (diff > 2) {
      //     if (mex1 == -1)
      //       mex2 = v[i][j] + 2;
      //     else
      //       mex2 = v[i][j] + 1;
      //     break;
      //   } else if (diff == 2) {
      //     if (mex1 == -1) {
      //       mex1 = 1;
      //     } else {
      //       mex2 = v[i][j] + 1;
      //       break;
      //     }
      //   }
      // }

      // if (mex2 == -1) {
      //   if (mex1 == -1) {
      //     mex2 = v[i][v[i].size() - 1] + 2;
      //   } else {
      //     mex2 = v[i][v[i].size() - 1] + 1;
      //   }
      // }