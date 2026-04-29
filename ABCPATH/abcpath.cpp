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

const int maxn = 55;

int table[maxn][maxn];
int d[maxn][maxn];
int n, m;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct state
{
  int x, y, num;

  state() {}
  state(int x, int y, int num) : x(x), y(y), num(num) {}
};

int bfs(int x, int y)
{
  int ret = 0;
  memset(d, 0, sizeof(d));
  queue<state> q;
  q.push(state(x, y, 0));
  while (!q.empty())
  {
    state cs = q.front();
    int cx = cs.x;
    int cy = cs.y;
    int cn = cs.num;
    if (ret < cn) ret = cn;
    q.pop();
    for (int i = 0; i < 8; ++i)
    {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      int nn = cn + 1;
      if (nx < 0 || ny < 0) continue;
      if (nx >= n || ny >= m) continue;
      if (d[nx][ny] >= nn) continue;
      if (table[nx][ny] == nn)
      {
        q.push(state(nx, ny, nn));
        d[nx][ny] = nn;
      }
    }
  }
  return ret + 1;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  ios::sync_with_stdio(false);
	
  int T = 1;
  while (1)
  {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    memset(table, 0, sizeof(table));
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        char ch;
        cin >> ch;
        table[i][j] = ch - 'A';
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (table[i][j] != 0) continue;
        int ca = bfs(i, j);
        if (ans < ca) ans = ca;
      }
    }
    cout << "Case " << T << ": " << ans << endl;
    ++T;
  }

  return 0;
}       
