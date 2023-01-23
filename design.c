#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include<time.h>

#include"design.h"
#include"basic_logic.h"
#include"Draw.h"


int x, y;//游戏界面横纵长度
int player_num;//总玩家数
int real_player_num;//真人玩家数
int player;//当前是哪个玩家
int die_point;//点数
int game_ends;//游戏结束与否的判断
char plane_no;//选择时棋子编号
char order;//构成宏定义next_order
int round;//回合数
_square square[52];//结构体数组，环形跑道
int plane[4][4];//表明棋子
int parting[4][6];//结束区域，停机坪
int sheet;//move函数中使用
int start[4];//机场
int over[4];//停机点
char player_name[4][20];//真人玩家名字
int com_type[4];

void startup()//初始化数据
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