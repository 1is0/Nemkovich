#include "Functions.h"

void CheckInput(int* a)
{
	while (!scanf("%d", &(*a)) || *a <= 0)
	{
		printf("Wrong input! Try again:\n");
		while (getchar() != '\n');
	}
}

int main(int argc, char* argv[])
{
	struct node* lst1Gen = NULL, * lst2Gen = NULL, * lst1 = NULL, * lst2 = NULL;
	int n1 = 0;
	printf("Size of first list = ");
	CheckInput(&n1);
	printf("Enter elements of first list:\n");
	for (int i = 0; i < n1; i++)
	{
		int x = 0;
		CheckInput(&x);
		if (lst1Gen == NULL)
		{
			lst1Gen = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(lst1Gen);
			lst1Gen->element = x;
			lst1Gen->next = lst1;
		}
		else
			lst1 = AddEl(lst1Gen, x);
	}
	while (getchar() != '\n');

	int n2 = 0;
	printf("\nSize of second list = "); 
	CheckInput(&n2); 
	printf("Enter elements of second list:\n");
	for (int i = 0; i < n2; i++)
	{
		int x = 0;
		CheckInput(&x);
		if (lst2Gen == NULL)
		{
			lst2Gen = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(lst2Gen);
			lst2Gen->element = x;
			lst2Gen->next = lst2;
		}
		else
			lst2 = AddEl(lst2Gen, x);
	}
	while (getchar() != '\n');

	system("cls");
	printf("First list after sort:\n");
	lst1Gen = Sort(lst1Gen);
	Show(lst1Gen);
	printf("\nSecond list after sort:\n");
	lst2Gen = Sort(lst2Gen);
	Show(lst2Gen);
	struct node* generalListRoot = NULL, * generalList = NULL;
	generalListRoot = PlusList(lst1Gen, generalListRoot);
	generalListRoot = PlusList(lst2Gen, generalListRoot);
	generalListRoot = Sort(generalListRoot);
	DeleteDuplElements(generalListRoot);
	printf("\nGeneral list:\n");
	Show(generalListRoot);
	printf("\n");

	free(lst1Gen);
	free(lst2Gen);
	return 0;
}
