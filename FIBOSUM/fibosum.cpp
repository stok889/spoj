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

typedef pair< int, int > pii;
typedef vector< int > vi;
typedef vector< string > vs;

#define NAME "fibosum"
//#define NAME "fibosumRandTest"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )
#define FS first
#define SE second

const int MOD = 1e9 + 7;

int getSum( int n )
{
  long long res[2][2], b[2][2], c[2][2];

  if( n == 0 ) return 0;
  if( n == 1 ) return 1;
  
  b[0][0] = 0LL;
  b[1][1] = b[0][1] = b[1][0] = 1LL;
  res[0][0] = 0LL;
  res[1][1] = res[0][1] = res[1][0] = 1LL;
  while( n )
  {
    if( n & 1 )
    {
      --n;

      for( int i = 0; i < 2; ++i )
	for( int j = 0; j < 2; ++j )
	{
	  long long tmp = 0LL;
	  for( int r = 0; r < 2; ++r )
	  {
	    tmp += res[i][r] * b[r][j];
	    tmp %= MOD;
	  }
	  c[i][j] = tmp;
	}
      memcpy( res, c, sizeof(c) );
    }
    else
    {
      n >>= 1;

      for( int i = 0; i < 2; ++i )
	for( int j = 0; j < 2; ++j )
	{
	  long long tmp = 0LL;
	  for( int r = 0; r < 2; ++r )
	  {
	    tmp += b[i][r] * b[r][j];
	    tmp %= MOD;
	  }
	  c[i][j] = tmp;
	}
      memcpy( b, c, sizeof(c) );
    }
  }

  return res[1][0];
};

int main()
{
  #ifdef LOCAL
  freopen( NAME".in", "rt", stdin );
  freopen( NAME".out", "wt", stdout );
  #endif

  int T;
  scanf("%d", &T);
  while( T-- )
  {
    int n, m;
    scanf("%d%d", &n, &m);
    int sn = getSum( n );
    int sm = getSum( m + 1 );
    int ans = (sm - sn + MOD) % MOD;
    if( sn == 0 ) --ans;
    //printf("sm = %d, sn = %d, %d\n", sm, sn, ans);
    printf("%d\n", ans);
  }
	
  return 0;
}       