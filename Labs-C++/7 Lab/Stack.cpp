// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Stack.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void Stack::Add(int info) {
	Node* temp = new Node;
	temp->info = info;
	if (this->Head == 0) {
		temp->next = 0;
		this->Head = temp;
	}
	else {
		temp->next = this->Head;
		this->Head = temp;
	}
}

void Stack::Print(TMemo *Memo) {
	Node*temp = this->Head;
	for (; temp != 0;) {
		Memo->Lines->Add(temp->info);
		temp = temp->next;
	}
}

void Stack::DelHead() {
	if (Head != 0) {
		Node* temp = Head->next;
		Head = temp;
		delete(temp);
	}
}

void Stack::DelStack() {
	for (; Head != 0;) {
		DelHead();
	}
}

void Stack::DelHeadEl(Node* temp){
	Head = temp;
    delete(temp);
}
