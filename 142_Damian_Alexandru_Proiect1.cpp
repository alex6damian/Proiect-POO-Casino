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

    throw runtime_error("Indexul este invalid!");

}

//initializare static int
int Clienti::nrClienti = 0;

//suprascriere ">>" Clienti
istream& operator>>(istream& in, Clienti& obj)
{
    char aux[100];
    if (obj.nume != NULL)delete[]obj.nume;

    cout << "Introduceti numele clientului: ";
    in.get();
    in.getline(aux, 100);
    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);

    cout << "Introduceti suma jucata: ";
    in >> obj.sumaJucata;

    cout << "Introduceti profitul clientului: ";
    in >> obj.profit;

    if (!obj.profit)
    {
        cout << "Introduceti pierderile clientului: ";
        in >> obj.pierderi;
    }
    else obj.pierderi = 0;

    while (obj.pierderi > 0 and obj.profit > 0) {

        cout << "Nu poti avea pierderi cat timp ai facut profit!\n";
        
        obj.pierderi = 0;
    }

    while (obj.pierderi > obj.sumaJucata) {

        cout << "Suma pierduta nu poate fi mai mare decat cea jucata!\n";
       
        cout << "Pierderi: ";

        in >> obj.pierderi;
    }

    cout << "Introduceti ultimele 5 pariuri ale clientului: \n";

    if (obj.ultimelePariuri != NULL)delete[]obj.ultimelePariuri;

    obj.ultimelePariuri = new int[5];

    for (int i = 0;i < 5;i++)
    {
        cout << "Rezultatul pariului " << i + 1 << "(1 - castigat; 0 - pierdut):";
        
        in >> obj.ultimelePariuri[i];

    }

    cin.get();
    return in;
}

//suprascriere "<<" Clienti
ostream& operator<<(ostream& out, const Clienti& obj) {

    out << '\n';

    out << "Numele client: " << obj.nume << '\n';

    out << "Suma jucata: " << obj.sumaJucata << "$" << '\n';

    out << "Profitul clientului: " << obj.profit << "$" << '\n';

    out << "Pierderile clientului: " << obj.pierderi << "$" << '\n';

    if(obj.ultimelePariuri!=NULL)
    { 
    out << "Ultimele 5 pariuri ale clientului:\n";
    
    for (int i = 0;i < 5;i++,out<<'\n')
    {
        out << "Pariul " << i + 1 << " a fost ";
        if (obj.ultimelePariuri[i] == 1)out << "castigat!";
        else out << "pierdut!";
    }
    }
    return out;

}


//clasa Angajati
class Angajati {

    char* nume;
    string job;
    char zona;
    float salariu, tips;

public:

    //constructor default
    Angajati();

    //constructor cu parametri
    Angajati(string job);

    Angajati(string job, float salariu, float tips);

    //constructor cu toti parametri
    Angajati(char* nume, string job, char zona, float salariu, float tips);

    //copy-constructor
    Angajati(const Angajati& obj);

    //suprascriere "="(dest+copycons)
    Angajati& operator=(const Angajati& obj);

    //suprascriere preincrementare(creste tips)
    Angajati& operator++();

    //supraincarcare postincrementare
    Angajati operator++(int);

    //predecrementare
    Angajati& operator--();

    //postdecrementare
    Angajati operator--(int);


    //suprascriere + cu un double(adauga tips)
    Angajati operator+(float suma);

    //suprascriere - cu un double(scade tips)
    Angajati operator-(float suma);

    //suprascriere + intre clase
    Angajati operator+(const Angajati& obj);

    //suprascriere operator "=="
    bool operator==(const Angajati& obj);

    //suprascriere operator ">"
    bool operator>(const Angajati& obj);

    //cast implicit
    //operator float();

    // setter nume
    void setNume(const char* n);

    // getter nume
    const char* getNume();

    // setter job
    void setJob(string& j);

    // getter job
    string getJob();

    // setter zona
    void setZona(char z);

    // getter zona
    char getZona();

    // setter salariu
    void setSalariu(float salariu);

    // getter salariu
    float getSalariu();

    // setter tips
    void setTips(float t);

    // getter tips
    float getTips();



    //destructor
    ~Angajati() {
        if (this->nume != NULL)delete[]this->nume;
        this->nume = NULL;
    }

    friend istream& operator>>(istream& in, Angajati& obj);
    friend ostream& operator<<(ostream& out, const Angajati& obj);

    friend Angajati operator+(float suma, Angajati obj);
    friend Angajati operator-(float suma, Angajati obj);

};

