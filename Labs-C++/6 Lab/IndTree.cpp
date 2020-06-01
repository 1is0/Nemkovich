// ---------------------------------------------------------------------------

#pragma hdrstop

#include "IndTree.h"
#include <string>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void IndTree::SearchMinMax() {
	int min = pHead->number, max = pHead->number;
	List* TmpMin = pHead;
	List* TmpMax = pHead;

	SearchMin(pHead, min, TmpMin);
	SearchMax(pHead, max, TmpMax);

	AnsiString temp = TmpMin->surname;
	TmpMin->surname = TmpMax->surname;
	TmpMax->surname = temp;
}

void IndTree::SearchMin(List* root, int &min, List* &TmpMin) {
	if (root == NULL) {
		return;
	}
	int _min = root->number;
	if (_min < min) {
		min = _min;
		TmpMin = root;
	}
	SearchMin(root->pRight, min, TmpMin);
    SearchMin(root->pLeft, min, TmpMin);
}

void IndTree::SearchMax(List* root, int &max, List* &TmpMax) {
	if (root == NULL) {
		return;
	}
	int _max = root->number;
	if (_max > max) {
		max = _max;
		TmpMax = root;
	}
	SearchMax(root->pRight, max, TmpMax);
    SearchMax(root->pLeft, max, TmpMax);
}
