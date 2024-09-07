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
#define pii pair<int , int>
#define lp(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vpi vector<pii>
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e4+5
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;
#define oo 1e18

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

ll calc(ll st, ll end, ll mid)
{
  ll pos = (mid * (mid + 1)) / 2 - (st * (st - 1)) / 2;
  ll neg = (end * (end + 1)) / 2 - ((mid + 1) * mid) / 2;

  return pos - neg;
}

ll detePart(ll arrLen, ll indx, ll cycl, ll relIndx) //0 left, 1 right
{
  if (relIndx >= cycl)
    return 0;
  return 1;
}

ll getSum(ll l, ll r, vector<ll> &v)
{
  return v[r] - v[l - 1];
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--)
  {
    ll n, q;
    cin >> n >> q;

    ll totSum = 0;
    vector<ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      cin >> v[i];
      totSum += v[i];
      v[i] += v[i - 1];
    }


    while (q--)
    {
      ll l, r;
      cin >> l >> r;

      ll lCyc = ceil(double(l) / n);
      ll rCyc = ceil(double(r) / n);
      
      ll oldRelativeL = l - ((lCyc - 1) * (v.size() - 1));
      ll oldRelativeR = r - ((rCyc - 1) * (v.size() - 1));

      ll relativeL = (oldRelativeL + (lCyc - 1));
      if (relativeL >= v.size())
        relativeL++;
      relativeL = relativeL % v.size();
      
      ll relativeR = (oldRelativeR + (rCyc - 1));
      if (relativeR >= v.size())
        relativeR++;
      relativeR = relativeR % v.size();

      ll res = 0;

      if (rCyc - lCyc == 0)
      {
        if (detePart(v.size() - 1, l, lCyc, relativeL) == detePart(v.size() - 1, r, rCyc, relativeR))
        {
          res += getSum(relativeL, relativeR, v);
        }
        else
        {
          res += getSum(1, relativeR, v) + getSum(relativeL, n, v); 
        }
      }
      else
      {
        if (rCyc - lCyc > 1)
          res += ((rCyc - lCyc - 1) * totSum);

        if (detePart(v.size() - 1, l, lCyc, relativeL) == 0)
        {
          ll st = max(relativeL - (oldRelativeL - 1), lCyc);
          res += (totSum - getSum(st, relativeL - 1, v));
        }
        else
        {
          ll end = lCyc - 1;
          res += getSum(relativeL, end, v);
        }

        if (detePart(v.size() - 1, r, rCyc, relativeR) == 0)
        {
          ll st = max(relativeR - (oldRelativeR - 1), rCyc);
          res += getSum(rCyc, relativeR, v);
        }
        else
        {
          ll end = rCyc - 1;
          res += (totSum - getSum(relativeR + 1, end, v));
        }
      }

      cout << res << "\n";
    }
  }
}