// prime1.cpp : Defines the entry point for the console application.
//
#include <cstdio>
#include <string>
#include <cmath>

#ifdef __GNUC__
typedef long long int64;
#else 
typedef __int64 int64;
#endif

const long nn = 100000;

class task
{
 private :
 
 int f[nn];
 
 public :
 
 task() 
 {
 }

 void find_mn_prime(int64 m, int64 n)
 {
  int64 i = m;
  int64 r = n - m + 1;

  memset(f, 0, sizeof(f));

  if (m == 1) i++;
  for (; i <= n; i++)
      {
       if (f[i % r]) continue;

       int flag = 0;

       for (int64 j = 2; j < (int64)sqrt((double)i); j++)	
           if (!(i % j))
	      {
	       flag = 1;
	       break;		
	      }

       for (int64 j = 2 * i; j <= n; j += i)
			f[j % r] = 1;

       if (!flag) break;
      }

  for (; i <= n; i++)
      {
       if (f[i % r] || (i % 2 == 0 && i != 2)) continue;

       printf("%lld\n", i);

       for (int64 j = 2 * i; j <= n; j += i)
		   f[j % r] = 1;
      }
 }
};

task p;

int main()
{
 int t;
 int64 m, n;

 scanf("%d", &t);
 for (int k = 0; k < t; k++)
     {
      scanf("%I64d%I64d", &m, &n);
      p.find_mn_prime(m, n);
	  printf("\n");
     }

 return 0;
}