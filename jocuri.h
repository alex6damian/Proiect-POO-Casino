#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;

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

    cout << " Introduceti tipul jocului: ";
   
    in.get();
    getline(in, obj.tip);

    cout << " Introduceti zona (un caracter): ";
    in >> obj.zona;

    cout << " Jocul este disponibil? (1 pentru da, 0 pentru nu): ";
    in >> obj.disponibilitate;

    cout << " Introduceti numarul de jucatori: ";
    in >> obj.jucatori;

    cout << '\n';

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

    out << " Tipul jocului: " << obj.tip << '\n';

    out << " Zona: " << obj.zona << '\n';
     
    out << " Disponibilitate: " << (obj.disponibilitate ? "Da" : "Nu") << '\n';

    out << " Numarul de jucatori: " << obj.jucatori << '\n';

    if (obj.jucatori)out << '\n';

    for (int i = 0;i < obj.jucatori;i++, out << '\n')
    {
        out << " Informatiile jucatorului " << i + 1 << ":";
        out << obj.clienti[i];
    }

    out << " Castig joc: " << obj.castig << "$" << '\n';
    out << '\n';

    return out;
}
