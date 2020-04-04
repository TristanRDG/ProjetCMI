#include <iostream>
using namespace std;

#include "C:\Users\leo31\Documents\ProjetCMI\regles.cpp"
#include "C:\Users\leo31\Documents\ProjetCMI\tableau.cpp"

#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl

int main() {

    cout<<endl;
    cout<<endl;
    cout<<"Debut de la partie :"<<endl;


    int** AdresseTableau;  // Pointeur vers l'adresse du tableaux (premierre valeur) || Pointeur de pointeur
    int  DefTaille;  // Taille du tableau


    tailleTab(&DefTaille);
    AdresseTableau = creaTableaux(DefTaille);
    remplisTableau(AdresseTableau, DefTaille);

    cout<<endl<<endl;
    cout<<"Attention ! La premiere ligne/colonne commence a 0, la deuxieme a 1 etc..."<<endl<<endl;

    while(regle1_1(AdresseTableau, DefTaille)!=true || regle1_2(AdresseTableau, DefTaille)!=true || regle2(AdresseTableau, DefTaille)!=true || regle3(AdresseTableau, DefTaille)!=true)
    {
        saisirValeur(AdresseTableau, DefTaille);
        printTab(AdresseTableau, DefTaille);
        cout<<endl<<endl;
    }

    cout<<"VICTOIRE !"<<endl;
    
    //SUPRESION  DU TABLEAUX DE LA MEMOIRE
        for (int k=0; k<=DefTaille; k++)
        {         
            delete [] AdresseTableau[k];
        }
        delete []  AdresseTableau;
    //////////////////////////////////////
    
    system("pause");
    return 0;
}
