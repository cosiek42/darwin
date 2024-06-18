/** @file */
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/**
Funkcja wyznacza warto�� przystosowania osobnik�w do warunk�w �rodowiska.
@param osobnik wektor zawieraj�cy chromosomy osobnika
@return warto�� przystosowania osobnika
@warning Funkcja zwraca liczbe rzeczywist� z zakresu [0,1].
*/
double fDopasuj(const vector <unsigned>& osobnik);
/**
Funkcja dzieli napis na wektor podci�g�w typu liczbowego.
@param tekst ci�g znak�w do podzielenia
@param znak znak, kt�ry b�dzie dzieli� napis
@return wektor zawieraj�cy podzielony ci�g znak�w
@warning Funkcja ignoruje bia�e znaki i litery.
*/
vector <unsigned> uSplit(const string& tekst, const char& znak);
/**
Funkcja dokonuje krzy�owania podanych osobnik�w przez referencje.
@param osobnik1 wektor zawieraj�cy chromosomy pierwszego osobnika
@param osobnik2 wektor zawieraj�cy chromosomy drugiego osobnika
*/
void krzyzowka(vector <unsigned>& osobnik1, vector <unsigned>& osobnik2);
/**
Funkcja koryguj�ca populacj�, poprzez sprawdzenie warto�ci przystosowania dla ka�dego osobnika.
@param osobniki wektor zawieraj�cy populacje
@param dopasowania wektor zawieraj�cy warto�ci funkcji przystosowania dla ka�dego osobnika
@param w warto�� wsp�czynnika wymierania
@param r warto�� wsp�czynnika rozmna�ania
@return wektor zawieraj�cy now� populacj�
@remark Je�li f - warto�� funkcji przystosowania, w - wsp�czynnik wymierania i r - wsp�czynnik rozmna�ania, to je�li f<w, osobnik jest usuwany z populacji, je�li f>r, to osobnik jest klonowany, a je�li w<=f<=r, to osobnik pozostaje w populacji, lecz si� nie rozmna�a.
*/
vector <vector <unsigned>> warunki(const vector <vector <unsigned>>& osobniki, const vector<double>& dopasowania, const double& w, const double& r);
/**
Funkcja wy�wietlaj�ca pomoc, czyli kr�tk� informacj� o tym, jak u�y� programu.
@param name nazwa programu
*/
void viewHelp(const string name);
/**
Funkcja, kt�ra przetwarza ka�d� linijk� pliku wej�ciowego.
@param plik referencja na zmienn� pliku wej�ciowego
@param osobniki wektor, do kt�rego b�d� dodawane nowe osobniki
@remark Funkcja korzysta z funkcji uSplit, dzi�ki czemu wektor osobniki b�dzie zawiera� tylko wektory chromosom�w osobnik�w.
*/
void readFile(fstream& plik, vector <vector <unsigned>>& osobniki);
/**
Funkcja losuj�ca pary osobnik�w do krzy�owania.
@param tab tablica zawieraj�ca indeksy osobnik�w z wektora osobniki wytypowanych do krzy�owania
@param size rozmiar tablicy tab
@param size_osobniki rozmiar wektora osobniki
@remark tab jest tablic� dwuwymiarow�, gdzie w pierwszym wymiarze s� wytypowane pary, a w drugim indeksy osobnik�w z wektora osobniki.
*/
void losujPary(unsigned tab[][2], const unsigned& size, const unsigned& size_osobniki);
/**
Funkcja zapisuj�ca wynik programu do pliku wyj�ciowego.
@param wplik referencja na zmienn� pliku wyj�ciowego
@param osobniki wektor zawieraj�cy populacje
*/
void saveFile(fstream& wplik, const vector <vector <unsigned>>& osobniki);
