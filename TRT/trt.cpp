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

#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

int main()
{
  int n;
  scanf("%d", &n);
  int ar[n];
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i)
    scanf("%d", &ar[i]);
  dp[0][0] = 0;
  dp[1][0] = ar[n - 1];
  dp[1][1] = ar[0];
  for (int i = 2; i <= n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      if (j == 0)
      {
        dp[i][j] = dp[i - 1][j] + i * ar[n - i];
      }
      else
      {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + i * ar[j - 1]);
        if (j < i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + i * ar[n - (i - j)]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    if (ans < dp[n][i]) ans = dp[n][i];
  printf("%d", ans);
  return 0;
}