#include <iostream>

using namespace std;

int main()
{
  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  a %= 100;
  b %= 100;
  c %= 100;
  d %= 100;

  long long result = (a * b * c * d) % 100;

  if (result < 10)
    cout << 0;

  cout << result << endl;
}