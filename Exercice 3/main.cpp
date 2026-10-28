
#include <iostream>
#include <string>
using namespace std;

// Classe de base Vehicule
class Vehicule {
protected:
    string marque;
    string modele;

public:
    Vehicule(string ma, string mo)
        : marque(ma), modele(mo) {
    }
};

// Héritage virtuel
class Thermique : virtual public Vehicule {
protected:
    double consommation;

public:
    Thermique(string ma, string mo, double c)
        : Vehicule(ma, mo), consommation(c) {
    }
};

// Héritage virtuel
class Electrique : virtual public Vehicule {
protected:
    double autonomie;

public:
    Electrique(string ma, string mo, double a)
        : Vehicule(ma, mo), autonomie(a) {
    }
};

// Héritage multiple
class Hybride : public Thermique, public Electrique {
public:
    Hybride(string ma, string mo, double c, double a)
        : Vehicule(ma, mo),
          Thermique(ma, mo, c),
          Electrique(ma, mo, a) {
    }

    void afficherCaracteristiques() {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Consommation carburant : "
             << consommation << " L/100 km" << endl;
        cout << "Autonomie batterie : "
             << autonomie << " km" << endl;
    }
};

// Fonction principale
int main() {
    Hybride v1("Toyota", "Prius", 4.5, 60);

    v1.afficherCaracteristiques();

    return 0;
}
