// ---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
// ---------------------------------------------------------------------------

struct List {
	int val;
	List* next;
	List* prev;
};

class Queue {
protected:
	List *head, *tail;

public:

	Queue() : head(NULL), tail(NULL) {
	}

	void AddEl(int el);
	bool IsEmpty();
	bool DeleteQueue();
	bool DeleteHead();
	bool DeleteTail();
    void Print(TListBox* ListBox);

};

// ---------------------------------------------------------------------------
#endif
