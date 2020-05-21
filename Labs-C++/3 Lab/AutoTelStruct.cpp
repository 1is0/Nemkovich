// ---------------------------------------------------------------------------

#pragma hdrstop

#include "AutoTelStruct.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ATE::ATE() {
	date = "";
	cityName = "";
	time = "";
	phoneNumber = "";
	subNumber = "";
	cityCode = 0;
	rate = 0;
}

void ATE::Print(TMemo *Memo1) {
	Memo1->Lines->Add("Date:  " + date);
	Memo1->Lines->Add("City Name:  " + cityName);
	Memo1->Lines->Add("Time:  " + time);
	Memo1->Lines->Add("Phone number:  " + phoneNumber);
	Memo1->Lines->Add("Subscribe phone number:  " + subNumber);
	Memo1->Lines->Add("City code:  " + IntToStr(cityCode));
	Memo1->Lines->Add("Rate:  " + IntToStr(rate));
	Memo1->Lines->Add
		("----------------------------------------------------------------");

};
