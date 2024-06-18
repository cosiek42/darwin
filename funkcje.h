/** @file */
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/**
Funkcja wyznacza wartoœæ przystosowania osobników do warunków œrodowiska.
@param osobnik wektor zawieraj¹cy chromosomy osobnika
@return wartoœæ przystosowania osobnika
@warning Funkcja zwraca liczbe rzeczywist¹ z zakresu [0,1].
*/
double fDopasuj(const vector <unsigned>& osobnik);
/**
Funkcja dzieli napis na wektor podci¹gów typu liczbowego.
@param tekst ci¹g znaków do podzielenia
@param znak znak, który bêdzie dzieli³ napis
@return wektor zawieraj¹cy podzielony ci¹g znaków
@warning Funkcja ignoruje bia³e znaki i litery.
*/
vector <unsigned> uSplit(const string& tekst, const char& znak);
/**
Funkcja dokonuje krzy¿owania podanych osobników przez referencje.
@param osobnik1 wektor zawieraj¹cy chromosomy pierwszego osobnika
@param osobnik2 wektor zawieraj¹cy chromosomy drugiego osobnika
*/
void krzyzowka(vector <unsigned>& osobnik1, vector <unsigned>& osobnik2);
/**
Funkcja koryguj¹ca populacjê, poprzez sprawdzenie wartoœci przystosowania dla ka¿dego osobnika.
@param osobniki wektor zawieraj¹cy populacje
@param dopasowania wektor zawieraj¹cy wartoœci funkcji przystosowania dla ka¿dego osobnika
@param w wartoœæ wspó³czynnika wymierania
@param r wartoœæ wspó³czynnika rozmna¿ania
@return wektor zawieraj¹cy now¹ populacjê
@remark Jeœli f - wartoœæ funkcji przystosowania, w - wspó³czynnik wymierania i r - wspó³czynnik rozmna¿ania, to jeœli f<w, osobnik jest usuwany z populacji, jeœli f>r, to osobnik jest klonowany, a jeœli w<=f<=r, to osobnik pozostaje w populacji, lecz siê nie rozmna¿a.
*/
vector <vector <unsigned>> warunki(const vector <vector <unsigned>>& osobniki, const vector<double>& dopasowania, const double& w, const double& r);
/**
Funkcja wyœwietlaj¹ca pomoc, czyli krótk¹ informacjê o tym, jak u¿yæ programu.
@param name nazwa programu
*/
void viewHelp(const string name);
/**
Funkcja, która przetwarza ka¿d¹ linijkê pliku wejœciowego.
@param plik referencja na zmienn¹ pliku wejœciowego
@param osobniki wektor, do którego bêd¹ dodawane nowe osobniki
@remark Funkcja korzysta z funkcji uSplit, dziêki czemu wektor osobniki bêdzie zawiera³ tylko wektory chromosomów osobników.
*/
void readFile(fstream& plik, vector <vector <unsigned>>& osobniki);
/**
Funkcja losuj¹ca pary osobników do krzy¿owania.
@param tab tablica zawieraj¹ca indeksy osobników z wektora osobniki wytypowanych do krzy¿owania
@param size rozmiar tablicy tab
@param size_osobniki rozmiar wektora osobniki
@remark tab jest tablic¹ dwuwymiarow¹, gdzie w pierwszym wymiarze s¹ wytypowane pary, a w drugim indeksy osobników z wektora osobniki.
*/
void losujPary(unsigned tab[][2], const unsigned& size, const unsigned& size_osobniki);
/**
Funkcja zapisuj¹ca wynik programu do pliku wyjœciowego.
@param wplik referencja na zmienn¹ pliku wyjœciowego
@param osobniki wektor zawieraj¹cy populacje
*/
void saveFile(fstream& wplik, const vector <vector <unsigned>>& osobniki);
