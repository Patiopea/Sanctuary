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

class Pacjent
{
public:
	Pacjent(string log, string has, string im, string naz, int rok);
	string login;
	string haslo;
	string imie;
	string nazwisko;
	int rocznik;
	~Pacjent();
};

