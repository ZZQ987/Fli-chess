#pragma once
#include"design.h"
#include"Draw.h"

#ifndef BASICLOGIC_H
#define BASICLOGIC_H

/***********************************************************************/

//#define DEBUG 1//若想要打开DEBUG模式，将此处取消注释即可

/***********************************************************************/

//初始选择
void begin();
//随机数生成
int getDieRes();
int getDieRes_computer();
//起飞和飞行的主程序
void take_off();
void fly();
//飞行判断
void move(int no);
void judge_move(int sheet, int no);
void k_head(int no);
//判断游戏是否结束
int judge();
#endif