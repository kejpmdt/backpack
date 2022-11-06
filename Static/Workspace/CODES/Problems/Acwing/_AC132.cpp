#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
template <class T>
inline T over_templatefunction_read(void)
{
   T ans;
   static bool f;
   static char us = getchar();
   ans = 0;
   f = false;
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
   return f ? -ans : ans;
}
template <typename T>
void put(T x)
{
   if (x < 0)
      return putchar(45), put(-x);
   else
      putchar(x > 9 ? put(x / 10), x % 10 | 48 : x % 10 | 48);
}
class man
{
public:
   man *lst;
   man *nt;
   int bh;
};
man *fst, *lst;
int xz[1000000];
man *top[1005];
void show(void)
{
   man *a;
   a = fst->nt;
   while (a->bh != -1)
   {
      printf("%d ", a->bh);
      a = a->nt;
   }
}
int main()
{
   freopen("C:\\Users\\Dell\\Desktop\\us.txt", "r", stdin);
   int t;
   int u;
   int n;
   string opt;
   fst = lst = new man;
   fst->nt = lst->lst = lst;
   fst->bh = -1;
   int nw = 1;
   while (1)
   {
      t = over_templatefunction_read<int>();
      memset(top, 0x00, sizeof top);
      if (t == 0)
         return 0;
      printf("Scenario #%d\n", nw);
      ++nw;
      for (int i = 1; i <= t; ++i)
      {
         n = over_templatefunction_read<int>();
         for (int j = 1; j <= n; ++j)
         {
            u = over_templatefunction_read<int>();
            xz[u] = i;
         }
      }
      fst = lst = new man;
      fst->nt = lst->lst = lst;
      fst->bh = -1;
      do
      {
         cin >> opt;
         if (opt == "STOP")
            break;
         if (opt == "ENQUEUE")
         {
            u = over_templatefunction_read<int>();
            if (top[xz[u]] == nullptr || top[xz[u]] == lst)
            {
               lst->nt = new man;
               lst->nt->lst = lst;
               lst = lst->nt;
               lst->bh = u;
               lst->nt = fst;
               top[xz[u]] = lst;
            }
            else
            {
               top[xz[u]]->nt->lst = new man;
               top[xz[u]]->nt->lst->nt = top[xz[u]]->nt;
               top[xz[u]]->nt->lst->lst = top[xz[u]];
               top[xz[u]]->nt = top[xz[u]]->nt->lst;
               top[xz[u]] = top[xz[u]]->nt;
               top[xz[u]]->bh = u;
            }
         }
         else
         {
            if (top[xz[lst->nt->bh]] == lst->nt)
               top[xz[lst->nt->bh]] = nullptr;
            printf("%d\n", fst->nt->bh);
            fst->nt->nt->lst = fst;
            fst->nt = fst->nt->nt;
         }
         //		show();
      } while (1);
      putchar(10);
   }
}
