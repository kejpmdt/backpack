#include <cstdio>
#include <algorithm>
#define MAXN 200005
using namespace std;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=int>T read(void){T x;read(x);return x;}
int fa[MAXN];
int getfa(int x)
{
   if (fa[x] != x)
      fa[x] = getfa(fa[x]);
   return fa[x];
}
int checkp[MAXN][3];
int dy[MAXN];
bool check(int n)
{
   int i;
   for (i = 1; i <= n; ++i)
   {
      if (getfa(checkp[i][0]) == getfa(checkp[i][0]))
         return false;
   }
   return true;
}
int main()
{
   int n,t,i,j;
   bool f;
   t = read();
   for (i = 1; i <= t; ++i)
   {
      n = read();
      for (j = 1; j <= n; ++j)
      {
         checkp[j][0] = read();
         checkp[j][1] = read();
         checkp[j][2] = read();
      }
      for (j = 1; j <= n; ++j)
      {
         dy[j << 1] = checkp[j][0];
         dy[j << 1 | 1] = checkp[j][1];
      }
      for (j = 1; j < MAXN; ++j)fa[j] = j;
      sort(dy, dy + n + n + 1);
      for (j = unique(dy, dy + n + n + 1) - dy; j <= n + n; ++j)dy[j] = 0x7fffffff;
      for (j = 1; j < MAXN; ++j)
      {
         checkp[j][0] = lower_bound(dy, dy + n + n, checkp[j][0]) - dy;
         checkp[j][1] = lower_bound(dy, dy + n + n, checkp[j][1]) - dy;
         checkp[j][2] = lower_bound(dy, dy + n + n, checkp[j][2]) - dy;
      }
      for (j = 1; j <= n; ++j)
         if (checkp[j][2] == 1)
            fa[getfa(checkp[j][0])] = getfa(checkp[j][1]);
      f = true;
      for (j = 1; j <= n; ++j)
         if (checkp[j][2] == 0)
            if (getfa(checkp[j][0]) == getfa(checkp[j][1]))
            {
               f = false;
               printf("NO\n");
               break;
            }
      if (f)printf("YES\n");
   }
   return 0;
}
