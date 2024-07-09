#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
  long long A, B;
  cin >> A >> B;
  double div = (float)A / B;
  cout << "floor " << A << " / " << B << " = " << floor(div) << endl;
  cout << "ceil " << A << " / " << B << " = " << ceil(div) << endl;
  cout << "round " << A << " / " << B << " = " << round(div) << endl;
}