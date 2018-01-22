#include "stdafx.h"
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


Zalecenia::Zalecenia(string lo, string imlek, string nazlek, string lek, int daw)
{
	log_pac = lo;
	imie_lekarza = imlek;
	naz_lekarza = nazlek;
	nazwaleku = lek;
	dawka = daw;
}


Zalecenia::~Zalecenia()
{
}
