#include "stdafx.h"
#include "Pacjent.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;


Pacjent::Pacjent(string log, string has, string im, string naz, int rok)
{
	login = log;
	haslo = has;
	imie = im;
	nazwisko = naz;
	rocznik = rok;
}


Pacjent::~Pacjent()
{
}
