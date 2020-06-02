// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Program.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

HashTabStack* hashtable;
IndTask* input1, *input2;
int hashTabSize, count, i;
int* key;

void beEnabled(){
	Form1->Button2->Enabled = true;
	Form1->Button3->Enabled = true;
	Form1->Button4->Enabled = true;
	Form1->Button5->Enabled = true;
	Form1->Button6->Enabled = true;
	Form1->Edit3->Enabled = true;
	Form1->Edit4->Enabled = true;
	Form1->Edit5->Enabled = true;
	Form1->Edit6->Enabled = true;
}

void beDisabled(){
	Form1->Button2->Enabled = false;
	Form1->Button3->Enabled = false;
	Form1->Button4->Enabled = false;
	Form1->Button5->Enabled = false;
	Form1->Button6->Enabled = false;
	Form1->Edit3->Enabled = false;
	Form1->Edit4->Enabled = false;
	Form1->Edit5->Enabled = false;
	Form1->Edit6->Enabled = false;
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender) {
	Form1->Close();
	system("exit");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	Memo1->Clear();
	hashTabSize = StrToInt(Edit1->Text);
	count = StrToInt(Edit2->Text);
	key = new int[count];
	for (i = 0; i < count; i++) {
		key[i] = rand() % 100 - 50;
		Memo1->Lines->Add(key[i]);
	}
	hashtable = new HashTabStack(hashTabSize, count, key);
	input1 = new IndTask(hashTabSize, count, key);
	input2 = new IndTask(hashTabSize, count, key);
	hashtable->InputTab();
	input1->InputIndTabFirst();
	input2->InputIndTabSecond();
	beEnabled();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	Memo2->Clear();
	Memo3->Clear();
	Memo4->Clear();
	hashtable->Print(Memo2);
	input1->Print(Memo3);
	input2->Print(Memo4);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	int position = hashtable->FindElement(StrToInt(Edit5->Text));
	if (position > 0) {
		Memo1->Text = Edit5->Text + " in " +
			IntToStr(position) + " stack.";
	}
	else {
		Memo1->Text = "Not found.";
	}
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    hashtable->FreeStack(StrToInt(Edit3->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
    hashtable->FreeHeadStack(StrToInt(Edit6->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	hashtable->AddKey(StrToInt(Edit4->Text));
	ShowMessage("Succes!");
    Edit4->Clear();
}
//---------------------------------------------------------------------------

