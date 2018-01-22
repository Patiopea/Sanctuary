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

class Zalecenia
{
public:
	Zalecenia(string lo, string imlek, string nazlek, string lek, int daw);
	string log_pac;
	string imie_lekarza;
	string naz_lekarza;
	string nazwaleku;
	int dawka;
	~Zalecenia();
};

