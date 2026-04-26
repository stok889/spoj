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
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n;
    scanf("%d", &n);
    int d[2222];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; ++i)
    {
      int x;
      scanf("%d", &x);
      ++d[1000 + x];
    }
    int ans = -1;
    for (int i = 0; i < 2222; ++i)
    {
      if (d[i] > n / 2)
      {
        ans = i - 1000;
        break;
      }
    }
    if (ans == -1) printf("NO\n");
    else printf("YES %d\n", ans);
  }

  return 0;
}
