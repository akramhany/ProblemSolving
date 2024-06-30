#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
  long long N;
  cin >> N;
  long long sum = N * (N + 1) / 2;
  cout << sum << endl;
}