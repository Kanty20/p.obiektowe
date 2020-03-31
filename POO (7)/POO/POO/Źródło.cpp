#include "samochod.h"

using namespace std;

int main ()
{
	setlocale(LC_CTYPE, "Polish");

	using std::cout;
	using std::cin;
	using std::endl;
	using auta::Samochody;
	fstream plik;
	string lit;
	int nr_samochodu, choice = 0, level;
	Samochody tab[maks];
	plik.open("car.txt");
	if (!wczytaj(plik, nr_samochodu, tab))
	{
		plik.close();
		return(0);
	}
	plik.close();
	menu();
	int n = 0;
	while (choice != 1)
	{
		cout << endl << "Tw�j wyb�r: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "The end" << endl;
			return 0;
			break;
		case 2:
			menu();
			break;
		case 3:
			wyswietlenie(tab, nr_samochodu, n);
			break;
		case 4:
			wprowadzanie(tab, nr_samochodu);
			break;
		case 5:
			cout << "Kt�r� pozycj� usun��?: ";
			cin >> choice;
			usun(tab, nr_samochodu, choice);
			break;
		case 6:
			cout << "Jak� pozycj� wy�wietli�?: ";
			cin >> choice;
			cout << endl;
			wyswietlenie(tab, nr_samochodu, choice);
			break;
		case 7:
			sortowanie_menu();
			cin >> choice;
			sortowanie_rosnaco(tab, nr_samochodu, choice);
			break;
		case 8:
			sortowanie_menu();
			cin >> choice;
			sortowanie_malejaco(tab, nr_samochodu, choice);
			break;
		case 9:
			cout << "Jakie parametry b�d� wy�wietlane?" << endl;
			cout << " 1 - Rocznik" << endl;
			cout << " 2 - Pojemno��" << endl;
			cout << " 3 - Przebieg" << endl;
			cout << " 4 - Marka" << endl;
			cout << " 5 - Model" << endl;
			cout << " 6 - Skrzynia bieg�w" << endl;
			cout << " Tw�j wyb�r: ";
			cin >> choice;
			if (choice == 4)
			{
				cout << " Podaj liter�: ";
				cin >> lit;
			}
			else
				if (choice == 5)
				{
					cout << " Podaj liter�: ";
					cin >> lit;
				}
				else
				{
					cout << " Podaj warto��: ";
					cin >> level;
				}
			progi(tab, nr_samochodu, choice, level, lit);
			break;
		case 10:
			zapis(tab, nr_samochodu);
			break;
		default:
			cout << "Nie ma takiego numeru!" << endl;
		}
		if (cin.fail())
			wyjscie();
		choice = 0;
	}
	return 0;
}