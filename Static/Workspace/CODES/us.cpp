#include <cstdio>
using namespace std;
float x[3000];
int main(int argc, char **argv)
{
   x[1] = 2;
   for (int i = 1; i < 10000; i++)
   {
      x[i + 1] = 1 - (1 / x[i]);
   }
   float ans = 0;
   for (int i = 1; i <= 2021; i++)
   {
      ans += x[i];
   }
   printf("%f", ans);
   return ans;
}