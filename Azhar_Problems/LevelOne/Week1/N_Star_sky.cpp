#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <map>

#define ll long long

using namespace std;

int main()
{
  int n, q, c;
  cin >> n >> q >> c;

  int arr[102][102][12] = {0};

  for (int i = 0; i < n; i++)
  {
    int x, y, s;
    cin >> x >> y >> s;

    arr[x][y][s]++;
  }

  for (int i = 1; i <= 100; i++)
  {
    for (int j = 1; j <= 100; j++)
    {
      for (int k = 0; k <= 10; k++)
      {
        arr[i][j][k] += (arr[i - 1][j][k] + arr[i][j - 1][k] - arr[i - 1][j - 1][k]);
      }
    }
  }

  while (q--)
  {
    int t, x1, x2, y1, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;

    ll res = 0;

    for (int k = 0; k <= 10; k++)
    {
      res += (((t + k) % (c + 1)) * (arr[x2][y2][k] - arr[x2][y1 - 1][k] - arr[x1 - 1][y2][k] + arr[x1 - 1][y1 - 1][k]));
    }

    cout << res << endl;
  }
}