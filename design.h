#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include<time.h>

#ifndef DESIGN_H
#define DESIGN_H

#define main_game_h 25//����߶�y
#define main_game_w 51//������x
#define runway 52//1-52//�����ܵ�����
#define planeway 50//�ɻ�ʵ���ߵĻ����ܵ�����
#define final 56//�յ����
#define next_order order = _getch()

typedef struct _square
{
    int type;
    int num;
}_square;

extern _square square[52];
extern int x, y;
extern int player_num;//�����
extern  int real_player_num;//�����������
extern int player;//��ǰ���ĸ����
extern int die_point;//����
extern int game_ends;//��Ϸ���������ж�
extern char plane_no;
extern char order;
extern int round;
extern  int plane[4][4];//��������
extern int parting[4][6];//��������ͣ��ƺ
extern int sheet;
extern int start[4] ;
extern int over[4] ;//RED\BLUE\GREEN\YELLOW��ɵ���ͣ����
extern char player_name[4][20];
extern int com_type[4];

void startup();
#endif