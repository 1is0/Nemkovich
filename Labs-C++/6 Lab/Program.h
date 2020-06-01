//---------------------------------------------------------------------------

#ifndef ProgramH
#define ProgramH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Tree.h"
#include "IndTree.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TTreeView *TreeView1;
	TMemo *Memo1;
	TStringGrid *StringGrid1;
	TButton *Button1;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button2;
	TButton *Button5;
	TButton *Button7;
	TEdit *Edit4;
	TButton *Button8;
	TButton *Button9;
	TEdit *Edit5;
	TButton *Button3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
