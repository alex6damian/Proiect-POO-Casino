#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>


using namespace std;

//clasa Clienti
class Clienti {

    char* nume;
    double sumaJucata, profit, pierderi;
    int* ultimelePariuri;
    const int id;
    static int nrClienti;

public:

    //constructor default
    Clienti();

    //constructor cu toti parametri
    Clienti(char* nume, double sumaJucata, double profit, double pierderi, int* ultimelePariuri);

    //constructori cu parametri
    Clienti(double sumaJucata);
    Clienti(double sumaJucata, double profit);

    //copy-constructor
    Clienti(const Clienti& obj);

    //suprascriere "="(dest+copycons)
    Clienti& operator=(const Clienti& obj);

    //suprascriere preincrementare(mai adauga bani)
    Clienti& operator++();

    //supraincarcare postincrementare
    Clienti operator++(int);

    //predecrementare
    Clienti& operator--();

    //postdecrementare
    Clienti operator--(int);


    //suprascriere + cu un double
    Clienti operator+(double suma);

    //suprascriere - cu un double(retragere bani)
    Clienti operator-(double suma);

    //suprascriere + intre obiecte
    Clienti operator+(const Clienti& obj);

    //suprascriere operator "=="
    bool operator==(const Clienti& obj);

    //suprascriere operator ">"
    bool operator>(const Clienti& obj);

    //cast implicit
    //operator double();

    //setter nume
    void setNume(char* nume);

    //getter nume
    const char* getNume();

    //setter sumaJucata
    void setsumaJucata(double sumaJucata);

    //getter sumaJucata
    double getsumaJucata();

    //setter profit
    void setProfit(double profit);

    //getter profit
    double getProfit();

    //setter pierderi
    void setPierderi(double pierderi);

    //getter pierderi
    double getPierderi();

    //setter ultimelePariuri
    void setUltimelePariuri(int* ultimelePariuri);
    
    //getter ultimelePierderi
    const int* getUltimelePariuri();

    //getter id
    const int getId();

    //getter nrClienti
    static int getNrClienti() {
        return nrClienti;
    }

    //suprascriere indexare "[]"
    int operator[](int index);


    //destructor
    ~Clienti()
    {
        if (this->ultimelePariuri != NULL)delete[]this->ultimelePariuri;
        this->ultimelePariuri = NULL;

        if (this->nume != NULL)delete[]this->nume;
        this->nume = NULL;

        this->nrClienti--;
    }

    friend istream& operator>>(istream& in, Clienti& obj);
    friend ostream& operator<<(ostream& out, const Clienti& obj);

    friend Clienti operator+(double suma, Clienti obj);
    friend Clienti operator-(double suma, Clienti obj);
};

//constructor default
Clienti::Clienti() :id(nrClienti++), sumaJucata(0.0), profit(0.0), pierderi(0.0) {

    this->ultimelePariuri = NULL;

    nume = new char[strlen("Necunoscut") + 1];
    strcpy(nume, "Necunoscut");
}

//constructor cu toti parametri
Clienti::Clienti(char* nume, double sumaJucata, double profit, double pierderi, int*ultimelePariuri) :id(nrClienti++),
sumaJucata(sumaJucata), profit(profit), pierderi(pierderi)
{
    this->ultimelePariuri = ultimelePariuri;

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}

//constructori cu parametri
Clienti::Clienti(double sumaJucata) :id(nrClienti++), sumaJucata(sumaJucata), profit(0), pierderi(0) {

    this->ultimelePariuri = new int[5];
    for (int i = 0;i < 5;i++)
        this->ultimelePariuri[i] = 0;

    this->nume = new char[strlen("Necunoscut") + 1];
    strcpy(this->nume, "Necunoscut");
}

Clienti::Clienti(double sumaJucata, double profit) :id(nrClienti++), sumaJucata(sumaJucata), profit(profit), pierderi(0) {

    this->ultimelePariuri = new int[5];
    for (int i = 0;i < 5;i++)
        this->ultimelePariuri[i] = 0;

    this->nume = new char[strlen("Necunoscut") + 1];
    strcpy(this->nume, "Necunoscut");
}

