#pragma once
#include"design.h"

#ifndef DRAW_H
#define DRAW_H
void show();
void draw_frame();
void draw_main();
void draw_bar();
void color(const unsigned short textColor);
void mvaddch(int y, int x, char ch);
void gotoxy(int x, int y);
void HideCursor();
#endif