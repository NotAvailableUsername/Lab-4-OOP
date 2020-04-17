#include "Apotheke.h"

Apotheke::Apotheke()
{
	apotheke = {};

}

bool Apotheke::search_med(string name) 
{
	bool exista = false;
	int size = sizeof(apotheke) / sizeof(apotheke[0]);
	int i = 0;
	while (i < size || !exista)
	{
		if (apotheke[i].getName() == name)
		{
			exista = true;
		}
		else i++;
	}
	return exista;
}

void Apotheke::add_medicament(string name, double concentration, double preis, int anz)
{
	apotheke.push_back(Medikament(name, concentration, preis, anz));
}

void Apotheke::remove_medicament(string name)
{

}
vector<Medikament> Apotheke::getApotheke()
{
	return apotheke;
}
