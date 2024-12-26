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
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;
    s = ' ' + s;

    int pos = 0;
    int dest = n + 1;

    bool canReach = true;

    while (pos != dest)
    {
      bool moved = false;

      if (s[pos] == 'W')
      {
        if (pos + 1 >= dest)
          break;

        if (s[pos + 1] == 'W' || s[pos + 1] == 'C')
        {
          canReach = false;
          break;
        }
      }
      for (int i = m; i > 0; i--)
      {
        if (pos + i >= dest || s[pos + i] == 'L' || s[pos + i] == 'W')
        {
          pos += i;
          moved = true;
          break;
        }
      }

      if (pos >= dest)
        break;

      if (!moved && s[pos] == 'L')
      {
        if (s[pos + 1] == 'C')
        {
          canReach = false;
          break;
        }
        else // the next block is water
        {
          if (k == 0)
          {
            canReach = false;
            break;
          }
          k -= 1;
          pos += 1;
        }
      }
    }

    if (canReach)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}