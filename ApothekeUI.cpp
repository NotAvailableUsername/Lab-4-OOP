#include "ApothekeUI.h"
#include <iostream>

using namespace std;

ApothekeUI::ApothekeUI()
{
    this->controller = ApothekeController();
}

void ApothekeUI::show_menu()
{
    cout << "1.Inserare medicament   2.Eliminare medicament   3.Schimbare pret   4.Cautare medicament" << endl;
    cout << "5.Medicamente dupa cantitate   6.Grupare dupa pret   8.Exit" << endl;
}

void ApothekeUI::add_medicament()
{
    string name;
    double concentration, preis;
    int anz;
    cout << "Numele medicamentului: ";
    cin >> name;
    cout << "Concentratia medicamentului: ";
    cin >> concentration;
    cout << "Pretul brut: ";
    cin >> preis;
    cout << "Cantitate: ";
    cin >> anz;

    controller.add_medicament(name, concentration, preis, anz);
}

void ApothekeUI::remove_medicament()
{
    string name;
    cout << "Introduceti numele medicamentului pe care doriti sa il stergeti: ";
    cin >> name;

    controller.remove_medicament(name);
}

void ApothekeUI::change_med()
{
    string name;
    double preis;
    cout << "Introduceti numele medicamentului pe care doriti sa il actualizati: ";
    cin >> name;
    cout << "Introduceti pretul nou: ";
    cin >> preis;

    controller.change_med(name, preis);
}

void ApothekeUI::search_str()
{
    string str;
    cout << "Introduceti stringul pe care doriti sa il cautati: ";
    cin >> str;
    
    controller.search_str(str);
}

void ApothekeUI::less_med()
{
    int x;
    cout << "Introduceti cantitatea minima: ";
    cin >> x;

    controller.less_med(x);
}

void ApothekeUI::preis_group()
{
    controller.preis_group();
}

void ApothekeUI::startUI()
{
    int input = -1;
    while (input != 7) {
        show_menu();
        cout << "Introduceti optiunea dorita: ";
        cin >> input;
        switch (input)
        {
        case 1:
            add_medicament();
            break;
        case 2:
            remove_medicament();
            break;
        case 3:
            change_med();
            break;
        case 4:
            search_str();
            break;
        case 5:
            less_med();
            break;
        case 6:
            preis_group();
            break;
        default:
            break;
        }
    }
}