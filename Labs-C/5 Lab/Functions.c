#include "Functions.h"

struct node* AddEl(struct node* listRoot, int val)
{
	struct node* current = listRoot, *newNode;
	while (current->next != NULL)
	{
		current = current->next;
	}
	newNode = (struct node*)malloc(sizeof(struct node)); // узел
	MemoryCheck(newNode);
	newNode->element = val;
	newNode->next = NULL;
	current->next = newNode;
	return newNode;
}

struct node* Sort(struct node* listRoot)
{
	struct node* current = listRoot, *tmp = NULL, *prev = NULL;
	int flag = 0;
	do
	{
		flag = 0;
		current = listRoot;
		while (current->next != NULL)
		{
			if (current->element > current->next->element)
			{
				if (current == listRoot)
				{
					tmp = current;
					current = tmp->next;
					tmp->next = current->next;
					current->next = tmp;
					listRoot = current;
					flag = 1;
				}
				else
				{
					tmp = current;
					current = tmp->next;
					tmp->next = current->next;
					current->next = tmp;
					prev->next = current;
					flag = 1;
				}
			}
			prev = current;
			current = current->next;
		}
	} while (flag == 1);
	return listRoot;
}

void DeleteDuplElements(struct node* listRoot)
{
	struct node* placeholder, * temp = listRoot;
	while (temp != NULL && temp->next != NULL)
	{
		while (temp->element == temp->next->element) 
		{
			placeholder = temp->next->next;
			free(temp->next);
			temp->next = placeholder;
			if (temp->next == NULL)
				break;
		}
		if (temp->next == NULL)
			break;
		while (temp->element != temp->next->element)
		{
			temp = temp->next;
			if (temp->next == NULL)
				break;
		}
	}
	listRoot = temp;
}

struct node* PlusList(struct node* listPlusRoot, struct node* generalListRoot)
{
	struct node* listPlus = listPlusRoot, * generalList = generalListRoot;
	while (listPlus != NULL)
	{
		if (generalListRoot == NULL)
		{
			generalListRoot = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(generalListRoot);
			generalListRoot->element = listPlus->element;
			generalListRoot->next = generalList;
		}
		else
			generalList = AddEl(generalListRoot, listPlus->element);
		listPlus = listPlus->next;
	}
	return generalListRoot;
}
void Show(struct node* listRoot)
{
	struct node* current;
	current = listRoot;
	while (current != NULL)
	{
		printf(" %d ", current->element);
		if (current->next != NULL)
		{
			current = current->next;
		}
		else
			break;
	}
}

void MemoryCheck(struct node* pointer)
{
	if (pointer == NULL)
	{
		printf("\nError!");
		exit(1);
	}
}