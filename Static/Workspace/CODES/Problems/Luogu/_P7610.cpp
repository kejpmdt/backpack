#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 30000
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
using namespace std;
class player;
class buff;
class heap;
class player
{
public:
   signed long long player_signedlonglong_hp;          //
   signed long long player_signedlonglong_HP;          //
   signed long long player_signedlonglong_mp;          //
   signed long long player_signedlonglong_MP;          //
   signed long long player_signedlonglong_atk;         //
   signed long long player_signedlonglong_def;         //
   signed long long player_signedlonglong_deltaatk;    //
   signed long long player_signedlonglong_deltadef;    //
   signed long long player_signedlonglong_deltamp;     //
   signed long long player_signedlonglong_jn;          //
   signed long long player_signedlonglong_jnnum1;      //
   signed long long player_signedlonglong_jnnum2;      //
   signed long long player_signedlonglong_jnnum3;      //
   signed long long player_signedlonglong_tf;          //
   signed long long player_signedlonglong_tfnum1;      //
   signed long long player_signedlonglong_tfnum2;      //
   signed long long player_signedlonglong_nwtargetnum; //
   signed long long player_signedlonglong_teamnum;     //
   bool player_bool_isdead;                            //
   player *player_playerpointerarray_targets[MAXN];    //

   void player_voidfunction_init(signed long long);                   //
   void player_voidfunction_jn(signed long long);                     //
   void player_voidfunction_pg(void);                                 //
   void player_voidfunction_hurt(signed long long, signed long long); //
   signed long long player_signedlonglongfunction_job(void);          //

   player(void); //
};
class buff
{
public:
   signed long long buff_signedlonglong_endtime;
   signed long long buff_signedlonglong_effectmp;
   signed long long buff_signedlonglong_effectdef;
   signed long long buff_signedlonglong_effectatk;
   signed long long buff_signedlonglong_effectteamnum;

   buff(signed long long, signed long long, signed long long, signed long long, signed long long); //
   bool operator()(const buff *a, const buff *b)
   {
      return a->buff_signedlonglong_endtime > b->buff_signedlonglong_endtime;
   }
};
class heap
{
private:
   void heap_voidfunction_sp(buff *&, buff *&);

public:
   signed long long heap_signedlonglong_sz;
   buff *heap_buffpointerarray_D[MAXN];
   void heap_voidfunction_init(void);
   buff *heap_buffpointerfunction_top(void);
   void heap_voidfunction_pop(void);
   void heap_voidfunction_upcheck(int);
   void heap_voidfunction_downcheck(int);
   void heap_voidfunction_push(buff *);
   bool heap_boolfunction_empty(void);
};
signed long long over_signedlonglong_n;
signed long long over_signedlonglong_gameendtime;
signed long long over_signedlonglong_gameoverteamnum;
player *over_playerpointerarray_players[MAXN][2];
heap over_heap_buffs;

