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

const int INF = 0x3f3f3f3f;

#define NAME "phone"
#define ABS( a ) ( (a) > 0 ? (a) : -(a) )
#define SIZE( a ) ( int( (a).size() ) )
#define LENGTH( a ) ( int( (a).length() ) )
#define SQR( a ) ( (a) * (a) )

struct tree
{
  bool leaf;
  tree *child[10];

  tree()
  {
    leaf = false;
    for (int i = 0; i < 10; ++i) child[i] = NULL;
  }

  ~tree()
  {
    for (int i = 0; i < 10; ++i) delete child[i];
    for (int i = 0; i < 10; ++i) child[i] = NULL;
  }
};

bool insert(tree *root, string &arg)
{
  int len = LENGTH(arg);
  tree *v = root;
  char ch;
  bool f;
  for (int i = 0; i < len; ++i)
  {
    f = false;
    ch = arg[i] - '0';
    if (v->child[ch] == NULL) 
    {
      v->child[ch] = new tree();
      f = true;
    }
    if (v->leaf == true) return false;
    v = v->child[ch];
  }
  if (v->leaf == true || f == false) return false;
  v->leaf = true;
  return true;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  #endif

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    tree root;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
      string str;
      cin >> str;
      if (insert(&root, str) == false)
      {
        flag = false;
        //break;
      }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}       