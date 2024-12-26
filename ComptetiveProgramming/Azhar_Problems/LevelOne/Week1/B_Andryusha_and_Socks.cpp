#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

int main()
{
  int n;
  std::cin >> n;

  int arr[200005] = {0};

  int count = 0, maxCount = 0;
  std::vector<int> v(2 * n);

  for (auto &i : v)
    std::cin >> i;

  for (int i = 0; i < 2 * n; i++)
  {
    arr[v[i]]++;

    if (arr[v[i]] == 1)
      count++;
    else if (arr[v[i]] == 2)
      count--;

    if (count > maxCount)
      maxCount = count;
  }

  std::cout << maxCount << std::endl;
}