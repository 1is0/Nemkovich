// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Program.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
IndQueue VQueue;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
    ShowMessage("Have a nice day! =)");
	Form1->Close();
	system("exit");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	Form1->ListBox1->Clear();
	int a = StrToInt(Edit1->Text);
	VQueue.AddEl(a);
	VQueue.Print(Form1->ListBox1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender) {
	if (VQueue.DeleteHead() == true)
		ShowMessage("Succses!");
	else
		ShowMessage("Error! Check empty queue.");
	Form1->ListBox1->Clear();
	VQueue.Print(Form1->ListBox1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender) {
	if (VQueue.DeleteTail() == true)
		ShowMessage("Succes!");
	else
		ShowMessage("Error! Check empty queue.");
	Form1->ListBox1->Clear();
	VQueue.Print(Form1->ListBox1);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	Form1->ListBox1->Clear();
	if (VQueue.DeleteQueue() == true)
		ShowMessage("Succes!");
	else
		ShowMessage("Error! Check empty queue.");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender) {
	if (VQueue.IsEmpty() == true)
		ShowMessage("Queue with elements.");
	else
		ShowMessage("No elements in queue.");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	Form1->ListBox1->Clear();
	VQueue.AddRandEls();
	VQueue.Print(Form1->ListBox1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) {
	if (VQueue.SearchMin() == true) {
		Form1->ListBox1->Clear();
		VQueue.Print(Form1->ListBox1);
	}
	else
        ShowMessage("Error! Check empty queue.");
}
// ---------------------------------------------------------------------------
