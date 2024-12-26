#include <iostream>

using namespace std;

int main()
{
  int seq[] = {0, 1};
  cout << "0 1";
  for (int i = 2; i <= 8; i++)
  {
    seq[i % 2] = seq[0] + seq[1];
    cout << " " << seq[i % 2];
  }
}