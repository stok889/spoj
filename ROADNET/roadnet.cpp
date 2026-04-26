#include <cstdio>
#include <string>

#define NN 201

using namespace std;

class Task
{
 private :
 int t;
 int N;
 int map[NN][NN];

 void Load();
 void solve();

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
 scanf("%d", &t);
 Load();
}

void Task :: Load()
{
 int i;
 int j, k;

 for (k = 0; k < t; k++)
     {
      memset(map, 0, sizeof(map));
      scanf("%d", &N);
      for (i = 0; i < N; i++)
          for (j = 0; j < N; j++)
              scanf("%d", &map[i][j]);
      solve();
     }
}

void Task :: solve()
{
 int i, j, k;
 int f;

 for (i = 0; i < N - 1; i++)
     for (j = i + 1; j < N; j++)
         {
          if (map[i][j])
             {
              f = 1;
              for (k = 0; k < N; k++)
                  if (map[i][k] && map[k][j] && 
	              map[i][j] == map[i][k] + map[k][j])
	              {
	               f = 0;
	               break;
	              }
	      if (f)
	         printf("%d %d\n", i + 1, j + 1);
             }
         }
}