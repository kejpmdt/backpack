#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
   int userdata;
   scanf("%d", &userdata);
   fstream f;
   fstream f1;
   int health = 10;
   int maxmoney = 5;
   for (int turn = 1; 1; ++turn)
   {
      printf("health:%5d \n", health);
      printf("chose your active\n");
      if (userdata == 1)
      {
         f.open("user1.dat", ios::out);
      }
      else
      {
         f.open("user2.dat", ios::add);
      }
      f << turn << endl;
      int money = maxmoney;
      while (money)
      {
         if (userdata == 1)
         {
            f.open("user1.dat", ios::out);
         }
         else
         {
            f.open("user2.dat", ios::out);
         }
         int a, b;
         cin >> a >> b;
         if (a <= 0 || a >= 3 || b <= 0 || b >= 10)
            cout << "try again" << endl;
         if (a == 1)
         {
            money -= 3;
            if (money < 0)
            {
               cout << "try again" << endl;
               money += 3;
               continue;
            }
            else
               f << a << ' ' << b << endl;
         }
         else
         {
            money -= 1;
            f << a << ' ' << b << endl;
         }
         f.close();
      }
      while (1)
      {
         if (userdata == 1)
            f1.open("check1.dat", ios::in);
         else
            f1.open("check2.dat", ios::in);
         int u;
         f1 >> u;
         if (u == turn)
         {
            f1 >> u;
            health -= u;
            break;
         }
         f1.close();
      }
      system("clear");
   }
}