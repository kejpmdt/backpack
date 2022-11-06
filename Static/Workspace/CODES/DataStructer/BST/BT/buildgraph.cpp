#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
   int n;
   freopen("seed.txt", "r", stdin);
   cin >> n;
   srand(n);
   fclose(stdin);
   freopen("seed.txt", "w", stdout);
   cout << rand();
   freopen("BT.in", "w", stdout);
   n = rand();
   cout << n << endl;
   while (n--)
   {
      cout << rand() % 20 + 1 << endl;
   }
}