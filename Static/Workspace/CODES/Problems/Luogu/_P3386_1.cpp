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
   int line_int_num;
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
   int node_int_num;
   line *node_linepointer_fst;
   node(void);
   bool node_boolfunction_runadinic(void);
};
int over_int_n, over_int_m, over_int_s, over_int_t;
line over_linearray_lines[MAXM];
node over_nodearray_nodes[MAXN];
int over_intarray_uss[MAXN];
line *over_linepointerarray_frm[MAXN];
template <class T>
inline T over_templatefunction_read(void);
template <typename T>
void put(T);
signed long long over_signedlonglongfunction_wll(void);
signed long long over_signedlonglongfunction_zg(void);
void over_voidfunction_show(void);
void over_voidfunction_dinicbfs(void);
signed long long over_signedlonglongfunction_diniczg(void);
int main()
{
   freopen("us.txt", "r", stdin);
   over_int_n = over_templatefunction_read<int>();
   over_int_m = over_templatefunction_read<int>();
   over_int_s = over_templatefunction_read<int>();
   over_int_t = over_templatefunction_read<int>();
   int main_int_i;
   for (main_int_i = 1; main_int_i <= over_int_n; ++main_int_i)
      over_nodearray_nodes[main_int_i].node_int_num = main_int_i;
   for (main_int_i = 1; main_int_i <= over_int_m; ++main_int_i)
      over_linearray_lines[main_int_i << 1 | 1].line_voidfunction_add();
   for (main_int_i = 1; main_int_i <= over_int_m << 1; ++main_int_i)
      over_linearray_lines[main_int_i].line_int_num = main_int_i;
   signed long long main_int_ans;
   main_int_ans = over_signedlonglongfunction_wll();
   put(main_int_ans);
   return 0;
}
bool node::node_boolfunction_runadinic(signed long long &mst)
{
   if (node_int_num == over_int_t)
      return true;
   line *node_boolfunction_runadinic_pointer_usline;
   signed long long node_boolfunction_runadinic_signedlonglong_anothermst;
   for (node_boolfunction_runadinic_pointer_usline = node_linepointer_fst; node_boolfunction_runadinic_pointer_usline; node_boolfunction_runadinic_pointer_usline = node_boolfunction_runadinic_pointer_usline->line_linepointer_nt)
   {
      if (over_intarray_uss[node_boolfunction_runadinic_pointer_usline->line_nodepointer_to->node_int_num] == over_intarray_uss[node_int_num] + 1)
      {
         if (node_boolfunction_runadinic_pointer_usline->line_nodepointer_to->node_boolfunction_runadinic(mst))
         {
            node_boolfunction_runadinic_pointer_usline->line_signedlonglong_v -= mst;
            if (node_boolfunction_runadinic_pointer_usline->line_signedlonglong_v != 0)
               over_linepointerarray_frm[node_boolfunction_runadinic_pointer_usline->line_nodepointer_to->node_int_num] = node_boolfunction_runadinic_pointer_usline;
            return true;
         }
      }
   }
   return false;
}
signed long long over_signedlonglongfunction_diniczg(void)
{
   over_voidfunction_dinicbfs();
   if (over_intarray_uss[over_int_t] == 0)
      return 0;
   signed long long over_signedlonglongfunction_diniczg_signedlonglong_ans = 0;
   signed long long over_signedlonglongfunction_diniczg_signedlonglong_us;
   line *over_signedlonglongfunction_diniczg_linepointer_usline;
   while (over_nodearray_nodes[over_int_s].node_boolfunction_runadinic())
   {
      over_signedlonglongfunction_diniczg_signedlonglong_us = 0x7fffffff;
      for (over_signedlonglongfunction_diniczg_linepointer_usline = over_linepointerarray_frm[over_int_t]; over_signedlonglongfunction_diniczg_linepointer_usline; over_signedlonglongfunction_diniczg_linepointer_usline = over_linepointerarray_frm[over_signedlonglongfunction_diniczg_linepointer_usline->line_nodepointer_frm->node_int_num])
      {
         over_signedlonglongfunction_diniczg_signedlonglong_us = mi2(over_signedlonglongfunction_diniczg_signedlonglong_us, over_signedlonglongfunction_diniczg_linepointer_usline->line_signedlonglong_v);
      }
      for (over_signedlonglongfunction_diniczg_linepointer_usline = over_linepointerarray_frm[over_int_t]; over_signedlonglongfunction_diniczg_linepointer_usline; over_signedlonglongfunction_diniczg_linepointer_usline = over_linepointerarray_frm[over_signedlonglongfunction_diniczg_linepointer_usline->line_nodepointer_frm->node_int_num])
      {
         over_signedlonglongfunction_diniczg_linepointer_usline->line_signedlonglong_v -= over_signedlonglongfunction_diniczg_signedlonglong_us;
         over_linearray_lines[over_signedlonglongfunction_diniczg_linepointer_usline->line_int_num ^ 1].line_voidfunction_add(over_signedlonglongfunction_diniczg_linepointer_usline->line_nodepointer_to, over_signedlonglongfunction_diniczg_linepointer_usline->line_nodepointer_to, over_signedlonglongfunction_diniczg_signedlonglong_us);
         if (!over_signedlonglongfunction_diniczg_linepointer_usline->line_signedlonglong_v)
            over_signedlonglongfunction_diniczg_linepointer_usline->line_voidfunction_rem();
      }
      over_signedlonglongfunction_diniczg_signedlonglong_ans += over_signedlonglongfunction_diniczg_signedlonglong_us;
   }
   return over_signedlonglongfunction_diniczg_signedlonglong_ans;
}

