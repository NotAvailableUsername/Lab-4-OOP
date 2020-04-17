#include "Medikament.h"

Medikament::Medikament(string name, double concentration, double preis, int anz)
{
	this->name = name;
	this->koncentration = concentration;
	this->preis = preis;
	this->cant = anz;
}

string Medikament::getName()
{
	return name;
}

void Medikament::setName(string name)
{
	this->name = name;
}


double Medikament::getConcentration()
{
	return koncentration;
}

void Medikament::setConcentration(double concentration)
{
	this->koncentration = concentration;
}

double Medikament::getPreis()
{
	return preis;
}

void Medikament::setPreis(double preis)
{
	this->preis = preis;
}

int Medikament::getAnz()
{
	return cant;
}

void Medikament::setAnz(int anz)
{
	this->cant = anz;
}
