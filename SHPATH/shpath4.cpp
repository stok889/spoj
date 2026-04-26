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

#define NAME "shpath"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

const int nn = 10001;

struct vertex
{
	int v, c;
	vertex(){}
	vertex( const int a, const int b ) : v( a ), c( b ) {}
	
	void operator =( const vertex &arg )
	{
		v = arg.v;
		c = arg.c;
	}
};

class heap
{
private:

	int sz;
	vertex space[ nn ];

public:

	heap() : sz( 0 ) {}

	void insert( const vertex &x )
	{
		space[ sz++ ] = x;
		int id = sz - 1;
		while( id )
		{
			int pid = double( id ) / 2.0;
			if( space[ pid ].c <= space[ id ].c ) break;
			swap( space[ pid ], space[ id ] );
			id = pid;
		}
	}

	int get_min()
	{
		int ret = space[ 0 ].v;
		int cid = 0, nid = -1;

		swap( space[ 0 ], space[ sz - 1 ] );
		--sz;
		while( 1 )
		{
			if( 2 * cid < sz && space[ cid ].c > space[ 2 * cid ].c ) nid = 2 * cid;
			if( 2 * cid + 1 < sz && space[ cid ].c > space[ 2 * cid + 1 ].c ) nid = 2 * cid + 1;
			if( nid == -1 ) break;
			swap( space[ cid ], space[ nid ] );
			cid = nid;
			nid = -1;
		}

		return ret;
	}
};

int dijkstra( const vector < vertex > *ee, const int n, const int v1, const int v2 )
{
	int d[ nn ], mark[ nn ];
	heap q;

	memset( d, 63, sizeof( d ) );
	memset( mark, 0, sizeof( mark ) );

	d[ v1 ] = 0;
	q.insert( vertex( v1, 0 ) );
	for( int i = 0; i < n; ++i )
	{
		int mv = q.get_min();
		if( mark[ mv ] ) continue;
		mark[ mv ] = 1;
		if( mv == v2 ) break;
		for( int i = 0; i < SIZE( ee[ mv ] ); ++i )
		{
			int nv = ee[ mv ][ i ].v;
			if( d[ nv ] > d[ mv ] + ee[ mv ][ i ].c )
			{
				d[ nv ] = d[ mv ] + ee[ mv ][ i ].c;
				q.insert( vertex( nv, d[ nv ] ) );
			}
		}
	}

	return d[ v2 ];
}

int main()
{
	int t;
	int n, m;
	char city1[ 11 ], city2[ 11 ];

	scanf("%d\n", &t);
	while( t-- )
	{
		map < string, int > msi;
		vector < vertex > ee[nn];
		int id = 0;

		scanf("%d\n", &n);
		for( int i = 0; i < n; ++i )
		{
			scanf("%s\n", city1);
			msi.insert( make_pair( city1, id ) );
			scanf("%d\n", &m);
			for( int i = 0; i < m; ++i )
			{
				int v, c;
				scanf("%d%d\n", &v, &c);
				--v;
				ee[ id ].push_back( vertex( v, c ) );
			}
			++id;
		}

		int nq;
		scanf("%d\n", &nq);
		for( int i = 0; i < nq; ++i )
		{
			int v1 = -1, v2 = -1;
			scanf("%s %s\n", city1 ,city2);
			v1 = msi[ city1 ]; v2 = msi[ city2 ];
			printf("%d\n", dijkstra( ee, n,  v1, v2 ));
		}
	}
  

  return 0;
}       