//constructor default
Angajati::Angajati() : job("Nescunoscut"), zona('x'), salariu(0), tips(0) {

    this->nume = new char[strlen("Necunoscut") + 1];
    strcpy(this->nume, "Necunoscut");
}

//constructor cu parametri
Angajati::Angajati(string job) : job(job), zona('x'), salariu(0), tips(0) {

    this->nume = new char[strlen("Necunoscut") + 1];
    strcpy(this->nume, "Necunoscut");
}

Angajati::Angajati(string job, float salariu, float tips) : job(job), salariu(salariu), tips(tips), zona('x') {
    this->nume = new char[strlen("Necunoscut") + 1];
    strcpy(this->nume, "Necunoscut");
}

//constructor cu toti parametri
Angajati::Angajati(char* nume, string job, char zona, float salariu, float tips)
    : job(job), zona(zona), salariu(salariu), tips(tips) {

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

}

//copy-constructor
Angajati::Angajati(const Angajati& obj) : zona(obj.zona), job(obj.job), salariu(obj.salariu), tips(obj.tips) {

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

}

//suprascriere "="(dest+copycons)
Angajati& Angajati::operator=(const Angajati& obj) {

    if (this != &obj) {
        if (this->nume != NULL)delete[]this->nume;
        this->nume = new char[strlen(obj.nume) + 1];
        strcpy(this->nume, obj.nume);
        this->job = obj.job;
        this->salariu = obj.salariu;
        this->tips = obj.tips;
        this->zona = obj.zona;

    }
    return *this;

}

//suprascriere preincrementare(creste tips)
Angajati& Angajati:: operator++() {

    this->tips = this->tips + 500;
    return *this;

}

//supraincarcare postincrementare
Angajati Angajati::operator++(int) {

    Angajati copy;
    copy = *this;
    ++(*this);
    return copy;

}

//predecrementare
Angajati& Angajati::operator--() {

    this->tips = this->tips - 500;
    return *this;

}

//postdecrementare
Angajati Angajati::operator--(int) {

    Angajati copy;
    copy = *this;
    --(*this);
    return copy;

}

//suprascriere + cu un float(adauga tips)
Angajati Angajati::operator+(float suma) {

    Angajati copy;
    copy = *this;
    copy.tips = copy.tips + suma;
    return copy;

}

//suprascriere - cu un float(scade tips)
Angajati Angajati::operator-(float suma) {

    Angajati copy;
    copy = *this;
    copy.tips = copy.tips - suma;
    return copy;

}

//comutativitate +
Angajati operator+(float suma, Angajati obj) {
    
    obj.tips = obj.tips + suma;

    return obj;

}

//comutativitate -
Angajati operator-(float suma, Angajati obj)
{
    obj.tips = obj.tips - suma;

    return obj;

}

//suprascriere + intre obiecte
Angajati Angajati::operator+(const Angajati& obj) {

    Angajati copy;
    copy = *this;

    copy.salariu += obj.salariu;
    copy.tips += obj.salariu;

    copy.job = copy.job + " si " + obj.job;

    int lungimeNoua = strlen(this->nume) + strlen(" si ") + strlen(obj.nume);
    char* aux = new char[lungimeNoua + 1];

    strcpy(aux, copy.nume);
    strcat(aux, " si ");
    strcat(aux, obj.nume);

    if (copy.nume != NULL)delete[]copy.nume;

    copy.nume = new char[lungimeNoua + 1];
    strcpy(copy.nume, aux);

    delete[]aux;
    return copy;

}

//suprascriere operator "=="
bool Angajati::operator==(const Angajati& obj) {

    return (this->job == obj.job and this->tips == obj.tips);

}

//suprascriere operator ">"
bool Angajati::operator>(const Angajati& obj) {

    return this->salariu > obj.salariu;

}

/*
//cast implicit
Angajati::operator float() {

    return this->salariu;

}*/

// Setter pentru 'nume'
void Angajati::setNume(const char* n) {

    if (nume != NULL)delete[]nume;
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);

}

// Getter pentru 'nume'
const char* Angajati::getNume() {
    return nume;
}

// Setter pentru 'job'
void Angajati::setJob(string& j) {
    job = j;
}

// Getter pentru 'job'
string Angajati::getJob() {
    return job;
}

// Setter pentru 'zona'
void Angajati::setZona(char z) {
    zona = z;
}

// Getter pentru 'zona'
char Angajati::getZona() {
    return zona;
}

