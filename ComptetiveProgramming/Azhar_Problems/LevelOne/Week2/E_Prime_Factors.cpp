#include <iostream>
#include <cstring>
#include <stack>

#define ll long long

using namespace std;

int arr[10005];

void getFactors(int n)
{
  if (n == 2)
  {
    arr[2]++;
    return;
  }
  else if (n < 2)
    return;

  stack<int> s;
  s.push(n);

  while (!s.empty())
  {
    bool isPrime = true;
    int k = s.top();
    s.pop();

    for (int i = 2; i * i <= k; i++)
    {
      if (k % i == 0)
      {
        isPrime = false;
        s.push(k / i);
        s.push(i);
        break;
      }
    }

    if (isPrime == true && k < 10005)
      arr[k]++;
  }
}

int main()
{
  int n;
  cin >> n;

  memset(arr, 0, 10005);

  getFactors(n);

  for (int i = 2; i < 10000; i++)
  {
    if (arr[i] != 0)
      printf("%d %d\n", i, arr[i]);
  }

  return 0;
}