#include <bits/stdc++.h>

using namespace std;

class Jeleu {
public:
    virtual void afisareJeleu() = 0;

    static Jeleu *Creeaza();
};

Jeleu* Jeleu::Creeaza() {
}

class Capsuni : public Jeleu {
public:
    void afisareJeleu() {
        cout << "Sunt jeleu capsuni\n";
    }
};

class Piersici : public Jeleu{
public:
    void afisareJeleu(){
        cout<<"Sunt jeleu piersici\n";
    }
};

class FructulPasiunii : public Jeleu {
public:
    void afisareJeleu() {
        cout << "Sunt jeleu fructul pasiunii\n";
    }
};

class Meniu {
public:
    void afisare();

private:
    Jeleu *jeleu;
};

void Meniu::afisare() {
    bool meniu1 = true;
    int optiune;
    while (meniu1) {
        cout << "Introduceti tipul de jeleuri pe care le vreti:\n"
                "1 - Struguri\n"
                "2 - Fructul Pasiunii\n"
                "3 - Capsuni\n"
                "4 - Exit\n";
        cin >> optiune;
        switch (optiune) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                meniu1 = false;
                break;
            default:
                cout << "Optiune invalida\n";
                break;
        }
    }
}

int main() {
    //meniu clasa
    Meniu meniu;
    meniu.afisare();
    return 0;
}