#include <bits/stdc++.h>
using namespace std;
void init()
{
   //������Ԥ����DP����
}
int dp(int x)
{
   if (x == 0)
   {
      //�������е�0
   }
   vector<int> v;
   while (x)
      v.push_back(x % 10), x /= 10; //���ｫ���ֽ�����λ��֣�10��ʾ10����
   int ans = 0, lst;                //����ͣ�һ����ͳ����Ŀ��ans��ǰ���ۼ�Ӱ���lst
   for (int i = v.size() - 1; i >= 0; --i)
   {
      int x = v[i];
      for (int i = 0; i < x; ++i)
      {
         //���ﴦ��һ���Ե�Ӱ��
      }
      if (x /*...*/)
      {
         //���������ֹ����
         break;
      }
      lst /*...*/; //�ۼ�Ӱ��
      if (!i)
      {
         //��󵥶�����
      }
   }
   return ans;
}
