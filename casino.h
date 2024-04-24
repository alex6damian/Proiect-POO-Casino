#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>


using namespace std;

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
    void setAdresa(const char* adresa);

    //getter adresa
    const char* getAdresa();
 
    //setter capacitate
    void setCapacitate(int capacitate);
    
    //getter capacitate
    int getCapacitate();

    //setter jocuri
    void setJocuri( Jocuri* jocuri);

    //getter jocuri
    const Jocuri* getJocuri();

    //setter angajati
    void setAngajati( Angajati* angajati);

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

    for (int i = 0; i < copy.nrAngajati - 1; ++i) 
        aux[i] = copy.angajati[i];
    
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
void Casino::setAdresa(const char* adresa) {

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

    if (this->jocuri != NULL)delete[]this->jocuri;

    this->jocuri = jocuri;

}

//getter jocuri
const Jocuri* Casino::getJocuri(){

    return jocuri;

}

//setter angajati
void Casino::setAngajati(Angajati* angajati) {

    if (this->angajati!=NULL)delete[]this->angajati;

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

    for (int i = 0;i < this->nrAngajati;i++) 
        lista[angajati[i].getZona()-'a'] = 1;
    

    cout << " \n\nZone unde exista angajati: ";

    for (char i = 0;i < 'z' - 'a' + 1;i++)
        if (lista[i] == 1)cout << char(i + 97)<<" ";
    
    
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

    cout << " Introduceti numele managerului: ";
    in.get();
    getline(in, obj.manager);

    cout << " Introduceti adresa: ";
    char aux[256];

    in.getline(aux, 256);

    obj.adresa = new char[strlen(aux) + 1];
    strcpy(obj.adresa, aux);

    cout << " Introduceti numarul de jocuri: ";
    in >> obj.nrJocuri;

    cout << '\n';

    if (obj.jocuri != NULL)delete[]obj.jocuri;
    obj.jocuri = new Jocuri[obj.nrJocuri];

    for (int i = 0;i < obj.nrJocuri;i++)
    {
        in >> obj.jocuri[i];
        obj.profit += obj.jocuri[i].getCastig();
    }

    
    cout << " Introduceti numarul de angajati: ";

    in >> obj.nrAngajati;

    cout << '\n';

    if (obj.angajati != NULL)delete[]obj.angajati;
    obj.angajati = new Angajati[obj.nrAngajati];

    for (int i = 0;i < obj.nrAngajati;i++)
    {
        in >> obj.angajati[i];
        obj.profit -= obj.angajati[i].getSalariu();
    }
    cout << " Introduceti capacitatea: ";
    in >> obj.capacitate;

    return in;
}

//suprascriere "<<" Casino
ostream& operator<<(ostream& out, const Casino& obj) {

    out << '\n';

    out << " Manager casino: " << obj.manager << '\n';

    out << " Adresa casino: " << (obj.adresa ? obj.adresa : "Necunoscuta") << '\n';

    out << " Numarul de jocuri din Casino: " << obj.nrJocuri << '\n';
    
    out << '\n';

    for (int i = 0;i < obj.nrJocuri;i++)
    {
        out << " Informatiile jocului " << i + 1 << ": \n";
        out << obj.jocuri[i];
    }

    out << " Numarul angajatilor din Casino: " <<obj.nrAngajati<< '\n';

    out << '\n';

    for (int i = 0;i < obj.nrAngajati;i++, out<<'\n') {
        out << " Informatiile angajatului " << i + 1 << ":\n";
        out << obj.angajati[i];
    }
    
    out << " Capacitate: " << obj.capacitate << " oameni\n";

    out << " Profit casino: " << obj.profit <<'$' << '\n';

    return out;
}