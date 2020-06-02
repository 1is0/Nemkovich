// ---------------------------------------------------------------------------

#pragma hdrstop

#include "IndTask.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void IndTask::InputIndTabFirst() {
	for (int i = 0; i < count; i++) {
		if (key[i] >= 0)
			stacks[this->Oper(key[i], hashTabSize)]->Add(key[i]);
	}
}

void IndTask::InputIndTabSecond() {
	for (int i = 0; i < count; i++) {
		if (key[i] < 0)
			stacks[this->Oper(key[i], hashTabSize)]->Add(key[i]);
	}
}
