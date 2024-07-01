#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

bool isDivInt(int a, int b)
{
  double div = float(a) / b;
  if (div - (a / b) < 1e-9)
    return true;
  return false;
}

int calculateSum(int n)
{
  return n * (n + 1) / 2;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> v(n);

  for (auto &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  int result = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (abs(v[j] - v[i]) <= m)
        result += 2;
      else
        break;
    }
  }
  cout << result << endl;
}