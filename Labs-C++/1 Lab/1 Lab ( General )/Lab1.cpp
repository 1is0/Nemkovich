//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Lab1.h"
#include <Windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tel tel;
int pr1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	tel.MCanvaClear();
	tel.Draw();
	pr1 = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (pr1 == false) {
	}
	else {
		for (int i = 0; i < 100; i++) {
			tel.TelMoove(-1,0);
			Sleep(20);
			tel.MCanvaClear();
			tel.Draw();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
     if (pr1 == false) {
	}
	else {
		for (int i = 0; i < 100; i++) {
			tel.TelMoove(1,0);
			Sleep(20);
			tel.MCanvaClear();
			tel.Draw();
		}
	}
}
//---------------------------------------------------------------------------
