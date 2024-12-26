#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

using namespace std;

ll countBits(int num)
{
  ll count = 0;
  while (num)
  {
    num /= 2;
    count++;
  }
  return count;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    if (m == 0)
    {
      cout << n << endl;
      continue;
    }
    else if (m == 1)
    {
      ll res = 0;
      if (n == 0)
        res = (n) | (n + 1);
      else
        res = (n - 1) | (n) | (n + 1);

      cout << res << endl;
      continue;
    }

    ll numOfBits = countBits(n + 1);
    ll rNumOfBits = countBits(n + m);
    ll lNumOfBits = countBits(n - m + 2);

    ll r = (n + m - 1);
    ll l = (n - m + 1);

    ll res1 = 0;
    if (n == 0)
      res1 = n | (n + 1);
    else
      res1 = (n - 1) | n | (n + 1);

    ll res2 = rNumOfBits > numOfBits ? (pow(2, rNumOfBits) - 1) : ((r - 1) | r | (r + 1));

    if (rNumOfBits > numOfBits)
    {
      res2 = pow(2, rNumOfBits) - 1;
    }
    else
    {
      for (int i = n + 1; i < r + 1; i++)
        res2 = max(res2, (ll)((i - 1) | i | (i + 1)));
    }

    ll res3 = 0;
    if (lNumOfBits < numOfBits)
      res3 = pow(2, numOfBits) - 1;
    else if (l > 0)
    {
      for (int i = l; i < n; i++)
        res3 = max(res3, (ll)((i - 1) | i | (i + 1)));
    }

    ll res = max(res1, max(res2, res3));
    cout << res << endl;
  }
}