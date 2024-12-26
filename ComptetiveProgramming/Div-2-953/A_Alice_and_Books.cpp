#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    vector<ll> v(n);

    for (auto &i : v)
      cin >> i;

    ll max1 = v[v.size() - 1];
    ll max2 = -1;

    for (int i = 0; i < v.size() - 1; i++)
    {
      if (v[i] > max2)
        max2 = v[i];
    }

    cout << max1 + max2 << endl;
  }
}