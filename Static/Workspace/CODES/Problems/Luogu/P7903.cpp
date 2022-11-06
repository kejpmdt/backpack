#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
   int n;
   cin >> n;
   if (n <= 8)
   {
      cout << -1;
      return 0;
   }
   cout << n << endl;
   printf("1 2\n2 3\n3 4\n4 5\n5 6\n6 7\n");
   for (int i = 8; i <= n; ++i)
   {
      printf("%d 3\n", i);
   }
   return 0;
}