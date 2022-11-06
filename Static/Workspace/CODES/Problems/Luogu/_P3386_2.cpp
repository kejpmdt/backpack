#include <cstdio>
#include <queue>
#include <cstring>
#define mi2(a, b) (a < b ? a : b)
#define MAXN 205
#define MAXM 10005
using namespace std;
class node;
class line;
class line
{
public:
   node *line_nodepointer_frm;
   node *line_nodepointer_to;
   signed long long line_signedlonglong_v;
   signed int line_signedint_num;
   line *line_linepointer_nt;
   line *line_linepointer_lst;
   line(void);
   void line_voidfunction_add(void);
   void line_voidfunction_add(node *, node *, signed long long);
   void line_voidfunction_rem(void);
};
class node
{
public:
   signed int node_signedint_num;
   line *node_linepointer_fst;
   node(void);
   bool node_boolfunction_runadinic(signed long long &);
};
signed int over_signedint_n, over_signedint_m, over_signedint_s, over_signedint_t;
line over_linearray_lines[MAXM];
node over_nodearray_nodes[MAXN];
signed int over_signedintarray_uss[MAXN];
line *over_linepointerarray_nw[MAXN];
template <class T>
inline T over_templatefunction_read(void);
template <typename T>
void put(T);
signed long long over_signedlonglongfunction_wll(void);
void over_voidfunction_show(void);
void over_voidfunction_dinicbfs(void);
signed long long over_signedlonglongfunction_diniczg(void);
void over_voidfunction_rebuild(void);
signed int main()
{
   //	freopen("us.txt","r",stdin);
   over_signedint_n = over_templatefunction_read<int>();
   over_signedint_m = over_templatefunction_read<int>();
   over_signedint_s = over_templatefunction_read<int>();
   over_signedint_t = over_templatefunction_read<int>();
   signed int main_signedint_i;
   for (main_signedint_i = 1; main_signedint_i <= over_signedint_n; ++main_signedint_i)
      over_nodearray_nodes[main_signedint_i].node_signedint_num = main_signedint_i;
   for (main_signedint_i = 1; main_signedint_i <= over_signedint_m; ++main_signedint_i)
      over_linearray_lines[main_signedint_i << 1 | 1].line_voidfunction_add();
   for (main_signedint_i = 1; main_signedint_i <= over_signedint_m << 1; ++main_signedint_i)
      over_linearray_lines[main_signedint_i].line_signedint_num = main_signedint_i;
   signed long long main_signedint_ans;
   main_signedint_ans = over_signedlonglongfunction_wll();
   put(main_signedint_ans);
   return 0;
}
void over_voidfunction_rebuild(void)
{
   memset(over_linepointerarray_nw, 0x00, sizeof over_linepointerarray_nw);
   signed int over_voidfunction_rebuild_signedint_nw;
   line *over_voidfunction_rebuild_linepointer_usline;
   for (over_voidfunction_rebuild_signedint_nw = 1; over_voidfunction_rebuild_signedint_nw <= over_signedint_n; ++over_voidfunction_rebuild_signedint_nw)
   {
      for (over_voidfunction_rebuild_linepointer_usline = over_nodearray_nodes[over_voidfunction_rebuild_signedint_nw].node_linepointer_fst; over_voidfunction_rebuild_linepointer_usline; over_voidfunction_rebuild_linepointer_usline = over_voidfunction_rebuild_linepointer_usline->line_linepointer_nt)
      {
         if (over_linepointerarray_nw[over_voidfunction_rebuild_linepointer_usline->line_nodepointer_to->node_signedint_num])
         {
            over_linepointerarray_nw[over_voidfunction_rebuild_linepointer_usline->line_nodepointer_to->node_signedint_num]->line_voidfunction_add(over_linepointerarray_nw[over_voidfunction_rebuild_linepointer_usline->line_nodepointer_to->node_signedint_num]->line_nodepointer_frm, over_linepointerarray_nw[over_voidfunction_rebuild_linepointer_usline->line_nodepointer_to->node_signedint_num]->line_nodepointer_to, over_voidfunction_rebuild_linepointer_usline->line_signedlonglong_v);
            over_voidfunction_rebuild_linepointer_usline->line_voidfunction_rem();
         }
         else
         {
            over_linepointerarray_nw[over_voidfunction_rebuild_linepointer_usline->line_nodepointer_to->node_signedint_num] = over_voidfunction_rebuild_linepointer_usline;
         }
      }
   }
}
bool node::node_boolfunction_runadinic(signed long long &mst)
{
   if (node_signedint_num == over_signedint_t)
      return true;
   signed long long node_boolfunction_runadinic_signedlonglong_anothermst;
   signed long long node_boolfunction_runadinic_signedlonglong_restmst = mst;
   if (over_linepointerarray_nw[node_signedint_num] == nullptr)
      over_linepointerarray_nw[node_signedint_num] = node_linepointer_fst;
   for (; over_linepointerarray_nw[node_signedint_num]; over_linepointerarray_nw[node_signedint_num] = over_linepointerarray_nw[node_signedint_num]->line_linepointer_nt)
   {
      if (over_signedintarray_uss[over_linepointerarray_nw[node_signedint_num]->line_nodepointer_to->node_signedint_num] == over_signedintarray_uss[node_signedint_num] + 1)
      {
         while (node_boolfunction_runadinic_signedlonglong_restmst)
         {
            node_boolfunction_runadinic_signedlonglong_anothermst = mi2(over_linepointerarray_nw[node_signedint_num]->line_signedlonglong_v, node_boolfunction_runadinic_signedlonglong_restmst);
            if (over_linepointerarray_nw[node_signedint_num]->line_nodepointer_to->node_boolfunction_runadinic(node_boolfunction_runadinic_signedlonglong_anothermst))
            {
               over_linepointerarray_nw[node_signedint_num]->line_signedlonglong_v -= node_boolfunction_runadinic_signedlonglong_anothermst;
               over_linearray_lines[over_linepointerarray_nw[node_signedint_num]->line_signedint_num ^ 1].line_voidfunction_add(over_linepointerarray_nw[node_signedint_num]->line_nodepointer_to, over_linepointerarray_nw[node_signedint_num]->line_nodepointer_frm, node_boolfunction_runadinic_signedlonglong_anothermst);
               node_boolfunction_runadinic_signedlonglong_restmst -= node_boolfunction_runadinic_signedlonglong_anothermst;
               if (over_linepointerarray_nw[node_signedint_num]->line_signedlonglong_v == 0)
               {
                  over_linepointerarray_nw[node_signedint_num]->line_voidfunction_rem();
                  break;
               }
            }
            else
            {
               break;
            }
         }
      }
   }
   mst -= node_boolfunction_runadinic_signedlonglong_restmst;
   return mst != 0;
}
signed long long over_signedlonglongfunction_diniczg(void)
{
   over_voidfunction_dinicbfs();
   if (over_signedintarray_uss[over_signedint_t] == 0)
      return 0;
   signed long long over_signedlonglongfunction_diniczg_signedlonglong_ans = 0x7fffffffffffffffll;
   over_nodearray_nodes[over_signedint_s].node_boolfunction_runadinic(over_signedlonglongfunction_diniczg_signedlonglong_ans);
   return over_signedlonglongfunction_diniczg_signedlonglong_ans;
}
void over_voidfunction_dinicbfs(void)
{
   memset(over_signedintarray_uss, 0x00, sizeof over_signedintarray_uss);
   deque<int> over_voidfunction_dinicbfs_signedintdeque_d;
   over_signedintarray_uss[over_signedint_s] = 1;
   over_voidfunction_dinicbfs_signedintdeque_d.push_back(over_signedint_s);
   line *over_voidfunction_dinicbfs_linepointer_usline;
   while (!over_voidfunction_dinicbfs_signedintdeque_d.empty())
   {
      for (over_voidfunction_dinicbfs_linepointer_usline = over_nodearray_nodes[over_voidfunction_dinicbfs_signedintdeque_d.front()].node_linepointer_fst; over_voidfunction_dinicbfs_linepointer_usline; over_voidfunction_dinicbfs_linepointer_usline = over_voidfunction_dinicbfs_linepointer_usline->line_linepointer_nt)
      {
         if (!over_signedintarray_uss[over_voidfunction_dinicbfs_linepointer_usline->line_nodepointer_to->node_signedint_num])
         {
            over_signedintarray_uss[over_voidfunction_dinicbfs_linepointer_usline->line_nodepointer_to->node_signedint_num] = over_signedintarray_uss[over_voidfunction_dinicbfs_signedintdeque_d.front()] + 1;
            over_voidfunction_dinicbfs_signedintdeque_d.push_back(over_voidfunction_dinicbfs_linepointer_usline->line_nodepointer_to->node_signedint_num);
         }
      }
      over_voidfunction_dinicbfs_signedintdeque_d.pop_front();
   }
   return;
}
void over_voidfunction_show(void)
{
   printf("\n\n");
   signed int over_voidfunction_show_signedint_nw;
   line *over_voidfunction_show_linepointer_usline;
   for (over_voidfunction_show_signedint_nw = 1; over_voidfunction_show_signedint_nw <= over_signedint_n; ++over_voidfunction_show_signedint_nw)
   {
      printf("%4d %4d\n", over_voidfunction_show_signedint_nw, over_signedintarray_uss[over_voidfunction_show_signedint_nw]);
      for (over_voidfunction_show_linepointer_usline = over_nodearray_nodes[over_voidfunction_show_signedint_nw].node_linepointer_fst; over_voidfunction_show_linepointer_usline; over_voidfunction_show_linepointer_usline = over_voidfunction_show_linepointer_usline->line_linepointer_nt)
      {
         printf("     %4d %4lld\n", over_voidfunction_show_linepointer_usline->line_nodepointer_to->node_signedint_num, over_voidfunction_show_linepointer_usline->line_signedlonglong_v);
      }
   }
   printf("\n\n");
   return;
}
void line::line_voidfunction_add(node *frm, node *to, signed long long v)
{
   line_nodepointer_frm = frm;
   line_nodepointer_to = to;
   line_signedlonglong_v += v;
   line_linepointer_nt = line_nodepointer_frm->node_linepointer_fst;
   line_linepointer_lst = nullptr;
   line_nodepointer_frm->node_linepointer_fst = this;
   if (line_linepointer_nt)
      line_linepointer_nt->line_linepointer_lst = this;
   return;
}
void line::line_voidfunction_rem(void)
{
   if (line_nodepointer_frm->node_linepointer_fst == this)
      line_nodepointer_frm->node_linepointer_fst = line_linepointer_nt;
   if (line_linepointer_lst)
      line_linepointer_lst->line_linepointer_nt = line_linepointer_nt;
   if (line_linepointer_nt)
      line_linepointer_nt->line_linepointer_lst = line_linepointer_lst;
   line_signedlonglong_v = 0;
}
line::line(void)
{
   line_nodepointer_frm = line_nodepointer_to = nullptr;
   line_linepointer_lst = line_linepointer_nt = nullptr;
   line_signedlonglong_v = 0;
}
node::node(void)
{
   node_linepointer_fst = nullptr;
}

