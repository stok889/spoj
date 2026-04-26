#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;

typedef long double ld;
typedef vector < int > vi;
typedef vector < string > vs;
typedef pair < int, int > pii;
typedef map < string, int > msi;

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define abs(a) ( (a) < 0 ? -(a) : (a) )
#define sqr(a) ( (a) * (a) )
#define size(a) ( (int) (a).size() )
#define length(a) ( (int) (a).length() )

#ifdef WIN32
typedef __int64 i64;
#define Ld "%I64d"
#else
typedef long long i64;
#define Ld "%lld"
#endif

const char *const in = "shpath.in";
const char *const out = "shpath.out";

const int maxn = 10001;

struct vert
{
 int v, cst;
 vert() : v(-1), cst(-1) {}
 vert(int a, int b) : v(a), cst(b) {}
};

int path(int a, int b, vector < vert > *e)
{
 int d[maxn]; 
 set < pii > q;
  
 memset(d, 63, sizeof(d));
 
 d[a] = 0;
 q.insert( mp(0, a) );
 for (; !q.empty();)
     {
      pii tmp = *q.begin();
      q.erase( q.begin() );
      int v1 = tmp.second, sz = size( e[v1] );
      for (int i = 0; i < sz; ++i)
          {
           int v2 = e[v1][i].v, c = e[v1][i].cst;
           if (d[v2] > d[v1] + c)
              {
               d[v2] = d[v1] + c;
               q.insert( mp(d[v2], v2) );
              }
          }
     }

 return d[b];
}

int main()
{
 int tt;

 scanf("%d\n", &tt);

 for (; tt--;)
     {
      msi H;
      vector < vert > e[maxn];
      int n, t;

      scanf("%d\n", &n);
      for (int i = 0; i < n; ++i)
          {
           char name[256];

           scanf("%s\n", name);
           H[name] = i;

           scanf("%d\n", &t);

           for (; t--;)
               {
                int v, cst;
                scanf("%d%d\n", &v, &cst);
                e[i].pb( vert(--v, cst) );
               }
          }

      scanf("%d\n", &t);
      for (; t--;)
          {
           char n1[256], n2[256];
           scanf("%s %s\n", n1, n2);
           printf("%d\n", path( H[n1], H[n2], e ));
          }
     }

 return 0;
}