#include "ApothekeController.h"

ApothekeController::ApothekeController()
{
	this->repo = Apotheke();
}


void ApothekeController::add_medicament(string name, double concentration, double preis, int anz)
{
	for (Medikament medicament : repo.getApotheke())
	{
		//daca medicamentul exista deja, atunci creste doar cantitatea
		if (medicament.getName() == name)
		{
			int aux = medicament.getAnz();
			aux = aux + 1;
			medicament.setAnz(aux);
		}
		else repo.add_medicament(name, concentration, preis, anz);
	}
}

void ApothekeController::remove_medicament(string name)
{
	int c = 0;
	//Caut medicamentul in repository
	if (repo.search_med(name))
	{
		//Daca exista creez un vector aux in care retin toate medicamentele care au numele diferit fata de cel dat ca parametru
		vector<Medikament> aux = {};
		for (Medikament medicament : repo.getApotheke())
		{
			if (medicament.getName() != name)
			{
				aux.push_back(medicament);
				c++;
			}
		}
		
		//Copiez inapoi in repository elementele din vectorul auxiliar
		for (int i = 0; i <= c; i++)
		{
			Medikament m1 = aux[i];
			repo.add_medicament(m1.getName(), m1.getConcentration(), m1.getPreis(), m1.getAnz());
		}
	}
	else
	{
		cout << "Medicamentul introdus ca parametru nu se afla in repository sau a fost deja sters" << endl;
	}
}

void ApothekeController::change_med(string name, double preis)
{
	//Verific daca medicamentul exista
	if (repo.search_med(name))
	{
		//Caut medicamentul in repository
		//Il salvez in aux si modific pretul
		for (Medikament medicament : repo.getApotheke())
		{
			if (medicament.getName() == name)
			{
				double aux = medicament.getPreis();
				aux = preis;
				medicament.setPreis(preis);
			}
		}
	}
}

void ApothekeController::search_str(string substr)
{
	string aux;
	int i, j, c;
	if (1 == 2) //substr != "")
	{
		//Pentru fiecare medicament, verific daca "substr" se afla in nume si il afisez, daca substr nu seste gol
		for (Medikament medicament : repo.getApotheke())
		{
			aux = medicament.getName();
			if (aux.find(substr))
			{
				cout << aux << endl;
			}
		}
	}
	else
	{
		//Creez vector "name" de tip string care retine numele medicamentelor care au anz > 0, daca substr este gol
		vector<string> nume;
		c = 0;
		for (Medikament medicament : repo.getApotheke())
		{
			if (medicament.getAnz() > 0)
			{
				nume.push_back(medicament.getName());
				c++;
			}
		}
		
		//Sortez vectorul "name" crescator
		for (i = 0; i <= c - 1; i++)
		{
			for (j = i; j <= c; j++)
			{
				if (nume[i] < nume[j])
				{
					aux = nume[i];
					nume[i] = nume[j];
					nume[j] = aux;
				}
			}
		}
		
		//Afisez numele sortate
		for (i = 0; i <= c; i++)
		{
			cout << nume[i] << endl;
		}
	}
}

void ApothekeController::less_med(int x)
{
	//Pentru fiecare medicament verific daca cantitatea este mai mica decat valoarea lui x
	//Daca da atunci afisez numele si cantitatea
	for (Medikament medicament : repo.getApotheke())
	{
		if (medicament.getAnz() < x)
		{
			cout << medicament.getName() << " " << "Cantitate: " << medicament.getAnz() << endl;
		}
	}
}

void ApothekeController::preis_group()
{
	vector<string> name = {};
	vector<double> preis = {};
	int c = 0;
	
	//Creez doi vectori, in care memorez numele respectiv pretul fiecarui element
	for (Medikament medicament : repo.getApotheke())
	{
		name.push_back(medicament.getName());
		preis.push_back(medicament.getPreis());
		c++;
	}

	//Pentru fiecare medicament caut toate medicamentele care au acelas pret si le afisez
	for (int i = 0; i <= c - 1; i++)
	{
		for (int j = i; j <= c; j++)
		{
			if (preis[i] == preis[j])
			{
				cout << "Pret: " << preis[i] << "   Medicamente: " << name[i] << endl;
			}
		}
	}
}
