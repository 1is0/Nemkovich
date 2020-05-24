// ---------------------------------------------------------------------------

#ifndef StackH
#define StackH
#include "Program.h"

// ---------------------------------------------------------------------------
template<typename T>
class Stack {
public:
	Stack() : tail(0), head(0) {
	}

	~Stack() {
		while (head) {
			tail = head->next;
			delete head;
			head = tail;
		}
	}

	bool IsEmpty() {
		if (tail == 0) {
			return true;

		}
		else
			return false;
	}

	void Push(T val) {
		Node* Temp;
		Temp = new Node;
		Temp->elem = val;
		if (tail == 0) {
			tail = Temp;
		}
		else {
			Temp->next = tail;
			tail = Temp;
		}
	}

	T Top() {
		if (tail == 0) {
			return -1;
		}
		return tail->elem;
	}

	T Pop() {
		if (tail == 0) {
			return -1;
		}
		Node* delptr = tail;
		T value = delptr->elem;
		tail = tail->next;
		delete delptr;
		return value;
	}

private:
	struct Node {
		Node() : elem(0), next(0) {
		}

		Node* next;
		T elem;
	};

private:
	Node* head;
	Node* tail;
};
// ---------------------------------------------------------------------------
#endif
