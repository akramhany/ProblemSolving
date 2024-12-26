#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
  long long N, M;
  cin >> N >> M;
  int res = (N % 10) + (M % 10);
  cout << res << endl;
}