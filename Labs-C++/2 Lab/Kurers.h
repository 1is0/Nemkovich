// ---------------------------------------------------------------------------

#ifndef KurersH
#define KurersH
#include <string>

class Kurers {
public:
	bool proverkavvoda = true;
	int numZak = -1;

	int number2, gruzweight, time1, time2; // № курьера, груз-сть, время с - до

	std::string fio; // ФИО

	Kurers* addElement(Kurers* obj, const int amount);
	void setdata(Kurers *obj, int at, int te1, int te2, int wt, std::string fo);
	Kurers* deleteElement(Kurers* obj, int amount, int n);
	static bool input(Kurers *arr, int n);
};
// ---------------------------------------------------------------------------
#endif
