#include"design.h"
#include"Draw.h"
#include"basic_logic.h"

//��ʼѡ��
void begin()//��ʼ����
{
	gotoxy(0, 0);
	draw_frame();
	gotoxy(x / 2 - 2, y / 2 - 1);
	printf("�� �� ��\n");
	gotoxy(x / 2 - 17, y / 2 + 1);
	printf("���밴�¿ո����ʼ��Ϸ�����������˳���");
	HideCursor();
	char input1;
	for (;;)
	{
		input1 = _getch();
		if (input1 == ' ')
		{
			gotoxy(x / 2 - 2, y / 2 + 3);
			printf("��ӭ����");
			break;
		}
		else
		{
			gotoxy(x / 2 - 4, y / 2 + 3);
			printf("��ӭ�´�����");
			Sleep(600);
			system("CLS");
			exit(0);
		}
	}
	Sleep(800);
	system("CLS");
	printf("�����˽���Ϸ���򼰲���ָ��\n\n");
	printf("��Ϸ����˵��:\n");
	printf("1.��������Ϊ��ͬ���ϵķ��������\n");
	printf("2.��������ӵ���Ϊ6�����зɻ�δ�����������ȷɻ�����\n");
	printf("3.��ҿ�������ӣ����ӣ����ӣ����ӵĲ������г��������������ϣ���û��(�ɡ���)���ϲ���\n");
	printf("4.������������յ���ִ�з�������\n");
	printf("\n\n");
	printf("����ָ�ϣ�\n");
	printf("1.��Ҹ�����ʾ���ú󣬽�����Ϸ�����ո��Ͷ�����ӣ�ѡ�����ӣ�������1��4ѡ�����ӣ����ƶ��������׶ΰ�z������Ϸ����x�˳���Ϸ�����ո������һ�غ�\n");
	printf("2.��ҿ���basiclogic.h�ļ��д�DEBUGģʽ�����������������ģʽ���ڿ�����ģʽ����û�в������ƣ���������ʹ�ã�����ʱ��Ҳ��ɼ�\n");
	printf("3.������ʱѡ��ʱ��ϳ���ȴ�\n");
	printf("4.�յ㴦��ʾ������������(��д��ĸ��ʾһ������)���������ƶ�\n");
	printf("5.���ӳ����󣬻�������ʾ#�������յ�󣬻�������ʾ$\n");
	printf("6.����Ϸ������������ƺ�DEBUGģʽ�������������������벻��Ҫ�س���\n");
	printf("\n\n\n\n\n\n");
	HideCursor();
	Sleep(1000);
	HideCursor();
	printf("�밴�¿ո����ʼ��Ϸף����Ϸ���");
	next_order;
	system("CLS");
	HideCursor();
	for (;;)
	{
		printf("��ѡ����Ϸ������2-4��\n");
		input1 = _getch();
		switch (input1)
		{
		case '2': {player_num = 2; goto next1; }
		case '3': {player_num = 3; goto next1; }
		case '4': {player_num = 4; goto next1; }
		default: {printf("��������������ѡ��\n"); }
		}
	}
next1:Sleep(600);

	char input2;
	for (;;)
	{
		printf("��ѡ���������������0-������\n");
		input2 = _getch();
		if (input2 > input1) printf("����������ѡ��\n");
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

	printf("��ѡ�����Ϸ�����%c���������������%c��\n", input1, input2);

	for (int i = 1; i <= (input2 - '0'); i++)
	{
		printf("���������%d�����֣�(���л�Ӣ�����뷨��������20λ�������Զ���ȡ)\n", i);
		for (int j = 0; j < 20; j++)
		{
			char ch;
			scanf("%c", &ch);
			if (ch == '\n' && j != 0)
				break;
			else if (ch == '\n' && j == 0)
			{
				printf("����������\n");
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
		printf("��ѡ��������%d�ŵ�����:\n", i);
		printf("1�����������ң������߿�ǰ������\n");
		printf("2�������Ե���ң������һ������\n");
		printf("3�����Ƚ�����ң��߿�������ӣ���ͷ����\n");
		printf("4�������ǵ���ң����Խ��и����������\n");
		for (;;)
		{
			char comtype;
			comtype = _getch();
			if (comtype - '0' < 1 || comtype - '0' > 4)printf("ѡ�����ʹ�������������\n");
			else
			{
				com_type[i - 1] = comtype - '0';
				printf("��ѡ���˵����������%d\n", com_type[i - 1]);
				break;
			}
		}

	}



	printf("������ϣ���Ϸ��ʼ\n�Ŵ󴰿���Ϸ�������");
	Sleep(2000);
	system("CLS");
}
//�����
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
//ѡ�����
void take_off()
{
	printf("�ɻ�����������Ͷ��һ��\n");
	if (player <= real_player_num)next_order;
	start[player - 1]--;
	die_point = getDieRes();
	printf("���%d�����ӵ���Ϊ%d\n", player, die_point);
	Sleep(200);
	printf("��ѡ���������\n");
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
			printf("��ѡ��Ҫ�ƶ�������\n");
			Sleep(300);
			plane_no = _getch();
			if (plane_no >= '1' && plane_no <= '4' && plane[player - 1][plane_no - '0' - 1] == 0)
			{
				printf("ѡ����%d��\n", plane_no - '0');
				Sleep(200);
				break;
			}
			else
			{
				printf("ѡ���������¿������ѡ��\n");
				Sleep(200);
			}
		}
	}
	else
	{
		printf("�����ѡ��\n");
		Sleep(150);
		int plane_no_int = 0;
		for (;;)
		{
			plane_no_int = getDieRes_computer();
			if (plane[player - 1][plane_no_int - 1] == 0) break;
		}
		plane_no = plane_no_int + '0';
		printf("ѡ����%d��\n", plane_no_int);
		Sleep(200);
	}
}
void fly()
{
	printf("��ѡ���������\n");
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
			printf("��ѡ��Ҫ�ƶ�������\n");
			Sleep(300);
			plane_no = _getch();
			if (plane_no >= '1' && plane_no <= '4' && plane[player - 1][plane_no - '0' - 1] != final && plane[player - 1][plane_no - '0' - 1] != 0)
			{
				printf("ѡ����%d��\n", plane_no - '0');
				Sleep(200);
				break;
			}
			else
			{
				printf("ѡ���������¿������ѡ��\n");
				Sleep(200);
			}
		}
	}
	else
	{
		printf("�����ѡ��\n");
		Sleep(150);
		int plane_no_int = 0;
		if (com_type[player - 1] == 2)//���ģʽ
		{
			for (;;)
			{
				plane_no_int = getDieRes_computer();
				if (plane[player - 1][plane_no_int - 1] != final && plane[player - 1][plane_no_int - 1] != 0) break;
			}
		}
		else if (com_type[player - 1] == 1)//�߿�ǰ��ģʽ
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
		else if (com_type[player - 1] == 3)//������ģʽ
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
		else if (com_type[player - 1] == 4)//���߼��жϵĵ���
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
		printf("ѡ����%d��\n", plane_no_int);
		Sleep(200);
	}

}
//�ƶ�����
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
	//������ĩ����û���յ�
	if (sheet > planeway && sheet < final)
	{
		parting[player - 1][sheet - planeway - 1]++;
		return;
	}
	//�����յ�
	if (sheet == final)
	{
		over[player - 1]++;
		parting[player - 1][5]++;
		//parting[player - 1][sheet - runway - 1]++;
		return;
	}
	//���ڹ�������
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
			printf("���������ӡ�,�Ե�%d���������\n", square[sheet - 1].type);
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
	//����
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
			plane[player - 1][no - 1] = 30;//��
			printf("�������ɡ�\n");
		}
		else
		{
			plane[player - 1][no - 1] += 4;//��
			printf("����������\n");
		}
	}

	judge_move(plane[player - 1][no - 1], no);
}
//�ж���Ϸ�Ƿ����
int judge()
{
	if      (over[0] == 4)return 1;
	else if (over[1] == 4)return 2;
	else if (over[2] == 4)return 3;
	else if (over[3] == 4)return 4;
	else  return 0;
}
