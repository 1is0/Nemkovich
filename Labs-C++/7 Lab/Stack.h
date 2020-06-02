//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
#include "Node.h"

class Stack {
	Node* Head;

public:
	Stack() {
		Head = 0;
	}

	int GetInfo() {
		return this->Head->info;
	}

	Node* GetNode() {
		return Head;
	}

	void Add(int info);
	void Print(TMemo *Memo);
	void DelHeadEl(Node* temp);
	void DelHead();
	void DelStack();
};

//---------------------------------------------------------------------------
#endif
