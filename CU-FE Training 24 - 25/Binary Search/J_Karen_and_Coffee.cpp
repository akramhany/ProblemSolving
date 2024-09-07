#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <cstring>

#define ll long long
#define llu unsigned long long

using namespace std;

bool isPrime(ll n)
{
  if (n == 2)
    return true;
  else if (n < 2 || n % 2 == 0)
    return false;

  for (ll i = 3; i * i <= n; i += 2)
  {
    if (n % i == 0)
      return false;
  }

  return true;
}

ll sumDivisors(ll n)
{
  ll sum = 0;

  for (ll i = 1; i * i <= n; i++)
  {
    if (i * i == n)
    {
      sum += i;
    }
    else if (n % i == 0)
    {
      sum += i;
      sum += (n / i);
    }
  }

  return sum;
}

// a must be the bigger number
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

// a must be the bigger number
ll lcm(ll a, ll b)
{
  return (ll)(a * b) / gcd(a, b);
}

int calculate(char dir, char c)
{
  if (c == dir)
    return 0;

  if (dir == 'L')
  {
    if (c == 'R')
      return 2;
    else
      return 1;
  }
  else if (dir == 'R')
  {
    if (c == 'L')
      return 2;
    else
      return 1;
  }
  else if (dir == 'U')
  {
    if (c == 'D')
      return 2;
    else
      return 1;
  }
  else
  {
    if (c == 'U')
      return 2;
    else
      return 1;
  }
}

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, k, q;
  cin >> n >> k >> q;

  vector<int> v;
  deque<int> dq;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    v.push_back(x);
    dq.push_back(y);
  }

  sort(v.begin(), v.end());
  sort(dq.begin(), dq.end());
  v.push_back(dq.back() + 1);

  ll arr[200005] = {0};

  int index = 0, counter = 0, c2 = 0;
  while (index < n) {
    counter++;
    int st = v[index];
    bool x = false;
    while (st < v[index + 1]) {
      x = false;
      arr[st] += counter;
      st++;
      while (!dq.empty() && st > dq.front()) {
        counter--;
        dq.pop_front();
      }
      if (arr[st - 1] < k) {
        arr[st - 1] = 0;
        x = true;
      }
      else {
        arr[st - 1] = 1;
        x = true;
      }
    }

    if (!x) {
    if (arr[st - 1] < k)
      arr[st - 1] = 0;
    else
      arr[st - 1] = 1;

    }

    index++;
  }

  for (int i = 1; i <= 200000; i++)
    arr[i] += arr[i - 1];
  
  while (q--) {
    int l, r;
    cin >> l >> r;


    cout << arr[r] - arr[l - 1] << "\n";
  }
}