#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int numOfZeroSeg = 0, numOfOneSeg = 0, numOfOnes = 0;
    char currentNum = '2';

    for (int i = 0; i < n; i++)
    {
      if (s[i] != currentNum)
      {
        if (s[i] == '1')
          numOfOneSeg++;
        else
          numOfZeroSeg++;

        currentNum = s[i];
      }

      if (s[i] == '1')
        numOfOnes++;
    }

    if (numOfOneSeg > numOfZeroSeg || numOfOnes > numOfZeroSeg)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}