template <class T>
inline T over_templatefunction_read(void);
template <typename T>
void put(T x);
void over_voidfunction_runit(signed long long, signed long long); //
bool over_boolfunction_check(signed long long);                   //
void over_voidfunction_play(void);                                //
void over_voidfunction_init(void);                                //
void over_voidfunction_js(signed long long);                      //
void over_voidfunction_show(signed long long);                    //
void over_voidfunction_roundend(signed long long);
void over_voidfunction_debugshow(void);
bool over_boolfunction_findtarget(signed long long);
void over_bool signed int main()
{
   freopen("us.txt", "r", stdin);
   over_voidfunction_init();
   over_voidfunction_play();
   return 0;
}
bool heap::heap_boolfunction_empty(void)
{
   return heap_signedlonglong_sz == 0;
}
void over_voidfunction_debugshow(void)
{
   signed long long over_voidfunction_debugshow_signedlonglong_i;
   printf("\n\n\n\n\n\n");
   printf("Alice:\n");
   for (over_voidfunction_debugshow_signedlonglong_i = 1; over_voidfunction_debugshow_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_debugshow_signedlonglong_i)
   {
      if (over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0])
         printf("%3lld %3lld/%3lld %3lld/%3lld(+%3lld) %3lld+%-3lld %3lld+%-3lld %2lld:%3lld,%3lld,%3lld %2lld:%3lld,%3lld %3lld\n",
                over_voidfunction_debugshow_signedlonglong_i,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_hp,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_HP,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_mp,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_MP,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_deltamp,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_atk,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_deltaatk,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_def,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_deltadef,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_jn,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_jnnum1,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_jnnum2,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_jnnum3,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_tf,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_tfnum1,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_tfnum2,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_playerpointerarray_targets[over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_nwtargetnum]->player_signedlonglong_hp);
   }
   printf("Bob:\n");
   for (over_voidfunction_debugshow_signedlonglong_i = 1; over_voidfunction_debugshow_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_debugshow_signedlonglong_i)
   {
      if (over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1])
         printf("%3lld %3lld/%3lld %3lld/%3lld(+%3lld) %3lld+%-3lld %3lld+%-3lld %2lld:%3lld,%3lld,%3lld %2lld:%3lld,%3lld %3lld\n",
                over_voidfunction_debugshow_signedlonglong_i,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_hp,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_HP,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_mp,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_MP,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_deltamp,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_atk,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_deltaatk,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_def,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_deltadef,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_jn,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_jnnum1,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_jnnum2,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_jnnum3,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_tf,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_tfnum1,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_signedlonglong_tfnum2,
                over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][1]->player_playerpointerarray_targets[over_playerpointerarray_players[over_voidfunction_debugshow_signedlonglong_i][0]->player_signedlonglong_nwtargetnum]->player_signedlonglong_hp);
   }
   printf("\n");
   for (over_voidfunction_debugshow_signedlonglong_i = 1; over_voidfunction_debugshow_signedlonglong_i <= over_heap_buffs.heap_signedlonglong_sz; ++over_voidfunction_debugshow_signedlonglong_i)
   {
      printf("%lld %3lld %3lld,%3lld,%3lld\n",
             over_heap_buffs.heap_buffpointerarray_D[over_voidfunction_debugshow_signedlonglong_i]->buff_signedlonglong_effectteamnum,
             over_heap_buffs.heap_buffpointerarray_D[over_voidfunction_debugshow_signedlonglong_i]->buff_signedlonglong_endtime,
             over_heap_buffs.heap_buffpointerarray_D[over_voidfunction_debugshow_signedlonglong_i]->buff_signedlonglong_effectatk,
             over_heap_buffs.heap_buffpointerarray_D[over_voidfunction_debugshow_signedlonglong_i]->buff_signedlonglong_effectdef,
             over_heap_buffs.heap_buffpointerarray_D[over_voidfunction_debugshow_signedlonglong_i]->buff_signedlonglong_effectmp);
   }
}
void over_voidfunction_roundend(signed long long t)
{
   signed long long over_voidfunction_roundend_signedlonglong_i;
   if (t == over_signedlonglong_gameendtime)
   {
      for (over_voidfunction_roundend_signedlonglong_i = 1; over_voidfunction_roundend_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_roundend_signedlonglong_i)
      {
         over_playerpointerarray_players[over_voidfunction_roundend_signedlonglong_i][over_signedlonglong_gameoverteamnum]->player_bool_isdead = true;
      }
      return;
   }
   while (!over_heap_buffs.heap_boolfunction_empty() && t == over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_endtime)
   {
      for (over_voidfunction_roundend_signedlonglong_i = 1; over_voidfunction_roundend_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_roundend_signedlonglong_i)
      {
         if (over_playerpointerarray_players[over_voidfunction_roundend_signedlonglong_i][over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_effectteamnum]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[over_voidfunction_roundend_signedlonglong_i][over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_effectteamnum]->player_signedlonglong_deltamp -= over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_effectmp;
         over_playerpointerarray_players[over_voidfunction_roundend_signedlonglong_i][over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_effectteamnum]->player_signedlonglong_deltaatk -= over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_effectatk;
         over_playerpointerarray_players[over_voidfunction_roundend_signedlonglong_i][over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_effectteamnum]->player_signedlonglong_deltadef -= over_heap_buffs.heap_buffpointerfunction_top()->buff_signedlonglong_effectdef;
      }
      over_heap_buffs.heap_voidfunction_pop();
   }
   return;
}
void heap::heap_voidfunction_pop(void)
{
   heap_voidfunction_sp(heap_buffpointerarray_D[heap_signedlonglong_sz], heap_buffpointerarray_D[1]);
   --heap_signedlonglong_sz;
   heap_voidfunction_downcheck(1);
}
buff *heap::heap_buffpointerfunction_top(void)
{
   return heap_buffpointerarray_D[1];
}
void heap::heap_voidfunction_upcheck(int x)
{
   while (x > 1 && heap_buffpointerarray_D[x] < heap_buffpointerarray_D[x >> 1])
   {
      heap_voidfunction_sp(heap_buffpointerarray_D[x], heap_buffpointerarray_D[x >> 1]);
      x >>= 1;
   }
   return;
}
void heap::heap_voidfunction_downcheck(int x)
{
   while (1)
   {
      if (x << 1 > heap_signedlonglong_sz)
         return;
      if (x << 1 == heap_signedlonglong_sz)
      {
         if (heap_buffpointerarray_D[x] < heap_buffpointerarray_D[x << 1])
            return;
         heap_voidfunction_sp(heap_buffpointerarray_D[x], heap_buffpointerarray_D[x << 1]);
         return;
      }
      if (heap_buffpointerarray_D[x] < heap_buffpointerarray_D[x << 1] && heap_buffpointerarray_D[x] < heap_buffpointerarray_D[(x << 1) | 1])
         return;
      if (heap_buffpointerarray_D[x << 1] < heap_buffpointerarray_D[(x << 1) | 1])
      {
         heap_voidfunction_sp(heap_buffpointerarray_D[x], heap_buffpointerarray_D[x << 1]);
         x <<= 1;
      }
      else
      {
         heap_voidfunction_sp(heap_buffpointerarray_D[x], heap_buffpointerarray_D[(x << 1) | 1]);
         x <<= 1;
         x |= 1;
      }
   }
}
void heap::heap_voidfunction_sp(buff *&a, buff *&b)
{
   buff *c = a;
   a = b;
   b = c;
}
void heap::heap_voidfunction_push(buff *x)
{
   ++heap_signedlonglong_sz;
   heap_buffpointerarray_D[heap_signedlonglong_sz] = x;
   heap_voidfunction_upcheck(heap_signedlonglong_sz);
}
void heap::heap_voidfunction_init(void)
{
   heap_signedlonglong_sz = 0;
}
buff::buff(signed long long endtime, signed long long effectmp, signed long long effectatk, signed long long effectdef, signed long long effectteamnum)
{
   buff_signedlonglong_endtime = endtime;
   buff_signedlonglong_effectmp = effectmp;
   buff_signedlonglong_effectatk = effectatk;
   buff_signedlonglong_effectdef = effectdef;
   buff_signedlonglong_effectteamnum = effectteamnum;
   return;
}

void player::player_voidfunction_jn(signed long long t)
{ // check target teamnum
   signed long long player_voidfunction_jn_signedlonglong_i;
   signed long long player_signedlonglong_jn_signedlonglong_num;
   signed long long player_signedlonglong_jn_signedlonglong_doer;
   player_signedlonglong_mp = 1;
   if (player_signedlonglong_jn == 0)
   {
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 1)
   {
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_voidfunction_hurt(player_signedlonglong_jnnum1, 0);
      }
      if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
         return;
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_signedlonglong_mp -= (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_signedlonglong_mp / 10);
      }
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 2)
   {
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_voidfunction_hurt(0, player_signedlonglong_atk + player_signedlonglong_deltaatk);
      }
      if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
         return;
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 3)
   {
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_voidfunction_hurt(mi2(over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_signedlonglong_HP / 10, (signed long long)player_signedlonglong_jnnum1 * (player_signedlonglong_atk + player_signedlonglong_deltaatk)), 0);
      }
      if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
         return;
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 4)
   {
      over_heap_buffs.heap_voidfunction_push(new buff(t + player_signedlonglong_jnnum1 - 1, player_signedlonglong_jnnum2, 0, 0, player_signedlonglong_teamnum));
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_deltamp += player_signedlonglong_jnnum2;
      }
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 5)
   {
      player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_deltadef -= player_signedlonglong_jnnum1;
      player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_voidfunction_hurt(0, player_signedlonglong_atk + player_signedlonglong_deltaatk);
      if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
         return;
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 6)
   {
      player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_voidfunction_hurt(0, player_signedlonglong_atk + player_signedlonglong_deltaatk);
      over_heap_buffs.heap_voidfunction_push(new buff(t + player_signedlonglong_jnnum1 - 1, 0, -player_signedlonglong_jnnum2, 0, player_signedlonglong_teamnum ^ 1));
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_signedlonglong_deltaatk -= player_signedlonglong_jnnum2;
      }
      if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
         return;
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 7)
   {
      player_signedlonglong_jn_signedlonglong_num = 0x7fffffffffffffffll;
      player_signedlonglong_jn_signedlonglong_doer = 0;
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_bool_isdead)
            continue;
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_hp < player_signedlonglong_jn_signedlonglong_num)
         {
            player_signedlonglong_jn_signedlonglong_num = over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_hp;
            player_signedlonglong_jn_signedlonglong_doer = player_voidfunction_jn_signedlonglong_i;
         }
      }
      if (player_signedlonglong_jn_signedlonglong_doer != 0)
      {
         over_playerpointerarray_players[player_signedlonglong_jn_signedlonglong_doer][player_signedlonglong_teamnum]->player_signedlonglong_hp += player_signedlonglong_jnnum3;
         if (over_playerpointerarray_players[player_signedlonglong_jn_signedlonglong_doer][player_signedlonglong_teamnum]->player_signedlonglong_hp > over_playerpointerarray_players[player_signedlonglong_jn_signedlonglong_doer][player_signedlonglong_teamnum]->player_signedlonglong_HP)
         {
            over_playerpointerarray_players[player_signedlonglong_jn_signedlonglong_doer][player_signedlonglong_teamnum]->player_signedlonglong_hp = over_playerpointerarray_players[player_signedlonglong_jn_signedlonglong_doer][player_signedlonglong_teamnum]->player_signedlonglong_HP;
         }
         over_heap_buffs.heap_voidfunction_push(new buff(t + player_signedlonglong_jnnum1 - 1, 0, player_signedlonglong_jnnum2, 0, player_signedlonglong_teamnum));
         for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
         {
            if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_bool_isdead)
               continue;
            over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_deltaatk += player_signedlonglong_jnnum2;
         }
         if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
            return;
         if (player_signedlonglong_tf == 5)
         {
            player_signedlonglong_mp += player_signedlonglong_tfnum2;
            if (player_signedlonglong_mp > player_signedlonglong_MP)
               player_signedlonglong_mp = player_signedlonglong_MP;
         }
      }
   }
   if (player_signedlonglong_jn == 8)
   {
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_voidfunction_hurt(player_signedlonglong_atk + player_signedlonglong_deltaatk, 0);
      }
      if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
         return;
      over_heap_buffs.heap_voidfunction_push(new buff(t + player_signedlonglong_jnnum1, 0, 0, -player_signedlonglong_jnnum2, player_signedlonglong_teamnum ^ 1));
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum ^ 1]->player_signedlonglong_deltadef -= player_signedlonglong_jnnum2;
      }
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 9)
   {
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_hp += player_signedlonglong_jnnum3;
      }
      over_heap_buffs.heap_voidfunction_push(new buff(t + player_signedlonglong_jnnum1 - 1, 0, 0, player_signedlonglong_jnnum2, player_signedlonglong_teamnum));
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_deltadef += player_signedlonglong_jnnum2;
      }
      if (player_signedlonglong_tf == 5)
      {
         player_signedlonglong_mp += player_signedlonglong_tfnum2;
         if (player_signedlonglong_mp > player_signedlonglong_MP)
            player_signedlonglong_mp = player_signedlonglong_MP;
      }
      return;
   }
   if (player_signedlonglong_jn == 10)
   {
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_bool_isdead)
            continue;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_atk = over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_atk << 1;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_def = over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_def << 1;
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_hp = mx2(over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_hp, over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_HP >> 1);
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_mp = mx2(over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_mp, over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_MP >> 1);
         over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_deltamp = over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][player_signedlonglong_teamnum]->player_signedlonglong_deltamp + 1;
      }
      over_signedlonglong_gameoverteamnum = player_signedlonglong_teamnum;
      over_signedlonglong_gameendtime = t + player_signedlonglong_jnnum1 - 1;
      for (player_voidfunction_jn_signedlonglong_i = 1; player_voidfunction_jn_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_jn_signedlonglong_i)
      {
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][0]->player_signedlonglong_jn == 10)
            over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][0]->player_signedlonglong_jn = 0;
         if (over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][1]->player_signedlonglong_jn == 10)
            over_playerpointerarray_players[player_voidfunction_jn_signedlonglong_i][1]->player_signedlonglong_jn = 0;
      }
      return;
   }
}
void player::player_voidfunction_hurt(signed long long x, signed long long y)
{
   player_signedlonglong_hp -= mx2(x - player_signedlonglong_def - player_signedlonglong_deltadef, 0);
   if (player_signedlonglong_tf == 1)
   {
      player_signedlonglong_hp -= y;
      player_signedlonglong_hp += y >> 1;
   }
   else
      player_signedlonglong_hp -= y;
   ++player_signedlonglong_mp;
   if (player_signedlonglong_mp > player_signedlonglong_MP)
      player_signedlonglong_mp = player_signedlonglong_MP;
   if (player_signedlonglong_hp <= 0)
   {
      player_bool_isdead = true;
      player_signedlonglong_hp = 0;
   }
   return;
}

