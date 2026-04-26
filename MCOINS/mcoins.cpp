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

const int maxn = 1e6 + 11;

int k, l;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  int dp[maxn];
  int m;
  cin >> k >> l >> m;
  memset(dp, -1, sizeof(dp));
  dp[1] = 0;
  dp[k] = 0;
  dp[l] = 0;
  for (int i = 2; i < maxn; ++i)
  {
    if (dp[i] != -1) continue;
    int mn = 0;
    mn = max(mn, dp[i - 1]);
    if (i > k) mn = max(mn, dp[i - k]);
    if (i > l) mn = max(mn, dp[i - l]);
    dp[i] = 1 - mn;
  }

  while (m--)
  {
    int n;
    cin >> n;
    cout << (dp[n] == 0 ? 'A' : 'B');
  }
	
  return 0;
}       
