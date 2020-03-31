#include "samochod.h"


namespace auta 
{
	Samochody::Samochody(const std::string & mar, const std::string & mod, const int & r, const int & m, const int & p, const bool & s)
	{
		marka = mar;
		model = mod;
		rocznik = r;
		pojemnosc = m;
		przebieg = p;
		skrz_bieg = s;
	}

	ostream& operator << (ostream& o, Samochody& c)
	{
		using std::endl;
		o << "Marka: " << c._marka() << endl;
		o << "Model: " << c._model() << endl;
		o << "Rocznik: " << c._rocznik() << endl;
		o << "Moc: " << c._pojemnosc() << endl;
		o << "Przebieg: " << c._przebieg() << endl;
		o << "Skrzynia: ";
		if (c._skrz_bieg()) // rozroznienie skrzyni biegow(automatyczna konwersja innych wartosci na typ bool)
			o << "manualna";
		else
			o << "automatyczna";
		return(o);
	}

	istream& operator >> (istream& i, Samochody& c)
	{
		using std::cout;
		string marka, model;
		int przebieg, rocznik, moc;
		short skrzynia;
		i >> marka;
		i >> model;
		i >> rocznik;
		i >> moc;
		i >> przebieg;
		i >> skrzynia;
		c = Samochody(marka, model, rocznik, moc, przebieg, skrzynia); // stworzenie obiektu za pomoca konstruktora klasy
		return(i);
	}
}

void menu() {
	using std::cout;
	using std::endl;
	cout << "[1] - Wyjdz z programu" << endl;
	cout << "[2] - Pokaz menu programu" << endl;       /* otwarcie pliku w trybie do wpisywanie */
	cout << "[3] - Cala lista samochodow" << endl;
	cout << "[4] - Dodaj nowy samochod" << endl;
	cout << "[5] - Usun samochodod" << endl;
	cout << "[6] - Wyœwietlenie pojedynczej pozycji" << endl;
	cout << "[7] - Sortowanie rosn¹co" << endl;
	cout << "[8] - Sortowanie malej¹co" << endl;
	cout << "[9] - Próg od jakiego maj¹ byæ wyœwietlone pozycje" << endl;
	cout << "[10] - Zapis" << endl;
}

void wyswietlenie(auta::Samochody tab[], int &nr_samochodu, int &n) 
{
	using std::cout;
	using std::endl;
	if (n == 0)
	{
		for (int n = 0; n < nr_samochodu; ++n)
			cout << "Samochód numer " << n + 1 << ":\n" << tab[n] << endl<<endl;
	}
	else
		cout << "Samochód numer " << n  << ":\n" << tab[n-1] << endl;
}

void wyjscie()
{
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

int wczytaj(fstream &plik, int& n, auta::Samochody tab[])
{
	if (!plik.is_open())
	{
		cout << "Niepoprawnie otwarty plik!" << endl;
		return 0;
	}
	plik >> n;
	if (n > maks) 
	{
		cout << "Zbyt du¿a iloœæ pozycji na liœcie" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) 
		plik >> tab[i]; 
	return 1;
}

void wprowadzanie(auta::Samochody tab[],int &nr_samochodu)
{
	
	if (nr_samochodu < maks)
	{
		cout << "Wg: Marka Model Rocznik Moc Przebieg Skrzynia biegow" << endl;
		cout << "Podaj dane:";
		cin >> tab[nr_samochodu];
		nr_samochodu++;
	}
	else
		std::cerr << "Nie mozna dodac - pelna lista samochodow" << endl;
}

void usun(auta::Samochody tab[], int &nr_samochodu, int &n)
{
	using std::endl;
	if (n <= nr_samochodu)
	{
		tab[n - 1] = auta::Samochody();
		for (int i = n - 1; i < nr_samochodu; ++i)
			tab[i] = tab[i + 1];
		nr_samochodu--;
	}
	else
		cout << "Brak pozycji" << endl;
}

void zapis(auta::Samochody tab[], int &n)
{
	fstream plik;
	plik.open("car.txt", fstream::out);
	if (!plik.is_open()) // sprawdzenie poprawnosci otwarcia pliku
		std::cerr << "Blad otwarcia pliku" << std::endl;
	else
	{
		plik << n << std::endl; // zapisanie obecnej liczby samochodow
		for (int i = 0; i < n; ++i) // w petli wpisanie danych kazdego samochodu
		{
			plik << tab[i]._marka() << " ";
			plik << tab[i]._model() << " ";
			plik << tab[i]._rocznik() << " ";
			plik << tab[i]._pojemnosc() << " ";
			plik << tab[i]._przebieg() << " ";
			plik << tab[i]._skrz_bieg()<< std::endl;
		}
	}
	plik.close();
}

void sortowanie_malejaco(auta::Samochody tab[], int& nr_samochodu, int& n)
{
	auta::Samochody b = tab[0];
	if (n == 1)
	{
		for(int i=0; i<nr_samochodu - 1; ++i)
			for(int a=0;a<nr_samochodu-1;++a)
				if (tab[a]._pojemnosc() < tab[a + 1]._pojemnosc())
				{
					b = tab[a];
					tab[a] = tab[a + 1];
					tab[a + 1] = b;
				}
	}
	if (n == 2)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._rocznik() < tab[a + 1]._rocznik())
				{
					b = tab[a];
					tab[a] = tab[a + 1];
					tab[a + 1] = b;
				}
	}
	if (n == 3)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._przebieg() < tab[a + 1]._przebieg())
				{
					b = tab[a];
					tab[a] = tab[a + 1];
					tab[a + 1] = b;
				}
		if (n == 4)
		{
			for (int i = 0; i < nr_samochodu - 1; ++i)
				for (int a = 0; a < nr_samochodu - 1; ++a)
					if (tab[a]._marka() < tab[a + 1]._marka())
					{
						b = tab[a];
						tab[a] = tab[a + 1];
						tab[a + 1] = b;
					}
		}
	}
	if (n == 5)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._model() < tab[a + 1]._model())
				{
					b = tab[a];
					tab[a] = tab[a + 1];
					tab[a + 1] = b;
				}
	}
	if (n == 6)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._skrz_bieg() < tab[a + 1]._skrz_bieg())
				{
					b = tab[a];
					tab[a] = tab[a + 1];
					tab[a + 1] = b;
				}
	}
}