void over_voidfunction_dinicbfs(void)
{
   memset(over_intarray_uss, 0x00, sizeof over_intarray_uss);
   deque<int> over_voidfunction_dinicbfs_intdeque_d;
   over_intarray_uss[over_int_s] = 1;
   over_voidfunction_dinicbfs_intdeque_d.push_back(over_int_s);
   line *over_voidfunction_dinicbfs_linepointer_usline;
   while (!over_voidfunction_dinicbfs_intdeque_d.empty())
   {
      for (over_voidfunction_dinicbfs_linepointer_usline = over_nodearray_nodes[over_voidfunction_dinicbfs_intdeque_d.front()].node_linepointer_fst; over_voidfunction_dinicbfs_linepointer_usline; over_voidfunction_dinicbfs_linepointer_usline = over_voidfunction_dinicbfs_linepointer_usline->line_linepointer_nt)
      {
         if (!over_intarray_uss[over_voidfunction_dinicbfs_linepointer_usline->line_nodepointer_to->node_int_num])
         {
            over_intarray_uss[over_voidfunction_dinicbfs_linepointer_usline->line_nodepointer_to->node_int_num] = over_intarray_uss[over_voidfunction_dinicbfs_intdeque_d.front()] + 1;
            over_voidfunction_dinicbfs_intdeque_d.push_back(over_voidfunction_dinicbfs_linepointer_usline->line_nodepointer_to->node_int_num);
         }
      }
      over_voidfunction_dinicbfs_intdeque_d.pop_front();
   }
   return;
}
void over_voidfunction_show(void)
{
   printf("\n\n");
   int over_voidfunction_show_int_nw;
   line *over_voidfunction_show_linepointer_usline;
   for (over_voidfunction_show_int_nw = 1; over_voidfunction_show_int_nw <= over_int_n; ++over_voidfunction_show_int_nw)
   {
      printf("%4d %4d\n", over_voidfunction_show_int_nw, over_intarray_uss[over_voidfunction_show_int_nw]);
      for (over_voidfunction_show_linepointer_usline = over_nodearray_nodes[over_voidfunction_show_int_nw].node_linepointer_fst; over_voidfunction_show_linepointer_usline; over_voidfunction_show_linepointer_usline = over_voidfunction_show_linepointer_usline->line_linepointer_nt)
      {
         printf("     %4d %4lld\n", over_voidfunction_show_linepointer_usline->line_nodepointer_to->node_int_num, over_voidfunction_show_linepointer_usline->line_signedlonglong_v);
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
signed long long over_signedlonglongfunction_zg(void)
{
   memset(over_intarray_uss, 0x7f, sizeof over_intarray_uss);
   memset(over_linepointerarray_frm, 0x00, sizeof over_linepointerarray_frm);
   deque<int> over_signedlonglongfunction_zg_intdeque_q;
   over_signedlonglongfunction_zg_intdeque_q.push_back(over_int_s);
   over_intarray_uss[over_int_s] = 0;
   line *over_signedlonglongfunction_zg_linepointer_usline;
   while (!over_signedlonglongfunction_zg_intdeque_q.empty() && over_intarray_uss[over_int_t] == 0x7f7f7f7f)
   {
      for (over_signedlonglongfunction_zg_linepointer_usline = over_nodearray_nodes[over_signedlonglongfunction_zg_intdeque_q.front()].node_linepointer_fst; over_signedlonglongfunction_zg_linepointer_usline; over_signedlonglongfunction_zg_linepointer_usline = over_signedlonglongfunction_zg_linepointer_usline->line_linepointer_nt)
      {
         if (over_intarray_uss[over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_to->node_int_num] == 0x7f7f7f7f)
         {
            over_signedlonglongfunction_zg_intdeque_q.push_back(over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_to->node_int_num);
            over_intarray_uss[over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_to->node_int_num] = over_intarray_uss[over_signedlonglongfunction_zg_intdeque_q.front()] + 1;
            over_linepointerarray_frm[over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_to->node_int_num] = over_signedlonglongfunction_zg_linepointer_usline;
         }
      }
      over_signedlonglongfunction_zg_intdeque_q.pop_front();
   }
   if (!over_linepointerarray_frm[over_int_t])
      return 0;
   signed long long over_signedlonglongfunction_zg_signedlonglong_ans = 0x7f7f7f7f;
   for (over_signedlonglongfunction_zg_linepointer_usline = over_linepointerarray_frm[over_int_t]; over_signedlonglongfunction_zg_linepointer_usline; over_signedlonglongfunction_zg_linepointer_usline = over_linepointerarray_frm[over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_frm->node_int_num])
   {
      over_signedlonglongfunction_zg_signedlonglong_ans = mi2(over_signedlonglongfunction_zg_signedlonglong_ans, over_signedlonglongfunction_zg_linepointer_usline->line_signedlonglong_v);
   }
   for (over_signedlonglongfunction_zg_linepointer_usline = over_linepointerarray_frm[over_int_t]; over_signedlonglongfunction_zg_linepointer_usline; over_signedlonglongfunction_zg_linepointer_usline = over_linepointerarray_frm[over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_frm->node_int_num])
   {
      over_signedlonglongfunction_zg_linepointer_usline->line_signedlonglong_v -= over_signedlonglongfunction_zg_signedlonglong_ans;
      over_linearray_lines[over_signedlonglongfunction_zg_linepointer_usline->line_int_num ^ 1].line_voidfunction_add(over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_to, over_signedlonglongfunction_zg_linepointer_usline->line_nodepointer_to, over_signedlonglongfunction_zg_signedlonglong_ans);
      if (!over_signedlonglongfunction_zg_linepointer_usline->line_signedlonglong_v)
         over_signedlonglongfunction_zg_linepointer_usline->line_voidfunction_rem();
   }
   return over_signedlonglongfunction_zg_signedlonglong_ans;
}
signed long long over_signedlonglongfunction_wll(void)
{
   signed long long over_signedlonglongfunction_wll_int_ans = 0;
   signed long long over_signedlonglongfunction_wll_int_us = 1;
   do
   {
      over_signedlonglongfunction_wll_int_us = over_signedlonglongfunction_diniczg();
      over_signedlonglongfunction_wll_int_ans += over_signedlonglongfunction_wll_int_us;
   } while (over_signedlonglongfunction_wll_int_us);
   return over_signedlonglongfunction_wll_int_ans;
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
