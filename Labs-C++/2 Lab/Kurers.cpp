// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Kurers.h"
#include "Unit1.h"

Kurers* Kurers::addElement(Kurers* obj, const int amount) {
	if (amount == 1) {
		obj = new Kurers[amount];
		return obj;
	}
	else {
		Kurers* tempobj = new Kurers[amount];
		for (int i = 0; i < amount - 1; i++) {
			tempobj[i] = obj[i];
		}
		delete[]obj;
		return tempobj;
	}
}

void Kurers::setdata(Kurers *obj, int at, int te1, int te2, int wt, string fo) {
	if (te1 < 0 || te2 > 23 || te1 > te2 || wt <= 0) {
		obj[at - 1].proverkavvoda = false;
	}
	obj[at - 1].number2 = at;
	obj[at - 1].time1 = te1;
	obj[at - 1].time2 = te2;
	obj[at - 1].gruzweight = wt;
	obj[at - 1].fio = fo;
}

Kurers* Kurers::deleteElement(Kurers* obj, int amount, int n) {
	if (amount == 0) {
		delete[]obj;
		return obj;
	}
	else {
		Kurers* tempobj = new Kurers[amount];
		for (int i = 0, j = 0; i < amount; i++, j++) {
			if (j == n - 1) {
				j++;
				for (int q = j; q <= amount; q++) {
					obj[q].number2 = q;
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

bool Kurers::input(Kurers *arr, int n) {
	ifstream fin(Firm->OpenDialog1->FileName.c_str());
	if (fin.is_open()) {
		string tmp = "";
		bool first = true;
		fin.clear();
		for (int i = 0; i < n; i++) {
			if (first == false)
				fin.ignore();
			getline(fin, tmp);
			arr[i].number2 = stoi(tmp);
			fin >> tmp;
			arr[i].gruzweight = stoi(tmp);
			fin >> tmp;
			arr[i].time1 = stoi(tmp);
			fin >> tmp;
			arr[i].time2 = stoi(tmp);
			getline(fin, tmp, '.');
			arr[i].fio = tmp;
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
