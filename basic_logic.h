#pragma once
#include"design.h"
#include"Draw.h"

#ifndef BASICLOGIC_H
#define BASICLOGIC_H

/***********************************************************************/

//#define DEBUG 1//����Ҫ��DEBUGģʽ�����˴�ȡ��ע�ͼ���

/***********************************************************************/

//��ʼѡ��
void begin();
//���������
int getDieRes();
int getDieRes_computer();
//��ɺͷ��е�������
void take_off();
void fly();
//�����ж�
void move(int no);
void judge_move(int sheet, int no);
void k_head(int no);
//�ж���Ϸ�Ƿ����
int judge();
#endif