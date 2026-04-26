#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>

using namespace std;

const int INF = 0x3f3f3f3f;

#define NAME "1"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

const int maxn = 1e5 + 11;

bool primes[maxn];

void genprimes()
{
  bool mark[maxn];
  memset(mark, false, sizeof(mark));
  for (int i = 2; i < maxn; ++i)
  {
    if (mark[i]) continue;
    primes[i] = true;
    for (int j = i + i; j < maxn; j += i) mark[j] = true;
  }
}

int change(int x, int pos, int dig)
{
  int ret = 0;
  //cout << " x = " << x;
  for (int i = 3; i >= 0; --i)
  {
    if (i == pos && !(pos == 0 && dig == 0)) ret += dig * int(pow(10.0, double(3 - i)));
    else ret += (x % 10) * int(pow(10.0, double(3 - i)));
    x /= 10;
  }
  //cout << " ret = " << ret << endl;
  return ret;
}

int solve(int a, int b)
{
  int d[maxn], mark[maxn];
  memset(d, 63, sizeof(d));
  memset(mark, 0, sizeof(mark));
  //cout << "check " << d[0] << endl;
  d[a] = 0;
  mark[a] = 1;
  queue<int> q;
  q.push(a);
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    if (x == b) break;
    for (int i = 0; i < 4; ++i)
    {
      for (int dig = 0; dig <= 9; ++dig) 
      {
        if (i == 0 && dig == 0) continue;
        int nx = change(x, i, dig);
        if (mark[nx]) continue;
        if (!primes[nx]) continue;
        if (d[nx] > d[x] + 1)
        {
          d[nx] = d[x] + 1;
          mark[nx] = 1;
          q.push(nx);
        }
      }
    }
  }
  return d[b];
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  memset(primes, false, sizeof(primes));
  genprimes();

  //cout << "ind " << INF << endl;

  int T;
  cin >> T;
  while (T--)
  {
    int a, b;
    cin >> a >> b;
    int ans = solve(a, b);
    if (ans < INF) cout << ans;
    else cout << "Impossible";
    cout << endl;
  }
	
  return 0;
}       