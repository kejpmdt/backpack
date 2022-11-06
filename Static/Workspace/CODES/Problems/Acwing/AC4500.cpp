#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct num
{
   int data;
   int cnt;
   bool operator<(const num &oth) const
   {
      return data < oth.data;
   }
   bool operator==(const num &oth) const
   {
      return data == oth.data;
   }
} nums[3005];
int main()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i)
   {
      cin >> nums[i].data;
      nums[i].cnt = i;
   }
   sort(nums + 1, nums + n + 1);
   int u = unique(nums + 1, nums + n + 1) - nums - 1;
   if (u <= 2)
      cout << "-1 -1 -1";
   else
      printf("%d %d %d", nums[1].cnt, nums[2].cnt, nums[3].cnt);
}