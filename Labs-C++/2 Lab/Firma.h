// ---------------------------------------------------------------------------

#ifndef FirmaH
#define FirmaH
#include <string>

class Firma {
public:
	bool proverkavvoda = true;
	bool got = false;
	int numKur = -1; // � �������

	int number1, weight, time; // � ������, ���, �����

	std::string street; // ������

	Firma* addElement(Firma* obj, const int amount);
	void setdata(Firma *obj, int at, int te, int wt, std::string st);
	Firma * deleteElement(Firma * obj, int amount, int n);
	static bool input(Firma *arr, int n);
};

// ---------------------------------------------------------------------------
#endif
