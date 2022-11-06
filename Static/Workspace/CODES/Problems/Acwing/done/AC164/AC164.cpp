#include <cstdio>
#include <bitset>
#define MAXN 30005
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
class line;
class node;
class line
{
public:
   node *line_nodepointer_to;
   line *line_linepointer_nt;
};
class node
{
public:
   bitset<MAXN> node_bitset_able;
   line *node_linepointer_fst;
   int node_int_num;
   void node_voidfunction_addline(node *);
   node(void);
   void node_voidfunction_dfs(void);
};
int over_int_n;
int over_int_m;
node over_nodearray_nodes[MAXN];
bool over_boolarray_used[MAXN];
int main()
{
   over_int_n = over_templatefunction_read<int>();
   over_int_m = over_templatefunction_read<int>();
   int main_int_i;
   for (main_int_i = 1; main_int_i <= over_int_n; ++main_int_i)
      over_nodearray_nodes[main_int_i].node_int_num = main_int_i;
   for (main_int_i = 1; main_int_i <= over_int_m; ++main_int_i)
      over_nodearray_nodes[over_templatefunction_read<int>()].node_voidfunction_addline(&over_nodearray_nodes[over_templatefunction_read<int>()]);
   for (main_int_i = 1; main_int_i <= over_int_n; ++main_int_i)
      if (!over_boolarray_used[main_int_i])
         over_nodearray_nodes[main_int_i].node_voidfunction_dfs();
   for (main_int_i = 1; main_int_i <= over_int_n; ++main_int_i)
   {
      put(over_nodearray_nodes[main_int_i].node_bitset_able.count());
      putchar(10);
   }
   return 0;
}
node::node(void)
{
   node_bitset_able.reset();
   node_linepointer_fst = nullptr;
}
void node::node_voidfunction_addline(node *to)
{
   static line *node_voidfunction_addline_linepointer_usline;
   node_voidfunction_addline_linepointer_usline = new line;
   node_voidfunction_addline_linepointer_usline->line_nodepointer_to = to;
   node_voidfunction_addline_linepointer_usline->line_linepointer_nt = node_linepointer_fst;
   node_linepointer_fst = node_voidfunction_addline_linepointer_usline;
   return;
}
void node::node_voidfunction_dfs(void)
{
   if (over_boolarray_used[node_int_num])
      return;
   over_boolarray_used[node_int_num] = true;
   line *node_voidfunction_dfs_linepointer_usline;
   for (node_voidfunction_dfs_linepointer_usline = node_linepointer_fst; node_voidfunction_dfs_linepointer_usline; node_voidfunction_dfs_linepointer_usline = node_voidfunction_dfs_linepointer_usline->line_linepointer_nt)
   {
      node_voidfunction_dfs_linepointer_usline->line_nodepointer_to->node_voidfunction_dfs();
   }
   for (node_voidfunction_dfs_linepointer_usline = node_linepointer_fst; node_voidfunction_dfs_linepointer_usline; node_voidfunction_dfs_linepointer_usline = node_voidfunction_dfs_linepointer_usline->line_linepointer_nt)
   {
      node_bitset_able |= node_voidfunction_dfs_linepointer_usline->line_nodepointer_to->node_bitset_able;
   }
   node_bitset_able[node_int_num] = true;
   return;
}