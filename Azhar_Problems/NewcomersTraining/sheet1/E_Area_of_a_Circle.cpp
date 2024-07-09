#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define PI 3.141592653

int main()
{
  double radius;
  cin >> radius;

  cout << setprecision(11) << PI * pow(radius, 2) << endl;
}