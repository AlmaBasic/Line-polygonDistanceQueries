//---------------------------------------------------------------------------

#ifndef pomocnaH
#define pomocnaH
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct Tacka {
	double x,y;
	Tacka(double X = 0, double Y = 0):x(X),y(Y) {}
	void Crtaj(TImage*);
};

bool operator<(Tacka,Tacka);
bool operator==(Tacka,Tacka);

struct Duz {
	Tacka A,B;
	Duz(Tacka C, Tacka D):A(C),B(D) {
		if(B < A) swap(A,B);
    }
};

int Orijentacija(Tacka A, Tacka B, Tacka C);
void IscrtajPoligon(vector<Tacka> &poligon, TImage* slika);
pair<double,double> JednacinaPrave(Tacka A, Tacka B);
void ProjekcijeVrhovaNaPravu(vector<Tacka> &poligon, vector<Tacka> &prava,vector<Tacka> &projekcije);
double Udaljenost(Tacka A, Tacka B);

void NajblizaTacka(vector<Tacka> &poligon, vector<Tacka> &projekcije,
	 int &indeks);
//---------------------------------------------------------------------------
#endif
