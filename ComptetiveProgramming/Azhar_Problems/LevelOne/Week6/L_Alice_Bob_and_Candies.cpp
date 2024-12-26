#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <cstring>
#include <queue>

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

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi v(n);
    scn(v);

    int l = 0, r = n - 1;
    ll totSumA = 0, totSumB = 0, currentSum = 0;
    int currTurn = 0, numOfMoves = 0;

    while (l <= r)
    {
      numOfMoves++;
      ll tempSum = 0;
      if (currTurn == 0)
      {
        while (l <= r && tempSum <= currentSum)
          tempSum += v[l++];
        currentSum = tempSum;
        totSumA += tempSum;
      }
      else
      {
        while (l <= r && tempSum <= currentSum)
          tempSum += v[r--];
        currentSum = tempSum;
        totSumB += tempSum;
      }

      currTurn ^= 1;
    }

    cout << numOfMoves << " " << totSumA << " " << totSumB << "\n";
  }
}