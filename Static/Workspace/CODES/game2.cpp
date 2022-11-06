#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
short S[12][32] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, // 3       2
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, // 4       1
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
                   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0};
short i, j;
short BoardZB = 4;
short BallZB[2] = {5, 15};
short FX[2] = {1, 1};
char s;
bool GameOver = 1, PZSound = 0;
void Print()
{
   for (i = 0; i < 12; i++)
   {
      for (j = 0; j < 32; j++)
      {
         switch (S[i][j])
         {
         case 0:
            cout << " ";
            break;
         case 1:
            cout << "|";
            break;
         case 2:
            cout << "*";
            break;
         case 3:
            cout << "\n";
            break;
         case 4:
            cout << "O";
            break;
         }
      }
   }
}
void GOSound()
{
   Beep(1500, 500);
   Beep(1000, 200);
   Beep(1000, 300);
   Beep(1200, 400);
   Beep(800, 1200);
}
int main()
{
   //////////开始界面
   system("mode con cols=32 lines=13");
   cout << endl;
   cout << "-------------------------------" << endl
        << "          P  O  N  G           " << endl
        << "-------------------------------" << endl
        << endl
        << "    Press any key to start    " << endl
        << "    Press x to exit" << endl
        << "    How to play? -?" << endl;
   Beep(800, 500);
   Beep(1200, 400);
   Beep(1000, 300);
   Beep(1000, 200);
   Beep(1500, 1200);
   while (kbhit())
      getch();
   s = getch();

   //////////退出游戏
   if (s == 'x')
      return 0;

   ////////游戏说明
   if (s == '?')
   {
      system("cls");
      cout << endl
           << "  w -- up       |" << endl
           << "  s -- down     | -- board" << endl
           << "  O -- ball     |"
           << endl
           << endl
           << "  Control the board to hit the\n  ball" << endl;
      getch();
   }
   system("cls");

   //////////初始化
   srand(time(0));
   FX[0] = rand() % 2;
   FX[1] = rand() % 2;
   BallZB[0] = rand() % 4 + 4;
   BallZB[1] = rand() % 4 + 13;
   S[BallZB[0]][BallZB[1]] = 4;
   if (FX[0] == 0)
      FX[0]--;
   if (FX[1] == 0)
      FX[1]--;

   //////////开始
   Print();
   getch();
   while (GameOver)
   {
      //////////输出
      Print();
      if (PZSound == 1)
         Beep(500, 20);
      Sleep(150);
      system("cls");

      //////////输入
      if (kbhit())
         s = getch();
      else
         s = '\0';

      //////////处理输入
      switch (s)
      {
      case 's':
         if (BoardZB < 8)
            BoardZB++;
         for (i = 1; i <= 8; i++)
         {
            if (i == BoardZB)
            {
               S[i][0] = 1;
               S[i + 1][0] = 1;
               S[i + 2][0] = 1;
               i += 3;
            }
            else
               S[i][0] = 0;
         }
         break;
      case 'w':
         if (BoardZB > 1)
            BoardZB--;
         for (i = 1; i <= 8; i++)
         {
            if (i == BoardZB)
            {
               S[i][0] = 1;
               S[i + 1][0] = 1;
               S[i + 2][0] = 1;
               i += 3;
            }
            S[i][0] = 0;
         }
         break;
      default:
         break;
      }
      //////////碰撞处理
      PZSound = 0;
      S[BallZB[0]][BallZB[1]] = 0;
      if (S[BallZB[0] + 1][BallZB[1]] == 2)
      {
         FX[0] = -1;
         PZSound = 1;
      }
      if (S[BallZB[0] - 1][BallZB[1]] == 2)
      {
         FX[0] = 1;
         PZSound = 1;
      }
      if (S[BallZB[0]][BallZB[1] + 1] == 1)
      {
         FX[1] = -1;
         PZSound = 1;
      }
      if (S[BallZB[0]][BallZB[1] - 1] == 1)
      {
         FX[1] = 1;
         PZSound = 1;
      }
      switch (FX[0])
      {
      case 1:
         BallZB[0]++;
         break;
      case -1:
         BallZB[0]--;
         break;
      }
      switch (FX[1])
      {
      case 1:
         BallZB[1]++;
         break;
      case -1:
         BallZB[1]--;
         break;
      }
      S[BallZB[0]][BallZB[1]] = 4;
      ////////////失败判定

      if (BallZB[1] == 0)
         GameOver = 0;
   }
   //////////失败动画
   system("color f0");
   Print();
   Beep(2000, 200);
   Sleep(1500);
   system("cls");
   cout << endl;
   cout << "-------------------------------" << endl
        << "                               " << endl
        << "-------------------------------" << endl
        << endl;
   Sleep(1000);
   system("cls");
   cout << endl;
   cout << "-------------------------------" << endl
        << "       G A M E                 " << endl
        << "-------------------------------" << endl
        << endl;
   Sleep(1000);
   system("cls");
   cout << endl;
   cout << "-------------------------------" << endl
        << "       G A M E  O V E R        " << endl
        << "-------------------------------" << endl
        << endl;
   GOSound();
   cout << "    Press any key to continue  " << endl
        << "    Press x to exit          " << endl;
   Sleep(1000);
   while (kbhit())
      getch();
   s = getch();
   if (s != 'x')
   {
      system("cls");
      system("color 07");

      //失败后初始化
      S[BallZB[0]][BallZB[1]] = 0;
      GameOver = 1;

      //////////重来
      main();
   }
   return 0;
}