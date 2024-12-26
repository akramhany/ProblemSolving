#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll calculate(ll n, ll a, ll b, ll k);

void solve(ll n, ll a, ll b)
{
  int left = 0, right = min(n, b);
  ll res = -1;

  while (left < right)
  {
    ll mid = (left + right) / 2;
    ll currR = calculate(n, a, b, mid);

    if (currR > res)
      res = currR;

    ll resR = -1, resL = -1;
    if (mid + 1 <= right)
      resR = calculate(n, a, b, mid + 1);
    if (mid - 1 >= left)
      resL = calculate(n, a, b, mid - 1);

    if (resR > resL)
      left = mid + 1;
    else
      right = mid - 1;
  }

  res = max(res, calculate(n, a, b, left));
  res = max(res, calculate(n, a, b, right));

  cout << res << endl;
}

ll calculate(ll n, ll a, ll b, ll k)
{
  return k * (b + 1) - k * (k + 1) / 2 + (n - k) * a;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    ll n, a, b;
    cin >> n >> a >> b;

    solve(n, a, b);
  }
}