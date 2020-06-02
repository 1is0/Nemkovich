// ---------------------------------------------------------------------------

#pragma hdrstop

#include "HashTabStack.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void HashTabStack::AddKey(int info) {
	count++;
	key1 = new int[count];
	for (int i = 0; i < count - 1; i++)
		key1[i] = key[i];
	delete[]key;
	key = key1;
	key[count - 1] = info;
	stacks[this->Oper(key[count - 1], hashTabSize)]->Add(key[count - 1]);
}

int HashTabStack::FindElement(int info) {
	Node* temp = stacks[this->Oper(info, hashTabSize)]->GetNode();
	for (; temp != 0;) {
		if (temp->info == info) {
			return Oper(info, hashTabSize) + 1;
		}
		temp = temp->next;
	}
	return -1;
}

void HashTabStack::InputTab() {
	for (int i = 0; i < count; i++) {
		stacks[this->Oper(key[i], hashTabSize)]->Add(key[i]);
	}
}

void HashTabStack::Print(TMemo *Memo) {
	UnicodeString str;
	Node* temp;
	int i;
	temp = stacks[0]->GetNode();
	for (int i = 0; i < hashTabSize; i++) {
		str += IntToStr(i + 1) + ":";
		temp = stacks[i]->GetNode();
		for (; temp != 0;) {
			str += IntToStr(temp->info) + "->";
			temp = temp->next;
		}
		Memo->Lines->Add(str);
		str = "";
	}
}

void HashTabStack::FreeHeadStack(int info) {
	Node* temp = stacks[this->Oper(info, hashTabSize)]->GetNode();
	if (info >= -50 && info <= 50) {
		for (; temp != 0;) {
			if (temp->info == info) {
				temp = nullptr;
                stacks[this->Oper(info, hashTabSize)]->DelHeadEl(temp);
			}
			else {
				temp = temp->next;
			}
		}
	}
}

void HashTabStack::FreeStack(int info) {
	if (info > 0 && info <= hashTabSize)
		stacks[info - 1]->DelStack();
}

void HashTabStack::Free() {
	for (int i = 0; i < hashTabSize; i++) {
		stacks[i]->DelStack();
	}
	delete(key);
}

int HashTabStack::Oper(int key, int size) {
	if (key < 0)
		key *= -1;
	return (key % size);
}
