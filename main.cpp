/** @file */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include "funkcje.h"
using namespace std;

/**
@param argc liczba parametrów wywo³ania funkcji main
@param argv tablica napisów reprezentuj¹cych parametry
@return 0 jeœli funkcja nie napotka³a b³êdów
@return 1 jeœli zosta³y Ÿle podane prze³¹czniki
@return 447 jeœli w pliku wejœciowym jest za ma³o osobników (linii)
@return 2137 jeœli wyst¹pi³ b³¹d z plikiem wejœciowym lub wyjœciowym
*/
int main(int argc, char* argv[]) {
	if (argc != 13) {viewHelp(argv[0]); return 1;}
	string in, out;
	double w, r;
	unsigned p, k;
	for (int i=1; i<13; ++i) {
		if (string(argv[i]) == "-i") {
			if (i+1<argc && string(argv[i+1])[0] != '-') in = argv[++i];
			else {viewHelp(argv[0]); return 1;}
		}
		else if (string(argv[i]) == "-o") {
			if (i+1<argc && string(argv[i+1])[0] != '-') out = argv[++i];
			else {viewHelp(argv[0]); return 1;}
		}
		else if (string(argv[i]) == "-w") {
			if (i+1<argc && string(argv[i+1])[0] != '-') {
				try {w = stod(string(argv[++i]));}
				catch (invalid_argument) {viewHelp(argv[0]); return 1;}
			}
			else {viewHelp(argv[0]); return 1;}
		}
		else if (string(argv[i]) == "-r") {
			if (i+1<argc && string(argv[i+1])[0] != '-') {
				try {r = stod(string(argv[++i]));}
				catch (invalid_argument) {viewHelp(argv[0]); return 1;}
			}
			else {viewHelp(argv[0]); return 1;}
		}
		else if (string(argv[i]) == "-p") {
			if (i+1<argc && string(argv[i+1])[0] != '-') {
				try {p = stoul(string(argv[++i]));}
				catch (invalid_argument) {viewHelp(argv[0]); return 1;}
			}
			else {viewHelp(argv[0]); return 1;}
		}
		else if (string(argv[i]) == "-k") {
			if (i+1<argc && string(argv[i+1])[0] != '-') {
				try {k = stoul(string(argv[++i]));}
				catch (invalid_argument) {viewHelp(argv[0]); return 1;}
			}
			else {viewHelp(argv[0]); return 1;}
		}
		else {viewHelp(argv[0]); return 1;}
	}
	fstream plik;
	vector <vector <unsigned>> osobniki;
	plik.open(in, ios::in);
	srand (time(NULL));
	if (plik.good()) {
		readFile(plik, osobniki);
		if (osobniki.size() < 2) {
			cerr<<"Plik wejsciowy z populacja zawiera za malo osobnikow. Minimalna ilosc wynosi 2"<<endl;
			plik.close();
			return 447;
		}
		for (unsigned i=0; i<p; ++i) {
			if (osobniki.size() < 2) {
				cout<<"Zabraklo osobnikow do kontynuacji symulacji po "<<i<<" pokoleniu"<<endl;
				break;
			}
			unsigned typy[k][2];	
			losujPary(typy, k, osobniki.size());
			for (unsigned j=0; j<k; ++j) krzyzowka(osobniki[typy[j][0]], osobniki[typy[j][1]]);
			vector <double> dopasowania;
			for (unsigned j=0; j<osobniki.size(); ++j) dopasowania.push_back(fDopasuj(osobniki[j]));
			osobniki = warunki(osobniki, dopasowania, w, r);
		}
		fstream wplik;
		wplik.open(out, ios::out | ios::trunc);
		if (wplik.good()) saveFile(wplik, osobniki);
		else {
			cerr<<"Blad odczytu pliku wyjsciowego"<<endl;
			wplik.close();
			return 2137;
		}
		wplik.close();
	}
	else {
		cerr<<"Blad odczytu pliku wejsciowego"<<endl;
		plik.close();
		return 2137;
	}
	plik.close();
	cout<<"OK";
	return 0;
}
