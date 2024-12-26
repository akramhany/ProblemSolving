#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <map>

#define ll long long

using namespace std;

int calcAscii(string s)
{
  int asciiSum = 0;
  for (int i = 0; i < s.length(); i++)
    asciiSum += s[i];

  return asciiSum;
}

int main()
{
  int n;
  cin >> n;

  vector<pair<string, vector<int>>> v(n);
  vector<pair<int, int>> sortedV;

  for (int i = 0; i < n; i++)
  {
    int sum = 0;

    cin >> v[i].first;
    sum += calcAscii(v[i].first);

    for (int j = 0; j < 4; j++)
    {
      int coord;
      cin >> coord;
      v[i].second.push_back(coord);
      if (j == 1 || j == 3)
        sum += coord;
    }

    sortedV.push_back(make_pair(sum, i));
  }

  sort(sortedV.begin(), sortedV.end(), [](const pair<int, int> &a, const pair<int, int> &b)
       {
    if (a.first == b.first)
      return a.second > b.second;
    
    return a.first < b.first; });

  for (auto &it : sortedV)
  {
    cout << v[it.second].first << " ";
    for (auto &i : v[it.second].second)
      cout << i << " ";

    cout << endl;
  }
}