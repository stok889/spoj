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

using namespace std;

#define NAME "shpath"
#define ABS( a ) ((a) > 0 ? (a) : -(a))
#define SIZE( a ) (int( (a).size() ))
#define LENGTH( a ) ( int( (a).length() ) )

const int MAXINT = ( 1LL << 31 ) - 1;
const int nn = 256;
const int mnn = 10001;

int d[mnn], seen[mnn];

struct Pair
{
	int cost, v;

	Pair() : cost( -1 ), v( -1 ) {}
	Pair( const int _cost, const int _v ) : cost( _cost ), v( _v ) {}

	int operator <( const Pair &arg ) const
	{
		return cost < arg.cost;
	} 
};

int solve( vector < vector < Pair > > &gr, const int city1, const int city2 )
{
	set < Pair > q;  

	memset( d, 63, sizeof( d ) );
	memset( seen, 0, sizeof( seen ) );

	d[city1] = 0;
	q.insert( Pair( d[city1], city1 ) );

	while( !q.empty() )
	{
		Pair tmp = *q.begin();
		q.erase( q.begin() );

        int c1 = tmp.cost;
        int v1 = tmp.v;

		int n = SIZE( gr[v1] );

		if (seen[v1]) continue;

		seen[v1] = 1;

		for (int i = 0; i < n; ++i)
		{
			tmp = gr[v1][i];

			int c2 = tmp.cost;
			int v2 = tmp.v;

			if (d[v2] > c1 + c2)
			{
				d[v2] = c1 + c2;
				q.insert( Pair( d[v2], v2 ) );
			}	
		}	
	}
	
	return d[city2];
}

int main()
{
	int t;

	scanf("%d", &t);

	while( t-- )
	{
		int n, r;
		char cname[nn];

		map < string, int > name;
		vector < vector < Pair > > gr;

		scanf("%d\n", &n);

		for (int i = 0; i < n; ++i)
		{
			int neig;
			vector < Pair > v;

			scanf("%s\n", cname);
			
			name[cname] = i;

			scanf("%d\n", &neig);

			for (int j = 0; j < neig; ++j)
			{
				int id, price;

				scanf("%d %d\n", &id, &price);
				v.push_back( Pair( price, id - 1 ) );
			}

			gr.push_back( v ); 
		}
		
		/*
		for (int i = 0; i < 4; ++i)
		{
			printf("%d -> ", i);
			for (int j = 0; j < SIZE( gr[i] ); ++j)
				printf("%d ", gr[i][j].v);
			printf("\n");
		}
		*/

		scanf("%d\n", &r);

		for (int i = 0; i < r; ++i)
		{
			char n1[nn], n2[nn];

			scanf("%s %s\n", n1, n2);
			printf("%d\n", solve( gr, name[n1], name[n2] ));
		}
	}

	return 0;
}       