#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

int main()
{
  int n;
  std::cin >> n;

  std::vector<char> v(n);
  std::vector<int> freq(26, 0);

  for (auto &i : v)
    std::cin >> i;

  if (n == 1)
  {
    std::cout << "Yes" << std::endl;
    return (0);
  }
  for (auto i : v)
  {
    int indx = char(i) - 'a';
    freq[indx]++;

    if (freq[indx] > 1)
    {
      std::cout << "Yes" << std::endl;
      return (0);
    }
  }

  std::cout << "No" << std::endl;
}