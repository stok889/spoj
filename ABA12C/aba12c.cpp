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

#define INF (1<<30)
#define NAME "1"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n, k;
    scanf("%d%d", &n, &k);
    int p[k + 1];
    for (int i = 1; i <= k; ++i)
    {
      scanf("%d", &p[i]);
      if (p[i] == -1) p[i] = INF;
    }
    int dp[k + 1];
    dp[0] = INF;
    for (int i = 1; i <= k; ++i)
    {
      dp[i] = p[i];
      //printf("i = %d, dp[i] = %d\n", i, dp[i]);
      for (int j = 0; j < i; ++j)
      {
        if (dp[j] >= INF) continue;
        dp[i] = min(dp[j] + dp[i - j], dp[i]);
      }
      //printf("i = %d, dp[i] = %d\n", i, dp[i]);
    }
    if (dp[k] >= INF) printf("-1\n");
    else printf("%d\n", dp[k]);
  }
	
  return 0;
}       