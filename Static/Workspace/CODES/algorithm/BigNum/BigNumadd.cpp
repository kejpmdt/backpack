#include <cstdio>
#include <cstring>
#define mx2(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
class GJD
{
public:
   int num[500]; //此为存储空间，从1开始逆序存
   int sz;       //此为大小，也是最后一个的编号，最小为1
   GJD(void)
   {
      sz = 1;
      memset(num, 0, sizeof num);
   } //构造函数，初始化
   void print(void)
   {
      printf("%d", num[sz]);
      for (int i = sz - 1; i >= 1; --i)
      {
         printf("%d", num[i]);
      }
   } //输出
   void recheck(void)
   {
      for (int i = 1; i <= sz; ++i)
      {
         num[i + 1] += num[i] / 10;
         num[i] %= 10;
         if (i == sz && num[i + 1] != 0)
            ++sz;
      }
      while (sz > 1 && num[sz] == 0)
         --sz;
   } //检查
   void operator=(GJD x)
   {
      sz = x.sz;
      for (int i = 1; i <= sz; ++i)
         num[i] = x.num[i];
      recheck();
   } //拷贝
   void operator=(int x)
   {
      sz = 1;
      num[1] = x;
      recheck();
   } //赋值
   void operator+=(int x)
   {
      num[1] += x;
      recheck();
   } //加
   GJD operator+(GJD x)
   {
      GJD us;
      for (int i = 1; i <= sz || i <= x.sz; ++i)
         us.num[i] = num[i] + x.num[i];
      us.sz = mx2(sz, x.sz);
      us.recheck();
      return us;
   }
   GJD operator<<(int x)
   {
      GJD us;
      us = *this;
      for (int i = 1; i <= sz; ++i)
         us.num[i] <<= x;
      us.recheck();
      return us;
   } //左移
   short check(GJD x)
   {
      if (sz < x.sz)
         return -1;
      if (sz > x.sz)
         return 1;
      for (int i = sz; i >= 1; --i)
      {
         if (num[i] < x.num[i])
            return -1;
         if (num[i] > x.num[i])
            return 1;
      }
      return 0;
   }
   bool operator<(GJD x)
   {
      return (check(x) == -1);
   }
   bool operator>(GJD x)
   {
      return (check(x) == 1);
   }
};
GJD read(void)
{
   GJD ans;
   char us[1000];
   scanf("%s", us);
   ans.sz = strlen(us);
   for (int i = 1; i <= ans.sz; ++i)
      ans.num[i] = us[ans.sz - i] ^ 48;
   return ans;
}
int main()
{
   GJD a, b;
   a = read();
   while (1)
   {
      b=0;
      b = read();
      a = a + b;
      a.print();
   }

   return 0;
}