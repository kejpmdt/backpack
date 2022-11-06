#include <iostream>
#include <cstdio>
using namespace std;
long long L[100005];
long long R[100005];
int main()
{
   int n, m;
   cin >> n >> m;
   for (int i = 1; i <= n; ++i)
   {
      cin >> L[i];
      R[i] = L[i];
   }
   for (int i = n; i > 1; --i)
   {
      if (L[i] < L[i - 1])
      {
         L[i] = L[i - 1] - L[i];
      }
      else
      {
         L[i] = 0;
      }
   }
   for (int i = 1; i < n; ++i)
   {
      if (R[i] < R[i + 1])
      {
         R[i] = R[i + 1] - R[i];
      }
      else
      {
         R[i] = 0;
      }
   }
   L[1] = 0;
   R[n] = 0;
   for (int i = n - 1; i >= 1; --i)
   {
      R[i] += R[i + 1];
   }
   for (int i = 2; i <= n; ++i)
   {
      L[i] += L[i - 1];
   }
   while (m--)
   {
      int a, b;
      cin >> a >> b;
      if (a < b)
      {
         cout << L[b] - L[a] << endl;
      }
      else
      {
         cout << R[b] - R[a] << endl;
      }
   }
   return 0;
}