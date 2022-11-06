#include <cstdio>
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
class puke;
class puke
{
public:
   puke *puke_pukepointer_lst;
   puke *puke_pukepointer_nt;
   signed int puke_signedint_tonum;
   signed int puke_signedint_nwnum;
   void puke_voidfunction_rem(void);
};
void over_voidfunction_show(void);
puke *over_pukepointerarray_pukes[13];
puke *over_pukepointerarray_unders[13];
signed int over_signedintarray_on[13];
signed int main()
{
   signed int main_signedint_i;
   signed int main_signedint_j;
   char main_char_usc;
   puke *main_pukepointer_pk;
   for (main_signedint_i = 0; main_signedint_i <= 12; ++main_signedint_i)
   {
      for (main_signedint_j = 1; main_signedint_j <= 4; ++main_signedint_j)
      {
         main_char_usc = getchar();
         main_pukepointer_pk = new puke;
         main_pukepointer_pk->puke_signedint_nwnum = main_signedint_i;
         if (main_char_usc > 48 && main_char_usc < 58)
         {
            main_pukepointer_pk->puke_signedint_tonum = main_char_usc - 49;
            main_pukepointer_pk->puke_pukepointer_nt = over_pukepointerarray_pukes[main_signedint_i];
            main_pukepointer_pk->puke_pukepointer_lst = nullptr;
            if (main_pukepointer_pk->puke_pukepointer_nt)
               main_pukepointer_pk->puke_pukepointer_nt->puke_pukepointer_lst = main_pukepointer_pk;
            over_pukepointerarray_pukes[main_signedint_i] = main_pukepointer_pk;
            if (over_pukepointerarray_unders[main_signedint_i] == nullptr)
               over_pukepointerarray_unders[main_signedint_i] = main_pukepointer_pk;
         }
         else
         {
            switch (main_char_usc)
            {
            case 48:
            {
               main_pukepointer_pk->puke_signedint_tonum = 9;
               main_pukepointer_pk->puke_pukepointer_nt = over_pukepointerarray_pukes[main_signedint_i];
               main_pukepointer_pk->puke_pukepointer_lst = nullptr;
               if (main_pukepointer_pk->puke_pukepointer_nt)
                  main_pukepointer_pk->puke_pukepointer_nt->puke_pukepointer_lst = main_pukepointer_pk;
               over_pukepointerarray_pukes[main_signedint_i] = main_pukepointer_pk;
               if (over_pukepointerarray_unders[main_signedint_i] == nullptr)
                  over_pukepointerarray_unders[main_signedint_i] = main_pukepointer_pk;
               break;
            }
            case 74:
            {
               main_pukepointer_pk->puke_signedint_tonum = 10;
               main_pukepointer_pk->puke_pukepointer_nt = over_pukepointerarray_pukes[main_signedint_i];
               main_pukepointer_pk->puke_pukepointer_lst = nullptr;
               if (main_pukepointer_pk->puke_pukepointer_nt)
                  main_pukepointer_pk->puke_pukepointer_nt->puke_pukepointer_lst = main_pukepointer_pk;
               over_pukepointerarray_pukes[main_signedint_i] = main_pukepointer_pk;
               if (over_pukepointerarray_unders[main_signedint_i] == nullptr)
                  over_pukepointerarray_unders[main_signedint_i] = main_pukepointer_pk;
               break;
            }
            case 81:
            {
               main_pukepointer_pk->puke_signedint_tonum = 11;
               main_pukepointer_pk->puke_pukepointer_nt = over_pukepointerarray_pukes[main_signedint_i];
               main_pukepointer_pk->puke_pukepointer_lst = nullptr;
               if (main_pukepointer_pk->puke_pukepointer_nt)
                  main_pukepointer_pk->puke_pukepointer_nt->puke_pukepointer_lst = main_pukepointer_pk;
               over_pukepointerarray_pukes[main_signedint_i] = main_pukepointer_pk;
               if (over_pukepointerarray_unders[main_signedint_i] == nullptr)
                  over_pukepointerarray_unders[main_signedint_i] = main_pukepointer_pk;
               break;
            }
            case 75:
            {
               main_pukepointer_pk->puke_signedint_tonum = 12;
               main_pukepointer_pk->puke_pukepointer_nt = over_pukepointerarray_pukes[main_signedint_i];
               main_pukepointer_pk->puke_pukepointer_lst = nullptr;
               if (main_pukepointer_pk->puke_pukepointer_nt)
                  main_pukepointer_pk->puke_pukepointer_nt->puke_pukepointer_lst = main_pukepointer_pk;
               over_pukepointerarray_pukes[main_signedint_i] = main_pukepointer_pk;
               if (over_pukepointerarray_unders[main_signedint_i] == nullptr)
                  over_pukepointerarray_unders[main_signedint_i] = main_pukepointer_pk;
               break;
            }
            case 65:
            {
               main_pukepointer_pk->puke_signedint_tonum = 0;
               main_pukepointer_pk->puke_pukepointer_nt = over_pukepointerarray_pukes[main_signedint_i];
               main_pukepointer_pk->puke_pukepointer_lst = nullptr;
               if (main_pukepointer_pk->puke_pukepointer_nt)
                  main_pukepointer_pk->puke_pukepointer_nt->puke_pukepointer_lst = main_pukepointer_pk;
               over_pukepointerarray_pukes[main_signedint_i] = main_pukepointer_pk;
               if (over_pukepointerarray_unders[main_signedint_i] == nullptr)
                  over_pukepointerarray_unders[main_signedint_i] = main_pukepointer_pk;
               break;
            }
            }
         }
         main_char_usc = getchar();
      }
   }
   for (main_signedint_i = 1; main_signedint_i <= 4; ++main_signedint_i)
   {
      main_pukepointer_pk = over_pukepointerarray_pukes[12];
      main_pukepointer_pk->puke_voidfunction_rem();
      while (main_pukepointer_pk->puke_signedint_tonum != 12)
      {
         main_pukepointer_pk->puke_pukepointer_lst = over_pukepointerarray_unders[main_pukepointer_pk->puke_signedint_tonum];
         if (main_pukepointer_pk->puke_pukepointer_lst)
            main_pukepointer_pk->puke_pukepointer_lst->puke_pukepointer_nt = main_pukepointer_pk;
         over_pukepointerarray_unders[main_pukepointer_pk->puke_signedint_tonum] = main_pukepointer_pk;
         ++over_signedintarray_on[main_pukepointer_pk->puke_signedint_tonum];
         main_pukepointer_pk->puke_pukepointer_nt = nullptr;
         main_pukepointer_pk->puke_signedint_nwnum = main_pukepointer_pk->puke_signedint_tonum;
         main_pukepointer_pk = over_pukepointerarray_pukes[main_pukepointer_pk->puke_signedint_tonum];
         main_pukepointer_pk->puke_voidfunction_rem();
      }
   }
   main_signedint_j = 0;
   for (main_signedint_i = 0; main_signedint_i < 12; ++main_signedint_i)
      if (over_signedintarray_on[main_signedint_i] == 4)
         ++main_signedint_j;
   put(main_signedint_j);
   return 0;
}
void puke::puke_voidfunction_rem(void)
{
   if (puke_pukepointer_nt)
      puke_pukepointer_nt->puke_pukepointer_lst = nullptr;
   over_pukepointerarray_pukes[puke_signedint_nwnum] = puke_pukepointer_nt;
   puke_pukepointer_nt = nullptr;
}
void over_voidfunction_show(void)
{
   puke *over_voidfunction_show_pukepointer_pk;
   signed int over_voidfunction_show_signedint_i;
   for (over_voidfunction_show_signedint_i = 0; over_voidfunction_show_signedint_i <= 12; ++over_voidfunction_show_signedint_i)
   {
      for (over_voidfunction_show_pukepointer_pk = over_pukepointerarray_pukes[over_voidfunction_show_signedint_i]; over_voidfunction_show_pukepointer_pk; over_voidfunction_show_pukepointer_pk = over_voidfunction_show_pukepointer_pk->puke_pukepointer_nt)
      {
         printf("%3d ", over_voidfunction_show_pukepointer_pk->puke_signedint_tonum);
      }
      printf("\n");
   }
   printf("\n\n\n");
}
