// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0, X3 = 0, Y3 = 0, counter = 0;
Triangle *A = new Triangle(0, 0, 0, 0, 0, 0);
Rectan *B = new Rectan(0, 0, 0, 0);
Ellips *C = new Ellips(0, 0, 0, 0);

bool Enter = false;
bool draw = true;
bool inc = true;
bool prTrian = false;
bool prEllip = false;
bool prRect = false;
int color;
float gravCenterX, gravCenterY;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->Rectangle(0, 0, Image1->Width, Image1->Height);
}
// ---------------------------------------------------------------------------

void setColor(int color, TImage * Image1) {
	switch (color) {
	case 0:
		Image1->Canvas->Brush->Color = clBlue;
		Image1->Canvas->Pen->Color = clBlue;
		break;
	case 1:
		Image1->Canvas->Brush->Color = clYellow;
		Image1->Canvas->Pen->Color = clYellow;
		break;
	case 2:
		Image1->Canvas->Brush->Color = clGreen;
		Image1->Canvas->Pen->Color = clGreen;
		break;
	case 3:
		Image1->Canvas->Brush->Color = clPurple;
		Image1->Canvas->Pen->Color = clPurple;
		break;
	case 4:
		Image1->Canvas->Brush->Color = clRed;
		Image1->Canvas->Pen->Color = clRed;
		break;
	}
}

void inc_max(float &a, float &b, float &c) {
	if (a > c && a > b) {
		a += 10;
	}
	else if (b > c && b > a) {
		b += 10;
	}
	else if (c > b && c > a) {
		c += 10;
	}

}

void dec_max(float &a, float &b, float &c) {
	if (a > c && a > b) {
		a -= 10;
	}
	else if (b > c && b > a) {
		b -= 10;
	}
	else if (c > b && c > a) {
		c -= 10;
	}

}

void dec_min(float &a, float &b, float &c) {
	if (a < c && a < b) {
		a -= 10;
	}
	else if (b < c && b < a) {
		b -= 10;
	}
	else if (c < b && c < a) {
		c -= 10;
	}

}

