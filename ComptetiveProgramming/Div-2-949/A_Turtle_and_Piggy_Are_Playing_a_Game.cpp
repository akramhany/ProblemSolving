#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int l, r;
    cin >> l >> r;

    cout << (int)log2(r) << endl;
  }
}