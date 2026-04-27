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

const int MOD = 10000007;

long long p(int a, int b)
{
  long long ret = 1LL;
  long long x = a;
  if (b & 1)
  {
    ret = a;
    x = a;
  }
  b >>= 1;
  while (b)
  {
    x = SQR(x);
    x %= MOD;
    if (b & 1)
    {
      ret *= x;
      ret %= MOD;
    }
    b >>= 1;
  } 
  return ret;
}

int main()
{
  while (1)
  {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 0 && k == 0) break;
    long long ans = 0LL;
    ans += 2 * p(n - 1, n - 1);
    ans %= MOD;
    ans += 2 * p(n - 1, k);
    ans %= MOD;
    ans += p(n, k);
    ans %= MOD;
    ans += p(n, n);
    ans %= MOD;
    printf("%Ld\n", ans);
  }
  return 0;
}