// Setter pentru 'salariu'
void Angajati::setSalariu(float salariu) {

    this->salariu = salariu;

}

// Getter pentru 'salariu'
float Angajati::getSalariu() {
    return salariu;
}

// Setter pentru 'tips'
void Angajati::setTips(float t) {
    tips = t;
}

// Getter pentru 'tips'
float Angajati::getTips() {
    return tips;
}

//suprascriere >> Angajati
istream& operator>>(istream& in, Angajati& obj) {

    char aux[100]; // Buffer pentru citirea numelui

    cout << "Introduceti numele angajatului: ";
    in.get();
    in.getline(aux, 100);
    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);

    cout << "Introduceti jobul angajatului: ";
    in >> obj.job;

    cout << "Introduceti zona angajatului (un caracter): ";
    in >> obj.zona;

    cout << "Introduceti salariul angajatului: ";
    in >> obj.salariu;

    cout << "Introduceti tips-ul angajatului: ";
    in >> obj.tips;
    cout << '\n';

    return in;

}

//suprascriere << Angajati
ostream& operator<<(ostream& out, const Angajati& obj) {

    out << "Nume angajat: " << obj.nume << '\n';

    out << "Job angajat: " << obj.job << '\n';

    out << "Zona de care e responsabil: " << obj.zona << '\n';

    out << "Salariu angajat: " << obj.salariu << "$" << '\n';

    out << "Tips castigat: " << obj.tips << "$" << '\n';

    return out;

}

//clasa Jocuri
class Jocuri {

    string tip;
    Clienti* clienti;
    char zona;
    bool disponibilitate;
    int jucatori;
    double castig;

public:

    //constructor default
    Jocuri();

    //constructor cu toti param
    Jocuri(string tip, Clienti* clienti, char zona, bool disponibilitate, double castig, int jucatori);

    //constructor cu param
    Jocuri(string tip);

    Jocuri(string tip, char zona);

    //copy-constructor
    Jocuri(const Jocuri& obj);

    //operator egal(destr+copy-cons)
    Jocuri& operator=(const Jocuri& obj);

    //suprascriere ++(pre) adauga locuri
    Jocuri& operator++();

    //suprascriere ++(post)
    Jocuri operator++(int);

    //suprascriere --(pre)
    Jocuri& operator--();

    //suprascriere --(post)
    Jocuri operator--(int);

    //suprascriere + cu un double(adauga castigul)
    Jocuri operator+(double suma);

    //suprascriere - cu un double(scade din castig)
    Jocuri operator-(double suma);

    //cast implicit
    //operator double();

    //suprascriere "=="
    bool operator==(const Jocuri& obj);

    //suprascriere ">"
    bool operator>(const Jocuri& obj);

    //suprascriere + intre obiecte
    Jocuri operator+(const Jocuri& obj);

    //setter clienti
    void setClienti(Clienti* clienti);

    //getter clienti
    const Clienti* getClienti();

    //setter zona
    void setZona(char zona);

    //getter zona
    char getZona();

    //setter disponibilitate
    void setDisponibilitate(bool disponibilitate);

    //getter disponibilitate
    bool getDisponibilitate();

    //setter jucatori
    void setJucatori(int jucatori);

    // getter jucatori
    const int getJucatori();

    //setter castig
    void setCastig(double castig);

    //getter castig
    double getCastig();

    //suprascriere indexare[]
    Clienti operator[](int index);

    //functionalitate clienti
    void celMaiNorocos();

    ~Jocuri() {
        if (this->clienti != NULL)delete[]clienti;
    }

    friend istream& operator>>(istream& in, Jocuri& obj);
    friend ostream& operator<<(ostream& out, const Jocuri& obj);

    friend Jocuri operator+(double suma, Jocuri obj);
    friend Jocuri operator-(double suma, Jocuri obj);
};

//constructor default
Jocuri::Jocuri() :tip("Neunoscut"), clienti(NULL), zona('x'), castig(0), disponibilitate(true), jucatori(0) {

}

//constructor cu toti param
Jocuri::Jocuri(string tip, Clienti* clienti, char zona, bool disponibilitate, double castig, int jucatori) :tip(tip), zona(zona), disponibilitate(disponibilitate), castig(castig), jucatori(jucatori) {

    this->clienti = new Clienti[jucatori];
    

    for (int i = 0;i < this->jucatori;i++)
        this->clienti[i] = clienti[i];
    
}

//constructor cu param
Jocuri::Jocuri(string tip) :jucatori(0), zona('x'), tip(tip), clienti(NULL), castig(0), disponibilitate(true)
{
}

