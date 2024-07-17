#include <iostream>

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

    if (k == 2)
    {
      cout << n - 1 << endl;
      continue;
    }

    int res = n / (k - 1);
    if (n % (k - 1) > 1)
      res++;

    cout << res << endl;
  }
}