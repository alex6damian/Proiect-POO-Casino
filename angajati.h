#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>


using namespace std;

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
    void setJob(string j);

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
void Angajati::setJob(string j) {
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

    cout << " Introduceti numele angajatului: ";
    
    in.get();
    in.getline(aux, 100);
    
    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);

    cout << " Introduceti jobul angajatului: ";
    getline(in, obj.job);

    cout << " Introduceti zona angajatului (un caracter): ";
    in >> obj.zona;

    cout << " Introduceti salariul angajatului: ";
    in >> obj.salariu;

    cout << " Introduceti tips-ul angajatului: ";
    in >> obj.tips;

    cout << '\n';

    return in;

}

//suprascriere << Angajati
ostream& operator<<(ostream& out, const Angajati& obj) {

    out << " Nume angajat: " << obj.nume << '\n';

    out << " Job angajat: " << obj.job << '\n';

    out << " Zona de care e responsabil: " << obj.zona << '\n';

    out << " Salariu angajat: " << obj.salariu << "$" << '\n';

    out << " Tips castigat: " << obj.tips << "$" << '\n';

    return out;

}

