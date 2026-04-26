#include <cstdio>

#define NN 100001

using namespace std;

class Task
{
 private : 
 long n; 
 long p1[NN], p2[NN];

 void load();
 int chek();

 public :
 Task();
};

int main()
{
 Task *p;

 p = new Task();

 return 0;
}

Task :: Task()
{
 load();
}

void Task :: load()
{
 long i;

 scanf("%ld", &n);
 for (;n;)
     {
      for (i = 0; i < n; i++)
          {
           scanf("%ld", &p1[i]);
           p2[p1[i] - 1] = i + 1;
          }
      if (chek())
         printf("ambiguous\n");
       else printf("not ambiguous\n");
      scanf("%ld", &n);
     }
}

int Task :: chek()
{
 long i;
 for (i = 0; i < n; i++)
     if (p1[i] != p2[i])
        return 0;
 return 1;
}