
#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Utilisateur {
protected:
    int identifiant;
    string login;

public:
    Utilisateur(int id, string l)
        : identifiant(id), login(l) {
    }

    void afficherUtilisateur() {
        cout << "Identifiant : " << identifiant << endl;
        cout << "Login : " << login << endl;
    }
};

// Classe Administrateur
class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int id, string l, string droits)
        : Utilisateur(id, l), droitsAcces(droits) {
    }

    void gererSysteme() {
        cout << "L'administrateur gere le systeme."
             << endl;
        cout << "Droits d'acces : " << droitsAcces << endl;
    }
};

// Classe Moderateur
class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int id, string l, int niveau)
        : Utilisateur(id, l), niveauModeration(niveau) {
    }

    void modererContenu() {
        cout << "Le moderateur gere les contenus."
             << endl;
        cout << "Niveau de moderation : "
             << niveauModeration << endl;
    }
};

// Classe SuperUtilisateur
class SuperUtilisateur : public Administrateur,
                         public Moderateur {
public:
    SuperUtilisateur(int id, string l, string droits, int niveau)
        : Utilisateur(id, l),
          Administrateur(id, l, droits),
          Moderateur(id, l, niveau) {
    }

    void afficherInformations() {
        Utilisateur::afficherUtilisateur();
        Administrateur::gererSysteme();
        Moderateur::modererContenu();
    }
};

// Programme principal
int main() {
    int choix;
    int id;
    string login, droits;
    int niveau;

    cout << "=== Creation d'un SuperUtilisateur ===" << endl;

    cout << "Entrez l'identifiant : ";
    cin >> id;

    cout << "Entrez le login : ";
    cin >> login;

    cout << "Entrez les droits d'acces : ";
    cin >> droits;

    cout << "Entrez le niveau de moderation : ";
    cin >> niveau;

    SuperUtilisateur su(id, login, droits, niveau);

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Afficher les informations" << endl;
        cout << "2. Gerer le systeme" << endl;
        cout << "3. Moderer le contenu" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                su.afficherInformations();
                break;

            case 2:
                su.Administrateur::gererSysteme();
                break;

            case 3:
                su.Moderateur::modererContenu();
                break;

            case 0:
                cout << "Fin du programme." << endl;
                break;

            default:
                cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    return 0;
}
