#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
#define eps 1e-9

typedef long double LD;
typedef vector < int > VI;
typedef vector < string > VS;
typedef pair < int, int > PII;
typedef map < string, int > MSI;

#define ABS(a) ( (a) < 0 ? -(a) : (a) )
#define SQR(a) ( (a) * (a) )
#define SIZE(a) ( (int) (a).size() )

#ifdef WIN32
typedef __int64 i64;
#define Ld "%I64d"
#else
typedef long long i64;
#define Ld "%lld"
#endif

const char *const in = "javac.in";
const char *const out = "javac.out";

const int nn = 200;
const string err = "Error!";

string ctoj(string s)
{
 string res;
 int L = SIZE(s), f = 0;

 if (s[0] == '_') return err;

 for (int i = 0; i < L; ++i)
     {
      char c = s[i];

      if (c == '_')
         {
          if (f) return err;
          f = 1;
          continue;
         }

      if (f)
         {
          f = 0;
          c = toupper(c);
         }

      res.push_back(c);
     }

 if (f) return err;

 return res;
}

string jtoc(string s)
{
 string res;
 int L = SIZE(s);

 if (isupper(s[0])) return err;

 for (int i = 0; i < L; ++i)
     {
      char c = s[i];
      if (isupper(c))
         {
          c = tolower(c);
          res.push_back('_');
         }
      res.push_back(c);
     }

 return res;
}

int main()
{
 char str[nn];

 for (; scanf("%s\n", str) == 1;)
     {
      //printf("str = %s\n", str);
      int java = 0, cpp = 0;
      for (int i = 0; str[i]; ++i)
          if (isupper(str[i]))
             java = 1;
           else
             {
              if (str[i] == '_')
                  cpp = 1;
             }

      //printf("F = %d\n", F);

      if (java && cpp) 
         printf("%s\n", err.c_str());
       else
         { 
          if (!java && !cpp) 
             printf("%s\n", str);
           else printf("%s\n", cpp == 1 ? ctoj(str).c_str() : jtoc(str).c_str());
         }
     }

 return 0;
}