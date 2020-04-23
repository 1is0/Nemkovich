// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
#include "Lab1.h"

class MRectangle {
public:
	int XSize = 100;
	int YSize = 25;
	int XCoord = 100;
	int YCoord = 85;

	void TelMoove(int a, int b) {
		XCoord += a;
		YCoord += b;
	}

public:
	void Draw();

	void MCanvaClear() {
		Form1->Canvas->Pen->Color = clWhite;
		Form1->Canvas->Brush->Color = clWhite;
		Form1->Canvas->Rectangle(0, 0, 1920, 1080);
	}
};
// ---------------------------------------------------------------------------
#endif
