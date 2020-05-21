//---------------------------------------------------------------------------
#include "vcl.h"

#ifndef AutoTelStructH
#define AutoTelStructH
//---------------------------------------------------------------------------
struct ATE {
	AnsiString date;
	AnsiString cityName;
	AnsiString time;
	AnsiString phoneNumber;
    AnsiString subNumber;
	int cityCode;
	int rate;

	ATE();
	void Print(TMemo *Memo1);
};

#endif
