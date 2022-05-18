#include <bits/stdc++.h>

using namespace std;

/*
 * Meniu -> Singleton ☻
 * OfertaZilei -> Factory ☻
 * Desert ☻
 * Aperitiv  * Rulada ☻
 *           * Rulori ☻
 * Aperitiv -> Template ☻*/

//OfertaZilei este o clasa implementata ca factory pattern.
class OfertaZilei {
public:
    OfertaZilei();

    static OfertaZilei *oferta(int);

    virtual int afisarePret() = 0;

    friend istream &operator>>(istream &, OfertaZilei &);
};

class Desert : public OfertaZilei {
public:
    Desert();

    Desert(const Desert &);

    Desert(string, int);

    void setTipServire(string);

    string getTipServire();

    void setPret(int);

    int afisarePret();

    friend istream &operator>>(istream &, Desert &);

    friend class OfertaZilei;

private:
    string tipServire;  //rece, cald
    int pret;
};

Desert::Desert() {}

Desert::Desert(string tip, int lei) {
    this->tipServire = tip;
    this->pret = lei;
}

void Desert::setTipServire(string tip) {
    this->tipServire = tip;
}

string Desert::getTipServire() {
    return this->tipServire;
}

void Desert::setPret(int lei) {
    this->pret = lei;
}

int Desert::afisarePret() {
    return this->pret;
}

istream &operator>>(istream &citire, Desert &desert) {
    citire >> desert.tipServire >> desert.pret;
    return citire;
}

Desert::Desert(const Desert &desert) {
    this->pret = desert.pret;
    this->tipServire = desert.tipServire;
}

//Aperitiv este clasa template. O voi folosi pentru a afisa pretul final al unor produse.
template<class T>
class Aperitiv : public OfertaZilei {
public:
    Aperitiv();

    Aperitiv(T);

    Aperitiv(const Aperitiv &) {}

    Aperitiv &operator=(const Aperitiv &a) { return *this; }

    int afisarePret();

private:
    T felDeMancare;
};


template<class T>
Aperitiv<T>::Aperitiv() : felDeMancare() {}

template<class T>
int Aperitiv<T>::afisarePret() {
    return felDeMancare.getPretKg() * felDeMancare.getGramaj();
}

template<class T>
Aperitiv<T>::Aperitiv(T mancare) : felDeMancare(mancare) {}

class Rulada {
public:
    Rulada();

    Rulada(int, int, int);

    void setGramaj(int);

    int getGramaj();

    void setPretKg(int);

    int getPretKg();

    void setCalorii(int);

    int getCalorii();

    Rulada &operator=(Rulada);

    friend istream &operator>>(istream &, Rulada &);

    friend class OfertaZilei;

private:
    int gramaj, pretKg, calorii;
};

void Rulada::setGramaj(int gr) {
    this->gramaj = gr;
}

void Rulada::setPretKg(int lei) {
    this->pretKg = lei;
}

int Rulada::getGramaj() {
    return this->gramaj;
}

int Rulada::getPretKg() {
    return this->pretKg;
}

void Rulada::setCalorii(int cantitate) {
    this->calorii = cantitate;
}

int Rulada::getCalorii() {
    return this->calorii;
}

Rulada::Rulada() {}

Rulada::Rulada(int gr, int lei, int cantitate) {
    this->gramaj = gr;
    this->pretKg = lei;
    this->calorii = cantitate;
}

Rulada &Rulada::operator=(Rulada rulada) {
    this->gramaj = rulada.gramaj;
    this->pretKg = rulada.pretKg;
    this->calorii = rulada.calorii;
    return *this;
}

istream &operator>>(istream &citire, Rulada &rulada) {
    citire >> rulada.gramaj >> rulada.pretKg >> rulada.calorii;
    return citire;
}

class Chec {
public:
    Chec();

    Chec(int, int, int);

    void setGramaj(int);

    int getGramaj();

    void setPretKg(int);

    int getPretKg();

    void setZahar(int);

    int getZahar();

    Chec &operator=(Chec);

    friend istream &operator>>(istream &, Chec &);

    friend class OfertaZilei;

private:
    int gramaj, pretKg, zahar;
};

void Chec::setGramaj(int gr) {
    this->gramaj = gr;
}

