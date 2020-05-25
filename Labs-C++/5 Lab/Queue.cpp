// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void Queue::AddEl(int el) {
	List *temp = new List;
	temp->val = el;
	temp->next = NULL;
	if (head == NULL) {
		temp->prev = NULL;
		head = tail = temp;
	}
	else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

bool Queue::IsEmpty() {
	if (head == NULL) {
		return false;
	}
	else
		return true;
}

bool Queue::DeleteQueue() {
	if (head == NULL) {
        return false;
	}
	else {
		while (head != NULL) {
			List *temp = new List;
			temp = head->next;
			delete head;
			head = temp;
			delete temp;
		}
		if (head == NULL)
			return true;
		else
			return false;
	}
}

bool Queue::DeleteHead() {
	if (head != NULL) {
		List *temp = new List;
		temp = head->next;
		delete head;
		head = temp;
		return true;
	}
	else
		return false;
}

bool Queue::DeleteTail() {
	if (head != NULL && tail != head) {
		List *temp = new List;
		temp = tail->prev;
		delete tail;
		tail = temp;
		tail->next = NULL;
		return true;
	}
	else
		return false;
}

void Queue::Print(TListBox *ListBox) {
	List* temp = new List;
	temp = head;
	while (temp != NULL) {
		ListBox->Items->Add(temp->val);
		temp = temp->next;
	}
}
