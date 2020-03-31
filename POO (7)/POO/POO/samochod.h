
#ifndef auta_H
#define auta_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int maks = 10;

namespace auta {
	class Samochody
	{
	private:
		string marka;
		string model;
		int rocznik;
		int pojemnosc;
		int przebieg;
		bool skrz_bieg;
	public:
		Samochody(const std::string & mar = "Brak", const std::string & mod = "Brak", const int & r = 0, const int & m = 0, const int& p = 0, const bool& s = 1);
		string _marka(void)const { return (marka); };
		string _model(void)const { return (model); };
		int _rocznik(void)const { return (rocznik); };
		int _pojemnosc(void)const { return (pojemnosc); };
		int _przebieg(void)const { return (przebieg); };
		bool _skrz_bieg(void)const { return (skrz_bieg); };
	};
	ostream & operator << (std::ostream& o, Samochody& c);
	istream & operator >> (std::istream& i, Samochody& c);
}
	int wczytaj(fstream &plik, int& n, auta::Samochody tab[]);                     // wczytywanie z pliku
	void zapis(auta::Samochody tab[], int& n);                   // zapisywanie do pliku
	void wprowadzanie(auta::Samochody tab[], int& nr_samochodu); // pozwala wprowadzic nowy samochod do katalogu
	void wyswietlenie(auta::Samochody tab[], int& nr_samochodu, int& n); /* wyswietla liste samochodow */
	void menu();	                 //menu
	void wyjscie();                  //wychodzi z programu
	void usun(auta::Samochody tab[], int& nr_samochodu, int& n);
	void sortowanie_rosnaco(auta::Samochody tab[], int& nr_samochodu, int& n);
	void sortowanie_malejaco(auta::Samochody tab[], int& nr_samochodu, int& n);
	void sortowanie_menu();
	void progi(auta::Samochody tab[], int& nr_samochodu, int& choice, int& level, string& lit);
#endif 