Jocuri::Jocuri(string tip, char zona) :tip(tip), zona(zona), jucatori(0), clienti(NULL), castig(0), disponibilitate(true) {

}

//copy-constructor
Jocuri::Jocuri(const Jocuri& obj) :tip(obj.tip), jucatori(obj.jucatori), zona(obj.zona), castig(obj.castig), disponibilitate(obj.disponibilitate) {

    this->clienti = new Clienti[this->jucatori];
    for (int i = 0;i < this->jucatori;i++)
        this->clienti[i] = obj.clienti[i];
}

//operator egal(destr+copy-cons)
Jocuri& Jocuri :: operator=(const Jocuri& obj) {

    if (this != &obj) {

        if (this->clienti != NULL)delete[]clienti;

        this->tip = obj.tip;
        this->jucatori = obj.jucatori;
        this->clienti = new Clienti[this->jucatori];
        this->zona = obj.zona;
        this->disponibilitate = obj.disponibilitate;
        this->castig = obj.castig;
        this->jucatori = obj.jucatori;

        for (int i = 0;i < this->jucatori;i++)
            this->clienti[i] = obj.clienti[i];

    }
    return *this;
}

//suprascriere ++(pre) adauga locuri
Jocuri& Jocuri ::  operator++() {

    this->jucatori++;

    Clienti* aux = new Clienti[this->jucatori];

    for (int i = 0;i < this->jucatori - 1;i++)
        aux[i] = this->clienti[i];

    Clienti nou;
    aux[this->jucatori - 1] = nou;

    if (this->clienti != NULL)delete[]this->clienti;
    this->clienti = aux;

    return *this;
}

//suprascriere ++(post)
Jocuri Jocuri :: operator++(int) {

    Jocuri copy;
    copy = *this;

    ++(*this);

    return copy;
}

//suprascriere --(pre)
Jocuri& Jocuri :: operator--() {

    this->jucatori--;
    Clienti* aux = new Clienti[this->jucatori];
    for (int i = 0;i < this->jucatori;i++)
        aux[i] = this->clienti[i];
    if (this->clienti != NULL)delete[]this->clienti;
    this->clienti = aux;
    return *this;
}

//suprascriere --(post)
Jocuri Jocuri :: operator--(int) {

    Jocuri copy;
    copy = *this;

    --(*this);

    return copy;
}

//suprascriere + cu un double(adauga castigul)
Jocuri Jocuri :: operator+(double suma) {
    
    Jocuri copy;
    copy = *this;

    copy.castig += suma;
    return copy;
}

//suprascriere - cu un double(scade din castig)
Jocuri Jocuri :: operator-(double suma)
{
    Jocuri copy;
    copy = *this;

    copy.castig -= suma;
    return copy;
}
/*
//cast implicit
Jocuri :: operator double() {

    return this->castig;

}
*/
//suprascriere "=="
bool Jocuri :: operator==(const Jocuri& obj) {
    
    return this->jucatori = obj.jucatori;

}

//suprascriere ">"
bool Jocuri::operator>(const Jocuri& obj) {
    
    return this->jucatori > obj.jucatori;

}

//suprascriere + intre obiecte
Jocuri  Jocuri::operator+(const Jocuri& obj) {

    Jocuri copy;
    copy = *this;

    copy.tip = copy.tip + " " + obj.tip;
    copy.jucatori += obj.jucatori;
    copy.castig += obj.castig;

    Clienti* aux = new Clienti[copy.jucatori];

    for (int i = 0;i < copy.jucatori - obj.jucatori;i++)
        aux[i] = copy.clienti[i];

    for (int i = copy.jucatori - obj.jucatori;i < copy.jucatori;i++)
        aux[i] = obj.clienti[i - obj.jucatori];

    if (copy.clienti != NULL)delete[]copy.clienti;
    copy.clienti = aux;

    return copy;

}

//setter clienti
void Jocuri::setClienti(Clienti* clienti) {

    this->clienti = clienti;

}

//getter clienti
const Clienti* Jocuri::getClienti() {
 
    return clienti;

}

//setter zona
void Jocuri::setZona(char zona) {
  
    this->zona = zona;

}

//getter zona
char Jocuri::getZona() {
 
    return zona;

}

//setter disponibilitate
void Jocuri::setDisponibilitate(bool disponibilitate) {

    this->disponibilitate = disponibilitate;

}

//getter disponibilitate
bool Jocuri::getDisponibilitate() {
  
    return disponibilitate;

}

