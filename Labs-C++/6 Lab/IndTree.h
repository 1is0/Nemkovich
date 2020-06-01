// ---------------------------------------------------------------------------

#ifndef IndTreeH
#define IndTreeH
#include "Tree.h"

class IndTree : public Tree {
public:
	IndTree() : Tree() {
	}
	void SearchMinMax();
	void SearchMin(List* root, int &min, List* &TmpMin);
	void SearchMax(List* root, int &max, List* &TmpMax);
};
// ---------------------------------------------------------------------------
#endif
