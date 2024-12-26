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
    int n, k;
    cin >> n >> k;

    vector<int> v(k);

    for (auto &i : v)
      cin >> i;

    int maxIndx = 0;

    for (int i = 0; i < k; i++)
    {
      if (v[i] > v[maxIndx])
        maxIndx = i;
    }

    ll res = 0;
    for (int i = 0; i < k; i++)
    {
      if (i == maxIndx)
        continue;

      res += (v[i] * 2 - 1);
    }

    cout << res << endl;
  }
}