//setter jucatori
void Jocuri::setJucatori(int jucatori) {

    this->jucatori = jucatori;

}

// getter jucatori
const int Jocuri::getJucatori() {

    return jucatori;

}

//setter castig
void Jocuri::setCastig(double castig) {

    this->castig = castig;

}

//getter castig
double Jocuri::getCastig() {
    
    return castig;

}

//suprascriere indexare "[]"
Clienti Jocuri :: operator[](int index)
{
    if (index >= 0 and index < this->jucatori)
        return this->clienti[index];

    throw runtime_error("Clientul cu numarul dat nu exista!");

}

//clientul cu cele mai multe maini castigate
void Jocuri::celMaiNorocos() {

    Clienti copy;
    int maxWins = 0;
    for (int i = 0;i < this->getJucatori();i++)
    {
        int wins = 0;
        
        for (int j = 0;j < 5;j++)

            if (this->clienti[i][j] == 1) wins++;

        if (wins > maxWins) {
            maxWins = wins;
            copy = this->clienti[i];
        }
    }

    cout << copy;

}

//comutativitate +
Jocuri operator+(double suma, Jocuri obj) {
    
    obj.castig += suma;
    return obj;

}

//comutativitate -
Jocuri operator-(double suma, Jocuri obj) {

    obj.castig -= suma;
    return obj;

}

//suprascriere >> Jocuri
istream& operator>>(istream& in, Jocuri& obj)
{
    if (obj.clienti != NULL)delete[]obj.clienti;

    cout << "Introduceti tipul jocului: ";
    in >> obj.tip;

    cout << "Introduceti zona (un caracter): ";
    in >> obj.zona;

    cout << "Jocul este disponibil? (1 pentru da, 0 pentru nu): ";
    in >> obj.disponibilitate;

    cout << "Introduceti numarul de jucatori: ";
    in >> obj.jucatori;

    obj.clienti = new Clienti[obj.jucatori];

    for (int i = 0;i < obj.jucatori;i++)
    {
        in >> obj.clienti[i];
        obj.castig += obj.clienti[i].getPierderi();
    }
    cout << '\n';

    return in;
}

//suprascriere << Jocuri
ostream& operator<<(ostream& out, const Jocuri& obj) {

    out << "Tipul jocului: " << obj.tip << '\n';

    out << "Zona: " << obj.zona << '\n';

    out << "Disponibilitate: " << (obj.disponibilitate ? "Da" : "Nu") << '\n';

    out << "Numarul de jucatori: " << obj.jucatori << '\n';

    if (obj.jucatori)out << '\n';

    for (int i = 0;i < obj.jucatori;i++, out << '\n')
    {
        out << "Informatiile jucatorului " << i + 1 << ":";
        out << obj.clienti[i];
    }

    out << "Castig joc: " << obj.castig << "$" << '\n';
    out << '\n';

    return out;
}


//clasa Casino
class Casino {

    string manager;
    char* adresa;
    int capacitate;
    int nrJocuri;
    Jocuri* jocuri;
    int nrAngajati;
    Angajati* angajati;
    double profit;

public:

    //constructor default
    Casino();

    //constructor toti param
    Casino(string manager, char* adresa, int capacitate, Jocuri* jocuri, Angajati* angajati, double profit, int nrJocuri, int nrAngajati);

    //constructor cu parametri
    Casino(string manager, int capacitate);

    Casino(string manager, int capacitate, double profit);

    //copy-constructor
    Casino(const Casino& obj);

    //operator egal(destr+copy-cons)
    Casino& operator=(const Casino& obj);

    //suprascriere ++(pre) adauga locuri la capacitate
    Casino& operator++();

    //suprascriere ++(post)
    Casino operator++(int);

    //suprascriere --(pre)
    Casino& operator--();

    //suprascriere --(post)
    Casino operator--(int);

    //suprascriere + cu un double(adauga profit)
    Casino operator+(double suma);

    //suprascriere - cu un double(scade din profit)
    Casino operator-(double suma);

    //cast implicit
    //operator double();

    //suprascriere "=="
    bool operator==(const Casino& obj);

    //suprascriere ">"
    bool operator>(const Casino& obj);

    //suprascriere + intre obiecte
    Casino operator+(const Casino& obj);

    //suprascriere indexare "[]"
    Jocuri operator[](int index);

    //suprascriere + intre clase
    Casino operator+(const Angajati& obj);

    //setter manager
    void setManager(string m);
    
    //getter manager
    string getManager();

    //setter adresa
    void setAdresa(char* adresa);