void player::player_voidfunction_pg(void)
{
   if (player_signedlonglong_tf == 2)
   {
      player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_voidfunction_hurt(player_signedlonglong_atk + player_signedlonglong_deltaatk, player_signedlonglong_tfnum1);
      ++player_signedlonglong_mp;
      if (player_signedlonglong_mp > player_signedlonglong_MP)
         player_signedlonglong_mp = player_signedlonglong_mp;
      return;
   }
   if (player_signedlonglong_tf == 4)
   {
      player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_voidfunction_hurt(0, player_signedlonglong_atk + player_signedlonglong_deltaatk);
      ++player_signedlonglong_mp;
      if (player_signedlonglong_mp > player_signedlonglong_MP)
         player_signedlonglong_mp = player_signedlonglong_mp;
      return;
   }
   if (player_signedlonglong_tf == 5)
   {
      player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_voidfunction_hurt(player_signedlonglong_atk + player_signedlonglong_deltaatk, 0);
      if (over_boolfunction_check(player_signedlonglong_teamnum ^ 1))
         return;
      player_signedlonglong_hp += player_signedlonglong_tfnum1;
      if (player_signedlonglong_hp > player_signedlonglong_HP)
         player_signedlonglong_hp = player_signedlonglong_HP;
      ++player_signedlonglong_mp;
      if (player_signedlonglong_mp > player_signedlonglong_MP)
         player_signedlonglong_mp = player_signedlonglong_mp;
      return;
   }
   player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_voidfunction_hurt(player_signedlonglong_atk + player_signedlonglong_deltaatk, 0);
   ++player_signedlonglong_mp;
   return;
}
signed long long player::player_signedlonglongfunction_job(void)
{
   if (player_signedlonglong_tf == 2)
   {
      if (player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_tf == 1)
      {
         return player_signedlonglong_tfnum1 - (player_signedlonglong_tfnum1 >> 1) + mx2(0, player_signedlonglong_atk + player_signedlonglong_deltaatk - player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_def - player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_deltadef);
      }
      else
         return mx2(0, player_signedlonglong_atk + player_signedlonglong_deltaatk - player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_def - player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_deltadef) + player_signedlonglong_tfnum1;
   }
   if (player_signedlonglong_tf == 4)
   {
      if (player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_tf == 1)
      {
         return (player_signedlonglong_atk + player_signedlonglong_deltaatk) - ((player_signedlonglong_atk + player_signedlonglong_deltaatk) >> 1);
      }
      else
         return player_signedlonglong_atk + player_signedlonglong_deltaatk;
   }
   return mx2(0, player_signedlonglong_atk + player_signedlonglong_deltaatk - player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_def - player_playerpointerarray_targets[player_signedlonglong_nwtargetnum]->player_signedlonglong_deltadef);
}
player::player(void)
{
   player_signedlonglong_mp = player_signedlonglong_deltaatk = player_signedlonglong_deltadef = 0;
   player_signedlonglong_deltamp = 1;
   player_bool_isdead = false;
   return;
}
void player::player_voidfunction_init(signed long long x)
{
   player_signedlonglong_teamnum = x;
   over_signedlonglong_gameendtime = 0;
   player_signedlonglong_HP = over_templatefunction_read<signed long long>();
   player_signedlonglong_MP = over_templatefunction_read<signed long long>();
   player_signedlonglong_atk = over_templatefunction_read<signed long long>();
   player_signedlonglong_def = over_templatefunction_read<signed long long>();
   for (player_signedlonglong_nwtargetnum = 1; player_signedlonglong_nwtargetnum <= over_signedlonglong_n; ++player_signedlonglong_nwtargetnum)
      player_playerpointerarray_targets[player_signedlonglong_nwtargetnum] = over_playerpointerarray_players[over_templatefunction_read<signed long long>()][player_signedlonglong_teamnum ^ 1];
   player_signedlonglong_nwtargetnum = 1;
   player_signedlonglong_tf = over_templatefunction_read<signed long long>();
   player_signedlonglong_tfnum1 = over_templatefunction_read<signed long long>();
   player_signedlonglong_tfnum2 = over_templatefunction_read<signed long long>();
   if (player_signedlonglong_tf == 3)
      player_signedlonglong_deltamp += player_signedlonglong_tfnum2;
   player_signedlonglong_jn = over_templatefunction_read<signed long long>();
   player_signedlonglong_jnnum1 = over_templatefunction_read<signed long long>();
   player_signedlonglong_jnnum2 = over_templatefunction_read<signed long long>();
   player_signedlonglong_jnnum3 = over_templatefunction_read<signed long long>();
   player_signedlonglong_hp = player_signedlonglong_HP;
}
void over_voidfunction_show(signed long long x)
{
   signed long long over_voidfunction_show_signedlonglong_i;
   for (over_voidfunction_show_signedlonglong_i = 1; over_voidfunction_show_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_show_signedlonglong_i)
   {
      if (over_playerpointerarray_players[over_voidfunction_show_signedlonglong_i][x]->player_bool_isdead)
         putchar(48);
      else
         put(over_playerpointerarray_players[over_voidfunction_show_signedlonglong_i][x]->player_signedlonglong_hp);
      putchar(32);
   }
   return;
}
bool over_boolfunction_check(signed long long x)
{
   signed long long over_boolfunction_check_signedlonglong_i;
   for (over_boolfunction_check_signedlonglong_i = 1; over_boolfunction_check_signedlonglong_i <= over_signedlonglong_n; ++over_boolfunction_check_signedlonglong_i)
   {
      if (over_playerpointerarray_players[over_boolfunction_check_signedlonglong_i][x]->player_bool_isdead == false)
         return false;
   }
   return true;
}
void over_voidfunction_js(signed long long x)
{
   signed long long over_voidfunction_js_signedlonglong_i;
   for (over_voidfunction_js_signedlonglong_i = 1; over_voidfunction_js_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_js_signedlonglong_i)
   {
      if (over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_bool_isdead)
         continue;
      if (over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_tf == 3)
      {
         over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_hp += over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_tfnum1;
         if (over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_hp > over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_HP)
            over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_hp = over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_HP;
      }
      over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_mp += over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_deltamp;
      if (over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_mp > over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_MP)
         over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_mp = over_playerpointerarray_players[over_voidfunction_js_signedlonglong_i][x]->player_signedlonglong_MP;
   }
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
   else
      putchar(x > 9 ? put(x / 10), x % 10 | 48 : x % 10 | 48);
}
void over_voidfunction_init(void)
{
   over_signedlonglong_n = over_templatefunction_read<signed long long>();
   signed long long over_voidfunction_init_signedlonglong_i;
   for (over_voidfunction_init_signedlonglong_i = 1; over_voidfunction_init_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_init_signedlonglong_i)
   {
      over_playerpointerarray_players[over_voidfunction_init_signedlonglong_i][0] = new player;
      over_playerpointerarray_players[over_voidfunction_init_signedlonglong_i][1] = new player;
   }
   for (over_voidfunction_init_signedlonglong_i = 1; over_voidfunction_init_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_init_signedlonglong_i)
   {
      over_playerpointerarray_players[over_voidfunction_init_signedlonglong_i][0]->player_voidfunction_init(0);
   }
   for (over_voidfunction_init_signedlonglong_i = 1; over_voidfunction_init_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_init_signedlonglong_i)
   {
      over_playerpointerarray_players[over_voidfunction_init_signedlonglong_i][1]->player_voidfunction_init(1);
   }
   return;
}
void over_voidfunction_play(void)
{
   signed long long over_voidfunction_play_t = 0;
   while (1)
   {
      ++over_voidfunction_play_t;
      over_voidfunction_runit(0, over_voidfunction_play_t);
      if (over_boolfunction_check(1))
         break;
      over_voidfunction_js(0);
      over_voidfunction_runit(1, over_voidfunction_play_t);
      if (over_boolfunction_check(0))
         break;
      over_voidfunction_js(1);
      over_voidfunction_roundend(over_voidfunction_play_t);
      if (over_boolfunction_check(over_signedlonglong_gameoverteamnum))
         break;
   }
   put(over_voidfunction_play_t);
   putchar(10);
   if (over_boolfunction_check(0))
   {
      printf("Bob\n");
      over_voidfunction_show(1);
   }
   else
   {
      printf("Alice\n");
      over_voidfunction_show(0);
   }
}
void over_voidfunction_runit(signed long long x, signed long long t)
{
   signed long long player_voidfunction_doit_signedlonglong_i;
   signed long long player_voidfunction_doit_signedlonglong_mxdoer = 0;
   signed long long player_voidfunction_doit_signedlonglong_mxdodata1 = 0;
   signed long long player_voidfunction_doit_signedlonglong_mxdodata2 = 0;
   if (over_boolfunction_findtarget(x))
      return;
   for (player_voidfunction_doit_signedlonglong_i = 1; player_voidfunction_doit_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_doit_signedlonglong_i)
   {
      if (over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_bool_isdead)
         continue;
      if (over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_mp != over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_MP)
      {
         continue;
      }
      if (over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_jn >= player_voidfunction_doit_signedlonglong_mxdodata1)
      {
         player_voidfunction_doit_signedlonglong_mxdodata1 = over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_jn;
         player_voidfunction_doit_signedlonglong_mxdoer = player_voidfunction_doit_signedlonglong_i;
      }
   }
   if (player_voidfunction_doit_signedlonglong_mxdoer != 0)
   {
      over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_mxdoer][x]->player_voidfunction_jn(t);
      return;
   }
   player_voidfunction_doit_signedlonglong_mxdoer = 0;
   player_voidfunction_doit_signedlonglong_mxdodata1 = 0;
   player_voidfunction_doit_signedlonglong_mxdodata2 = 0;
   for (player_voidfunction_doit_signedlonglong_i = 1; player_voidfunction_doit_signedlonglong_i <= over_signedlonglong_n; ++player_voidfunction_doit_signedlonglong_i)
   {
      if (over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_bool_isdead)
         continue;
      if (over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_playerpointerarray_targets[over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_nwtargetnum]->player_signedlonglong_hp > player_voidfunction_doit_signedlonglong_mxdodata1)
      {
         player_voidfunction_doit_signedlonglong_mxdoer = player_voidfunction_doit_signedlonglong_i;
         player_voidfunction_doit_signedlonglong_mxdodata1 = over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_playerpointerarray_targets[over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_nwtargetnum]->player_signedlonglong_hp;
         player_voidfunction_doit_signedlonglong_mxdodata2 = over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglongfunction_job();
      }
      if (over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_playerpointerarray_targets[over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_nwtargetnum]->player_signedlonglong_hp == player_voidfunction_doit_signedlonglong_mxdodata1)
      {
         if (over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglongfunction_job() >= player_voidfunction_doit_signedlonglong_mxdodata2)
         {
            player_voidfunction_doit_signedlonglong_mxdoer = player_voidfunction_doit_signedlonglong_i;
            player_voidfunction_doit_signedlonglong_mxdodata1 = over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_playerpointerarray_targets[over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglong_nwtargetnum]->player_signedlonglong_hp;
            player_voidfunction_doit_signedlonglong_mxdodata2 = over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_i][x]->player_signedlonglongfunction_job();
         }
      }
   }
   over_playerpointerarray_players[player_voidfunction_doit_signedlonglong_mxdoer][x]->player_voidfunction_pg();
   return;
}
bool over_boolfunction_findtarget(signed long long x)
{
   signed long long over_voidfunction_findtarget_signedlonglong_i;
   for (over_voidfunction_findtarget_signedlonglong_i = 1; over_voidfunction_findtarget_signedlonglong_i <= over_signedlonglong_n; ++over_voidfunction_findtarget_signedlonglong_i)
   {
      while (over_playerpointerarray_players[over_voidfunction_findtarget_signedlonglong_i][x]->player_signedlonglong_nwtargetnum <= over_signedlonglong_n && over_playerpointerarray_players[over_voidfunction_findtarget_signedlonglong_i][x]->player_playerpointerarray_targets[over_playerpointerarray_players[over_voidfunction_findtarget_signedlonglong_i][x]->player_signedlonglong_nwtargetnum]->player_bool_isdead)
         ++over_playerpointerarray_players[over_voidfunction_findtarget_signedlonglong_i][x]->player_signedlonglong_nwtargetnum;
      if (over_playerpointerarray_players[over_voidfunction_findtarget_signedlonglong_i][x]->player_signedlonglong_nwtargetnum > over_signedlonglong_n)
         return true;
   }
   return false;
}