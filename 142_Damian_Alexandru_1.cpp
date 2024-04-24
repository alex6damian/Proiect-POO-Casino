#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <vector>
#include "angajati.h"
#include "clienti.h"
#include "jocuri.h"
#include "casino.h"

using namespace std;

int main()
{

    int k = 1;

    vector<Casino> casino;

    while (k == 1) {

        cout << "\n\n\n 1 Creeaza un Casino \n";
        cout << "\n 2 Afiseaza informatii Casino \n";
        cout << "\n 3 Modifica Casino \n";
        cout << "\n 4 Sterge Casino \n";
        cout << "\n 5 Exit \n";

        int op;

        cout << "\n Introduceti comanda: ";
        cin >> op;
        cout << "\n\n";

        switch (op)
        {
        case 1: {
            
            cout << " Ati ales sa creati un Casino!\n\n";
            Casino c;
            cin >> c;
            casino.push_back(c);
            break;
        }
        case 2:
        {
            int comanda;

            cout << " Ati ales sa aflati informatii despre un Casino!\n\n";
            cout << " Ce Casino v-ar interesa?(In functie de numele managerului): \n";

            for (int i = 0;i < casino.size();i++,cout<<'\n')
                cout <<" "<< i + 1 << " " << casino[i].getManager();
            if (casino.size() == 0)break;
            cout << '\n';

            cout << " Introduceti numarulul Casinoului care va intereseaza: ";

            cin >> comanda;

            cout << '\n';

            cout << "\n Ati ales Casinoul al carui manager este " << casino[comanda - 1].getManager()<<"!\n\n";

            int key;

            cout << "\n\n\n 1 Afiseaza toate informatiile \n";
            cout << "\n 2 Afiseaza jocurile in functie de castigul acestora \n";
            cout << "\n 3 Afiseaza zonele unde exista angajati \n";
            cout << "\n 4 Inapoi \n";
            cout << "\n Introduceti comanda: "; cin >> key;

            switch (key)
            {
            case 1:
            {

                cout << casino[comanda - 1];
                break;

            }
            case 2:
            {

                casino[comanda - 1].bestJocuri();
                break;

            }
            case 3: {

                casino[comanda - 1].zoneOcupate();
                break;

            }
            case 4:
                break;
            }
            break;
        }
        case 3: {



            cout << " Ati ales sa faceti modificari asupra unui Casino!\n\n";
            cout << " Ce Casino v-ar interesa sa modificati?(In functie de numele managerului): \n";
            

            if (casino.size() == 0)break;
            for (int i = 0;i < casino.size();i++, cout << '\n')
                cout <<" " << i + 1 << " " << casino[i].getManager();

            
            cout << '\n';
            cout << " Introduceti numarul Casinoului pe care doriti sa il modificati: ";
            int comanda;
            cin >> comanda;
            cout << " Ati ales Casinoul al carui manager este " << casino[comanda - 1].getManager() << "!\n\n";
            cout << " Ce modificari doriti sa faceti?\n";
            int index;
            int t = 1;
            while (t == 1) {
                cout << "\n\n\n 1 Modifica salariu angajat \n";
                cout << "\n 2 Modifica profit Casino \n";
                cout << "\n 3 Modifica capacitate \n";
                cout << "\n 4 Adauga angajat nou \n";
                cout << "\n 5 Exit \n";
                cout << '\n';
                cout << " Introduceti comanda: ";
                cin >> index;
                cout << '\n';
;                switch (index)
                {
            case 1: {

                int indice;
                cout << " Alegeti angajatul dupa nume: \n";

                for (int i = 0;i < casino[comanda - 1].getNrAngajati();i++, cout<<'\n')
                    cout << " " << i + 1 << " " << casino[comanda - 1].getAngajati()[i].getNume();

                cout << "\n Introduceti comanda: ";
                cin >> indice;

                int salariu;
                cout << "\n Introduceti noul salariu: ";
                cin >> salariu;
                
                cout << '\n';
                casino[comanda - 1].getAngajati()[indice-1].setSalariu(salariu);
                cout << "\n Salariul a fost modificat cu succes!\n";
                break;
            }
            case 2: {
                int suma;
                cout << " Introduceti noua suma: ";
                cin >> suma;
                casino[comanda - 1].setProfit(suma);
                cout << "\n Profitul a fost modificat cu succes!\n";
                break;
            }
            case 3:
            {
                int capacitate;
                cout << " Introduceti noua capacitate: ";
                cin >> capacitate;
                casino[comanda - 1].setCapacitate(capacitate);
                cout << "\n Capacitatea a fost modificata cu succes!\n";
                break;
            }
            case 4: 
            {
                Angajati angajat;

                cin >> angajat;

                casino[comanda - 1] = casino[comanda - 1] + angajat;

                cout << " Angajatul "<< angajat.getNume()<<" a fost adaugat cu succes!\n\n\n";
                break;
            }
            case 5:
            {
                t = 0;
                break;
            }
                }
            }
            break;
        }
        case 4: {
            int index;
            if (casino.size() == 0)break;
            cout << " Ati ales sa stergeti un Casino!\n\n";
            cout << " Numarul de Casinouri existente: " << casino.size()<<'\n';
            cout << " Ce Casino ati vrea sa stergeti?(In functie de numele managerului): \n";
            for (int i = 0;i < casino.size();i++, cout << '\n')
                cout << " " << i + 1 << " " << casino[i].getManager();
                cout << '\n';
                cout << "\n Introduceti comanda: ";
                cin >> index;
                casino.erase(casino.begin() + index - 1);
                cout << " \n\n\nCasinoul a fost sters cu succes!\n";

            break;
        }
        case 5: {
            cout << " Ati ales sa parasiti aplicatia noastra!\n\n\n\n";
            k = 0;
            break;
        }
        }
    }
    return 0;
}
