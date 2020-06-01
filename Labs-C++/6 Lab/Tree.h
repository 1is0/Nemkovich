// ---------------------------------------------------------------------------
#include <vcl.h>
#ifndef TreeH
#define TreeH

class List {
public:
	AnsiString surname;
	int number;
	List* pLeft;
	List* pRight;
};

class Tree {
private:

	List* SearchFree(List*, int);
	void PrintTree(List*, TTreeView*, int&);
	void ToArray(List*, int*, AnsiString*, int&);
	List* MakeTree(int*, AnsiString*, int, int);
	void Delete(List*);
	void NLR(TMemo*, List*);
	void LRN(TMemo*, List*);
	void LNR(TMemo*, List*);
	void Count(List*, int&);

public:
	List *pHead;
	int NumList;

	Tree();
	void AddList(AnsiString, int);
	void ShowTree(TTreeView*);
	AnsiString GetKey(int);
	void DeleteList(int);
	void Balance();
	void Right(TMemo*);
	void Back(TMemo*);
	void Growth(TMemo*);
};
// ---------------------------------------------------------------------------
#endif
