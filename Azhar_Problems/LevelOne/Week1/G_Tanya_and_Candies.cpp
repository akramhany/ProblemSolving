#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

int main()
{
  int n;
  std::cin >> n;

  std::vector<int> leftSum(n);
  std::vector<int> rightSum(n);

  for (auto &i : leftSum)
  {
    std::cin >> i;
  }

  for (int i = 0; i < n; i++)
    rightSum[i] = leftSum[i];

  for (int i = 2; i < n; i++)
  {
    leftSum[i] += leftSum[i - 2];
    rightSum[n - i - 1] += rightSum[n - i + 1];
  }

  int res = 0;

  for (int i = 0; i < n; i++)
  {
    ll evenSum = 0, oddSum = 0;

    if (i % 2 == 1) // odd
    {
      oddSum += (i - 2 >= 0 ? leftSum[i - 2] : 0);
      oddSum += (i + 1 < n ? rightSum[i + 1] : 0);
      evenSum += (i - 1 >= 0 ? leftSum[i - 1] : 0);
      evenSum += (i + 2 < n ? rightSum[i + 2] : 0);
    }
    else
    {
      evenSum += (i - 2 >= 0 ? leftSum[i - 2] : 0);
      evenSum += (i + 1 < n ? rightSum[i + 1] : 0);
      oddSum += (i - 1 >= 0 ? leftSum[i - 1] : 0);
      oddSum += (i + 2 < n ? rightSum[i + 2] : 0);
    }

    if (evenSum == oddSum)
      res++;
  }

  std::cout << res << std::endl;
}