#pragma once
#include "items.h"

void make_order(LombardItems* lst);
int get_sum(LombardItems* lst, int fl);
Lombard* get_item(LombardItems* lst, char* str);
int check_borders(int l_b, int r_b);
void check_string(char* str);
void order_history();
void Menu();
void print_info(LombardItems* lst);