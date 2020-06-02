//---------------------------------------------------------------------------

#ifndef IndTaskH
#define IndTaskH
#include "HashTabStack.h"

class IndTask : public HashTabStack {
public:
	IndTask(int size1, int size2, int* keys) : HashTabStack(size1, size2, keys) {
		hashTabSize = size1;
		count = size2;
		key = keys;
		stacks = new Stack*[hashTabSize];
		for (int i = 0; i < hashTabSize; i++) {
			stacks[i] = new Stack();
		}
	}

	void InputIndTabFirst();
	void InputIndTabSecond();
};

//---------------------------------------------------------------------------
#endif
