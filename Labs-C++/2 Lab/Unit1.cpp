// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Firma.h"
#include "Kurers.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFirm *Firm;
int amountclass = 0, amountclasskurer = 0;
Firma* firm;
Kurers* kurer;

// ---------------------------------------------------------------------------
__fastcall TFirm::TFirm(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button9Click(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button3Click(TObject *Sender) {
	Form2->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button6Click(TObject *Sender) {
	Form3->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender) {
	UnicodeString adres = (Edit2->Text);
	AnsiString temp = adres;
	string adr = temp.c_str();
	int time = StrToInt(Edit3->Text);
	int weight = StrToInt(Edit4->Text);
	amountclass++;
	firm = firm->addElement(firm, amountclass);
	firm->setdata(firm, amountclass, time, weight, adr);
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender) {
	UnicodeString fios = (Edit1->Text);
	AnsiString temp = fios;
	string fio = temp.c_str();
	int gruzweight = StrToInt(Edit2->Text);
	int time1 = StrToInt(Edit3->Text);
	int time2 = StrToInt(Edit4->Text);
	amountclasskurer++;
	kurer = kurer->addElement(kurer, amountclasskurer);
	kurer->setdata(kurer, amountclasskurer, time1, time2, gruzweight, fio);
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button10Click(TObject *Sender) {
	ComboBox1->Items->Clear();
	for (int i = 0; i < amountclass; i++) {
		AnsiString str = IntToStr(firm[i].number1);
		ComboBox1->Items->Add(str);
		firm[i].got = false;
	}
	ComboBox2->Items->Clear();
	for (int i = 0; i < amountclasskurer; i++) {
		AnsiString str = IntToStr(kurer[i].number2);
		ComboBox2->Items->Add(str);
	}
	Memo1->Lines->Clear();
	Memo2->Lines->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::ComboBox1Change(TObject *Sender) {
	for (int i = 0; i < amountclass; i++) {
		if (ComboBox1->ItemIndex == i) {
			char *cstr = &firm[i].street[0];
			Edit2->Text = cstr;
			Edit3->Text = firm[i].time;
			Edit4->Text = firm[i].weight;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::ComboBox2Change(TObject *Sender) {
	for (int i = 0; i < amountclasskurer; i++) {
		if (ComboBox2->ItemIndex == i) {
			char *cstr = &kurer[i].fio[0];
			Edit6->Text = cstr;
			Edit7->Text = kurer[i].time1;
			Edit1->Text = kurer[i].time2;
			Edit8->Text = kurer[i].gruzweight;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button2Click(TObject *Sender) {
	Memo2->Lines->Clear();
	Memo2->Lines->Add("Некорректный ввод заказов:");
	for (int i = 0; i < amountclass; i++) {
		if (firm[i].proverkavvoda == false) {
			Memo2->SelText = ("Заказ № ");
			Memo2->SelText = (i + 1);
			Memo2->Lines->Add("");
		}
	}
	Memo2->Lines->Add("Невыполнимые в срок заказы:");
	for (int i = 0; i < amountclass; i++) {
		if (firm[i].got == false && firm[i].proverkavvoda == true) {
			Memo2->SelText = ("Заказ № ");
			Memo2->SelText = (i + 1);
			Memo2->Lines->Add("");
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button1Click(TObject *Sender) {
	Memo1->Clear();
	Memo1->Lines->Add("Список распределенных заказов:");
	for (int i = 0; i < amountclasskurer; i++) {
		if (kurer[i].proverkavvoda == true) {
			for (int j = 0; j < amountclass; j++) {
				if (firm[j].proverkavvoda == true) {
					if (firm[j].got == false && firm[j].time >=
						kurer[i].time1 && firm[j].time <= kurer[i].time2) {
						if (firm[j].weight <= kurer[i].gruzweight) {
							firm[j].got = true;
							Memo1->SelText = ("Заказ № ");
							Memo1->SelText = (firm[j].number1);
							Memo1->SelText = (" взят курьером № ");
							Memo1->SelText = (kurer[i].number2);
							Memo1->Lines->Add("");
						}
					}
				}
			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFirm::Button8Click(TObject *Sender) {
	int n = StrToInt(Edit10->Text);
	if (n <= 0 || n > amountclass) {

	}
	else {
		amountclass--;
		firm = firm->deleteElement(firm, amountclass, n);
		Edit2->Clear();
		Edit3->Clear();
		Edit4->Clear();
		ComboBox1->Items->Clear();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button5Click(TObject *Sender) {
	Memo3->Clear();
	for (int i = 0; i < amountclass; i++) {
		Memo3->SelText = firm[i].number1;
		Memo3->SelText = '\n';
		Memo3->SelText = firm[i].time;
		Memo3->SelText = '\n';
		Memo3->SelText = firm[i].weight;
		Memo3->SelText = '\n';
		char* cstr = &firm[i].street[0];
		Memo3->SelText = cstr;
		Memo3->SelText = '\n';
		Memo3->SelText = firm[i].proverkavvoda;
		Memo3->SelText = '\n';
	}
	if (SaveDialog1->Execute()) {
		ofstream fout(SaveDialog1->FileName.c_str(), ofstream::trunc);
		for (int i = 0; i < amountclass; i++) {
			fout << firm[i].number1 << "\n" << firm[i].time << "\n" << firm[i]
				.weight << firm[i].street << ".\n" << firm[i]
				.proverkavvoda << "\n";
		}
		fout.close();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFirm::Button7Click(TObject *Sender) {
	int n = StrToInt(Edit9->Text);
	if (n <= 0 || n > amountclasskurer) {

	}
	else {
		amountclasskurer--;
		kurer = kurer->deleteElement(kurer, amountclasskurer, n);
		Edit6->Clear();
		Edit7->Clear();
		Edit1->Clear();
		Edit8->Clear();
		ComboBox2->Items->Clear();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFirm::Button4Click(TObject *Sender) {
	if (OpenDialog1->Execute()) {
		ComboBox1->Clear();
		Memo3->Lines->LoadFromFile(Firm->OpenDialog1->FileName);
		amountclass = (Memo3->Lines->Count) / 5;
		firm = new Firma[amountclass];
		if (Firma::input(firm, amountclass) == true) {
			for (int i = 0; i < amountclass; i++) {
				ComboBox1->Items->Add(firm[i].number1);
			}

		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFirm::Button11Click(TObject *Sender) {
	Memo4->Clear();
	for (int i = 0; i < amountclasskurer; i++) {
		Memo4->SelText = kurer[i].number2;
		Memo4->SelText = '\n';
		Memo4->SelText = kurer[i].gruzweight;
		Memo4->SelText = '\n';
		Memo4->SelText = kurer[i].time1;
		Memo4->SelText = '\n';
		Memo4->SelText = kurer[i].time2;
		Memo4->SelText = '\n';
		char* cstr = &kurer[i].fio[0];
		Memo4->SelText = cstr;
		Memo4->SelText = ".";
		Memo4->SelText = '\n';
		Memo4->SelText = kurer[i].proverkavvoda;
		Memo4->SelText = '\n';
	}
	if (SaveDialog1->Execute()) {
		ofstream fout(SaveDialog1->FileName.c_str(), ofstream::trunc);
		for (int i = 0; i < amountclasskurer; i++) {
			fout << kurer[i].number2 << "\n" << kurer[i]
				.gruzweight << "\n" << kurer[i].time1 << "\n" << kurer[i]
				.time2 << "\n" << kurer[i].fio << ".\n" << kurer[i]
				.proverkavvoda << "\n";
		}
		fout.close();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFirm::Button12Click(TObject *Sender) {
	if (OpenDialog1->Execute()) {
		ComboBox2->Clear();
		Memo4->Lines->LoadFromFile(Firm->OpenDialog1->FileName);
		amountclasskurer = (Memo4->Lines->Count) / 6;
		kurer = new Kurers[amountclasskurer];
		if (Kurers::input(kurer, amountclasskurer) == true) {
			for (int i = 0; i < amountclasskurer; i++) {
				ComboBox2->Items->Add(kurer[i].number2);
			}

		}
	}
}
// ---------------------------------------------------------------------------
