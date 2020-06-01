// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Program.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
IndTree tree;

bool IsRepeat(int num) {
	for (int i = 1; i < Form1->StringGrid1->RowCount; i++) {
		if (num == Form1->StringGrid1->Cells[1][i].ToInt())
			return false;
	}
	return true;
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	Form1->Close();
	system("exit");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender) {
	if (StringGrid1->RowCount >= 2) {
		tree.Balance();
		tree.ShowTree(Form1->TreeView1);
	}
	else
		ShowMessage("Error! Input keys.");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	Memo1->Clear();
	Memo1->Lines->Add("===============");
	Memo1->Lines->Add("Direct bypass:");
	Memo1->Lines->Add("");
	tree.Right(Memo1);
	Memo1->Lines->Add("");
	Memo1->Lines->Add("===============");
	Memo1->Lines->Add("Reverse bypass:");
	Memo1->Lines->Add("");
	tree.Back(Memo1);
	Memo1->Lines->Add("");
	Memo1->Lines->Add("===============");
	Memo1->Lines->Add("Ascending bypass:");
	Memo1->Lines->Add("");
	tree.Growth(Memo1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	try {
		AnsiString str = Edit1->Text;
		int key = StrToInt(Edit2->Text);
		if (IsRepeat(key) && Edit1->Text != "") {
			if (key <= 0) {
				Edit2->Text = "";
				ShowMessage("Error input!");
			}
			else {
				if (StringGrid1->Cells[0][0] == "") {
					StringGrid1->Cells[0][0] = "Full name";
					StringGrid1->Cells[1][0] = "Key";
				}
				StringGrid1->RowCount++;
				StringGrid1->Cells[0][StringGrid1->RowCount - 1] = str;
				StringGrid1->Cells[1][StringGrid1->RowCount - 1] = key;
				tree.AddList(str, key);
				Memo1->Lines->Add("*New member added*");
				Memo1->Lines->Add("Full name: " + str);
				Memo1->Lines->Add("Key: " + IntToStr(key));
				Memo1->Lines->Add("");
				tree.ShowTree(Form1->TreeView1);
				Edit1->Text = "";
				Edit2->Text = "";
			}
		}
		else {
			Edit2->Text = "";
			ShowMessage("Key number error!");
		}
	}
	catch (...) {
		Form1->Edit2->Text = "";
		ShowMessage("Incorrect key!");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	if (StringGrid1->RowCount >= 2) {
		tree.SearchMinMax();
		tree.ShowTree(Form1->TreeView1);
	}
	else
		ShowMessage("Error! Input keys.");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender) {
	try {
		int key = StrToInt(Edit5->Text);
		if (key > 0) {
			AnsiString str = tree.GetKey(key);
			if (str != "") {
				Memo1->Lines->Add("Succes!");
				Memo1->Lines->Add("Full name: " + str);
				Memo1->Lines->Add("Key: " + IntToStr(key));
				Memo1->Lines->Add("");
			}
			else {
				Memo1->Lines->Add("Error! =(");
				Memo1->Lines->Add("");
			}
		}
		else {
			Edit5->Text = "";
			ShowMessage("Incorrect key! =C");
		}
	}
	catch (...) {
		Edit5->Text = "";
		ShowMessage("Incorrect key!");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	try {
		int key = StrToInt(Edit4->Text);
		if (!IsRepeat(key)) {
			AnsiString str = tree.GetKey(key);
			tree.DeleteList(key);
			tree.ShowTree(TreeView1);
			Memo1->Lines->Add("Key deleted");
			Memo1->Lines->Add("Full name: " + str);
			Memo1->Lines->Add("Key: " + IntToStr(key));
			Memo1->Lines->Add("");
			for (int i = 1, j = 1; i < StringGrid1->RowCount; i++) {
				if (StringGrid1->Cells[1][i] != key) {
					StringGrid1->Cells[0][j] = StringGrid1->Cells[0][i];
					StringGrid1->Cells[1][j] = StringGrid1->Cells[1][i];
					j++;
				}
			}
			StringGrid1->RowCount--;
			Edit4->Text = "";
		}
		else {
			Edit4->Text = "";
			ShowMessage("Error input key!");
		}
	}
	catch (...) {
		Edit4->Text = "";
		ShowMessage("Incorrect key!");
	}
}
// ---------------------------------------------------------------------------
