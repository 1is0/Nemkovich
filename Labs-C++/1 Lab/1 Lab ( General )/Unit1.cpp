// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit1.h"

void MRectangle::Draw() { // Telega
	Form1->Canvas->Pen->Color = clBlack;
	Form1->Canvas->Brush->Color = clGreen;
	Form1->Canvas->Rectangle(XCoord, YCoord, XCoord + XSize, YCoord + YSize);
	// Wheels
	Form1->Canvas->Brush->Color = clBlack;
	Form1->Canvas->Ellipse(XCoord + 15, YCoord + YSize + 10, XCoord + 35,
		YCoord + YSize - 10);
	Form1->Canvas->Ellipse(XCoord + 85, YCoord + YSize + 10, XCoord + 65,
		YCoord + YSize - 10);
	// Bort
	Form1->Canvas->Pen->Color = clMaroon;
	Form1->Canvas->Rectangle(XCoord + 3, YCoord, XCoord + 8, YCoord - 25);
	Form1->Canvas->Rectangle(XCoord + 92, YCoord, XCoord + 97, YCoord - 25);
	Form1->Canvas->Rectangle(XCoord + 3, YCoord - 25, XCoord + 97, YCoord - 20);
	Form1->Canvas->Rectangle(XCoord + 3, YCoord - 12, XCoord + 97, YCoord - 7);
	Form1->Canvas->Brush->Color = clBlack;
	Form1->Canvas->Rectangle(XCoord + XSize, YCoord + YSize - 2,
		XCoord + XSize + 3, YCoord + YSize - 10);
	// Tractor
	Form1->Canvas->Brush->Color = clRed;
	Form1->Canvas->Rectangle(XCoord + XSize + 3, YCoord + YSize,
		XCoord + XSize + 113, YCoord - 10);
	Form1->Canvas->Rectangle(XCoord + XSize + 3, YCoord + YSize,
		XCoord + XSize + 50, YCoord - 40);
	Form1->Canvas->Brush->Color = clWhite;
	Form1->Canvas->Rectangle(XCoord + XSize + 7, YCoord + YSize - 36,
		XCoord + XSize + 46, YCoord - 36);
	// Far
	Form1->Canvas->Brush->Color = clYellow;
	Form1->Canvas->Rectangle(XCoord + XSize + 103, YCoord + YSize - 15,
		XCoord + XSize + 113, YCoord + YSize - 30);
	// Wheels ( Tractor )
	Form1->Canvas->Brush->Color = clBlack;
	Form1->Canvas->Ellipse(XCoord + XSize + 8, YCoord + YSize + 10,
		XCoord + XSize + 46, YCoord + YSize - 28);
	Form1->Canvas->Ellipse(XCoord + XSize + 68, YCoord + YSize + 10,
		XCoord + XSize + 98, YCoord + YSize - 20);
}
// ---------------------------------------------------------------------------
#pragma package(smart_init)