//copy-constructor
Clienti::Clienti(const Clienti& obj) :id(nrClienti++), sumaJucata(obj.sumaJucata), profit(obj.profit), pierderi(obj.pierderi) {

    this->ultimelePariuri = obj.ultimelePariuri;

    this->nume = new char[strlen(obj.nume) + 1];
    strcpy(this->nume, obj.nume);

}

//suprascriere "="(dest+copycons)
Clienti& Clienti :: operator=(const Clienti& obj) {
    if (this != &obj) {
        if (this->nume != NULL)delete[]this->nume;
        if (this->ultimelePariuri != NULL)delete[]this->ultimelePariuri;

        this->ultimelePariuri = new int[5];

        this->nume = new char[strlen(obj.nume) + 1];
        strcpy(this->nume, obj.nume);
        
        this->sumaJucata = obj.sumaJucata;
        this->profit = obj.profit;
        this->pierderi = obj.pierderi;
        this->nrClienti = obj.nrClienti;
        
        for (int i = 0;i < 5;i++)
            this->ultimelePariuri[i] = obj.ultimelePariuri[i];

    }
    return *this; //dereferentiere pentru a returna obiectul
}

//suprascriere preincrementare(mai adauga bani)
Clienti& Clienti :: operator++() {
    this->sumaJucata += 500.0;
    return *this;
}

//supraincarcare postincrementare
Clienti Clienti :: operator++(int) {
    Clienti copy;
    copy = *this;
    ++(*this);
    return copy;
}

//supraincarcare preincrementare(scade)
Clienti& Clienti :: operator--() {

    this->pierderi -= 500.0;
    return *this;
}

//postincrementare
Clienti Clienti :: operator--(int)
{
    Clienti copy;
    copy = *this;
    --(*this);
    return copy;
}

//suprascriere + cu un double
Clienti Clienti :: operator+(double suma) {
    Clienti copy;
    copy = *this;
    copy.sumaJucata += suma;
    return copy;
}

//suprascriere - cu un double(retragere bani)
Clienti Clienti :: operator-(double suma) {
    Clienti copy;
    copy = *this;
    if (copy.profit >= suma) copy.profit -= suma;
    return copy;
}

//suprascriere + intre obiecte
Clienti Clienti :: operator+(const Clienti& obj) {

    Clienti copy;
    copy = *this;
    
    copy.sumaJucata += obj.sumaJucata;
    copy.profit += obj.profit;
    copy.pierderi += obj.pierderi;

    int* nou = new int[10];
    for (int i = 0;i < 5;i++)
        nou[i] = copy.ultimelePariuri[i];
    
    for (int i = 0;i < 5;i++)
        nou[i + 5] = obj.ultimelePariuri[i];

    if (copy.ultimelePariuri != NULL)delete[]copy.ultimelePariuri;//stergem vechea zona de memorie
    
    copy.ultimelePariuri = nou; //pointam catre noua zona de memorie

    int lungimeNoua = strlen(copy.nume) + strlen(" si ") + strlen(obj.nume) + 1;
    char* aux = new char[lungimeNoua];
    strcpy(aux, copy.nume);
    strcat(aux, " si ");
    strcat(aux, obj.nume);
    
    if (copy.nume != NULL)delete[]copy.nume;
    copy.nume = new char[lungimeNoua];
    strcpy(copy.nume, aux);
    
    delete[]aux;
    return copy;

}

//suprascriere operator "=="
bool Clienti :: operator==(const Clienti& obj)
{

    return this->profit == obj.profit and this->sumaJucata==obj.sumaJucata;

}

//suprascriere operator ">"
bool Clienti:: operator>(const Clienti& obj) {

    return this->profit > obj.profit and this->sumaJucata>obj.sumaJucata;

}
/*
//cast implicit
Clienti :: operator double() {

    return this->sumaJucata;

}*/

//setter nume
void Clienti::setNume(char* nume) {

    if (this->nume != NULL)delete[]this->nume;

    this->nume = new char[strlen(nume) + 1];

    strcpy(this->nume, nume);

}

