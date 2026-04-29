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

const int INF = 0x3f3f3f3f;

#define NAME "1"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

const int maxn = 1e5+111;
int ee[maxn][3];
long long dp[maxn][3];

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  ios::sync_with_stdio(false);

  int k = 1;
  while (1)
  {
    int n;
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        cin >> ee[i][j];
      }
    }
    memset(dp, 127, sizeof(dp));
    dp[0][1] = ee[0][1];
    dp[0][2] = ee[0][2] + ee[0][1];
    for (int i = 1; i < n; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        dp[i][j] = ee[i][j];
        long long x = dp[i - 1][j];
        if (j > 0) 
        {
          x = min(x, dp[i - 1][j - 1]);
          x = min(x, dp[i][j - 1]);
        }
        if (j < 2) x = min(x, dp[i - 1][j + 1]);
        dp[i][j] += x;
      }
    }
    cout << k++ << ". " << dp[n - 1][1] << endl;
  }

  return 0;
}       
