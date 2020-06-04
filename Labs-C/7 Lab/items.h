#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

const int max_str_length = 25;
const int radix = 10;

struct Lombard
{
    char customer[max_str_length];
    char nameItem[max_str_length];
    char requisites[max_str_length];
	char date_of_completion[max_str_length]; // дата сдачи
	char shelf_life[max_str_length]; // срок хранени€
    int items_amount;
    int assessed_value; // оценочна€ стоимость
    int price;
    Lombard* next, * prev;
};
struct LombardItems
{
    Lombard* head, * tail;
    int size;
};

int file_size(FILE* file);
void delete_lobard_items(LombardItems* lst);
void add_to_lombard_list(LombardItems* lst, Lombard* book);
Lombard* load_items_from_file(FILE* file);
void load_items_to_file(Lombard* book, int flag, int count);
void change_item(LombardItems* lst);
Lombard* add_item();
void print_info(LombardItems* lst);
void print_items(LombardItems* lst);
LombardItems* read_items(int flag);