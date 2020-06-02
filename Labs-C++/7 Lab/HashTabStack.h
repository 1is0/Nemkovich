//---------------------------------------------------------------------------

#ifndef HashTabStackH
#define HashTabStackH
#include "Stack.h"

class HashTabStack {
protected:
	int hashTabSize;
	int count;
	int* key;
	int* key1;
	Stack** stacks;

public:
	HashTabStack(int size1, int size2, int* keys) {
		hashTabSize = size1;
		count = size2;
		key = keys;
		stacks = new Stack*[hashTabSize];
		for (int i = 0; i < hashTabSize; i++) {
			stacks[i] = new Stack();
		}
	}

	Stack* GetStack(int i) {
		return stacks[i];
	}

	void AddKey(int info);
	int FindElement(int info);
	void InputTab();
	void Print(TMemo *Memo);
	void FreeHeadStack(int info);
	void FreeStack(int info);
	void Free();
	int Oper(int key, int size);
};

//---------------------------------------------------------------------------
#endif
