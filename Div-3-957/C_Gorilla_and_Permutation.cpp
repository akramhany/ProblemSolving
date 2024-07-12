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
    int n, m, k;
    cin >> n >> m >> k;

    if (m == k)
      m--;

    vector<int> v(n);

    int val = n;
    for (int i = 0; i < n - k + 1; i++)
    {
      v[i] = val;
      val--;
    }

    val = m;
    for (int i = n - 1; i > n - m - 1; i--)
      v[i] = val--;

    val = k - 1;
    for (int i = n - k + 1; i < n - m; i++)
      v[i] = val--;

    for (auto &i : v)
      cout << i << " ";

    cout << endl;
  }
}