#pragma once

#include <vector>
#include "Apotheke.h"
#include "Medikament.h"

using namespace std;

class Apotheke
{
private:
	
	vector<Medikament> apotheke;

public:
	
	// Constructor pentru Apotheke
	//vector gol
	explicit Apotheke();

	//verifica daca medicamentul se afla in repo
	bool search_med(string name);

	//adauga un medicament in apotheke
	void add_medicament(string name, double concentration, double preis, int anz);

	//sterge un medicament
	void remove_medicament(string name);

	//Returneaza toate elementele din vector
	vector<Medikament> getApotheke();
};