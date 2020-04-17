#pragma once

#include <iostream>
#include "Apotheke.h"
#include <algorithm>
#include "Medikament.h"

using namespace std;

class ApothekeController
{
private:
	Apotheke repo;

public:

	// Constructor pentru controller
	explicit ApothekeController();

	//adauga un element nou in aphoteke
	void add_medicament(string name, double concentration, double preis, int anz);

	//sterge un medicament
	void remove_medicament(string name);

	//schimba pretul unui medicament
	void change_med(string name, double preis);

	//cauata si returneaza un medicament
	void search_str(string substr);

	//afiseaza numele si cantitatea medicamentelor care au cantitatea mai mica decat x
	void less_med(int x);

	//afiseaza medicamentele grupate dupa pret
	void preis_group();
};

