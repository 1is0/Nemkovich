#include "Tree.h"

void CheckInput(int* a);
void MemCheck(Node* pointer);
void Dispose(Node* node);

int main()
{
m1:
	system("cls");
	printf("Click \"Enter\" to start or \"ESC\" to exit.\n");
	char start = _getch();
	if (start == 13) {
		while (start != 27)
		{
			Node* root = NULL;

			printf("Enter elements of a tree:\n");
			int x = 0;
			do
			{
				CheckInput(&x);

				if (x != 0)
					AddNode(&root, x);

			} while (x != 0);

			if (root != NULL)
				printf("\nAll nodes of the tree: ");
			Print(root);

			if (root != NULL)
			{
				int sum = 0;
				int length = GetBrAndSum(root, 1, &sum);

				printf("\nThe length of the longest branch: %d\nThe sum of the longest branch: %d\n", length, sum);

				Dispose(root);
			}
			else
				printf("\nThe tree is empty!\n");

			printf("\nClick any keys to continue or \"ESC\" to exit ...");
			start = _getch();
			if (start == 27)
				return 0;
			else
				system("cls");
		}
	}
	else
	{
		printf("Please, click only 2 keys.");
		_getch();
		goto m1;
	}
}

void Dispose(Node* node)
{
	if (node->left != NULL)
		Dispose(node->left);

	if (node->right != NULL)
		Dispose(node->right);

	free(node);
}

void CheckInput(int* a)
{
	while (!scanf("%d", &(*a)))
	{
		printf("Error! Try again:\n");
		while (getchar() != '\n');
	}
}

void MemCheck(Node* pointer)
{
	if (pointer == NULL) 
	{
		printf("\nError!");
		exit(1);
	}
}