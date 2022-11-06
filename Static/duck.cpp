#include <iostream>
#include <cstdio>
#include <windows.h>
#include "conio.h"
#include <cstdlib>
#include <ctime>
using namespace std;
/*
蓝方  王1  士2  象3 马4  车5  鸭6  兵7
红方  王a  士b  象c 马d  车e  鸭f  兵g
*/
bool language;
int changeX(int);
int changeY(int);
char a[11][10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 
			      '0', '5', '4', '3', '2', '1', '2', '3', '4', '5',
				  '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 
				  '0', '6', '0', '0', '0', '0', '0', '0', '0', '6', 
				  '0', '7', '0', '7', '0', '7', '0', '7', '0', '7', 
				  '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 
				  '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				  '0', 'g', '0', 'g', '0', 'g', '0', 'g', '0', 'g', 
				  '0', 'f', '0', '0', '0', '0', '0', '0', '0', 'f', 
				  '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 
				  '0', 'e', 'd', 'c', 'b', 'a', 'b', 'c', 'd', 'e'};
void print_string(string);
void start();
void print_checkerboard();
void write_answer(char);
int dict_captain[5][2] = {0, 0, 
						  0, 1, 
						  0, -1, 
						  1, 0, 
						  -1, 0};
bool move_red_captain(int, int, int, int);
bool move_blue_captain(int, int, int, int);
int dict_guard[5][2] = {0, 0, 
						1, 1, 
						-1, -1, 
						1, -1, 
						-1, 1};
bool move_red_guard(int, int, int, int);
bool move_blue_guard(int, int, int, int);
int dict_sxy[5][2] = {0, 0, 
					  1, 1, 
					  -1, -1,
					  1, -1, 
					  -1, 1};
bool move_red_elephant(int, int, int, int);
bool move_blue_elephant(int, int, int, int);
bool move_red_horse(int, int, int, int);
bool move_blue_horse(int, int, int, int);
bool move_red_car(int, int, int, int);
bool move_blue_car(int, int, int, int);
bool move_red_duck(int, int, int, int);
bool move_blue_duck(int, int, int, int);
int dict_soldier[9][2] = {0, 0, 
						  -1, -1, 
						  -1, 0, 
						  -1, 1, 
						  0, -1, 
						  0, 1, 
						  1, -1, 
						  1, 0,
						  1, 1};
