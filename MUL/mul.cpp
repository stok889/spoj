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
#include <complex>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>

using namespace std;

#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

const int nn = 11111;
int n;

vector<complex<double> > fft(complex<double> *x)
{
  int rev[n], high = -1;
  rev[0] = 0;
  int k = log2(n);
  for (int i = 1; i < n; ++i)
  {
    if ((i & (i - 1)) == 0) ++high;
    rev[i] = rev[i ^ (1 << high)];
    rev[i] |= 1 << (k - high - 1);
  }
  vector<complex<double> > cur(n);
  for (int i = 0; i < n; ++i)
    cur[i] = x[rev[i]];
  complex<double> w[n];
  for (int i = 0; i < n; ++i)
  {
    double r = 2.0 * M_PI * double(i) / double(n);
    w[i] = complex<double> (cos(r), sin(r));
  }
  for (int l = 1; l < n; l <<= 1)
  {
    int len = l << 1;
    int nroot = n / len;
    vector<complex<double> > ncur(n);
    for (int i = 0; i < n; i += len)
    {
      int p1 = i;
      for (int j = 0; j < l; ++j)
      {
        complex<double> p2 = w[nroot * j] * cur[p1 + l];
        ncur[p1] = cur[p1] + p2;
        ncur[p1 + l] = cur[p1] - p2;
        ++p1;
      }
    }
    swap(cur, ncur);
  }
  return cur;
}

int main()
{
  int T;
  scanf("%d\n", &T);
  while (T--)
  {
    char s1[nn], s2[nn];
    scanf("%s %s\n", s1, s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    int nn = l1 + l2 + 1;
    n = 1;
    while (nn > n) n <<= 1;
    complex<double> x1[n], x2[n];
    for (int i = 0; i < l1; ++i) x1[i] = s1[l1 - i - 1] - '0';
    for (int i = 0; i < l2; ++i) x2[i] = s2[l2 - i - 1] - '0';
    vector<complex<double> > a1 = fft(x1);
    vector<complex<double> > a2 = fft(x2); 
    complex<double> a[n];
    for (int i = 0; i < n; ++i) a[i] = a1[i] * a2[i];
    vector<complex<double> > ret = fft(a);
    for (int i = 0; i < n; ++i) ret[i] /= n;
    for (int i = 1; i < n / 2; ++i) swap(ret[i], ret[n - i]);
    int ans[n + 1];
    int d = 0;
    for (int i = 0; i < n; ++i)
    {
      ans[i] = int(ret[i].real() + 1e-5) % 10 + d;
      d = int(ret[i].real() + 1e-5) / 10 + ans[i] / 10;
      ans[i] %= 10;
    }
    ans[n] = d;
    int i = n;
    while (i > 0 && ans[i] == 0) --i;
    while (i >= 0) printf("%d", ans[i--]);
    printf("\n");
  }
  return 0;
}