    //getter adresa
    const char* getAdresa();
 
    //setter capacitate
    void setCapacitate(int capacitate);
    
    //getter capacitate
    int getCapacitate();

    //setter jocuri
    void setJocuri(Jocuri* jocuri);

    //getter jocuri
    const Jocuri* getJocuri();

    //setter angajati
    void setAngajati(Angajati* angajati);

    //getter angajati
    Angajati* getAngajati();

    //setter profit
    void setProfit(double profit);
    
    //getter profit
    double getProfit();
    
    //setter nrJocuri
    void setNrJocuri(int nrJocuri);

    //getter nrJocuri
    int getNrJocuri();

    //getter nrAngajati
    int getNrAngajati();

    //setter nrAngajati
    void setNrAngajati(int nrAngajati);

    //verificare zone unde exista angajati
    void zoneOcupate();

    //functionalitate jocuri
    void bestJocuri();

    //destructor
    ~Casino() {

        if (this->adresa != NULL)delete[]this->adresa;
        this->adresa = NULL;

        if (this->jocuri != NULL)delete[]this->jocuri;
        this->jocuri = NULL;

        if (this->angajati != NULL)delete[]this->angajati;
        this->angajati = NULL;
    }

    friend Casino operator+(const Angajati& obj, Casino copy);

    friend istream& operator>>(istream& in, Casino& obj);
    friend ostream& operator<<(ostream& out, const Casino& obj);
    
    friend Casino operator+(double suma, Casino obj);
    friend Casino operator-(double suma, Casino obj);

    

};

//constructor default
Casino::Casino() :manager("Necunoscut"), capacitate(0), profit(0), nrJocuri(0),nrAngajati(0) {

    this->angajati = NULL;
    this->jocuri = NULL;
    adresa = new char[strlen("Necunoscuta") + 1];
    strcpy(adresa, "Necunoscuta");

}

//constructor toti param
Casino::Casino(string manager, char* adresa, int capacitate, Jocuri* jocuri, Angajati* angajati, double profit, 
    int nrJocuri,int nrAngajati) :manager(manager),capacitate(capacitate), jocuri(jocuri), angajati(angajati), 
    profit(profit),nrJocuri(nrJocuri),nrAngajati(nrAngajati) {

    this->adresa = new char[strlen(adresa) + 1];//alocare dinamica

    strcpy(this->adresa, adresa);


}

//constructor cu parametri
Casino::Casino(string manager, int capacitate) :manager(manager), capacitate(capacitate), nrAngajati(0),nrJocuri(0) {
    
    this->angajati = NULL; //initializare pointeri
    this->jocuri = NULL;

}

Casino::Casino(string manager, int capacitate, double profit) :manager(manager), capacitate(capacitate), 
            profit(profit), nrJocuri(0),nrAngajati(0) {

    this->angajati = NULL; //initializare pointeri
    this->jocuri = NULL;

}

//copy-constructor
Casino::Casino(const Casino& obj) :manager(obj.manager), capacitate(obj.capacitate), profit(obj.profit),
            nrAngajati(obj.nrAngajati), nrJocuri(obj.nrJocuri) {


    this->adresa = new char[strlen(obj.adresa) + 1];
    strcpy(this->adresa, obj.adresa);

    this->jocuri = new Jocuri[obj.nrJocuri];
    for (int i = 0;i < obj.nrJocuri;i++)
        this->jocuri[i] = obj.jocuri[i];

    this->angajati = new Angajati[obj.nrAngajati];
    for (int i = 0;i < obj.nrAngajati;i++)
        this->angajati[i] = obj.angajati[i];

}

//operator egal(destr+copy-cons)
Casino& Casino::operator=(const Casino& obj){
    if (this != &obj) {
        if (this->adresa != NULL)delete[]this->adresa;
        this->adresa = NULL;

        if (this->jocuri != NULL)delete[]this->jocuri;
        this->jocuri = NULL;

        if (this->angajati != NULL)delete[]this->angajati;
        this->angajati = NULL;

        this->manager = obj.manager;
        this->capacitate = obj.capacitate;
        this->profit = obj.profit;

        this->nrAngajati = obj.nrAngajati;
        this->nrJocuri = obj.nrJocuri;

        this->adresa = new char[strlen(obj.adresa) + 1];
        strcpy(this->adresa, obj.adresa);

        this->jocuri = new Jocuri[obj.nrJocuri];
        for (int i = 0;i < obj.nrJocuri;i++)
            this->jocuri[i] = obj.jocuri[i];

        this->angajati = new Angajati[obj.nrAngajati];
        for (int i = 0;i < obj.nrAngajati;i++)
            this->angajati[i] = obj.angajati[i];

    }
    return *this;
}

