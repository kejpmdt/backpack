#include <cstdio>
#define MAXN 500005
#define MAXM 1000005
using namespace std;
int length[MAXN];
int data[MAXN];
int fst[MAXN], nt[MAXM];
int to[MAXM];
int leafnum[MAXM];
void addline(int a, int b)
{
   static int i = 0;
   to[++i] = b, nt[i] = fst[a], fst[a] = i;
   to[++i] = a, nt[i] = fst[b], fst[b] = i;
}
int leafsum;
void dfs1(int nw, int f)
{
   int i;
   length[nw] = 0;
   leafnum[nw] = 0;
   if (to[fst[nw]] == f)
   {
      fst[nw] = nt[fst[nw]];
   }
   if (fst[nw] == 0)
   {
      leafnum[nw] = 1;
      ++leafsum;
   }
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[nt[i]] == f)
      {
         nt[i] = nt[nt[i]];
      }
      dfs1(to[i], nw);
      leafnum[nw] += leafnum[to[i]];
      length[nw] += length[to[i]];
   }
   length[nw] += leafnum[nw] * data[nw];
}
double ans = -100;
void dfs2(int nw, int lst, int leftnum)
{
   if (nw == 1 && nt[fst[nw]] == 0 || fst[nw] == 0)
   {
      if (1.0 * (lst + length[nw] + leftnum * data[nw]) / (leafsum - 1) > ans)
      {
         ans = 1.0 * (lst + length[nw] + leftnum * data[nw]) / (leafsum - 1);
      }
   }
   else
   {
      if (1.0 * (lst + length[nw] + leftnum * data[nw]) / (leafsum) > ans)
      {
         ans = 1.0 * (lst + length[nw] + leftnum * data[nw]) / (leafsum);
      }
   }
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      dfs2(to[i], lst + length[nw] - length[to[i]] - data[nw] * leafnum[to[i]], leftnum + leafnum[nw] - leafnum[to[i]]);
   }
}
template <typename T>
void read(T &ans)
{
   ans = 0;
   char us = getchar();
   bool f = false;
   while (us < 48 || us > 57)
   {
      f |= (us == 45);
      us = getchar();
   }
   while (us > 47 && us < 58)
   {
      ans = (ans << 1) + (ans << 3) + (us ^ 48);
      us = getchar();
   }
   ans *= f ? -1 : 1;
   return;
}
template <typename T, typename... O>
void read(T &x, O &...oth)
{
   read(x);
   read(oth...);
}
int main()
{
   int n;
   read(n);
   int u, v;
   for (int i = 1; i < n; ++i)
   {
      read(u, v);
      addline(u, v);
   }
   for (int i = 1; i <= n; ++i)
   {
      read(data[i]);
   }
   dfs1(1, 1);
   if (nt[fst[1]] == 0)
   {
      ++leafsum;
   }
   dfs2(1, 0, 0);
   printf("%.4f", ans);
}