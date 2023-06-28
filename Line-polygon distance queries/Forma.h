//---------------------------------------------------------------------------

#ifndef FormaH
#define FormaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
#include <list>
#include "pomocna.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Slika;
	TButton *GrahamScanDugme;
	TRadioButton *dodavanjeTacakaRadio;
	TRadioButton *dodavanjePraveRadio;
	TButton *NajbliziVrhDugme;
	void __fastcall GrahamScanDugmeClick(TObject *Sender);
	void __fastcall SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall NajbliziVrhDugmeClick(TObject *Sender);
private:	// User declarations
	vector<Tacka> tacke;
	vector<Tacka> konveksni_omotac;
	vector<Tacka> prava;
	vector<Tacka> projekcije;
    int indeks = -1;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