//suprascriere ++(pre) adauga locuri
Casino& Casino::operator++() {

    this->capacitate += 10;
    return *this;

}

//suprascriere ++(post)
Casino Casino::operator++(int) {
    
    Casino copy;
    copy = *this;
    
    ++(*this);
    
    return copy;

}

//suprascriere --(pre)
Casino& Casino::operator--() {

    this->capacitate -= 10;
    return *this;

}

Casino Casino::operator--(int) {
    
    Casino copy;
    copy = *this;

    --(*this);
    return copy;

}

//suprascriere - cu un double(adauga profit)
Casino Casino::operator+(double suma)
{
    Casino copy;
    copy = *this;

    copy.profit += suma;
    return copy;
}

//suprascriere - cu un dobule(scade profitul)
Casino Casino::operator-(double suma) {

    Casino copy;
    copy = *this;

    copy.profit -= suma;
    return copy;

}
/*
//cast implicit
Casino::operator double() {

    return this->profit;

}
*/
//suprascriere "=="
bool Casino::operator==(const Casino& obj) {

    return this->capacitate == obj.capacitate and this->manager == obj.manager and
        this->profit == obj.profit;

}

//suprascriere ">"
bool Casino::operator>(const Casino& obj) {

    return this->capacitate > obj.capacitate and this->profit > obj.profit
        and this->nrJocuri>obj.nrJocuri;

}

//suprascriere "+" intre obiecte
Casino Casino::operator+(const Casino& obj) {

    Casino copy;
    copy = *this;

    copy.capacitate += obj.capacitate;
    copy.profit += obj.profit;
    copy.manager = copy.manager + " si " + obj.manager;

    if(obj.nrJocuri)
    *(copy.jocuri) = *(copy.jocuri) + *(obj.jocuri);
    
    if(obj.nrAngajati)
    *(copy.angajati) = *(copy.angajati) + *(obj.angajati);

    return copy;
}

//suprascriere indexare "[]"
Jocuri Casino::operator[](int index) {
    
    if (index >= 0 and index < this->nrJocuri)
        return this->jocuri[index];

    throw runtime_error("Angajatul cu numarul dat nu exista!");

}

//suprascriere + intre clase
Casino Casino::operator+(const Angajati& obj) {

    Casino copy;
    copy = *this;
    copy.nrAngajati++;
    Angajati* aux = new Angajati[copy.nrAngajati];
    for (int i = 0; i < copy.nrAngajati - 1; ++i) {
        aux[i] = copy.angajati[i];
    }
    aux[copy.nrAngajati-1] = obj;

    if (copy.angajati != NULL)
        delete[]copy.angajati;
    
    copy.angajati = aux;
    
    return copy;
}

//comutativitate + intre clase (FIX IT)
Casino operator+(const Angajati& obj, Casino copy) {
    
    copy.nrAngajati++;
    
    Angajati* aux = new Angajati[copy.nrAngajati];
    
    for (int i = 0; i < copy.nrAngajati - 1; ++i) 
        aux[i] = copy.angajati[i];
    
    aux[copy.nrAngajati - 1] = obj;

    if (copy.angajati != NULL)
        delete[]copy.angajati;

    copy.angajati = aux;

    return copy;

}

//comutativitate +
Casino operator+(double suma, Casino obj) {
    
    obj.profit += suma;
    return obj;

}

//comutativitate -
Casino operator-(double suma, Casino obj) {

    obj.profit -= suma;
    return obj;

}

//setter manager
void Casino::setManager(string manager) {
    this->manager = manager;
}

//getter manager
string Casino::getManager(){
    return manager;
}

//setter adresa
void Casino::setAdresa(char* adresa) {

    if (this->adresa!=NULL) delete[] this->adresa;
    
    this->adresa = new char[strlen(adresa) + 1];
    strcpy(this->adresa, adresa);
}

//getter adresa
const char* Casino::getAdresa(){
    return adresa;
}

//setter capacitate
void Casino::setCapacitate(int capacitate) {
    this->capacitate = capacitate;
}

//getter capacitate
int Casino::getCapacitate(){
    return capacitate;
}

//setter jocuri
void Casino::setJocuri(Jocuri* jocuri) {
    this->jocuri = jocuri;
}

//getter jocuri
const Jocuri* Casino::getJocuri(){
    return jocuri;
}