bool move_red_soldier(int, int, int, int);
bool move_blue_soldier(int, int, int, int);
bool judge(int, int, int, int, bool);
//以下为判断将军程序
bool general_captain(int, int, int, int);
bool general_guard(int, int, int, int);
bool general_elephant(int, int, int, int);
bool general_horse(int, int, int, int);
bool general_car(int, int, int, int);
bool general_duck(int, int, int, int);
bool general_soldier(int, int, int, int);
int Is_general();  //若存在将军返回 true， 否则返回 false 
int gameover();  //若游戏已经结束返回 true，否则返回 false
void introduction();
void color(int);
void loading();
void choose_language();
void content();
void rule();
void play();
void DUCK_GAME_IS_FUN();
/*
蓝方  王1  士2  象3 马4  车5  鸭6  兵7
红方  王a  士b  象c 马d  车e  鸭f  兵g
*/
int main()
{
	srand(time(0));
	start();
	play();
	return 0;
}
void color(int n) //颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
	return;
}
void choose_language()
{
	color(12);
	print_string("choose a language.\n");
	color(10);
	_sleep(500);
	print_string("english(en) puts 0\nchinese(zh) puts 1\n");
	char t = getch();
	color(15);
	while (t != '0' && t != '1')
	{
		print_string("error input.\n");
		t = getch();
	}
	language = (t == '1');
	color(12);
	if (language) print_string("OK. you choose chinese(zh).\n");
	else print_string("OK. you choose english(en).\n");	
}
void start()
{
	color(14);
	printf("******duct chess game*******鸭棋游戏******by liangbowen************\n");
	_sleep(1000);
	choose_language();
	_sleep(1000);
	loading();
	_sleep(1000);
	content();
}
void loading()
{
	for (int i = 1; i <= 50; i++)
	{
		system("cls");
		if (language == 0) printf("Loading...");
		else printf("加载中...");
		if (i == 50) printf("1000/1000");
		else printf("%d/1000", i * (rand() % 3 + 19));
	}
}
void content()
{
	
	if (language == 0)  //英语 
	{
		system("cls");
		color(10);
		printf("puts 1 to see the rule\n");
		color(11);
		printf("puts 2 to start the game\n");
		color(12);
		printf("puts 3 to see the author's game creation process\n");
	}
	else
	{
		system("cls");
		color(10);
		printf("1键查看游戏规则\n");
		color(11);
		printf("2键直接开始游戏\n");
		color(12);
		printf("3键查看作者游戏创作历程\n");
	}
	color(15);
	char t = getch();
	while (t != '1' && t != '2' && t != '3')
	{
		if (language == 0) print_string("error input.\n");
		else print_string("错误的读入。\n");
		t = getch();
	}
	system("cls");
	if (t == '1')
	{
		rule();
		if (language == 0)  //英语 
		{
			system("cls");
			color(11);
			printf("puts 2 to start the game\n");
			color(12);
			printf("puts 3 to see the author's game creation process\n");
		}
		else
		{
			system("cls");
			color(11);
			printf("2键直接开始游戏\n");
			color(12);
			printf("3键查看作者游戏创作历程\n");
		}
		color(15);
		char t = getch();
		while (t != '2' && t != '3')
		{
			if (language == 0) print_string("error input.\n");
			else print_string("错误的读入。\n");
			t = getch();
		}
		system("cls");
		if (t == '2') play();
		else if (t == '3')
		{
			introduction();
			system("cls");
			color(12);
			if (language == 0) print_string("now, let's start the game!\n");
			else print_string("现在，让我们开始游戏吧！\n");
			color(15);
			system("pause");
			system("cls");
			play();
		}
	}
	else if (t == '2') play();
	else if (t == '3')
	{
		introduction();
		if (language == 0)  //英语 
		{
			system("cls");
			color(10);
			printf("puts 1 to see the rule\n");
			color(11);
			printf("puts 2 to start the game\n");
		}
		else
		{
			system("cls");
			color(10);
			printf("1键查看游戏规则\n");
			color(11);
			printf("2键直接开始游戏\n");
		}
		color(15);
		char t = getch();
		while (t != '1' && t != '2')
		{
			if (language == 0) print_string("error input.\n");
			else print_string("错误的读入。\n");
			t = getch();
		}
		system("cls");
		if (t == '1')
		{
			rule();
			system("cls");
			color(12);
			if (language == 0) print_string("now, let's start the game!\n");
			else print_string("现在，让我们开始游戏吧！\n");
			color(15);
			system("pause");
			system("cls");
			play();
		}
		else if (t == '2') play();
	}
}
void play()
{
	system("cls");
	color(14);
	if (language == 0) print_string("Because there are many thing, it needs to be loaded again.\n");
	else print_string("由于资源较多，需要再次进行加载。\n");
	color(15);
	_sleep(1000);
	loading();
	_sleep(500);
	color(10);
	if (language == 0) printf("\nLoad complete!");
	else printf("\n加载完成！");
	color(15);
	_sleep(1000);
	DUCK_GAME_IS_FUN();
}
void DUCK_GAME_IS_FUN()
{
	bool who_ctrl = 0;   //0是红方，1是蓝方
	while (true)
	{
		print_checkerboard();
		if (language == 0)
		{
			printf("Now it's ");
			if (who_ctrl == 0) color(12), printf("red");
			else color(11), printf("blue");
			color(15);
			printf(" turn.\n");	
		}
		else
		{
			printf("现在由");
			if (who_ctrl == 0) color(12), printf("红方");
			else color(11), printf("蓝方");
			color(15);
			printf("操作。\n");			
		}
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1 = changeX(x1), y1 = changeY(y1), x2 = changeX(x2), y2 = changeY(y2);
		if (judge(x1, y1, x2, y2, who_ctrl) == false)
		{
			_sleep(1000);
			continue;
		}
		if (a[x2][y2] != '0')
		{
			if (language == 0) printf("EAT!\n");
			else printf("吃！\n");
			_sleep(300);
		}
		a[x2][y2] = a[x1][y1];
		a[x1][y1]  = '0';
		int ttttt = Is_general();
		if (ttttt == 1)
		{
			color(12);
			if (language == 0) print_string("WARNING red captain is generaled!!!\n");
			else print_string("警告 红王被将军了！！！\n");
			_sleep(2000);
			color(15);
		}
		else if (ttttt == 2)
		{
			color(11);
			if (language == 0) print_string("WARNING blue captain is generaled!!!\n");
			else print_string("警告 蓝王被将军了！！！\n");
			_sleep(2000);
			color(15);
		}
		ttttt = gameover();
		if (ttttt != 2)
		{
			system("cls");
			print_checkerboard();
			printf("\n\n");
			if (language == 0) print_string("Game over!");
			else print_string("游戏结束了！");
			if (ttttt == 0)
			{
				color(11);
				if (language == 0) print_string("blue win!!!\n");
				else print_string("蓝方获胜！！！\n");
				color(15);
			}
			else if (ttttt == 1)
			{
				color(12);
				if (language == 0) print_string("red win!!!\n");
				else print_string("红方获胜！！！\n");
				color(15);
			}
			color(14);
			printf("\n\n******************************************");
			exit(0);
		}
		who_ctrl = !who_ctrl;   //放在末尾才能有效忽略不合法操作 
	}
}
void rule()
{
	if (language == 0)  //英语 
	{
		print_string("You can get the rule from luogu P5380.\nLink:");
		color(11);
		print_string("https://www.luogu.com.cn/problem/P5380\n");
		color(15);
		print_string("al thing is the same, include the input.\n");
		_sleep(300);
		print_string("In fact, we will use the ");
		color(12);
		print_string("chinese ");
		color(15);
		print_string("to print the checkerboard.\n");
		system("pause");
	}
	else 
	{
		print_string("你可以通过洛谷 P5380 来了解游戏规则，\n网址：");
		color(11);
		print_string("https://www.luogu.com.cn/problem/P5380\n");
		color(15);
		print_string("包括输入的格式也是一样的。\n");
		system("pause");
	}	
}
void introduction()
{
	if (language == 0)
	{
		print_string("welcome to use the duck chess game which is made by @liangbowen!\n");
		_sleep(300);
		print_string("the game inspiration is from 【luogu P5380 duck chess】\n");
		_sleep(300);
		print_string("after the author's work, the problem was finished, \nand then the author make this game to commemorative the problem.\n");
		_sleep(300);
		color(12);
		print_string("other ways, this is the game's update:\n");
		_sleep(300);
		print_string("2022-3-21 finish the problem\n");
		_sleep(300);
		print_string("2022-3-26 start to do this game\n");
		_sleep(300);
		print_string("2022-3-28 finish the game\n");
		color(15);
		system("pause");
	}
	else
	{
		print_string("欢迎使用 @liangbowen 开发的鸭棋游戏！\n");
		_sleep(300);
		print_string("此游戏灵感来自于【洛谷P5380 鸭棋】\n");
		_sleep(300);
		print_string("经过作者的努力后，题目被完成了，\n随后作者灵感大发，创作了这款鸭棋游戏作为题目纪念。\n");
		_sleep(300);
		color(12);
		print_string("另外，游戏更新日志：\n");
		_sleep(300);
		print_string("2022-3-21 完成题目\n");
		_sleep(300);
		print_string("2022-3-26 开始制作游戏产品\n");
		_sleep(300);
		print_string("2022-3-28 完成游戏\n");
		color(15);
		system("pause");
	}

}
void print_string(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
		_sleep(30);
	}
}
void print_checkerboard()
{
	system("cls");
	for (int i = 1; i <= 10; i++)
	{
		printf("%-2d ", changeX(i));
		for (int j = 1; j <= 9; j++)
		{
			if (a[i][j] == '0')
			{
				color(15);
				printf("[]");
			}
			else if ('1' <= a[i][j] && a[i][j] <= '7')  //蓝方
			{
				color(11);
				if (a[i][j] == '1') printf("王");
				else if (a[i][j] == '2') printf("士");
				else if (a[i][j] == '3') printf("象");
				else if (a[i][j] == '4') printf("马");
				else if (a[i][j] == '5') printf("车");
				else if (a[i][j] == '6') printf("鸭");
				else if (a[i][j] == '7') printf("兵");
			}
			else if ('a' <= a[i][j] && a[i][j] <= 'g')  //红方
			{
				color(12);
				if (a[i][j] == 'a') printf("王");
				else if (a[i][j] == 'b') printf("士");
				else if (a[i][j] == 'c') printf("象");
				else if (a[i][j] == 'd') printf("马");
				else if (a[i][j] == 'e') printf("车");
				else if (a[i][j] == 'f') printf("鸭");
				else if (a[i][j] == 'g') printf("兵");
			} 
		}
		color(15);
		putchar('\n');
	}
	printf("  ");
	for (int j = 0; j <= 8; j++) printf("%2d", j);
	printf("\n\n");
}
int changeX(int x)
{
	return 10 - x;
}
int changeY(int y)
{
	return y + 1;
}
void write_answer(char x)
{
	if (language == 0) printf("Invalid command\n");
	else printf("操作错误。\n");
}
bool move_red_captain(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_captain[i][0], dy = y1 + dict_captain[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_blue_captain(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_captain[i][0], dy = y1 + dict_captain[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_red_guard(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_guard[i][0], dy = y1 + dict_guard[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_blue_guard(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_guard[i][0], dy = y1 + dict_guard[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_red_elephant(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_blue_elephant(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_red_horse(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		//one
		int dx = x1 + dict_sxy[i][0], dy = y1;
		if (a[dx][dy] != '0') continue;
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		//two
		int dx = x1, dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		dx = x1 + dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_blue_horse(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		//one
		int dx = x1 + dict_sxy[i][0], dy = y1;
		if (a[dx][dy] != '0') continue;
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		//two
		int dx = x1, dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		dx = x1 + dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_red_car(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
	{
		write_answer('x');
		return false;
	}
	if (x1 == x2 && y1 == y2)
	{
		write_answer('x');
		return false;
	}
	if (x1 != x2 && y1 != y2)
	{
		write_answer('x');
		return false;
	}
	if (x1 == x2)
	{
		int minn = min(y1, y2), maxn = max(y1, y2);
		for (int i = minn + 1; i < maxn; i++)
			if (a[x1][i] != '0')
			{
				write_answer('x');
				return false;
			}
		return true;
	}
	if (y1 == y2)
	{
		int minn = min(x1, x2), maxn = max(x1, x2);
		for (int i = minn + 1; i < maxn; i++)
			if (a[i][y1] != '0')
			{
				write_answer('x');
				return false;
			}
		return true;
	}
	write_answer('x');
	return false;
}
bool move_blue_car(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
	{
		write_answer('x');
		return false;
	}
	if (x1 == x2 && y1 == y2)
	{
		write_answer('x');
		return false;
	}
	if (x1 != x2 && y1 != y2)
	{
		write_answer('x');
		return false;
	}
	if (x1 == x2)
	{
		int minn = min(y1, y2), maxn = max(y1, y2);
		for (int i = minn + 1; i < maxn; i++)
			if (a[x1][i] != '0')
			{
				write_answer('x');
				return false;
			}
		return true;
	}
	if (y1 == y2)
	{
		int minn = min(x1, x2), maxn = max(x1, x2);
		for (int i = minn + 1; i < maxn; i++)
			if (a[i][y1] != '0')
			{
				write_answer('x');
				return false;
			}
		return true;
	}
	write_answer('x');
	return false;
}
bool move_red_duck(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		//one
		int dx = x1 + 2 * dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + dict_sxy[i][0], dy = y1;
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + 3 * dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		//two
		int dx = x1 + dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1, dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + 3 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_blue_duck(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 4; i++)
	{
		//one
		int dx = x1 + 2 * dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + dict_sxy[i][0], dy = y1;
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + 3 * dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		//two
		int dx = x1 + dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1, dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + 3 * dict_sxy[i][1];
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_red_soldier(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 8; i++)
	{
		int dx = x1 + dict_soldier[i][0], dy = y1 + dict_soldier[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2)
		{
			if ('a' <= a[x2][y2] && a[x2][y2] <= 'g') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool move_blue_soldier(int x1, int y1, int x2, int y2) 
{
	if (!(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9))
	{
		write_answer('x');
		return false;
	}
	for (int i = 1; i <= 8; i++)
	{
		int dx = x1 + dict_soldier[i][0], dy = y1 + dict_soldier[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2)
		{
			if ('1' <= a[x2][y2] && a[x2][y2] <= '7') //己方棋
			{
				write_answer('x');
				return false;
			}
			else return true;
		}
	}
	write_answer('x');
	return false;
}
bool judge(int x1, int y1, int x2, int y2, bool who_ctrl)
{
	if (!(1 <= x1 && x1 <= 10 && 1 <= y1 && y1 <= 9) || 
	    !(1 <= x2 && x2 <= 10 && 1 <= y2 && y2 <= 9) || 
	    a[x1][y1] == '0')
		{
			write_answer('x');
			return false;
		}
	else if (a[x1][y1] == 'a')   //王 
	{
		if (who_ctrl == 1)
		{
			write_answer('x');
			return false;
		}
		if (move_red_captain(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == '1')
	{
		if (who_ctrl == 0)
		{
			write_answer('x');
			return false;
		}
		if (move_blue_captain(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == 'b')   //士
	{
		if (who_ctrl == 1)
		{
			write_answer('x');
			return false;
		}
		if (move_red_guard(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == '2')
	{
		if (who_ctrl == 0)
		{
			write_answer('x');
			return false;
		}
		if (move_blue_guard(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == 'c')   //象 
	{
		if (who_ctrl == 1)
		{
			write_answer('x');
			return false;
		}
		if (move_red_elephant(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == '3')
	{
		if (who_ctrl == 0)
		{
			write_answer('x');
			return false;
		}
		if (move_blue_elephant(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == 'd')   //马 
	{
		if (who_ctrl == 1)
		{
			write_answer('x');
			return false;
		}
		if (move_red_horse(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == '4')
	{
		if (who_ctrl == 0)
		{
			write_answer('x');
			return false;
		}
		if (move_blue_horse(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == 'e')   //车
	{
		if (who_ctrl == 1)
		{
			write_answer('x');
			return false;
		}
		if (move_red_car(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == '5')
	{
		if (who_ctrl == 0)
		{
			write_answer('x');
			return false;
		}
		if (move_blue_car(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == 'f')   //鸭
	{
		if (who_ctrl == 1)
		{
			write_answer('x');
			return false;
		}
		if (move_red_duck(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == '6')
	{
		if (who_ctrl == 0)
		{
			write_answer('x');
			return false;
		}
		if (move_blue_duck(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == 'g')   //兵
	{
		if (who_ctrl == 1)
		{
			write_answer('x');
			return false;
		}
		if (move_red_soldier(x1, y1, x2, y2) == false) return false;
	}
	else if (a[x1][y1] == '7')
	{
		if (who_ctrl == 0)
		{
			write_answer('x');
			return false;
		}
		if (move_blue_soldier(x1, y1, x2, y2) == false) return false;
	}
	return true;
}
//以下为判断将军函数；判断 己方(x1, y1) 的棋 是否可以将军 (x2, y2)对方王的坐标
bool general_captain(int x1, int y1, int x2, int y2)
{
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_captain[i][0], dy = y1 + dict_captain[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2) return true;
	}
	return false;
}
bool general_guard(int x1, int y1, int x2, int y2) 
{
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_guard[i][0], dy = y1 + dict_guard[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2) return true;
	}
	return false;
}
bool general_elephant(int x1, int y1, int x2, int y2) 
{
	for (int i = 1; i <= 4; i++)
	{
		int dx = x1 + dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2) return true;
	}
	return false;
}
bool general_horse(int x1, int y1, int x2, int y2) 
{
	for (int i = 1; i <= 4; i++)
	{
		//one
		int dx = x1 + dict_sxy[i][0], dy = y1;
		if (a[dx][dy] != '0') continue;
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (dx == x2 && dy == y2) return true;
	}
	for (int i = 1; i <= 4; i++)
	{
		//two
		int dx = x1, dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		dx = x1 + dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2) return true;
	}
	return false;
}
bool general_car(int x1, int y1, int x2, int y2) 
{
	if (x1 == x2 && y1 == y2) return false;
	if (x1 != x2 && y1 != y2) return false;
	if (x1 == x2)
	{
		int minn = min(y1, y2), maxn = max(y1, y2);
		for (int i = minn + 1; i < maxn; i++)
			if (a[x1][i] != '0')
				return false;
		return true;
	}
	if (y1 == y2)
	{
		int minn = min(x1, x2), maxn = max(x1, x2);
		for (int i = minn + 1; i < maxn; i++)
			if (a[i][y1] != '0')
				return false;
		return true;
	}
}
bool general_duck(int x1, int y1, int x2, int y2) 
{
	for (int i = 1; i <= 4; i++)
	{
		//one
		int dx = x1 + 2 * dict_sxy[i][0], dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + dict_sxy[i][0], dy = y1;
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + 3 * dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (dx == x2 && dy == y2) return true;
	}
	for (int i = 1; i <= 4; i++)
	{
		//two
		int dx = x1 + dict_sxy[i][0], dy = y1 + 2 * dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1, dy = y1 + dict_sxy[i][1];
		if (a[dx][dy] != '0') continue;
		
		dx = x1 + 2 * dict_sxy[i][0], dy = y1 + 3 * dict_sxy[i][1];
		if (dx == x2 && dy == y2) return true;
	}
	return false;
}
bool general_soldier(int x1, int y1, int x2, int y2) 
{
	for (int i = 1; i <= 8; i++)
	{
		int dx = x1 + dict_soldier[i][0], dy = y1 + dict_soldier[i][1];
		if (!(1 <= dx && dx <= 10 && 1 <= dy && dy <= 9)) continue;
		if (dx == x2 && dy == y2) return true;
	}
	return false;
}
//重点！！！！！！ 同样类型的棋子可能有多个！！！！！！！！！！！ 
//思路：先 get 王的位置，然后直接遍历棋盘 
int Is_general()  //若存在红方被将军返回 1，蓝方被将军返回 2，没有将军返回 0 
{
	int red_captain_x = -1, red_captain_y, blue_captain_x = -1, blue_captain_y;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (a[i][j] == 'a') red_captain_x = i, red_captain_y = j;
			if (a[i][j] == '1') blue_captain_x = i, blue_captain_y = j;
		}
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (a[i][j] == '1')
			{
				if (general_captain(i, j, red_captain_x, red_captain_y)) return 1;
				continue;
			}
			if (a[i][j] == '2')
			{
				if (general_guard(i, j, red_captain_x, red_captain_y)) return 1;
				continue;
			}
			if (a[i][j] == '3')
			{
				if (general_elephant(i, j, red_captain_x, red_captain_y)) return 1;
				continue;
			}
			if (a[i][j] == '4')
			{
				if (general_horse(i, j, red_captain_x, red_captain_y)) return 1;
				continue;
			}
			if (a[i][j] == '5')
			{
				if (general_car(i, j, red_captain_x, red_captain_y)) return 1;
				continue;
			}
			if (a[i][j] == '6')
			{
				if (general_duck(i, j, red_captain_x, red_captain_y)) return 1;
				continue;
			}
			if (a[i][j] == '7')
			{
				if (general_soldier(i, j, red_captain_x, red_captain_y)) return 1;
				continue;
			}
			if (a[i][j] == 'a')
			{
				if (general_captain(i, j, blue_captain_x, blue_captain_y)) return 2;
				continue;
			}
			if (a[i][j] == 'b')
			{
				if (general_guard(i, j, blue_captain_x, blue_captain_y)) return 2;
				continue;
			}
			if (a[i][j] == 'c')
			{
				if (general_elephant(i, j, blue_captain_x, blue_captain_y)) return 2;
				continue;
			}
			if (a[i][j] == 'd')
			{
				if (general_horse(i, j, blue_captain_x, blue_captain_y)) return 2;
				continue;
			}
			if (a[i][j] == 'e')
			{
				if (general_car(i, j, blue_captain_x, blue_captain_y)) return 2;
				continue;
			}
			if (a[i][j] == 'f')
			{
				if (general_duck(i, j, blue_captain_x, blue_captain_y)) return 2;
				continue;
			}
			if (a[i][j] == 'g')
			{
				if (general_soldier(i, j, blue_captain_x, blue_captain_y)) return 2;
				continue;
			}
		}
	return 0;
}
//以下判断游戏是否结束 
int gameover()  //红方失败 0  蓝方失败 1  没有人失败 2 
{
	bool chk = true;
	for (int i = 1; i <= 10 && chk; i++)
		for (int j = 1; j <= 9 && chk; j++)
			if (a[i][j] == 'a')
				chk = false;
	if (chk) return 0;
	chk = true;
	for (int i = 1; i <= 10 && chk; i++)
		for (int j = 1; j <= 9 && chk; j++)
			if (a[i][j] == '1')
				chk = false;
	if (chk) return 1;
	return 2;
}
