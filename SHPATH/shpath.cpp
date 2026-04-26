#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef pair < int, int > ii;

const int nn = 10000;

int patch(int v1, int v2, vector < vector < ii > > &e)
{
 int d[nn];
 set < ii > s;

 memset(d, 0xff, sizeof(d));

 s.insert( ii(0, v1) );
 d[v1] = 0;
 for (; !s.empty();)
     {
      ii top = *s.begin();

      s.erase( s.begin() );

      int v = top.second;

      int n = (int) e[v].size();
      for (int i = 0; i < n; ++i)
          {
           int vv = e[v][i].first;
           int cc = e[v][i].second;

           if (d[vv] == -1 || d[vv] > d[v] + cc)
              {
               if (d[vv] != -1)
                  s.erase( s.find( ii(d[vv], vv) ) );
               d[vv] = d[v] + cc;
               s.insert( ii(d[vv], vv) );
              }
          }
     }
  
 return d[v2];
}

int main()
{
 int t;

 scanf("%d\n", &t);
 for (; t; --t)
     {
      int nv;
      map < string, int > h;
      vector < vector < ii > > e;

      scanf("%d\n", &nv);

      e.resize(nv);

      for (int k = 0; k < nv; ++k)
          {
           char str[256];

           scanf("%s\n", str);
           h.insert(make_pair(str, k));

           int nr;

           scanf("%d\n", &nr);
           for (int i = 0; i < nr; ++i)
               {
                int v, c;

                scanf("%d%d\n", &v, &c);
                e[k].push_back(ii(v - 1, c));
               }
          }

      scanf("%d\n", &nv);
      
      for (; nv; --nv)
          {
           char s1[256], s2[256];

           scanf("%s %s\n", s1, s2);

           int v1 = h[s1];
           int v2 = h[s2];

           printf("%d\n", patch(v1, v2, e));
          }
     }

 return 0;
}