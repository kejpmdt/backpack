#include <iostream>
using namespace std;
string s[200][7];
void print(string s, bool pd)
{
   if (pd)
      putchar(10);
   for (int i = 0; i < s.size() - 1; ++i)
   {
      putchar(s[i]);
   }
}
int main()
{
   for (int i = 0; i < 200; ++i)
   {
      s[i][0] = "     ";
      s[i][1] = "     ";
      s[i][2] = "     ";
      s[i][3] = "     ";
      s[i][4] = "     ";
      s[i][5] = "     ";
      s[i][6] = "     ";
   }
   for (int i = 'A'; i <= 'Z'; ++i)
   {
      for (int j = 0; j < 7; ++j)
      {
         cin >> s[i][j];
      }
   }
   string d;
   string t;
   while (getline(cin, t))
      d += t;
   string s1, s2, s3, s4, s5, s6, s0;
   bool f = false;
   bool pd = false;
   for (int i = 0; i < d.size(); ++i)
   {
      if (d[i] < 'A' || d[i] > 'Z')
      {
         if (f)
         {
            if (pd)
               putchar(10);
            print(s0, pd);
            pd = true;
            print(s1, pd);
            print(s2, pd);
            print(s3, pd);
            print(s4, pd);
            print(s5, pd);
            print(s6, pd);
            s0 = s1 = s2 = s3 = s4 = s5 = s6 = "";
         }
         f = false;
      }
      else
      {
         f = true;
         s0 = s0 + s[d[i]][0] + " ";
         s1 = s1 + s[d[i]][1] + " ";
         s2 = s2 + s[d[i]][2] + " ";
         s3 = s3 + s[d[i]][3] + " ";
         s4 = s4 + s[d[i]][4] + " ";
         s5 = s5 + s[d[i]][5] + " ";
         s6 = s6 + s[d[i]][6] + " ";
      }
   }
   if (f)
   {
      if (pd)
         putchar(10);
      print(s0, pd);
      pd = true;
      print(s1, pd);
      print(s2, pd);
      print(s3, pd);
      print(s4, pd);
      print(s5, pd);
      print(s6, pd);
      s0 = s1 = s2 = s3 = s4 = s5 = s6 = "";
   }
   return 0;
}
