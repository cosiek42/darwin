/** @file */
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include "funkcje.h"
using namespace std;

double fDopasuj(const vector <unsigned>& osobnik) {
	unsigned suma = 0;
	for (auto liczba : osobnik) suma += liczba;
	unsigned srednia = suma/osobnik.size();
	return abs(sin(srednia));
}

vector <unsigned> uSplit(const string& tekst, const char& znak) {
	stringstream ss;
	string liczba;
	vector <unsigned> tab;
	ss<<tekst;
	while (ss>>liczba) {
		try {tab.push_back(stoul(liczba));}
		catch (invalid_argument) {}
	}
	return tab;
}

void krzyzowka(vector <unsigned>& osobnik1, vector <unsigned>& osobnik2) {
	unsigned pekniecie1, pekniecie2;
	if (osobnik1.size() == 1) pekniecie1 = 0;
	else if (osobnik1.size() == 2) pekniecie1 = 1;
	else pekniecie1 = rand() % (osobnik1.size()-1) + 1;
	if (osobnik2.size() == 1 || osobnik2.size() == 2) pekniecie2 = 0;
	else pekniecie2 = rand() % (osobnik2.size()-1);
	vector <unsigned> new_osobnik1;
	vector <unsigned> new_osobnik2;
	for (unsigned i=(osobnik2.size()-1-pekniecie2); i<osobnik2.size(); ++i) new_osobnik1.push_back(osobnik2[i]);
	for (unsigned i=pekniecie1; i<osobnik1.size(); ++i) new_osobnik1.push_back(osobnik1[i]);
	for (unsigned i=0; i<(osobnik2.size()-1-pekniecie2); ++i) new_osobnik2.push_back(osobnik2[i]);
	for (unsigned i=0; i<pekniecie1; ++i) new_osobnik2.push_back(osobnik1[i]);
	osobnik1 = new_osobnik1;
	if (new_osobnik2.size() == 0) osobnik2 = new_osobnik1;
	else osobnik2 = new_osobnik2;
}

vector <vector <unsigned>> warunki(const vector <vector <unsigned>>& osobniki, const vector<double>& dopasowania, const double& w, const double& r) {
	vector <vector <unsigned>> new_osobniki;
	for (unsigned i=0; i<osobniki.size(); ++i) {
		if (dopasowania[i] > r) {
			vector <unsigned> osobnik = osobniki[i];
			new_osobniki.push_back(osobnik);
			new_osobniki.push_back(osobnik);
		}
		if (w <= dopasowania[i] && dopasowania[i] <= r) {
			vector <unsigned> osobnik = osobniki[i];
			new_osobniki.push_back(osobnik);
		}
	}
	return new_osobniki;
}

void viewHelp(const string name) {
	cerr<<"Sposob uzycia: "<<name<<" -i plikwejsciowy -o plikwyjsciowy -w wsp -r wsp -p pokolenia -k pary"<<endl<<endl;
	cerr<<"Bez argumentow   Wyswietla pomoc."<<endl;
	cerr<<"-i plikwejsciowy Ustawia plik wejsciowy z populacja."<<endl;
	cerr<<"-o plikwyjsciowy Ustawia plik wyjsciowy z populacja."<<endl;
	cerr<<"-w wsp           Okresla wspolczynnik wymierania. Wsp powinien byc liczba z przedzialu [0,1]."<<endl;
	cerr<<"-r wsp           Okresla wspolczynnik rozmnazania. Wsp powinien byc liczba z przedzialu [0,1]."<<endl;
	cerr<<"-p pokolenia     Ustawia liczbe pokolen w symulacji. Pokolenia powinny byc liczba dodatnia naturalna."<<endl;
	cerr<<"-k pary          Ustawia liczbe par osobnikow losowanych do krzyzowania. Pary powinny byc liczba dodatnia naturalna."<<endl;
}

void readFile(fstream& plik, vector <vector <unsigned>>& osobniki) {
	while (!plik.eof()) {
		string linia;
		getline (plik, linia);
		vector <unsigned> osobnik = uSplit(linia, ' ');
		if (osobnik.size() != 0) osobniki.push_back(osobnik);
	}
}

void losujPary(unsigned tab[][2], const unsigned& size, const unsigned& size_osobniki) {
	for (unsigned j=0; j<size; ++j) {
		tab[j][0] = rand() % size_osobniki;
		do tab[j][1] = rand() % size_osobniki; 
		while (tab[j][0] == tab[j][1]);
	}
}

void saveFile(fstream& wplik, const vector <vector <unsigned>>& osobniki) {
	for (unsigned i=0; i<osobniki.size(); ++i) {
		for (unsigned j=0; j<osobniki[i].size(); ++j) wplik<<osobniki[i][j]<<" ";
		wplik<<endl;	
	}
}
