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
#include <bitset>
#include <cassert>

using namespace std;

const int INF = 0x3f3f3f3f;
const double PI = 3.14159265358979323846;

typedef long long ll;
typedef pair< int, int > pii;
typedef vector< int > vi;
typedef vector< string > vs;

#define NAME "ulm09"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )
#define FILL( a, b ) ( memset((a), (b), sizeof(a)) )
#define FS first
#define SE second

struct edge
{
  int v1, v2, cst;
  edge( int a, int b, int c ) : v1(a), v2(b), cst(c) {}
  int operator <( const edge &arg ) const
  {
    return cst < arg.cst;
  }
};

class DSU
{
private:
  int *parent, *sz;
public:
  DSU( const int n )
  {
    parent = new int[n];
    sz = new int[n];
    for( int i = 0; i < n; ++i )
    {
      parent[i] = i;
      sz[i] = 1;
    }
  }
  
  ~DSU()
  {
    delete parent;
    delete sz;
  }

  int find( const int v )
  {
    if( v == parent[v] )
      return v;
    return parent[v] = find( parent[v] );
  }

  void fusion( int v1, int v2 )
  {
    int a = find( v1 );
    int b = find( v2 );
    if( a != b )
    {
      if( sz[a] < sz[b] ) swap( a, b );
      sz[a] += sz[b];
      parent[b] = a;
    }
  }
};

int mst( vector< edge > &e )
{
  int ret = 0;
  DSU s( SIZE(e) );
  for( int i = 0; i < SIZE(e); ++i )
  {
    int v1 = e[i].v1;
    int v2 = e[i].v2;
    if( s.find(v1) != s.find(v2) )
    {
      s.fusion( v1, v2 );
      ret += e[i].cst;
    }
  }
  return ret;
}

int main()
{
  #ifdef LOCAL
  freopen( NAME".in", "rt", stdin );
  freopen( NAME".out", "wt", stdout );
  #endif

  while( 1 ) 
  {
    int m, n;
    scanf("%d%d", &m, &n);
    if( m == 0 || n == 0 ) break;
    vector< edge > e;
    if( m == 0 || n == 0 ) break;
    int totalLen = 0;
    for( int i = 0; i < n; ++i )
    {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      e.push_back( edge(a, b, c) );
      totalLen += c;
    }
    sort( e.begin(), e.end() );
    printf("%d\n", totalLen - mst(e));
  }
  
  return 0;
}