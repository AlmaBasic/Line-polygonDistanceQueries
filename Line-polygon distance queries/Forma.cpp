//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Forma.h"
#include "pomocna.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Slika->Canvas->FillRect(Rect(0,0,Slika->Width, Slika->Height));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GrahamScanDugmeClick(TObject *Sender)
{
  int n = tacke.size();
  for(int i = 1; i < n; i++)
	if(tacke[i] < tacke[0]) swap(tacke[i],tacke[0]);

  Tacka lijeva = tacke[0];
  sort(tacke.begin()+1,tacke.end(),[lijeva](Tacka A, Tacka B)->bool {
										return Orijentacija(lijeva,A,B) < 0;
									});


  konveksni_omotac.push_back(tacke[0]);
  konveksni_omotac.push_back(tacke[1]);
  for(int i = 2; i < n; i++) {
	Tacka predzadnja = konveksni_omotac[konveksni_omotac.size()-2];
	Tacka zadnja = konveksni_omotac[konveksni_omotac.size()-1];
	Tacka nova = tacke[i];
	while(Orijentacija(predzadnja,zadnja,nova) > 0) {
	  konveksni_omotac.pop_back();
	  zadnja = predzadnja;
	  predzadnja = konveksni_omotac[konveksni_omotac.size()-2];
	}

	konveksni_omotac.push_back(nova);
  }
  IscrtajPoligon(konveksni_omotac,Slika);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    if(dodavanjeTacakaRadio->Checked) {
	  Tacka nova(X,Y);
	  tacke.push_back(nova);
	  nova.Crtaj(Slika);

	}
	else if(dodavanjePraveRadio->Checked){
		if(prava.empty()){
			Tacka nova(X,Y);
			prava.push_back(nova);
			nova.Crtaj(Slika);
			Slika->Canvas->MoveTo(X,Y);
		}
		 else{
             Tacka nova(X,Y);
			 prava.push_back(nova);
			 nova.Crtaj(Slika);
			 Slika->Canvas->LineTo(X,Y);
         }

	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::NajbliziVrhDugmeClick(TObject *Sender)
{
	//int indeks = -1;
    ProjekcijeVrhovaNaPravu(konveksni_omotac, prava, projekcije);
	NajblizaTacka(konveksni_omotac, projekcije, indeks);
	Slika->Canvas->MoveTo(konveksni_omotac[indeks].x, konveksni_omotac[indeks].y);
	Slika->Canvas->Brush->Color = clRed;
	ShowMessage(IntToStr(indeks));

}
//---------------------------------------------------------------------------
