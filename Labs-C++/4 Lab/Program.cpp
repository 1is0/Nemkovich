// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Program.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

bool IsOperation(const char &a) {
	if (a == '(' || a == ')' || a == '+' || a == '-' || a == '*' || a == '/' ||
		a == '^')
		return true;
	return false;
}

double Operation(double a, double b, const char &operation) {
	switch (operation) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '^':
		return pow(a, b);
	default:
		return -1;
	}
}

int Priority(const char &op) {
	switch (op) {
	case '(':
	case ')':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '^':
		return 4;
	default:
		return -1;
	}
}

void Calcul(char* polska, float a, float b, float c, float d, float e) {
	Stack<double> *numStack = new Stack<double>();
	for (int i = 0; i < strlen(polska); i++) {
		if (IsOperation(polska[i])) {
			double a, b;
			b = numStack->Pop();
			a = numStack->Pop();
			numStack->Push(Operation(a, b, polska[i]));
		}
		else {
			switch (polska[i]) {
			case 'a':
				numStack->Push(a);
				break;
			case 'b':
				numStack->Push(b);
				break;
			case 'c':
				numStack->Push(c);
				break;
			case 'd':
				numStack->Push(d);
				break;
			default:
				numStack->Push(e);
				break;
			}
		}
	}
	Form1->Edit3->Text = FloatToStr(numStack->Pop());
	if (Form1->Edit3->Text == "-1") {
		ShowMessage("Error input the formula!");
		Form1->Edit3->Text = "Result";
        Form1->Edit2->Text = "Polish entry";
	}
	delete numStack;
}

void ToPolska(const AnsiString &calcFormula, char* zapis) {

	Stack<char> *operationsStack = new Stack<char>();
	int len = 0;
	for (int i = 1; i <= calcFormula.Length(); i++) {
		if (IsOperation(calcFormula[i])) {
			if (operationsStack->IsEmpty()) {
				operationsStack->Push(calcFormula[i]);
				continue;
			}

			if (calcFormula[i] == '(') {
				operationsStack->Push('(');
				continue;
			}

			if (calcFormula[i] == ')') {
				while (operationsStack->Top() != '(')
					zapis[len++] = operationsStack->Pop();
				operationsStack->Pop();
				continue;
			}

			if (Priority(calcFormula[i]) > Priority(operationsStack->Top()))
				operationsStack->Push(calcFormula[i]);
			else if (Priority(calcFormula[i]) <=
				Priority(operationsStack->Top())) {
				while (operationsStack->Top() != '(')
					zapis[len++] = operationsStack->Pop();
				operationsStack->Push(calcFormula[i]);
			}
		}
		else if (calcFormula[i] == '$')
			while (!operationsStack->IsEmpty())
				zapis[len++] = operationsStack->Pop();
		else
			zapis[len++] = calcFormula[i];
	}
	Form1->Edit2->Text = zapis;
	delete operationsStack;
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	AnsiString calcFormula;
	Stack<char> *Checker;

	float a, b, c, d, e;

	try {
		calcFormula = "(" + Edit1->Text.Trim() + ")" + "$";

		for (int i = 1; i < calcFormula.Length(); i++) {
			if (calcFormula[i] != 'a' && calcFormula[i] != 'b' && calcFormula[i]
				!= 'c' && calcFormula[i] != 'd' && calcFormula[i]
				!= 'e' && calcFormula[i] != '+' && calcFormula[i]
				!= '-' && calcFormula[i] != '*' && calcFormula[i]
				!= '/' && calcFormula[i] != '(' && calcFormula[i]
				!= ')' && calcFormula[i] != '^')
				throw -1;
		}
		Checker = new Stack<char>();
		for (int i = 1; i < calcFormula.Length(); i++) {
			if (calcFormula[i] == '(')
				Checker->Push('(');
			if (calcFormula[i] == ')')
				Checker->Pop();
		}
		if (!Checker->IsEmpty())
			throw -1;

		a = StrToFloat(Edit4->Text);
		b = StrToFloat(Edit5->Text);
		c = StrToFloat(Edit6->Text);
		d = StrToFloat(Edit7->Text);
		e = StrToFloat(Edit8->Text);

		char polska[256] = {'\0'};
		ToPolska(calcFormula, polska);
		Calcul(polska, a, b, c, d, e);
	}
	catch (...) {
		ShowMessage(
			"Incorrect formula or incorrect input of parameter values. (Fractional numbers enter with a comma!)");
		delete Checker;
		return;
	}
}
// ---------------------------------------------------------------------------