void inc_min(float &a, float &b, float &c) {
	if (a < c && a < b) {
		a += 10;
	}
	else if (b < c && b < a) {
		b += 10;
	}
	else if (c < b && c < a) {
		c += 10;
	}

}

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	if (RadioGroup1->ItemIndex == 0 && RadioGroup2->ItemIndex == 0 &&
		Image1->Canvas->Pen->Color != clBlack) {
		X1 = X;
		Y1 = Y;
	}

	if (RadioGroup1->ItemIndex == 2 && RadioGroup2->ItemIndex == 0 &&
		Image1->Canvas->Pen->Color != clBlack) {

		if (counter == 0) {
			X1 = X;
			Y1 = Y;
			counter++;
		}
		else if (counter == 1) {
			X2 = X;
			Y2 = Y;
			counter++;
		}
		else if (counter == 2) {
			X3 = X;
			Y3 = Y;
			A = new Triangle(X1, Y1, X2, Y2, X3, Y3);
			A->Draw(Image1);
			A->Perimeter(Edit1);
			A->Area(Edit2);
			A->GravCenter(Edit3);
			counter = 0;
			prEllip = false;
			prRect = false;
			prTrian = true;
		}

	}

	if (RadioGroup1->ItemIndex == 1 && RadioGroup2->ItemIndex == 0 &&
		Image1->Canvas->Pen->Color != clBlack) {
		X1 = X;
		Y1 = Y;
	}

	if (RadioGroup1->ItemIndex == 0 && RadioGroup2->ItemIndex == 4 &&
		prRect == true) {
		B->Rotate(Image1, X, Y);
		B->GravCenter(Edit3);
	}
	else {
		if (RadioGroup1->ItemIndex == 1 && RadioGroup2->ItemIndex == 4 &&
			prEllip == true) {
			C->Rotate(Image1, X, Y);
			C->GravCenter(Edit3);
		}
		else {
			if (RadioGroup1->ItemIndex == 2 && RadioGroup2->ItemIndex == 4 &&
				prTrian == true) {
				A->Rotate(Image1, X, Y);
				A->GravCenter(Edit3);
			}
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (Edit4->Text != NULL && Edit5->Text != NULL && RadioGroup1->ItemIndex ==
		2 && prTrian == true) {
		A->GravCenterOffset(Edit4, Edit5, Image1, Edit3);
	}
	else {
		if (Edit4->Text != NULL && Edit5->Text != NULL &&
			RadioGroup1->ItemIndex == 1 && prEllip == true) {
			C->GravCenterOffset(Edit4, Edit5, Image1, Edit3);
		}
		else if (Edit4->Text != NULL && Edit5->Text != NULL &&
			RadioGroup1->ItemIndex == 0 && prRect == true) {
			B->GravCenterOffset(Edit4, Edit5, Image1, Edit3);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
	int X, int Y) {
	color = ComboBox1->ItemIndex;
	setColor(color, Image1);

	if (Shift.Contains(ssLeft) && RadioGroup1->ItemIndex == 2 &&
		RadioGroup2->ItemIndex == 1 && Image1->Canvas->Pixels[X][Y]
		!= clWhite && prTrian == true) {
		gravCenterX = (X1 + X2 + X3) / 3;
		gravCenterY = (Y1 + Y2 + Y3) / 3;
		float dx = X - gravCenterX;
		float dy = Y - gravCenterY;
		X1 += dx;
		X2 += dx;
		X3 += dx;
		Y1 += dy;
		Y2 += dy;
		Y3 += dy;
		gravCenterX = (X1 + X2 + X3) / 3;
		gravCenterY = (Y1 + Y2 + Y3) / 3;
		A->Move(Image1, X, Y);
		A->Perimeter(Edit1);
		A->Area(Edit2);
		A->GravCenter(Edit3);

	}
	else if (Shift.Contains(ssLeft)
		&& RadioGroup1->ItemIndex == 0 && RadioGroup2->ItemIndex == 1 &&
		Image1->Canvas->Pixels[X][Y] != clWhite && prRect == true) {
		gravCenterX = (X1 + X2) / 2;
		gravCenterY = (Y1 + Y2) / 2;
		float dx = X - gravCenterX;
		float dy = Y - gravCenterY;
		X1 += dx;
		X2 += dx;
		Y1 += dy;
		Y2 += dy;
		gravCenterX = (X1 + X2) / 2;
		gravCenterY = (Y1 + Y2) / 2;
		B->Move(Image1, X, Y);
		B->Perimeter(Edit1);
		B->Area(Edit2);
		B->GravCenter(Edit3);
	}
	else if (Shift.Contains(ssLeft)
		&& RadioGroup1->ItemIndex == 1 && RadioGroup2->ItemIndex == 1 &&
		Image1->Canvas->Pixels[X][Y] != clWhite && prEllip == true) {
		gravCenterX = (X1 + X2) / 2;
		gravCenterY = (Y1 + Y2) / 2;
		float dx = X - gravCenterX;
		float dy = Y - gravCenterY;
		X1 += dx;
		X2 += dx;
		Y1 += dy;
		Y2 += dy;
		gravCenterX = (X1 + X2) / 2;
		gravCenterY = (Y1 + Y2) / 2;
		C->Move(Image1, X, Y);
		C->Perimeter(Edit1);
		C->Area(Edit2);
		C->GravCenter(Edit3);
	}

	if (Shift.Contains(ssLeft) && RadioGroup1->ItemIndex == 0 &&
		RadioGroup2->ItemIndex == 0 && Image1->Canvas->Pen->Color != clBlack) {
		X2 = X;
		Y2 = Y;
		B = new Rectan(X1, Y1, X2, Y2);
		B->Draw(Image1);
		prEllip = false;
		prTrian = false;
		prRect = true;
	}
	if (Shift.Contains(ssLeft) && RadioGroup1->ItemIndex == 1 &&
		RadioGroup2->ItemIndex == 0 && Image1->Canvas->Pen->Color != clBlack) {
		X2 = X;
		Y2 = Y;
		Ellips *C = new Ellips(X1, Y1, X2, Y2);
		C->Draw(Image1);
		prTrian = false;
		prRect = false;
		prEllip = true;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->Rectangle(0, 0, Image1->Width, Image1->Height);
	X1 = 0, Y1 = 0, X2 = 0, Y2 = 0, X3 = 0, Y3 = 0, counter = 0;
	delete(A);
	delete(B);
	delete(C);
	prTrian = false;
	prEllip = false;
	prRect = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	if (RadioGroup1->ItemIndex == 0 && RadioGroup2->ItemIndex == 0 && Button ==
		mbLeft && Image1->Canvas->Pen->Color != clBlack) {
		B = new Rectan(X1, Y1, X2, Y2);
		B->Draw(Image1);
		B->Perimeter(Edit1);
		B->Area(Edit2);
		B->GravCenter(Edit3);
	}
	else {
		if (RadioGroup1->ItemIndex == 1 && RadioGroup2->ItemIndex == 0 && X2 !=
			0 && Button == mbLeft && Image1->Canvas->Pen->Color != clBlack) {
			C = new Ellips(X1, Y1, X2, Y2);
			C->Draw(Image1);
			C->Area(Edit2);
			C->Perimeter(Edit1);
			C->GravCenter(Edit3);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	if (RadioGroup2->ItemIndex == 2 && RadioGroup1->ItemIndex == 0 &&
		prRect == true) {
		inc = true;
		B->dec_and_inc(Image1, inc);
		B->Area(Edit2);
		B->Perimeter(Edit1);
	}
	else if (RadioGroup2->ItemIndex == 2 && RadioGroup1->ItemIndex == 1 &&
		prEllip == true) {
		inc = true;
		C->dec_and_inc(Image1, inc);
		C->Area(Edit2);
		C->Perimeter(Edit1);
	}
	else if (RadioGroup2->ItemIndex == 2 && RadioGroup1->ItemIndex == 2 &&
		prTrian == true) {
		inc = true;
		A->dec_and_inc(Image1, inc);
		A->Area(Edit2);
		A->Perimeter(Edit1);
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) {
	if (RadioGroup2->ItemIndex == 2 && RadioGroup1->ItemIndex == 0 &&
		prRect == true) {
		inc = false;
		B->dec_and_inc(Image1, inc);
		B->Area(Edit2);
		B->Perimeter(Edit1);
	}
	else if (RadioGroup2->ItemIndex == 2 && RadioGroup1->ItemIndex == 1 &&
		prEllip == true) {
		inc = false;
		C->dec_and_inc(Image1, inc);
		C->Area(Edit2);
		C->Perimeter(Edit1);
	}
	else if (RadioGroup2->ItemIndex == 2 && RadioGroup1->ItemIndex == 2 &&
		prTrian == true) {
		inc = false;
		A->dec_and_inc(Image1, inc);
		A->Area(Edit2);
		A->Perimeter(Edit1);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	if (RadioGroup1->ItemIndex == 0 && RadioGroup2->ItemIndex == 3 &&
		prRect == true) {
		B->Rotation(Image1);
	}
}
// ---------------------------------------------------------------------------
