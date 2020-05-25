// ---------------------------------------------------------------------------

#pragma hdrstop

#include "IndQueue.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void IndQueue::AddRandEls() {
	for (int i = 0; i < 10; i++) {
		int num = -9 + rand() % 100;
		List* temp = new List;
		temp->val = num;
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
}

bool IndQueue::SearchMin() {
	if (head == NULL) {
		return false;
	}
	else {
		List* temp = new List;
		List* temp2 = new List;
		temp = head;
		int num;
		int i = 0;
		while (temp != NULL) {
			if (i == 0) {
				num = temp->val;
				temp2 = temp;
			}
			else if (num > temp->val) {
				num = temp->val;
				temp2 = temp;
			}
			temp = temp->next;
			i++;
		}
		temp2->val = head->val;
		head->val = num;
		temp = head;
        return true;
	}
}

void IndQueue::Print(TListBox* ListBox) {
	List* temp = new List;
	temp = head;
	while (temp != NULL) {
		ListBox->Items->Add(temp->val);
		temp = temp->next;
	}
}
