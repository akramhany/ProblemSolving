#include <iostream>

using namespace std;

int main()
{
  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << (((a * b) % 100) * ((c * d) % 100)) % 100 << endl;
}