//setter angajati
void Casino::setAngajati(Angajati* angajati) {
    this->angajati = angajati;
}

//getter angajati
Angajati* Casino::getAngajati(){
    return angajati;
}

//setter profit
void Casino::setProfit(double profit){

    this->profit = profit;
}

//getter profit
double Casino::getProfit(){
    return profit;
}

//setter nrJocuri
void Casino::setNrJocuri(int nrJocuri) {
    
    this->nrJocuri = nrJocuri;

}

//getter nrJocuri
int Casino::getNrJocuri() {

    return nrJocuri;

}

//getter nrAngajati
int Casino::getNrAngajati() {

    return nrAngajati;

}

//setter nrAngajati
void Casino::setNrAngajati(int nrAngajati) {

    this->nrAngajati = nrAngajati;

}

//verificare zone unde exista angajati
void Casino::zoneOcupate() {

    //cautam zone unde exista angajati
    int lista['z' - 'a' + 1] = { 0 };

    for (int i = 0;i < this->nrAngajati;i++) {
        lista[angajati[i].getZona()-'a'] = 1;
    }

    cout << " Zone unde exista angajati: ";

    for (char i = 0;i < 'z' - 'a' + 1;i++)
        if (lista[i] == 1)cout << char(i + 'a')<<" ";

    cout << '\n\n';

}

//afisarea jocurilor in functie de castigurile acestora
void Casino::bestJocuri() {

    bool ok;
    int k = 0;
    do {
        ok = 1;
        for (int i = 0;i < this->nrJocuri - k - 1;i++)
            if (this->jocuri[i].getCastig() < this->jocuri[i + 1].getCastig())
            {
                swap(this->jocuri[i], this->jocuri[i + 1]);
                ok = 0;
            }k++;
    } while (ok == 0);

    for (int i = 0;i < this->nrJocuri;i++)
        cout << this->jocuri[i];

}

//suprascriere ">>" Casino
istream& operator>>(istream& in, Casino& obj) {

    cout << "Introduceti numele managerului: ";
    in >> obj.manager;

    cout << "Introduceti adresa: ";
    char aux[256];

    in.get();
    in.getline(aux, 256);

    obj.adresa = new char[strlen(aux) + 1];
    strcpy(obj.adresa, aux);

    cout << "Introduceti numarul de jocuri: ";
    in >> obj.nrJocuri;

    if (obj.jocuri != NULL)delete[]obj.jocuri;
    obj.jocuri = new Jocuri[obj.nrJocuri];

    for (int i = 0;i < obj.nrJocuri;i++)
    {
        in >> obj.jocuri[i];
        obj.profit += obj.jocuri[i].getCastig();
    }

    
    cout << "Introduceti numarul de angajati: ";

    in >> obj.nrAngajati;

    if (obj.angajati != NULL)delete[]obj.angajati;
    obj.angajati = new Angajati[obj.nrAngajati];

    for (int i = 0;i < obj.nrAngajati;i++)
    {
        in >> obj.angajati[i];
        obj.profit -= obj.angajati[i].getSalariu();
    }
    cout << "Introduceti capacitatea: ";
    in >> obj.capacitate;

    return in;
}

//suprascriere "<<" Casino
ostream& operator<<(ostream& out, const Casino& obj) {

    out << '\n';

    out << "Manager casino: " << obj.manager << '\n';

    out << "Adresa casino: " << (obj.adresa ? obj.adresa : "Necunoscuta") << '\n';

    out << "Numarul de jocuri din Casino: " << obj.nrJocuri << '\n';
    
    out << '\n';

    for (int i = 0;i < obj.nrJocuri;i++)
    {
        out << "Informatiile jocului " << i + 1 << ": \n";
        out << obj.jocuri[i];
    }

    out << "Numarul angajatilor din Casino: " <<obj.nrAngajati<< '\n';

    out << '\n';

    for (int i = 0;i < obj.nrAngajati;i++, out<<'\n') {
        out << "Informatiile angajatului " << i + 1 << ":\n";
        out << obj.angajati[i];
    }
    
    out << "Capacitate: " << obj.capacitate << " oameni\n";

    out << "Profit casino: " << obj.profit <<'$' << '\n';

    return out;
}



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

            cout << "\n 1 Afiseaza toate informatiile \n";
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
                cout << "\n 1 Modifica salariu angajat \n";
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
                cin >> index;
                casino.erase(casino.begin() + index - 1);
                cout << " Casinoul a fost sters cu succes!\n";

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
