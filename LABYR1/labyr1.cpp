#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int nn = 1010;

struct point
{
 int a, b;

 point() {};

 point(int _a, int _b) : a(_a), b(_b) {}

 point& save(int a, int b)
 { 
  this->a = a;
  this->b = b;

  return *this;
 }

 int check(int &n, int &m)
 {
  return 0 <= a && a < n && 0 <= b && b < m;
 }

 point& operator = (const point &arg)
 {
  a = arg.a;
  b = arg.b;

  return *this;
 }
};

int n, m;
long res;
vector < vector < int > > map;
vector < vector < int > > mark;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

void filling()
{
 for (int i = 0; i < n; ++i)
  fill(mark[i].begin(), mark[i].end(), 0);
}

int main()
{
 int t;

 scanf("%d\n", &t);
 for (; t; --t)
     {
      point start;
      int f = 0;
      
      scanf("%d%d\n", &m, &n);

      res = 0;
      map.resize(n);
      mark.resize(n);
      for (int i = 0; i < n; ++i)
          {
           map[i].resize(m);
           mark[i].resize(m);
          }

      for (int i = 0; i < n; ++i)
          {
           char str[nn];

           gets(str);
           for (int j = 0; j < m; ++j)
               {
                map[i][j] = mark[i][j] = 0;
                if (str[j] == '.')
                   {
                    map[i][j] = 1;
                    if (!f)
                       {
                        f = 1;
                        start.save(i, j);
                       }
                   }
               }
          }

      for (;;)
          {
           queue < point > q;
           int ans = 0;

           filling();

           q.push(start);
           for (;!q.empty();)
               {
                point t = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i)
                    {
                     point tmp(t.a + dx[i], t.b + dy[i]);
                     if (tmp.check(n, m) && !mark[tmp.a][tmp.b] 
                         && map[tmp.a][tmp.b])
                        {
                         mark[tmp.a][tmp.b] = mark[t.a][t.b] + 1;
                         if (ans < mark[tmp.a][tmp.b])
                            {
                             ans = mark[tmp.a][tmp.b];
                             start = tmp;
                            }
                         q.push(tmp);
                        }
                    }
               }
           if (ans > res) res = ans;
              else break;
          }

      printf("Maximum rope length is %ld.", res);
      if (t > 1) printf("\n");

      map.clear();
      mark.clear();
     }
 
 return 0;
}