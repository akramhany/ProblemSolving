#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#define ll long long

using namespace std;

int main()
{
  string s;
  cin >> s;

  int n = s.size() + 1;

  vector<int> prefA(n, 0);
  vector<int> prefB(n, 0);

  for (int i = 1; i < n; i++)
  {
    if (s[i - 1] == 'a')
      prefA[i] = prefA[i - 1] + 1;
    else
      prefA[i] = prefA[i - 1];

    if (s[i - 1] == 'b')
      prefB[i] = prefB[i - 1] + 1;
    else
      prefB[i] = prefB[i - 1];
  }

  int res = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      int count = prefA[j] + (prefB[i] - prefB[j]) + (prefA[n - 1] - prefA[i]);
      if (count > res)
        res = count;
    }
  }

  cout << res << endl;
}