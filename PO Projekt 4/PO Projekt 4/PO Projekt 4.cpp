// PO Projekt 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pacjent.h"
#include "Wizyta.h"
#include "Zalecenia.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

string loginadmina;
string hasloadmina;
string loginpacjenta;
string haslopacjenta;

int program = 1;
int logowanie;
int admin;
int whileadmin;

list<Pacjent> lista_pacjentow;
list<Pacjent>::iterator pac;
list<Wizyta> lista_wizyt;
list<Wizyta>::iterator wiz;
list<Zalecenia> lista_zalecen;
list<Zalecenia>::iterator zal;

void import_pacjentow()
{
	string a1, a2, a3, a4, b1;
	int a5;

	fstream pac1("pacjenci.txt", ios::in | ios::out);


	while (getline(pac1, a1))
	{
		getline(pac1, a2);
		getline(pac1, a3);
		getline(pac1, a4);
		getline(pac1, b1);
		a5 = atoi(b1.c_str());

		Pacjent P2(a1, a2, a3, a4, a5);
		lista_pacjentow.push_back(P2);
	}
	pac1.close();
}
void import_wizyt()
	{
		string b1, a2, b3, a4, a5, a6;
		int a1, a3;

		fstream wiz1("wizyty.txt", ios::in | ios::out);

		while (getline(wiz1, b1))
		{
			getline(wiz1, a2);
			getline(wiz1, b3);
			getline(wiz1, a4);
			getline(wiz1, a5);
			getline(wiz1, a6);

			a1 = atoi(b1.c_str());
			a3 = atoi(b3.c_str());

			Wizyta W2(a1, a2, a3, a4, a5, a6);
			lista_wizyt.push_back(W2);
		}
		wiz1.close();
	}
void import_zalecen()
	{
		string a1, a2, a3, a4, b5;
		int a5;
		
		fstream zal1("zalecenia.txt", ios::in | ios::out);

		while (getline(zal1, a1))
		{
			getline(zal1, a2);
			getline(zal1, a3);
			getline(zal1, a4);
			getline(zal1, b5);

			a5 = atoi(b5.c_str());

			Zalecenia Z2(a1, a2, a3, a4, a5);
			lista_zalecen.push_back(Z2);
		}
		zal1.close();
	}
void eksport_pacjentow()
	{
		ofstream pac123("pacjenci.txt", ios::out);
		pac = lista_pacjentow.begin();
		int flag = 0;

		while (pac != lista_pacjentow.end())
		{
			if (flag == 1) pac123 << endl;
			pac123 << pac->login << endl;
			pac123 << pac->haslo << endl;
			pac123 << pac->imie << endl;
			pac123 << pac->nazwisko << endl;
			pac123 << pac->rocznik;
			flag = 1;
			pac++;
		}
		pac123.close();
	}
void eksport_wizyt()
	{
		ofstream wiz1234("wizyty.txt", ios::out);
		wiz = lista_wizyt.begin();
		int flag = 0;

		while (wiz != lista_wizyt.end())
		{
			if (flag == 1) wiz1234 << endl;
			wiz1234 << wiz->dzien << endl;
			wiz1234 << wiz->miesiac << endl; 
			wiz1234 << wiz->rok << endl; 
			wiz1234 << wiz->imie_lekarza << endl;
			wiz1234 << wiz->naz_lekarza << endl;
			wiz1234 << wiz->loginpacjenta1;
			flag = 1;
			wiz++;
		}
		wiz1234.close();
	}
void eksport_zalecen()
	{
		ofstream zal123("zalecenia.txt", ios::out);
		zal = lista_zalecen.begin();
		int flag = 0;
		while (zal != lista_zalecen.end())
		{
			if (flag == 1) zal123 << endl;
			zal123 << zal->log_pac << endl;
			zal123 << zal->imie_lekarza << endl;
			zal123 << zal->naz_lekarza << endl;
			zal123 << zal->nazwaleku << endl;
			zal123 << zal->dawka;
			flag = 1;
			zal++;
		}
		zal123.close();
	}

void stworzenie(string login, string haslo, string imie, string nazwisko, int rocznik)
{
	Pacjent P1(login, haslo, imie, nazwisko, rocznik);
	lista_pacjentow.push_back(P1);
}

void stworzenie(int dzien, string miesiac, int rok, string imie_lek, string naz_lek, string login5)
{
	Wizyta W1(dzien, miesiac, rok, imie_lek, naz_lek, login5);
	lista_wizyt.push_back(W1);
}

