#pragma once

#include <string>;
using namespace std;

class Medikament
{
private:
	
	string name; //numele
	double koncentration, preis; //concentratie si pret
	int cant; //cantitate

public:
	
	// Constructorul clasei Madikament
	Medikament(string name, double concentration, double preis, int anz);

	//returneaza numele medicamentului
	string getName();

	//seteaza numele medicamentului
	void setName(string name);

	//returneaza concentratia medicamentului
	double getConcentration();

	//seteaza concentratia medicamentului
	void setConcentration(double concentration);
	
	//returneaza pretul medicamentului
	double getPreis();

	//seteaza pretul medicamentului
	void setPreis(double preis);

	//returneaza cantitatea medicamentului
	int getAnz();

	//seteaza cantitatea medicamentului
	void setAnz(int anz);
};

