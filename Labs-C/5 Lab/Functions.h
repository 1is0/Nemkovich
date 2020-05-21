#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int element;
	struct node* next;
};
struct node* AddEl(struct node*, int);
struct node* Sort(struct node*);
void DeleteDuplElements(struct node*);
struct node* PlusList(struct node*, struct node*);
void Show(struct node*);
void MemoryCheck(struct node*);