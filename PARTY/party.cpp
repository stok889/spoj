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

#define NAME "party"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )
#define FILL( a, b ) ( memset((a), (b), sizeof(a)) )
#define FS first
#define SE second

int compare( const pii &a, const pii &b )
{
	return a.FS < b.FS || ( a.FS == b.FS && a.SE < b.SE );
}

int main()
{
  #ifdef LOCAL
  freopen( NAME".in", "rt", stdin );
  freopen( NAME".out", "wt", stdout );
  #endif

	int m, n;
	while( scanf("%d%d", &m, &n) == 2 )
	{
		if( m == 0 && n == 0 ) break;
		vector< pii > p;
		for( int i = 0; i < n; ++i ) 
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if( x > m ) continue;
			p.push_back( pii( x, y ) );
		}

		n = SIZE( p );

		int dp[m + 1][n];
		FILL( dp, -1 );
		dp[p[0].FS][0] = p[0].SE;
		for( int i = 1; i < n; ++i )
		{
			dp[p[i].FS][i] = p[i].SE;
			for( int j = 0; j <= m; ++j )
			{
				if( dp[j][i - 1] != -1 ) dp[j][i] = max( dp[j][i], dp[j][i - 1]);
				int nm = j + p[i].FS;
				if( nm <= m )	dp[nm][i] = max( dp[nm][i], dp[j][i - 1] + p[i].SE );
			}
		}

		int rm = -1, rh = -1;
		for( int i = 0; i <= m; ++i ) 
			if( dp[i][n - 1] > rh )
			{
				rh = dp[i][n - 1];
				rm = i;
			}

		printf("%d %d\n", rm, rh);
	}

  #ifdef LOCAL
  fclose( stdin );
  fclose( stdout );
  #endif

  return 0;
}       