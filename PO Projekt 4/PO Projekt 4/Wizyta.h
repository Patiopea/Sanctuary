#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

class Wizyta
{
public:
	Wizyta(int dz, string mies, int r, string imlek, string nazlek, string log);
	int dzien;
	string miesiac;
	int rok;
	string imie_lekarza;
	string naz_lekarza;
	string loginpacjenta1;
	~Wizyta();
};