//getter nume
const char* Clienti::getNume() {

    return nume;

}

//setter sumaJucata
void Clienti::setsumaJucata(double sumaJucata) {

    this->sumaJucata = sumaJucata;

}
//getter sumaJucata
double Clienti::getsumaJucata() {

    return sumaJucata;

}

//setter profit
void Clienti::setProfit(double profit) {

    this->profit = profit;

}

//getter profit
double Clienti::getProfit() {

    return profit;

}

//setter pierderi
void Clienti::setPierderi(double pierderi) {
    this->pierderi = pierderi;
}

//getter pierderi
double Clienti::getPierderi() {
    return pierderi;
}

//setter ultimelePariuri
void Clienti::setUltimelePariuri(int* ultimelePariuri) {

    if (this->ultimelePariuri != NULL)delete[]this->ultimelePariuri;

    this->ultimelePariuri = new int[5];

    for (int i = 0;i < 5;i++)
        this->ultimelePariuri[i] = ultimelePariuri[i];

}

const int* Clienti::getUltimelePariuri() {

    return this->ultimelePariuri;

}

//getter id
const int Clienti::getId() {

    return id;
}

//distributivitate +
Clienti operator+(double suma, Clienti obj) {

    obj.sumaJucata = obj.sumaJucata + suma;
    return obj;
}

//distributivitate -
Clienti operator-(double suma, Clienti obj) {
    obj.sumaJucata = obj.sumaJucata - suma;
    return obj;
}

//suprascriere indexare "[]"
int Clienti::operator[](int index) {

    if (index >= 0 and index < 5)
        return this->ultimelePariuri[index];

    throw runtime_error(" Indexul este invalid!");

}

//initializare static int
int Clienti::nrClienti = 0;

//suprascriere ">>" Clienti
istream& operator>>(istream& in, Clienti& obj)
{
    char aux[100];
    if (obj.nume != NULL)delete[]obj.nume;

    cout << " Introduceti numele clientului: ";
    
    in.get();
    in.getline(aux, 100);

    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);

    cout << " Introduceti suma jucata: ";
    in >> obj.sumaJucata;

    cout << " Introduceti profitul clientului: ";
    in >> obj.profit;

    if (!obj.profit)
    {
        cout << " Introduceti pierderile clientului: ";
        in >> obj.pierderi;
    }
    else obj.pierderi = 0;

    while (obj.pierderi > 0 and obj.profit > 0) {

        cout << " Nu poti avea pierderi cat timp ai facut profit!\n";
        
        obj.pierderi = 0;
    }

    while (obj.pierderi > obj.sumaJucata) {

        cout << " Suma pierduta nu poate fi mai mare decat cea jucata!\n";
       
        cout << " Pierderi: ";

        in >> obj.pierderi;
    }

    cout << " Introduceti ultimele 5 pariuri ale clientului: \n\n";

    if (obj.ultimelePariuri != NULL)delete[]obj.ultimelePariuri;

    obj.ultimelePariuri = new int[5];

    for (int i = 0;i < 5;i++,cout<<'\n')
    {
        cout << " Rezultatul pariului " << i + 1 << "(1 - castigat; 0 - pierdut): ";
        
        in >> obj.ultimelePariuri[i];

    }

    in.get();
    return in;
}

//suprascriere "<<" Clienti
ostream& operator<<(ostream& out, const Clienti& obj) {

    out << '\n';
     
    out << " Numele jucatorului: " << obj.nume << '\n';

    out << " Suma jucata: " << obj.sumaJucata << "$" << '\n';

    out << " Profitul jucatorului: " << obj.profit << "$" << '\n';

    out << " Pierderile jucatorului: " << obj.pierderi << "$" << '\n';

    if(obj.ultimelePariuri!=NULL)
    { 
    out << " Ultimele 5 pariuri ale jucatorului:\n\n";
    
    for (int i = 0;i < 5;i++,out<<'\n')
    {
        out << " Pariul " << i + 1 << " a fost ";
        if (obj.ultimelePariuri[i] == 1)out << "castigat!";
        else out << "pierdut!";
    }
    }
    return out;

}
