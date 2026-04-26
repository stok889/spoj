#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

#define sqr(a) ((a) * (a))

using namespace std;

const int c = 10001;

class point
{
 public :
 int x, y;
 long num;
 
 int operator < (const point &arg) const
 {
  return (x != arg.x ? x < arg.x : y < arg.y);
 }
 int cross(const point &arg1, const point &arg2)
 {
  return (arg1.x - x) * (arg2.y - y) - (arg2.x - x) * (arg1.y - y);
 }
 double countL(const point &arg)
 {
  return sqrt(sqr(arg.x - x) + sqr(arg.y - y));
 }
};

class task
{
 private :
 vector <point> m; 
 set <long> hesh;
 
 public : 
 task();
 vector <point> convexHull();
 double countLen(vector <point>);
};

int main()
{
 task *p;

 p = new task();

 return 0;
}

task :: task()
{
 int t;

 scanf("%d", &t);
 for (int k = 0; k < t; k++)
     {
      long n;

      m.clear();
      hesh.clear();

      scanf("%ld", &n);
      for (long i = 0; i < n; i++)
          {
           point p;

           scanf("%d%d", &p.x, &p.y);
           p.num = i + 1;

           if (hesh.find(p.x * c + p.y) != hesh.end()) continue;

           m.push_back(p);
           hesh.insert(p.x * c + p.y);
          }

      vector <point> ans = convexHull();
      double l = countLen(ans);
      printf("%.2lf\n", l);
      
      long uk = 0;
      for (long i = 1; i < (long)ans.size(); i++)
          if (ans[uk].y > ans[i].y || 
             (ans[uk].y == ans[i].y && ans[uk].x > ans[i].x))
             uk = i;

      for (long i = uk; i < (long)ans.size(); i++)
          {
           printf("%ld ", ans[i].num);
          }
      for (long i = 0; i < uk; i++)
          {
           printf("%ld ", ans[i].num);
          }
      printf("\n\n");
     }
}

vector <point> task :: convexHull()
{
 vector <point> res;
 long limit = 1;

 sort(m.begin(), m.end()); 
 res.push_back(m[0]);

 for (long i = 1; i < (long)m.size(); i++)
     {
      for (;(long)res.size() > limit;)
          {
           if (res[res.size() - 2].cross(res[res.size() - 1], m[i]) > 0) break;
           res.pop_back();
          }
      res.push_back(m[i]);
     }

 limit = res.size();

 for (long i = m.size() - 1; i >= 0; i--)
     {
      for (;(long)res.size() > limit;)
          {
           if (res[res.size() - 2].cross(res[res.size() - 1], m[i]) > 0) break;
           res.pop_back();
          }
      res.push_back(m[i]);
     }

 res.pop_back();

 return res;
}

double task :: countLen(vector <point> ans)
{
 double res = 0.000000;

 if ((long)ans.size() == 1) return res;

 res = ans[ans.size() - 1].countL(ans[0]);
 for (long i = 0; i < (long)ans.size() - 1; i++)
     res += ans[i].countL(ans[i + 1]);

 return res;
}