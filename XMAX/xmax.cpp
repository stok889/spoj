#include <bits/stdc++.h>
using namespace std;
 
const int mxn = 111111;
int n;
unsigned long long ar[mxn];
int used[mxn];
 
unsigned long long genrand()
{
	return (rand() << 30) | rand();
}
 
void gen()
{
	srand(time(NULL));
	n = 15;
	for (int i = 0; i < n; ++i)
	{
		ar[i] = genrand();
		printf("%llu ", ar[i]);
	}
	printf("\n");
}
 
unsigned long long naive()
{
	unsigned long long ret = 0ULL;
	for (int i = 0; i < (1ULL<<n); ++i)
	{
		unsigned long long cret = 0ULL;
		for (int j = 0; j < 64; ++j)
		{
			if (i & (1ULL<<j))
			{
				cret ^= ar[j];
			}
		}
		if (ret < cret) 
		{
			ret = cret;
		}
	}
	return ret;
}
 
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%llu", &ar[i]);
	//gen();
	unsigned long long ans = 0ULL;
	for (int i = 63; i >= 0; --i)
	{
		unsigned long long f = -1;
	  unsigned long long x = 1ULL<<i;
    for (int j = 0; j < n; ++j)
		{
			if (used[j] == 1)	continue;
		 	if (ar[j] & x)
		 	{
		 		if (f == -1)
		 		{
		 			if (!(ans & x)) ans ^= ar[j];
		 			f = ar[j];
		 			used[j] = 1;
		 		}
		 		else ar[j] ^= f;
		 	}
		}
	}
	//printf("naive - %llu\n", naive());
	printf("%llu", ans);

  return 0;
}