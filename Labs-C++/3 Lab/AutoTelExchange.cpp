// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormForOutput.h"
#include "List.h"
#include "AutoTelStruct.h"
#include "AutoTelExchange.h"
#include <string>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

ATE *Buff = new ATE();
List<ATE>lst;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) {
	Form1->Close();
	system("exit");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	Buff->date = Edit1->Text;
	Buff->cityName = Edit3->Text;
	Buff->time = Edit4->Text;
	Buff->phoneNumber = Edit6->Text;
	Buff->subNumber = Edit7->Text;
	int sCode = 0;
	int r = 0;
	bool atrue = true;
	try {
		do {
			sCode = StrToInt(Edit2->Text);
			r = StrToInt(Edit5->Text);
			if (sCode <= 0) {
				atrue = false;
			}
			if (r <= 0) {
				atrue = false;
			}
			if (atrue == false) {
				throw -1;
			}
		}
		while (atrue == false);

		Buff->cityCode = sCode;
		Buff->rate = r;
		lst.push_back(*Buff);
		ShowMessage("Success!");
		Edit1->Text = "";
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
		Edit5->Text = "";
		Edit6->Text = "";
		Edit7->Text = "";
	}
	catch (...) {
		ShowMessage("Bad input! Try again.");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	Form2->Memo1->Clear();
	if (lst.GetSize() == 0) {
		ShowMessage("Error! Try again.");
	}
	else {
		for (int i = 0; i < lst.GetSize(); i++) {
			lst[i].Print(Form2->Memo1);
		}
		Form2->ShowModal();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	Buff->date = "---";
	Buff->time = "---";
	Buff->rate = 0;
	Buff->cityName = Edit9->Text;
	Buff->phoneNumber = Edit10->Text;
	Buff->subNumber = Edit11->Text;
	int sCode = 0;
	bool atrue = true;
	try {
		do {
			sCode = StrToInt(Edit8->Text);
			if (sCode <= 0) {
				atrue = false;
			}
			if (atrue == false) {
				throw -1;
			}
		}
		while (atrue == false);

		Buff->cityCode = sCode;
		lst.push_back(*Buff);
		ShowMessage("Success!");
		Edit8->Text = "";
		Edit9->Text = "";
		Edit10->Text = "";
		Edit11->Text = "";
	}
	catch (...) {
		ShowMessage("Error! Try again.");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	bool search = false;
	Form2->Memo1->Clear();
	for (int i = 0; i < lst.GetSize(); i++) {
		if (Edit13->Text == lst[i].subNumber) {
			search = true;
			lst[i].Print(Form2->Memo1);
		}
	}
	if (search == true) {
		Form2->ShowModal();
	}
	else
		ShowMessage("Not found.");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	bool search = false;
	Form2->Memo1->Clear();
	if (lst.GetSize == 0) {
		ShowMessage("Error!");
	}
	else {
		for (int i = 0; i < lst.GetSize(); i++) {
			if (Edit14->Text == lst[i].cityName) {
				search = true;
				lst[i].Print(Form2->Memo1);
			}
		}
		if (search == true) {
			Form2->ShowModal();
		}
		else
			ShowMessage("Not found.");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	bool del = false;
	if (lst.GetSize() == 0) {
		ShowMessage("Error!");
	}
	else {
		for (int i = 0; i < lst.GetSize(); i++) {
			if (Edit12->Text == lst[i].subNumber) {
				lst.deleteindex(i);
				del = true;
				i--;
			}
		}
	}
	if (del == true)
		ShowMessage("Succes!");
	else
		ShowMessage("Not found numbers for delete information! =C");
}
// ---------------------------------------------------------------------------