int Chec::getGramaj() {
    return this->gramaj;
}

void Chec::setPretKg(int lei) {
    this->pretKg;
}

int Chec::getPretKg() {
    return this->pretKg;
}

void Chec::setZahar(int cantitate) {
    this->zahar = cantitate;
}

int Chec::getZahar() {
    return this->zahar;
}

Chec::Chec() {}

Chec::Chec(int gr, int lei, int cantitate) {
    this->zahar = cantitate;
}

Chec &Chec::operator=(Chec chec) {
    this->gramaj = chec.gramaj;
    this->pretKg = chec.pretKg;
    this->zahar = chec.zahar;
    return *this;
}

istream &operator>>(istream &citire, Chec &chec) {
    citire >> chec.gramaj >> chec.pretKg >> chec.zahar;
    return citire;
}

OfertaZilei *OfertaZilei::oferta(int optiune) {
    if (optiune == 1) {
        Chec chec;
        cout << "Introduceti, in ordine, gramajul, pret per kg si cantitatea de zahar.\n";
        cin >> chec;
        return new Aperitiv<Chec>(chec);
    } else if (optiune == 2) {
        Rulada rulada;
        cout << "Introduceti, in ordine, gramajul, pret per kg si numarul de calorii.\n";
        cin >> rulada;
        return new Aperitiv<Rulada>(rulada);
    } else {
        Desert desert;
        cout << "Introduceti, in ordine, tipul de servire si pretul acestuia.\n";
        cin >> desert;
        return new Desert(desert);
    }
}


OfertaZilei::OfertaZilei() {

}

istream &operator>>(istream &citire, OfertaZilei &ofertaZilei) {
    citire >> ofertaZilei;
    return citire;
}

// Meniul este implementat ca singleton.
class Meniu {
public:
    static Meniu *generareUnic();

    void start();

    void cos();

private:
    static Meniu *unicitate;

    Meniu();
};

Meniu::Meniu() {}

Meniu *Meniu::generareUnic() {
    if (unicitate == 0) {

        unicitate = new Meniu;
    }
    return unicitate;
}

Meniu *Meniu::unicitate = nullptr;

void Meniu::start() {
    vector<OfertaZilei *> comanda;
    bool meniu1 = true, meniu2;
    int optiune1, optiune2, index, total, pret;
    while (meniu1) {
        cout << "Alegeti o optiune:\n1 - Catalog produse\n2 - Cos de Cumparaturi\n3 - Inchide sesiunea\n";
        cin >> optiune1;
        if (optiune1 == 1) {
            meniu2 = true;
            while (meniu2) {
                cout << "Alegeti un produs:\n1 - Chec\n2 - Rulada\n3 - Desert\n4 - Pagina anterioara\n";
                cin >> optiune2;
                if (optiune2 >= 1 and optiune2 <= 3) {
                    comanda.push_back(OfertaZilei::oferta(optiune2));
                } else {
                    if (optiune2 == 4)
                        meniu2 = false;
                    else cout << "Optiune invalida\n";
                }
            }
        } else if (optiune1 == 2) {
            cos();
            total = 0;
            for (index = 0; index < comanda.size(); index += 1) {
                pret = comanda[index]->afisarePret();
                total += pret;
                cout << index + 1 << " : " << pret
                     << (pret == 0 or ((pret % 100) < 20 and (pret % 100 != 0)) ? " lei\n" : " de lei\n");
            }
            cout << "Total de plata: " << total
                 << (total == 0 or ((total % 100) < 20 and (total % 100 != 0)) ? " lei\n" : " de lei\n");
        } else if (optiune1 == 3) {
            cout << "La revedere!\n";
            meniu1 = false;
        } else
            cout << "Optiune invalida\n";
    }
}

void Meniu::cos() {
    cout << " _        ,\n"
            "(_\\______/________\n"
            "   \\-|-|/|-|-|-|-|/\n"
            "    \\==/-|-|-|-|-/\n"
            "     \\/|-|-|-|,-'\n"
            "      \\--|-'''\n"
            "       \\_j________\n"
            "       (_)     (_)\n";
}

int main() {
    Meniu *m1 = m1->generareUnic();
    m1->start();
    return 0;
}