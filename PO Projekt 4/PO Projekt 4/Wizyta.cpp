#include "stdafx.h"
#include "Wizyta.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;


Wizyta::Wizyta(int dz, string mies, int r, string imlek, string nazlek, string log)
{
	dzien = dz;
	miesiac = mies;
	rok = r;
	// imie_pacjenta = impac;
	// nazwisko_pacjenta = nazpac;
	imie_lekarza = imlek;
	naz_lekarza = nazlek;
	loginpacjenta1 = log;
}


Wizyta::~Wizyta()
{
}
