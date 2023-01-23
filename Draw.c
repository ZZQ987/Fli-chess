#include"design.h"
#include"Draw.h"
HANDLE consoleHandle;

#define u 1//上下左右四个方向
#define d 2
#define l 3
#define r 4
//本文件用到的变量
int direct = 0;//方向
int my_color[4] = { 12,14,9,10 };
char mark[4] = { 'R','Y','B','G' };
int m_x[4][4] = { 14,16,14,16,14,16,14,16,35,37,35,37,35,37,35,37 };
int m_y[4][4] = { 17,17,18,18, 6,6,7,7,6,6,7,7 ,17,17,18,18 };
int x0 = 19, y0 = 19;
//画图函数
void show()
{
	HideCursor();
	gotoxy(0, 0);
	//画边框
	draw_frame();
	//画棋盘
	draw_main();
	//画状态栏
	draw_bar();
	return;
}
void draw_frame()//画一个有框界面
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i == 0 || j == 0 || i == y - 1 || j == x - 1)
			{
				if (i == 0 || i == y - 1)
				{
					if (j % 2 == 1)
					{
						char ch = ' ';
						mvaddch(i, j, ch);
						continue;
					}
				}
				char ch = '*';
				mvaddch(i, j, ch);
			}
		}
	}
}
void draw_main()
{

	//red 12  yellow  14 blue 9  green 10 
	//画机场
	{
		for (int i = 0; i < 4; i++)
		{
			color(my_color[i]);
			for (int j = 0; j < 4; j++)
			{
				if (plane[i][j] == 0)
				{
					mvaddch(m_y[i][j], m_x[i][j], mark[i]);
				}
				else if (plane[i][j] == final)
				{
					mvaddch(m_y[i][j], m_x[i][j], 36);
				}
				else
				{
					mvaddch(m_y[i][j], m_x[i][j], 35);
				}
			}
		}

		//画起飞点
		gotoxy(19, 20);
		printf("∧");
		gotoxy(10, 9);
		printf(">");
		gotoxy(31, 4);
		printf("∨");
		gotoxy(41, 15);
		printf("<");

		color(16);

		//画飞的航线
		for (int i = 2; i <= 10; i += 2)
		{
			if (i != 6)
				mvaddch(16, 19 + i, 'Z');
		}

		for (int i = 2; i <= 10; i += 2)
		{
			if (i != 6)
				mvaddch(8, 19 + i, 'Z');
		}
		for (int i = 1; i <= 5; i++)
		{
			if (i != 3)
				mvaddch(9 + i, 17, 'Z');
		}
		for (int i = 1; i <= 5; i++)
		{
			if (i != 3)
				mvaddch(9 + i, 33, 'Z');
		}
	}
	//画环形跑道
	{
		int _runway[runway + 1];
		for (int i = 0; i <= runway; i++)_runway[i] = 0;
		//q指向第一个结点。
	   //当前结点的序号，初始化为1 

		for (int i = 0; i < 52; i++) //循环查找第i个结点
		{
			if (square[i].num > 0)
			{
				_runway[i + 1] = 10 * (square[i].type) + square[i].num;
			}

		}

		for (int i = 1; i <= runway; i++)
		{
			gotoxy(x0, y0);
			if (_runway[i] == 0)
			{
				switch (i % 4)
				{
				case 0: {color(my_color[2]); break; }
				case 1: {color(my_color[3]); break; }
				case 2: {color(my_color[0]); break; }
				case 3: {color(my_color[1]); break; }
				}
				printf("□");
			}
			else
			{
				color(my_color[_runway[i] / 10 - 1]);
				if (_runway[i] % 10 == 1)
				{
					printf("%c", mark[_runway[i] / 10 - 1]);
				}
				else
				{
					printf("%d", _runway[i] % 10);
				}
			}
			if (i == 4 || i == 40 || i == 47)
			{
				direct = l;
				if (i == 4)
					y0--;
			}
			else if (i == 1 || i == 8 || i == 17)
			{
				direct = u;
				if (i == 17)
					x0 += 2;
			}
			else if (i == 14 || i == 30 || i == 21)
			{
				direct = r;
				if (i == 30)
					y0++;
			}
			else if (i == 27 || i == 34 || i == 43)
			{
				direct = d;
				if (i == 43)
					x0 -= 2;
			}
			switch (direct)
			{
			case u: {y0 -= 1; break; }
			case d: {y0 += 1; break; }
			case l: {x0 -= 2; break; }
			case r: {x0 += 2; break; }
			}
		}
	}

	//画最后直线跑道
	{
		for (int i = 0; i < 4; i++)
		{
			color(my_color[i]);
			for (int j = 0; j < 6; j++)
			{
				switch (i)
				{
				case 0: {gotoxy(25, 18 - j); break; }
				case 1: {gotoxy(13 + 2 * j, 12); break; }
				case 2: {gotoxy(25, 6 + j); break; }
				case 3: {gotoxy(37 - 2 * j, 12); break; }
				}
				if ((i + 1) <= player_num)
				{
					if (parting[i][j] == 1)
						printf("%c", mark[i]);
					else if (parting[i][j] > 1)
						printf("%d", parting[i][j]);
					else
						printf("□");
				}
				else
				{
					printf("□");
				}

			}
		}
		color(16);
		gotoxy(25, 12);
		printf("〇");

	}
}
void draw_bar()
{
	gotoxy(0, 26);
	printf("回合: %d\n", round);
	for (int i = 1; i <= player_num; i++)
	{
		color(my_color[i - 1]);
		printf("玩家%d: ", i);
		for (int j = 1; j <= 4; j++)
		{
			printf("棋子%d:", j);
			if (plane[i - 1][j - 1] == 0)printf("机场 ");
			else if (plane[i - 1][j - 1] == final)printf("终点 ");
			else printf("格子%d ", plane[i - 1][j - 1]);
		}
		printf("\n");
	}
	color(16);
}
//基础的工具函数
void gotoxy(int x, int y)      //光标移动到(x,y)位置
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void color(const unsigned short textColor)
{
	if (textColor >= 0 && textColor <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void mvaddch(int y, int x, char ch) //绘制
{
	COORD co = (COORD){ .X = x, .Y = y };
	SetConsoleCursorPosition(consoleHandle, co);
	putchar(ch);
}
void HideCursor() // 用于隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}