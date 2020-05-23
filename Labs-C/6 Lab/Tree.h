#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* right;
	struct node* left;
}Node;

void AddNode(Node** root, int val);
void Print(Node* current);
int GetBrAndSum(Node * current, int length, int* sum);
