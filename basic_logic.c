#include"design.h"
#include"Draw.h"
#include"basic_logic.h"

//初始选择
void begin()//初始界面
{
	gotoxy(0, 0);
	draw_frame();
	gotoxy(x / 2 - 2, y / 2 - 1);
	printf("飞 行 棋\n");
	gotoxy(x / 2 - 17, y / 2 + 1);
	printf("（请按下空格键开始游戏，或其他键退出）");
	HideCursor();
	char input1;
	for (;;)
	{
		input1 = _getch();
		if (input1 == ' ')
		{
			gotoxy(x / 2 - 2, y / 2 + 3);
			printf("欢迎游玩");
			break;
		}
		else
		{
			gotoxy(x / 2 - 4, y / 2 + 3);
			printf("欢迎下次来玩");
			Sleep(600);
			system("CLS");
			exit(0);
		}
	}
	Sleep(800);
	system("CLS");
	printf("请先了解游戏规则及操作指南\n\n");
	printf("游戏规则说明:\n");
	printf("1.基本规则为共同承认的飞行棋规则\n");
	printf("2.当玩家骰子点数为6，若有飞机未出发，则优先飞机出发\n");
	printf("3.玩家可完成跳子，叠子，飞子，吃子的操作，有吃子与其他的联合，但没有(飞—跳)联合操作\n");
	printf("4.如果点数超过终点则执行反弹操作\n");
	printf("\n\n");
	printf("操作指南：\n");
	printf("1.玩家根据提示设置后，进入游戏；按空格键投掷骰子，选择棋子（按键盘1—4选择棋子）或不移动，结束阶段按z重启游戏，按x退出游戏，按空格进入下一回合\n");
	printf("2.玩家可在basiclogic.h文件中打开DEBUG模式，自行输入点数，本模式属于开发者模式，故没有步数限制，请合理谨慎使用，游玩时玩家不可见\n");
	printf("3.电脑有时选择时间较长请等待\n");
	printf("4.终点处显示的是棋子数量(大写字母表示一个棋子)，并不能移动\n");
	printf("5.棋子出发后，机场处显示#，到达终点后，机场处显示$\n");
	printf("6.本游戏除输入玩家名称和DEBUG模式输入点数，其余情况输入不需要回车键\n");
	printf("\n\n\n\n\n\n");
	HideCursor();
	Sleep(1000);
	HideCursor();
	printf("请按下空格键开始游戏祝你游戏愉快");
	next_order;
	system("CLS");
	HideCursor();
	for (;;)
	{
		printf("请选择游戏人数（2-4）\n");
		input1 = _getch();
		switch (input1)
		{
		case '2': {player_num = 2; goto next1; }
		case '3': {player_num = 3; goto next1; }
		case '4': {player_num = 4; goto next1; }
		default: {printf("人数错误，请重新选择\n"); }
		}
	}
next1:Sleep(600);

	char input2;
	for (;;)
	{
		printf("请选择真人玩家人数（0-总数）\n");
		input2 = _getch();
		if (input2 > input1) printf("错误，请重新选择\n");
		else
		{
			switch (input2)
			{
			case '0': {real_player_num = 0; goto next2; }
			case '1': {real_player_num = 1; goto next2; }
			case '2': {real_player_num = 2; goto next2; }
			case '3': {real_player_num = 3; goto next2; }
			case '4': {real_player_num = 4; goto next2; }
			}
		}
	}
next2:Sleep(600);

	printf("你选择的游戏玩家有%c名，其中真人玩家%c名\n", input1, input2);

	for (int i = 1; i <= (input2 - '0'); i++)
	{
		printf("请输入玩家%d的名字：(请切换英文输入法，不超过20位，否则自动截取)\n", i);
		for (int j = 0; j < 20; j++)
		{
			char ch;
			scanf("%c", &ch);
			if (ch == '\n' && j != 0)
				break;
			else if (ch == '\n' && j == 0)
			{
				printf("请重新输入\n");
				j = -1;
			}
			else if (ch != '\n')
			{
				player_name[i - 1][j] = ch;
			}
		}
	}
	for (int i = (input2 - '0') + 1; i <= (input1 - '0'); i++)
	{
		printf("请选择电脑玩家%d号的类型:\n", i);
		printf("1——急躁的玩家，优先走靠前的棋子\n");
		printf("2——随性的玩家，随机走一个棋子\n");
		printf("3——稳健的玩家，走靠后的棋子，齐头并进\n");
		printf("4——机智的玩家，可以进行更巧妙的走子\n");
		for (;;)
		{
			char comtype;
			comtype = _getch();
			if (comtype - '0' < 1 || comtype - '0' > 4)printf("选择类型错误，请重新输入\n");
			else
			{
				com_type[i - 1] = comtype - '0';
				printf("你选择了电脑玩家类型%d\n", com_type[i - 1]);
				break;
			}
		}

	}



	printf("设置完毕，游戏开始\n放大窗口游戏体验更佳");
	Sleep(2000);
	system("CLS");
}
//随机数
int getDieRes_computer()
{
	srand((unsigned)time(NULL));
	return  rand() % 4 + 1;
}
int getDieRes()
{
#ifdef DEBUG
	int a;
	scanf("%d", &a);
	return a;

#else
	srand((unsigned)time(NULL));
	return  rand() % 6 + 1;
#endif
}
//选择操作
void take_off()
{
	printf("飞机出动，请再投掷一次\n");
	if (player <= real_player_num)next_order;
	start[player - 1]--;
	die_point = getDieRes();
	printf("玩家%d的骰子点数为%d\n", player, die_point);
	Sleep(200);
	printf("可选择的棋子有\n");
	Sleep(200);

	for (int i = 0; i < 4; i++)
	{
		if (plane[player - 1][i] == 0)
			printf("%d ", i + 1);
	}
	printf("\n");

	if (player <= real_player_num)
	{
		for (;;)
		{
			printf("请选择要移动的棋子\n");
			Sleep(300);
			plane_no = _getch();
			if (plane_no >= '1' && plane_no <= '4' && plane[player - 1][plane_no - '0' - 1] == 0)
			{
				printf("选择了%d号\n", plane_no - '0');
				Sleep(200);
				break;
			}
			else
			{
				printf("选择有误，重新看清楚再选择\n");
				Sleep(200);
			}
		}
	}
	else
	{
		printf("请电脑选择\n");
		Sleep(150);
		int plane_no_int = 0;
		for (;;)
		{
			plane_no_int = getDieRes_computer();
			if (plane[player - 1][plane_no_int - 1] == 0) break;
		}
		plane_no = plane_no_int + '0';
		printf("选择了%d号\n", plane_no_int);
		Sleep(200);
	}
}
void fly()
{
	printf("可选择的棋子有\n");
	Sleep(200);
	for (int i = 0; i < 4; i++)
	{
		if (plane[player - 1][i] != final && plane[player - 1][i] != 0)
			printf("%d ", i + 1);

	}
	printf("\n");

	if (player <= real_player_num)
	{
		for (;;)
		{
			printf("请选择要移动的棋子\n");
			Sleep(300);
			plane_no = _getch();
			if (plane_no >= '1' && plane_no <= '4' && plane[player - 1][plane_no - '0' - 1] != final && plane[player - 1][plane_no - '0' - 1] != 0)
			{
				printf("选择了%d号\n", plane_no - '0');
				Sleep(200);
				break;
			}
			else
			{
				printf("选择有误，重新看清楚再选择\n");
				Sleep(200);
			}
		}
	}
	else
	{
		printf("请电脑选择\n");
		Sleep(150);
		int plane_no_int = 0;
		if (com_type[player - 1] == 2)//随机模式
		{
			for (;;)
			{
				plane_no_int = getDieRes_computer();
				if (plane[player - 1][plane_no_int - 1] != final && plane[player - 1][plane_no_int - 1] != 0) break;
			}
		}
		else if (com_type[player - 1] == 1)//走靠前的模式
		{
			int j = 0;
			int max = 0;
			for (j = 0; j < 4; j++)
			{
				if (plane[player - 1][j] < final && plane[player - 1][j] > 0)
				{
					max = plane[player - 1][j];
					break;
				}
			}
			plane_no_int = j;
			for (int i = j; i < 4; i++)
			{
				if (plane[player - 1][i] > max && plane[player - 1][i] < final && plane[player - 1][i] > 0)
				{
					max = plane[player - 1][i];
					plane_no_int = i;
				}
			}
			plane_no_int++;
		}
		else if (com_type[player - 1] == 3)//走最后的模式
		{
			int j = 0;
			int min = 0;
			for (j = 0; j < 4; j++)
			{
				if (plane[player - 1][j] < final && plane[player - 1][j] > 0)
				{
					min = plane[player - 1][j];
					break;
				}
			}
			plane_no_int = j;

			for (int i = j; i < 4; i++)
			{
				if (plane[player - 1][i] < min && plane[player - 1][i] < final && plane[player - 1][i] > 0)
				{
					min = plane[player - 1][i];
					plane_no_int = i;
				}
			}
			plane_no_int++;
		}
		else if (com_type[player - 1] == 4)//更高级判断的电脑
		{
			int decision = 0;
			for (int i = 0; i < 4; i++)
			{
				if (plane[player - 1][i] != 0 && plane[player - 1][i] != final && plane[player - 1][i] + die_point == final)
				{
					plane_no_int = i + 1;
					decision = 1;
					break;
				}
			}
			if (!decision)
				for (int i = 0; i < 4; i++)
				{
					if (plane[player - 1][i] != 0 && plane[player - 1][i] != final && plane[player - 1][i] <= planeway && (plane[player - 1][i] + die_point) > planeway)
					{
						plane_no_int = i + 1;
						decision = 1;
						break;
					}
				}
			if (!decision)
				for (int i = 0; i < 4; i++)
				{
					if (plane[player - 1][i] != 0 && plane[player - 1][i] != final && (plane[player - 1][i] + die_point - 2) % 4 == 0 && (plane[player - 1][i] + die_point) < 50)
					{
						plane_no_int = i + 1;
						decision = 1;
						break;
					}
				}
			if (!decision)
				for (int i = 0; i < 4; i++)
				{
					sheet = (plane[player - 1][i] + die_point + 13 * (player - 1)) % runway;
					if (sheet == 0)sheet = 52;
					if (plane[player - 1][i] != 0 && plane[player - 1][i] != final && square[sheet - 1].type != player && square[sheet - 1].type != 0)
					{
						plane_no_int = i + 1;
						decision = 1;
						break;
					}
				}
			if (!decision)
				for (;;)
				{
					plane_no_int = getDieRes_computer();
					if (plane[player - 1][plane_no_int - 1] != final && plane[player - 1][plane_no_int - 1] != 0) break;
				}
		}
		plane_no = plane_no_int + '0';
		printf("选择了%d号\n", plane_no_int);
		Sleep(200);
	}

}
//移动棋子
void k_head(int no)
{
	if (plane[player - 1][no - 1] > planeway)
	{
		parting[player - 1][plane[player - 1][no - 1] - planeway - 1]--;
	}
	else if (plane[player - 1][no - 1] > 0 && plane[player - 1][no - 1] <= planeway)
	{
		int sheet = (plane[player - 1][no - 1] + 13 * (player - 1)) % runway;
		if (sheet == 0)sheet = 52;
		square[sheet - 1].num--;
		if (square[sheet - 1].num == 0)
			square[sheet - 1].type = 0;
	}
	return;
}
void judge_move(int sheet, int no)
{
	//到了终末但是没到终点
	if (sheet > planeway && sheet < final)
	{
		parting[player - 1][sheet - planeway - 1]++;
		return;
	}
	//到达终点
	if (sheet == final)
	{
		over[player - 1]++;
		parting[player - 1][5]++;
		//parting[player - 1][sheet - runway - 1]++;
		return;
	}
	//还在公共区域
	if (sheet <= planeway)
	{
		sheet = (sheet + 13 * (player - 1)) % runway;
		if (sheet == 0)sheet = 52;

		if (square[sheet - 1].type == 0)
		{
			square[sheet - 1].type = player;
			square[sheet - 1].num++;
			return;

		}
		else  if (square[sheet - 1].type == player)
		{
			square[sheet - 1].num++;
			return;
		}

		else if (square[sheet - 1].type != player && square[sheet - 1].type != 0)
		{
			printf("触发“吃子”,吃掉%d号玩家棋子\n", square[sheet - 1].type);
			for (int i = 0; i < 4; i++)
			{
				if ((plane[(square[sheet - 1].type) - 1][i] + 13 * ((square[sheet - 1].type) - 1)) % runway == sheet)
				{
					plane[square[sheet - 1].type - 1][i] = 0;
					start[square[sheet - 1].type - 1]++;
				}
				if ((plane[(square[sheet - 1].type) - 1][i] + 13 * ((square[sheet - 1].type) - 1)) % runway == 0 && sheet == 52)
				{
					plane[square[sheet - 1].type - 1][i] = 0;
					start[square[sheet - 1].type - 1]++;
				}
			}
			square[sheet - 1].type = player;
			square[sheet - 1].num = 1;
			return;

		}
	}
}
void move(int no)
{

	k_head(no);

	plane[player - 1][no - 1] += die_point;//0-56
	//反弹
	if (plane[player - 1][no - 1] > final)
	{

		plane[player - 1][no - 1] = final - (plane[player - 1][no - 1] - final);
	}

	if ((plane[player - 1][no - 1] - 2) % 4 == 0 && plane[player - 1][no - 1] < 50)
	{
		judge_move(plane[player - 1][no - 1], no);
		k_head(no);
		if (plane[player - 1][no - 1] == 18)
		{
			plane[player - 1][no - 1] = 30;//飞
			printf("触发“飞”\n");
		}
		else
		{
			plane[player - 1][no - 1] += 4;//跳
			printf("触发“跳”\n");
		}
	}

	judge_move(plane[player - 1][no - 1], no);
}
//判断游戏是否结束
int judge()
{
	if      (over[0] == 4)return 1;
	else if (over[1] == 4)return 2;
	else if (over[2] == 4)return 3;
	else if (over[3] == 4)return 4;
	else  return 0;
}
