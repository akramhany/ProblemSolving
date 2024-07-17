#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

#define ll long long

using namespace std;

void sortVector(vector<int> &v)
{
  int maxIndx = v.size() - 1;
  while (maxIndx != 0 && v[maxIndx] < v[maxIndx - 1])
  {
    swap(v[maxIndx], v[maxIndx - 1]);
    maxIndx--;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> v(m);

  for (auto &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  vector<int> maxV = v;

  int maxC = 0;

  // get max
  for (int i = n; i > 0; i--)
  {
    maxC += maxV[maxV.size() - 1];
    maxV[maxV.size() - 1]--;
    sortVector(maxV);
  }

  vector<int> minV = v;

  int minC = 0, counter = 0;
  for (int i = n; i > 0; i--)
  {
    minC += minV[counter];
    minV[counter]--;
    if (minV[counter] == 0)
      counter++;
  }

  cout << maxC << " " << minC << endl;
}