#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#define ll long long

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1);
  v[0] = 0;

  for (int i = 1; i < n + 1; i++)
    cin >> v[i];

  int occ[100005] = {0};

  vector<int> freq(n + 1);
  int numOfDist = 0;

  for (int i = n; i > 0; i--)
  {
    if (occ[v[i]] == 0)
    {
      occ[v[i]]++;
      numOfDist++;
    }

    freq[i] = numOfDist;
  }

  for (int i = 0; i < m; i++)
  {
    int l;
    cin >> l;
    cout << freq[l] << endl;
  }
}