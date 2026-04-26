#include <cstdio>
#include <string>

using namespace std;

const int nn = 1000010;

int main()
{
 int t;

 scanf("%d\n", &t);
 for (; t; --t)
     {
      char str[nn];
      int l, ost = 0;

      gets(str);
      strtok(str, " \n");

      string s(str), tmp(str);
      l = (int)s.length();

      for (int i = 0; i < l / 2; ++i)
          tmp.at(l - i - 1) = tmp.at(i);

      if (tmp > s)
         {
          printf("%s", tmp.c_str());
          if (t > 1) printf("\n"); 
          continue;
         }

      for (int i = (l >> 1) + (l & 1) - 1; i >= 0; --i)
          {
           char p = s.at(i) + 1;
           ost = 0;
           if (p > '9')
              {
               p = '0';
               ost = 1;
              }
           s.at(i) = p;
           if (!ost) break;
          }

      if (ost)
         {
          //fill(s.begin(), s.end(), '0');
          s.insert(0, "1");
          l++;
         }

      for (int i = 0; i < l / 2; ++i)
          s.at(l - i - 1) = s.at(i);

      printf("%s", s.c_str());
      if (t > 1) printf("\n"); 
     }

 return 0;
}