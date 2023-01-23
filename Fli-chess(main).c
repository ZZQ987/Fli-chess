#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include<time.h>
#include"design.h"
#include"Draw.h"
#include"basic_logic.h"

HANDLE consoleHandle;

int main()
{
	int times = 1;   //状态,与游戏重启还是退出有关(1,运行；0,退出)

	while (times)
	{
		times = 0;
		system("CLS");
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		HideCursor();

		startup();//初始化
		begin();//初始设置界面

		while (!game_ends) //游戏循环进行
		{
						show();//显示
			player = ((player + 1) % player_num);//切换玩家
			if (player == 0)
			{
				player = player_num;
				round++;
			}

			gotoxy(0, 32);
			if (player <= real_player_num)
			{
				printf("现在轮到%d号玩家(%s)，开始投骰子\n", player, player_name[player - 1]);
				next_order;//按下空格键
			}
			else
			{
				printf("现在轮到%d号玩家(电脑)，开始投骰子\n", player);
				Sleep(400);
			}
				

			die_point = getDieRes();
			printf("玩家%d骰子点数为%d\n", player, die_point);//投骰子
			Sleep(500);

			if (die_point == 6)
			{
				if (start[player - 1] != 0)
				{
					take_off();//一个棋子起飞
				}
				else
				{
					fly();//选择一个前进
				}
			}
			else
			{
				if (start[player - 1] + over[player - 1] == 4)
				{
					printf("无法移动\n请按下空格键继续或退出");

					order = _getch();

					if (order == 'z')//重启
					{
						times = 1;
						break;
					}
					else if (order == 'x')//退出游戏
					{
						times = 0;
						break;
					}
					system("CLS");
					continue;
				}
				else
				{
					fly();//前进
				}

			}

			move(plane_no - '0');//移动及判定

			printf("移动完成\n请按下空格键继续或退出");
			order = _getch();

			if (order == 'z')//重启
			{
				times = 1;
				break;
			}
			else if (order == 'x')//退出游戏
			{
				times = 0;
				break;
			}
			system("CLS");
			game_ends = judge();//判断游戏是否结束

		}
	}
	
	gotoxy(x / 2, y / 2);//到中央

	if (game_ends == 0)
	{
		system("CLS");
		gotoxy(x / 2, y / 2);
		printf("欢迎下次游玩\n\n\n\n\n\n\n\n\n");
	}
	else if (game_ends > real_player_num)
		printf("%d号电脑玩家获胜,欢迎下次游玩\n\n\n\n\n\n\n\n\n", game_ends);
	else
		printf("恭喜%d号玩家(%s)获胜，欢迎下次游玩\n\n\n\n\n\n\n\n\n", game_ends, player_name[game_ends - 1]);

	return 0;
}

