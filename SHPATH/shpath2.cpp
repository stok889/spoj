#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int maxn = 10001;

#define size( a ) ( (int) (a).size() )

struct vert 
{
	int v, c;
	vert() {}
	vert(int a, int b) : v(a), c(b) {}
};

int main()
{
	int t;

	scanf("%d\n", &t);

	while( t-- )
	{
		int n, nn;
		map < string, int > H;
		vector < vert > e[maxn]; 

		scanf("%d\n", &n);

		for( int i = 0; i < n; ++i )
		{
			char name[11];

			scanf("%s\n", name);
			H[name] = i;
			scanf("%d\n", &nn);
			e[i].resize( nn );
			for( int j = 0; j < nn; ++j )
			{
				scanf("%d%d\n", &e[i][j].v, &e[i][j].c);
				--e[i][j].v;
			}
		}

		scanf("%d\n", &nn);
		while( nn-- )
		{
			char n1[11], n2[11];
			scanf("%s %s\n", n1, n2);
			
			int a = H[n1], b = H[n2];

			{
				int d[maxn], q[maxn], qid[maxn], qs = 0;

				memset(d, 63, sizeof(d));	
				memset(q, 0, sizeof(q));
				memset(qid, -1, sizeof(qid));

				q[0] = a; d[a] = 0;
				qid[ q[0] ] = qs++;

				while( qs )
				{
					int u = q[0]; 
					qid[ q[0] ] = -1; q[0] = q[ --qs ];
					qid[ q[0] ] = 0;
					for( int i = 0, j = 2 * i + 1; j < qs; i = j, j = 2 * i + 1 )
					{
						if( j + 1 < qs && d[ q[i] ] > d[ q[j + 1] ] ) ++j;
						if( d[ q[i] ] <= d[ q[j] ] ) break;
						swap( q[i], q[j] );
						swap( qid[ q[i] ], qid[ q[j] ] );
					}

					int sz = size( e[u] );
					for( int k = 0; k < sz; ++k )
					{
						int v = e[u][k].v, c = e[u][k].c;
						int cost = d[u] + c;
						if( d[v] > cost )
						{
							d[v] = cost;
							if( qid[ v ] < 0 ) qid[ q[qs] = v ] = qs++;
							for( int i = qid[v], j = i / 2; d[ q[i] ] < d[ q[j] ] ; i = j, j /= 2 )
							{
								swap( q[i], q[j] ); swap( qid[ q[i] ], qid[ q[j] ] );
							}
						}
					}
				}

				printf("%d\n", d[b]);
			}
		}
	}

	return 0;
}