signed long long over_signedlonglongfunction_wll(void)
{
   signed long long over_signedlonglongfunction_wll_signedint_ans = 0;
   signed long long over_signedlonglongfunction_wll_signedint_us = 1;
   memset(over_linepointerarray_nw, 0x00, sizeof over_linepointerarray_nw);
   do
   {
      over_signedlonglongfunction_wll_signedint_us = over_signedlonglongfunction_diniczg();
      over_signedlonglongfunction_wll_signedint_ans += over_signedlonglongfunction_wll_signedint_us;
   } while (over_signedlonglongfunction_wll_signedint_us);
   return over_signedlonglongfunction_wll_signedint_ans;
}

inline void line::line_voidfunction_add(void)
{
   line_nodepointer_frm = &over_nodearray_nodes[over_templatefunction_read<int>()];
   line_nodepointer_to = &over_nodearray_nodes[over_templatefunction_read<int>()];
   line_signedlonglong_v = over_templatefunction_read<signed long long>();
   line_linepointer_nt = line_nodepointer_frm->node_linepointer_fst;
   line_linepointer_lst = nullptr;
   line_nodepointer_frm->node_linepointer_fst = this;
   if (line_linepointer_nt)
      line_linepointer_nt->line_linepointer_lst = this;
   return;
}
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
   putchar(x > 9 ? put(x / 10), x % 10 | 48 : x % 10 | 48);
}
