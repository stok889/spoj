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
#define FS first
#define SE second

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  int n, m;
  scanf("%d%d\n", &n, &m);
  char table[n][m];
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      scanf("%c", &table[i][j]);
    scanf("\n");
  }
  int as = 0, aw = 0;
  int seen[n][m];
  memset(seen, 0, sizeof(seen));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (table[i][j] == '#') continue;
      if (seen[i][j] == 0)
      {
        bool f = false;
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        seen[i][j] = 1;
        int w = 0, s = 0;
        if (table[i][j] == 'v') ++w;
        if (table[i][j] == 'k') ++s;
        while (!q.empty())
        {
          pair<int, int> ci = q.front();
          q.pop();
          int cx = ci.FS;
          int cy = ci.SE;
          for (int k = 0; k < 4; ++k)
          {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx < 0 || ny < 0)
            {
              f = true;
              continue;
            } 
            if (nx >= n || ny >= m)
            {
              f = true;
              continue;
            }
            if (seen[nx][ny] == 1)
            {
              continue;
            }
            if (table[nx][ny] == '#')
            {
              continue;
            }
            if (table[nx][ny] == 'v') ++w;
            if (table[nx][ny] == 'k') ++s;
            seen[nx][ny] = 1;
            q.push(make_pair(nx, ny));
          }
        }
        if (f == true)
        {
          as += s;
          aw += w;
        }
        else
        { 
          if (s > w) as += s;
          else aw += w;
        }
      }
    }
  }
  printf("%d %d", as, aw);
	
  return 0;
}       