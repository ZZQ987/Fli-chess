#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include<time.h>

#ifndef DESIGN_H
#define DESIGN_H

#define main_game_h 25//界面高度y
#define main_game_w 51//界面宽度x
#define runway 52//1-52//环形跑道长度
#define planeway 50//飞机实际走的环形跑道长度
#define final 56//终点距离
#define next_order order = _getch()

typedef struct _square
{
    int type;
    int num;
}_square;

extern _square square[52];
extern int x, y;
extern int player_num;//总玩家
extern  int real_player_num;//真人玩家数量
extern int player;//当前是哪个玩家
extern int die_point;//点数
extern int game_ends;//游戏结束与否的判断
extern char plane_no;
extern char order;
extern int round;
extern  int plane[4][4];//表明棋子
extern int parting[4][6];//结束区域，停机坪
extern int sheet;
extern int start[4] ;
extern int over[4] ;//RED\BLUE\GREEN\YELLOW起飞点与停机点
extern char player_name[4][20];
extern int com_type[4];

void startup();
#endif