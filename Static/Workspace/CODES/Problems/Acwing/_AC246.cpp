#include <cstdio>
#define MAXN 500005
using namespace std;
class Segment_Tree;
class Segment_Tree::Segment_Tree_Node;
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
signed long long over_signedlonglongarray_inp[MAXN];
class Segment_Tree
{
public:
   class Segment_Tree_Node
   {
   public:
      signed int Segment_Tree_Node_signedint_L;
      signed int Segment_Tree_Node_signedint_R;
      signed long long Segment_Tree_Node_signedlonglong_mxadd;
      signed long long Segment_Tree_Node_signedlonglong_leftmxadd;
      signed long long Segment_Tree_Node_signedlonglong_rightmxadd;
      signed long long Segment_Tree_Node_signedlonglong_sum;
      Segment_Tree_Node *Segment_Tree_Node_Segment_Tree_Nodepointer_lc;
      Segment_Tree_Node *Segment_Tree_Node_Segment_Tree_Nodepointer_rc;
      void Segment_Tree_Node_voidfunction_maintain(void)
      {
         if (Segment_Tree_Node_Segment_Tree_Nodepointer_lc)
         {
            Segment_Tree_Node_signedlonglong_mxadd = mx2(Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_signedlonglong_mxadd, Segment_Tree_Node_Segment_Tree_Nodepointer_rc->mxadd);
            Segment_Tree_Node_signedlonglong_mxadd = mx2(Segment_Tree_Node_signedlonglong_mxadd, Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_signedlonglong_rightmxadd + Segment_Tree_Node_Segment_Tree_Nodepointer_rc->Segment_Tree_Node_signedlonglong_leftmxadd);
            Segment_Tree_Node_signedlonglong_leftmxadd = mx2(Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_signedlonglong_leftmxadd, Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_signedlonglong_sum + Segment_Tree_Node_Segment_Tree_Nodepointer_rc->Segment_Tree_Node_signedlonglong_leftmxadd);
            Segment_Tree_Node_signedlonglong_rightmxadd = mx2(Segment_Tree_Node_Segment_Tree_Nodepointer_rc->Segment_Tree_Node_signedlonglong_rightmxadd, Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_signedlonglong_rightmxadd + Segment_Tree_Node_Segment_Tree_Nodepointer_rc->Segment_Tree_Node_signedlonglong_sum);
            Segment_Tree_Node_signedlonglong_sum = Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_signedlonglong_sum + Segment_Tree_Node_Segment_Tree_Nodepointer_rc->Segment_Tree_Node_signedlonglong_sum;
            return;
         }
         else
         {
            Segment_Tree_Node_signedlonglong_leftmxadd = Segment_Tree_Node_signedlonglong_mxadd = Segment_Tree_Node_signedlonglong_rightmxadd = Segment_Tree_Node_signedlonglong_sum > 0 ? Segment_Tree_Node_signedlonglong_sum : 0;
            return;
         }
      }
      void Segment_Tree_Node_voidfunction_build(signed int l, signed int r)
      {
         Segment_Tree_Node_signedint_L = l;
         Segment_Tree_Node_signedint_R = r;
         if (l != r)
         {
            Segment_Tree_Node_Segment_Tree_Nodepointer_lc = new Segment_Tree_Node;
            Segment_Tree_Node_Segment_Tree_Nodepointer_rc = new Segment_Tree_Node;
            Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_voidfunction_build(l, l + r >> 1);
            Segment_Tree_Node_Segment_Tree_Nodepointer_rc->Segment_Tree_Node_voidfunction_build(l + r >> 1 | 1, r);
         }
         else
         {
            Segment_Tree_Node_signedlonglong_sum = over_signedlonglongarray_inp[l];
            Segment_Tree_Node_Segment_Tree_Nodepointer_lc = Segment_Tree_Node_Segment_Tree_Nodepointer_rc = nullptr;
         }
         Segment_Tree_Node_voidfunction_maintain();
      }
      void Segment_Tree_Node_voidfunction_change(signed int x, signed long long y)
      {
         if (Segment_Tree_Node_signedint_L == Segment_Tree_Node_signedint_R && Segment_Tree_Node_signedint_L == x)
         {
            Segment_Tree_Node_signedlonglong_sum = y;
         }
         else
         {
            if (x <= Segment_Tree_Node_signedint_L + Segment_Tree_Node_signedint_R >> 1)
               Segment_Tree_Node_Segment_Tree_Nodepointer_lc->Segment_Tree_Node_voidfunction_change(x, y);
            else
               Segment_Tree_Node_Segment_Tree_Nodepointer_rc->Segment_Tree_Node_voidfunction_change(x, y);
         }
         Segment_Tree_Node_voidfunction_maintain();
      }
   };
   Segment_Tree_Node *Segment_Tree_Segment_Tree_Nodepointer_root;
   signed long long Segment_Tree_longlongfunction_ask(signed int l, signed int r)
   {
      if (l > r)
      {
         l ^= r;
         r ^= l;
         l ^= r;
      }
      Segment_Tree_Node *Segment_Tree_longlongfunction_ask_Segment_Tree_Nodepointer_usnode;
      Segment_Tree_longlongfunction_ask_Segment_Tree_Nodepointer_usnode = Segment_Tree_Segment_Tree_Nodepointer_root;

      int main()
      {
