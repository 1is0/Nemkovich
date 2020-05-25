// ---------------------------------------------------------------------------

#ifndef IndQueueH
#define IndQueueH
#include "Queue.h"
// ---------------------------------------------------------------------------

class IndQueue : public Queue {
public:
	IndQueue() : Queue() {
	}

	void AddRandEls();
	bool SearchMin();
	void Print(TListBox* ListBox);

};

// ---------------------------------------------------------------------------
#endif
