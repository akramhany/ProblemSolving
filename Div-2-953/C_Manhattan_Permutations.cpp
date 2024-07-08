#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll calcMax(ll n)
{
  if (n % 2 == 0)
    return n * (n / 2);
  else
    return n * (n / 2) + n / 2;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    ll n, p;
    cin >> n >> p;
    ll maxP = calcMax(n);

    if (p % 2 == 1 || maxP < p)
    {
      cout << "NO" << endl;
      continue;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[i] = i + 1;

    if (p / 2 < n)
    {
      swap(v[0], v[p / 2]);
    }
    else
    {
      int l = 0, r = n - 1;
      while (l < r)
      {
        int sub = (r - l) * 2;
        if (sub <= p)
        {
          swap(v[l], v[r]);
          p -= sub;
          l++;
        }
        r--;
      }
    }

    cout << "YES" << endl;

    for (auto i : v)
      cout << i << " ";

    cout << endl;
  }
}