void sortowanie_rosnaco(auta::Samochody tab[], int& nr_samochodu, int& n)
{
	auta::Samochody b = tab[0];
	if (n == 1)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._pojemnosc() > tab[a + 1]._pojemnosc())
				{
					b = tab[a+1];
					tab[a+1] = tab[a];
					tab[a] = b;
				}
	}
	if (n == 2)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._rocznik() > tab[a + 1]._rocznik())
				{
					b = tab[a + 1];
					tab[a + 1] = tab[a];
					tab[a] = b;
				}
	}
	if (n == 3)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._przebieg() > tab[a + 1]._przebieg())
				{
					b = tab[a + 1];
					tab[a + 1] = tab[a];
					tab[a] = b;
				}
		if (n == 4)
		{
			for (int i = 0; i < nr_samochodu - 1; ++i)
				for (int a = 0; a < nr_samochodu - 1; ++a)
					if (tab[a]._marka() > tab[a + 1]._marka())
					{
						b = tab[a + 1];
						tab[a + 1] = tab[a];
						tab[a] = b;
					}
		}
	}
	if (n == 5)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._model() > tab[a + 1]._model())
				{
					b = tab[a + 1];
					tab[a + 1] = tab[a];
					tab[a] = b;
				}
	}
	if (n == 6)
	{
		for (int i = 0; i < nr_samochodu - 1; ++i)
			for (int a = 0; a < nr_samochodu - 1; ++a)
				if (tab[a]._skrz_bieg() > tab[a + 1]._skrz_bieg())
				{
					b = tab[a + 1];
					tab[a + 1] = tab[a];
					tab[a] = b;
				}
	}
}

void sortowanie_menu()
{
	cout << "Wzglêdem czego posortowaæ pozycje?" << endl;
	cout << " 1 - Pojemnoœæ." << endl;
	cout << " 2 - Rocznik." << endl;
	cout << " 3 - Przebieg." << endl;
	cout << " 4 - Marka." << endl;
	cout << " 5 - Model." << endl;
	cout << " 6 - Skrzynia biegów." << endl;
	cout << " Twój wybór: ";
}

void progi(auta::Samochody tab[], int& nr_samochodu, int& choice, int& level, string &lit)
{
	using std::cout;
	using std::endl;
	if (choice == 1)
	{
		for (int i = 0; i < nr_samochodu; ++i)
		{
			if (tab[i]._rocznik() >= level)
				cout << tab[i] << endl;
		}
	}
	if (choice == 2)
	{
		for (int i = 0; i < nr_samochodu; ++i)
		{
			if (tab[i]._pojemnosc() >= level)
				cout << tab[i] << endl;
		}
	}
	if (choice == 3) 
	{
		for (int i = 0; i < nr_samochodu; ++i)
		{
			if (tab[i]._przebieg() >= level)
				cout << tab[i] << endl;
		}
	}
	if (choice == 4)
	{
		for (int i = 0; i < nr_samochodu; ++i)
		{
			if (tab[i]._marka() >= lit)
				cout << tab[i] << endl;
		}
	}
	if (choice == 5)
	{
		for (int i = 0; i < nr_samochodu; ++i)
		{
			if (tab[i]._model() >= lit)
				cout << tab[i] << endl;
		}
	}
	if (choice == 6)
	{
		for (int i = 0; i < nr_samochodu; ++i)
		{
			if (tab[i]._skrz_bieg() >= level)
				cout << tab[i] << endl;
		}
	}
}

