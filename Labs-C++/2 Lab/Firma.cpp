// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Firma.h"
#include <fstream>
#include <string>
#include "Unit1.h"

Firma* Firma::addElement(Firma* obj, const int amount) {
	if (amount == 1) {
		obj = new Firma[amount];
		return obj;
	}
	else {
		Firma* tempobj = new Firma[amount];
		for (int i = 0; i < amount - 1; i++) {
			tempobj[i] = obj[i];
		}
		delete[]obj;
		return tempobj;
	}
}

void Firma::setdata(Firma *obj, int at, int te, int wt, std::string st) {
	if (te < 0 || te > 23 || wt <= 0) {
		obj[at - 1].proverkavvoda = false;
	}
	obj[at - 1].number1 = at;
	obj[at - 1].time = te;
	obj[at - 1].weight = wt;
	obj[at - 1].street = st;
}

Firma* Firma::deleteElement(Firma* obj, int amount, int n) {
	if (amount == 0) {
		delete[]obj;
		return obj;
	}
	else {
		Firma* tempobj = new Firma[amount];
		for (int i = 0, j = 0; i < amount; i++, j++) {
			if (j == n - 1) {
				j++;
				for (int q = j; q <= amount; q++) {
					obj[q].number1 = q;
				}
				tempobj[i] = obj[j];
			}
			else
				tempobj[i] = obj[j];
		}
		delete[]obj;
		return tempobj;
	}
}

bool Firma::input(Firma *arr, int n) {
	ifstream fin(Firm->OpenDialog1->FileName.c_str());
	if (fin.is_open()) {
		string tmp = "";
		bool first = true;
		fin.clear();
		for (int i = 0; i < n; i++) {
			if (first == false)
				fin.ignore();
			getline(fin, tmp);
			arr[i].number1 = stoi(tmp);
			fin >> tmp;
			arr[i].time = stoi(tmp);
			fin >> tmp;
			arr[i].weight = stoi(tmp);
			getline(fin, tmp, '.');
			arr[i].street = tmp;
			fin >> tmp;
			arr[i].proverkavvoda = stoi(tmp);
			tmp = "";
			fin.clear();
			first = false;
		}
		fin.close();
		return true;
	}
	else {
		ShowMessage("Ошибка открытия файла!");
		return false;
	}

}
// ---------------------------------------------------------------------------
#pragma package(smart_init)
