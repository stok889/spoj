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

#define NAME "1"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int nn = 20;

int n, m;
char table[nn][nn];
pair<int, int> s(-1, -1), f(-1, -1);

bool ff(int flag, int x)
{
  bool ret = true;
  if (flag == 0)
  {
    for (int i = 0; i < n; ++i)
    {
      if (table[i][x] == '.')
      {
        if (s.first == -1)
        {
          s.first = i;
          s.second = x;
        }
        else
        {
          if (f.first == -1)
          {
            f.first = i;
            f.second = x;
          }
          else ret = false;
        }
      }
    }
  }
  else
  {
    for (int j = 1; j < m - 1; ++j)
    {
      if (table[x][j] == '.')
      {
        if (s.first == -1)
        {
          s.first = x;
          s.second = j;
        }
        else
        {
          if (f.first == -1)
          {
            f.first = x;
            f.second = j;
          }
          else ret = false;
        }
      }
    }
  }
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d%d\n", &n, &m);
    bool seen[n][m];
    memset(table, 0, sizeof(table));
    memset(seen, false, sizeof(seen));
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        scanf("%c", &table[i][j]);
      scanf("\n");
    }

    s.first = s.second = f.first = f.second = -1;

    bool ans = true;
    ans &= ff(0, 0);
    if (m > 1) ans &= ff(0, m - 1);
    ans &= ff(1, 0);
    if (n > 1) ans &= ff(1, n - 1);

    if (s.first == f.first && s.second == f.second) ans = false;
    if (s.first == -1 || f.first == -1) ans = false;
    if (ans == true)
    {
      queue<pair<int, int> > q;
      q.push(make_pair(s.first, s.second));
      seen[s.first][s.second] = true;
      while (!q.empty())
      {
        pair<int, int> ci = q.front();
        q.pop();
        int cx = ci.first;
        int cy = ci.second;
        for (int i = 0; i < 4; ++i)
        {
          int nx = cx + dx[i];
          int ny = cy + dy[i];
          if (nx < 0 || ny < 0) continue;
          if (nx >= n || ny >= m) continue;
          if (seen[nx][ny] == true) continue;
          if (table[nx][ny] == '#') continue;
          seen[nx][ny] = true;
          q.push(make_pair(nx, ny));
        }
      }
      if (seen[f.first][f.second] == false) ans = false;
    }
    if (ans == true) printf("valid\n");
    else printf("invalid\n");
  }
	
  return 0;
}       