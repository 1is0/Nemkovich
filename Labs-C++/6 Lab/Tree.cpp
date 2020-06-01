//---------------------------------------------------------------------------
#pragma hdrstop
#include "Tree.h"

Tree :: Tree()
{
	pHead = nullptr;
	NumList = 0;
}

void Tree :: AddList(AnsiString str, int num)
{
	if(!pHead)
	{
		pHead = new List;
		pHead->surname = str;
		pHead->number = num;
		pHead->pLeft = pHead->pRight = nullptr;
	}
	else
	{
		List *node = SearchFree(pHead, num);
		node->surname = str;
		node->number = num;
		node->pLeft = node->pRight = nullptr;
	}
	NumList++;
}

List* Tree :: SearchFree(List *temp, int num)
{
	if(num < temp->number)
	{
		if(!temp->pLeft)
		{
			temp->pLeft = new List;
			return temp->pLeft;
		}
		else return SearchFree(temp->pLeft, num);
	}
	else
	{
		if(!temp->pRight)
		{
			temp->pRight = new List;
			return temp->pRight;
		}
		else return SearchFree(temp->pRight, num);
	}
}

void Tree :: PrintTree(List* temp, TTreeView *TreeView, int &index)
{
	int i = index;
	if(temp->pLeft)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[i], temp->pLeft->surname);
		PrintTree(temp->pLeft, TreeView, ++index);
	}
	if(temp->pRight)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[i], temp->pRight->surname);
		PrintTree(temp->pRight, TreeView, ++index);
    }
}

void Tree :: ShowTree(TTreeView *TreeView)
{
	int index = 0;
	TreeView->Items->Clear();
	if(pHead)
	{
		TreeView->Items->Add(NULL, pHead->surname);
		PrintTree(pHead, TreeView, index);
    }
}

AnsiString Tree :: GetKey(int num)
{
	List *temp = pHead;
	while(temp->number != num)
	{
		if(num < temp->number) temp = temp->pLeft;
		else temp = temp->pRight;
	}
	if(temp)return temp->surname;
	else return "";
}

void Tree :: DeleteList(int num)
{
	List *del, *prevdel, *node, *prevnode;
	del = pHead;
	prevdel = nullptr;
	while(del->number != num)
	{
		prevdel = del;
		if(num < del->number) del = del->pLeft;
		else del = del->pRight;
	}
	if(!del)return;
	if(!del->pRight) node = del->pLeft;
	else if(!del->pLeft) node = del->pRight;
	else
	{
		prevnode = del;
		node = del->pLeft;
		while(node->pRight)
		{
			prevnode = node;
			node = node->pRight;
		}
		if(prevnode == del) node->pRight = del->pRight;
		else
		{
			node->pRight = del->pRight;
			prevnode->pRight = node->pLeft;
			node->pLeft = prevnode;
        }
	}
	if(!prevdel) pHead = prevdel = node;
	else if(del->number < prevdel->number) prevdel->pLeft = node;
	else prevdel->pRight = node;
	delete del;
	NumList--;
}

void Tree :: Delete(List *p)
{
	if(p)
	{
		NumList--;
		Delete(p->pLeft);
		Delete(p->pRight);
        delete p;
    }
}

void Tree :: Balance()
{
	int* arr = new int[NumList];
	AnsiString* str = new AnsiString[NumList];
	int size = 0;
	ToArray(pHead, arr, str, size);
	Delete(pHead);
	pHead = MakeTree(arr, str, 0, size);
}

void Tree :: ToArray(List *p, int* arr, AnsiString* str, int &index)
{
	if(p->pLeft) ToArray(p->pLeft, arr, str, index);
	str[index] = p->surname;
	arr[index] = p->number;
	index++;
	if(p->pRight) ToArray(p->pRight, arr, str, index);
}

List* Tree :: MakeTree(int *arr, AnsiString *str, int first, int last)
{
	if(!last) return nullptr;
	List *node = new List;
	node->surname = str[first + last / 2];
	node->number = arr[first + last / 2];
	NumList++;
	int lastl = last / 2;
	int lastr = last - lastl - 1;
	node->pLeft = MakeTree(arr, str, first, lastl);
	node->pRight = MakeTree(arr, str, first + lastl + 1, lastr);
	return node;
}

void Tree :: Right(TMemo *Memo)
{
	NLR(Memo, pHead);
}

void Tree :: NLR(TMemo *Memo, List *p)
{
	if(p)
	{
		Memo->Lines->Add(p->surname);
		NLR(Memo, p->pLeft);
		NLR(Memo, p->pRight);
    }
}

void Tree :: Back(TMemo *Memo)
{
	LRN(Memo, pHead);
}

void Tree :: LRN(TMemo *Memo, List *p)
{
	if(p)
	{
		LRN(Memo, p->pLeft);
		LRN(Memo, p->pRight);
		Memo->Lines->Add(p->surname);
    }
}

void Tree :: Growth(TMemo *Memo)
{
	LNR(Memo, pHead);
}

void Tree :: LNR(TMemo *Memo, List *p)
{
	if(p)
	{
		LNR(Memo, p->pLeft);
		Memo->Lines->Add(p->surname);
		LNR(Memo, p->pRight);
    }
}

void Tree :: Count(List *p, int &amount)
{
	if(p && p->pLeft && p->pRight)
	{
		Count(p->pLeft, amount);
		amount++;
		Count(p->pRight, amount);
    }
}
//--------------------------------------------------------------------------
#pragma package(smart_init)
