#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include<time.h>

#include"design.h"
#include"basic_logic.h"
#include"Draw.h"


int x, y;//��Ϸ������ݳ���
int player_num;//�������
int real_player_num;//���������
int player;//��ǰ���ĸ����
int die_point;//����
int game_ends;//��Ϸ���������ж�
char plane_no;//ѡ��ʱ���ӱ��
char order;//���ɺ궨��next_order
int round;//�غ���
_square square[52];//�ṹ�����飬�����ܵ�
int plane[4][4];//��������
int parting[4][6];//��������ͣ��ƺ
int sheet;//move������ʹ��
int start[4];//����
int over[4];//ͣ����
char player_name[4][20];//�����������
int com_type[4];

void startup()//��ʼ������
{
    for (int i = 0; i < 4; i++)
    {
        start[i] = 4;
        over[i] = 0;
        com_type[i] = 0;
        for (int j = 0; j < 4; j++)
        {
            plane[i][j] = 0;
        }
        for (int j = 0; j < 20; j++)
        {
            player_name[i][j] = '\0';
        }
        for (int j = 0; j < 6; j++)
        {
            parting[i][j] = 0;
        }
    }
  
    for (int i = 0; i < 52; i++)
    {
        square->type = 0;
        square->num = 0;
    }
    player_num = 0;
    real_player_num = 0;
    player = 0;
    game_ends = 0;
    x = main_game_w;
    y = main_game_h; 
    round = 1;
}