int main()
{
	import_pacjentow();
	import_wizyt();
	import_zalecen();
	while (program==1)
	{
		cout << "Logowanie: " << endl;
		cout << "1. Administrator" << endl;
		cout << "2. Pacjent" << endl;
		cout << endl; 
		cout << endl;
		cout << "Menu bez logowania:" << endl;
		cout << "3. Srednia wieku wszystkich pacjentow" << endl;
		cout << "4. Czestotliwosc wystepowania imion o okreslonej dlugosci" << endl;
		cout << "5. Wyjscie" << endl;
		cout << endl;
		cout << endl;
		cin >> logowanie;
		switch (logowanie) 
		{
			case 1: // logowanie admina
			{
				cout << "Login: ";
				cin >> loginadmina;
				if (loginadmina == "admin")
				{
					cout << "Haslo: ";
					cin >> hasloadmina;
					if (hasloadmina == "ciastka")
					{
						whileadmin = 1;
						while (whileadmin == 1)
						{
							system("cls");
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Menu administratora:" << endl;
							cout << "1. Zakladanie kont pacjentow" << endl;
							cout << "2. Wprowadzanie wizyty" << endl;
							cout << "3. Wprowadzenie zalecen" << endl;
							cout << "4. Wylogowanie" << endl;
							cin >> admin;
							switch (admin)
							{

								case 1: // zakładanie konta pacjenta
								{
									system("cls");
									string login;
									string haslo;
									string imie;
									string nazwisko;
									int rocznik;
									int tworze = 1;
									cout << endl;
									cout << "Imie pacjenta: ";
									cin >> imie;
									cout << "Nazwisko pacjenta: ";
									cin >> nazwisko;
									bool bkoniec = false;
									while (bkoniec!=true)
									{
										cout << "Rok urodzenia (miedzy 1920, a 2017): ";
										cin >> rocznik;
										if (rocznik >= 1919)
										{
											if (rocznik <= 2018)
											{
												bkoniec = true;
											}
										}
									}
									cout << "Login dla pacjenta: ";
									cin >> login;
									cout << "Haslo logowania: ";
									cin >> haslo;
									for (pac = lista_pacjentow.begin(); pac != lista_pacjentow.end(); ++pac)
									{
										if ((*pac).login == login)
										{
											tworze = 3;
										}
									}
									if (tworze == 1)
									{
										//Pacjent P1(login, haslo, imie, nazwisko, rocznik);
										//lista_pacjentow.push_back(P1);
										stworzenie(login, haslo, imie, nazwisko, rocznik);
									}
									else if (tworze == 3)
									{
										cout << "Nie mozna utworzyc konta pacjanta! Konto o takim loginie juz istnieje";
									}
									_getch();
									system("cls");
									break;
								}

								case 2: //wprowadzenie wizyty
								{
									system("cls");
									int dzien;
									string miesiac;
									int rok;
									string imie_pac;
									string naz_pac;
									string login5;
									string imie_lek;
									string naz_lek;
									int eee = 1;
									cout << endl;
									cout << "Login pacjenta: ";
									cin >> login5;
									for (pac = lista_pacjentow.begin(); pac != lista_pacjentow.end(); ++pac)
									{
										if ((*pac).login == login5)
										{
											eee = 2;
											cout << "Dzien wizyty: ";
											cin >> dzien;
											cout << "Miesiac wizyty (słownie): ";
											cin >> miesiac;
											cout << "Rok wizyty: ";
											cin >> rok;
											cout << "Lekarz (imie): ";
											cin >> imie_lek;
											cout << "Lekarz (nazwisko): ";
											cin >> naz_lek;
											//Wizyta W1(dzien, miesiac, rok, imie_lek, naz_lek, login5);
											//lista_wizyt.push_back(W1);
											stworzenie(dzien, miesiac, rok, imie_lek, naz_lek, login5);
										}
									}
									if (eee == 1)
									{
										cout << "Nie ma takiego pacjenta!" << endl;
									}
									_getch();
									system("cls");
									break;
								}

								case 3: //wprowadzenie zalecen
								{
									system("cls");
									string log1;
									string imielek1;
									string nazlek1;
									string nazwaleku;
									int zalecenie = 1;
									int wybrani=1;
									int dawka;
									int czypacjent = 1;
									cout << endl;
									cout << "Login pacjenta: ";
									cin >> log1;
									for (pac = lista_pacjentow.begin(); pac != lista_pacjentow.end(); ++pac)
									{
										if ((*pac).login == log1)
										{
											czypacjent = 2;
											cout << "Imie lekarza: ";
											cin >> imielek1;
											cout << "Nazwisko lekarza: ";
											cin >> nazlek1;
											while (zalecenie == 1)
											{
												cout << "Nazwa leku: ";
												cin >> nazwaleku;
												dawka = rand() % 5;
												Zalecenia Z1(log1, imielek1, nazlek1, nazwaleku, dawka);
												lista_zalecen.push_back(Z1);
												cout << "Czy chcesz wprowadzic dalsze zalecenia od tego lekarza? 1 - TAK; 2 - NIE" << endl;
												cin >> wybrani;
												if (wybrani == 2)
												{
													zalecenie = 2;
												}
											}
										}
									}
									if (czypacjent == 1)
									{
										cout << endl;
										cout << endl;
										cout << "Pacjent o podanym loginie nie istnieje!";
									}
									_getch();
									system("cls");
									break;
								}
								
								case 4: // wyjście
								{
									whileadmin = 3;
									system("cls");
									break;
								}
							}
						}
					}
					else if (hasloadmina != "ciastka")
					{
						cout << endl;
						cout << "Bledne haslo!" << endl;
						cout << endl;
						_getch();
						system("cls");
						break;
					}
				}
				else if (loginadmina != "admin")
				{
					cout << endl;
					cout << "Bledny login" << endl;
					cout << endl;
					_getch();
					system("cls");
					break;
				}
				break;
			}

			case 2: // logowanie pacjenta
			{
				cout << "Login: ";
				string logus;
				cin >> logus;
				int bllog = 1;
				int blhas = 2;
				for (pac = lista_pacjentow.begin(); pac != lista_pacjentow.end(); pac++)
				{
					if ((*pac).login == logus)
					{
						bllog = 2;
						blhas = 1;
						cout << "Haslo: ";
						cin >> haslopacjenta;
						if ((*pac).haslo == haslopacjenta)
						{
							blhas = 2;
							int pacjentowi = 3;
							system("cls");
							cout << endl;
							cout << endl;
							cout << "Dane personalne" << endl;
							cout << endl;
							cout << "Imie: " << (*pac).imie << endl;
							cout << "Nazwisko: " << (*pac).nazwisko << endl;
							cout << "Rok urodzenia: " << (*pac).rocznik << endl;
							cout << endl;
							cout << endl;
							_getch();
							while (pacjentowi != 1)
							{
								cout << "Menu: " << endl;
								cout << "1. Wyswietl historie wizyt" << endl;
								cout << "2. Wyswietl zalecenia" << endl;
								cout << "3. Wyloguj" << endl;
								int w;
								cin >> w;
								system("cls");
								cout << endl;
								cout << endl;
								switch (w)
								{
								case 1: //historia wizyt
								{
									for (wiz = lista_wizyt.begin(); wiz != lista_wizyt.end(); ++wiz)
									{
										if ((*wiz).loginpacjenta1 == logus)
										{
											cout << endl;
											cout << "Data wizyty: " << (*wiz).dzien << " " << (*wiz).miesiac << " " << (*wiz).rok << endl;
											cout << "Lekarz: " << (*wiz).imie_lekarza << " " << (*wiz).naz_lekarza << endl;
											cout << endl;
										}
									}
									break;
								}

								case 2: //zalecenia
								{
									for (zal = lista_zalecen.begin(); zal != lista_zalecen.end(); ++zal)
									{
										if ((*zal).log_pac == logus)
										{
											cout << endl;
											cout << "Lekarz: " << (*zal).imie_lekarza << " " << (*zal).naz_lekarza << endl;
											cout << "Lek: " << (*zal).nazwaleku << endl;
											cout << "Dawka: " << (*zal).dawka << " /dzien" << endl;
											cout << endl;
										}
									}
									break;
								}

								case 3: //wylogowanie
								{
									pacjentowi = 1;
									//system("cls");
									cout << "Wychodze";
									break;
								}
								}
							}

						}
					}
				}
					if (blhas == 1)
					{
						cout << endl;
						cout << endl;
						cout << "Bledne haslo!" << endl;
						cout << endl;
						_getch();
						system("cls");
						break;
					}
					if (bllog == 1)
					{
						cout << endl;
						cout << "Nie ma takiego pacjenta!";
						cout << endl;
						_getch();
						system("cls");
						break;
				}
				break;
			}

			case 3: // srednia wieku 
			{
				int rok;
				int roznica=0;
				int suma=0;
				int ilpac=0;
				for (pac = lista_pacjentow.begin(); pac != lista_pacjentow.end(); ++pac)
				{
					rok = (*pac).rocznik;
					roznica = 2018 - rok;
					suma = suma + roznica;
					ilpac++;
				}
				auto srednia = [](int x, int y)->void { cout<<"Wyrazenie lambda:"<< x / y<<endl; };
				srednia(suma, ilpac);
				_getch();
				system("cls");
				break;
			}

			case 4:
			{
				int dlugoscimienia;
				string imie1;
				int dopieciu = 0;
				int piecdosiedmiu = 0;
				int ponadsiedem = 0;
				for (pac = lista_pacjentow.begin(); pac != lista_pacjentow.end(); ++pac)
				{
					imie1 = (*pac).imie;
					dlugoscimienia = imie1.length();
					if (dlugoscimienia < 5)
					{
						dopieciu++;
					}
					else if (dlugoscimienia > 7)
					{
						ponadsiedem++;
					}
					else if (dlugoscimienia >= 5 || dlugoscimienia <= 7)
					{
						piecdosiedmiu++;
					}
				}
				cout << endl;
				cout << endl;
				cout << "Ilosc wystepowania imion:" << endl;
				cout << "- do 5 liter - " << dopieciu << " razy" << endl;
				cout << "- 5-7 liter - " << piecdosiedmiu << " razy" << endl;
				cout << "- powyzej 7 liter - " << ponadsiedem << " razy" << endl;
				break;
			}

			case 5: // wyjscie
			{
				program = 3;
				eksport_pacjentow();
				eksport_wizyt();
				eksport_zalecen();
				break;
			}

			case 6:
			{
				for (pac = lista_pacjentow.begin(); pac != lista_pacjentow.end(); ++pac)					{
				cout << "Login: " << (*pac).login << endl;
				}
				cout << endl;
				_getch();
				break;
			}
		}
	}
    return 0;
}

