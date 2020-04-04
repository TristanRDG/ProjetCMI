#include <iostream> 
using namespace std;
#include "Fonctions/regles.cpp" 
#include "Fonctions/Tableau.cpp"
#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl



int main()
{
//      ||VARIABLE GLOBAL||      //
    int** AdresseTableau;  //Pointeur vers l'adresse du tableaux (premierre valeur) || Pointeur de pointeur !!!
    int  DefTaille;  //Taille du tableaux 
//      ||VARIABLE GLOBAL||      //

    tailleTab(&DefTaille);
    AdresseTableau = creaTableaux(DefTaille);
    remplisTableau(AdresseTableau, DefTaille);

    //TEST SI LE TABLEAUX EST JUSTE

    //EVAL(regle1_1 (AdresseTableau, DefTaille));
    //EVAL(regle1_2 (AdresseTableau, DefTaille));
    //EVAL(regle2(AdresseTableau, DefTaille));
    //EVAL(regle3 (AdresseTableau, DefTaille));
    
    //SUPRESION  DU TABLEAUX DE LA MEMOIRE

    for (int k=0; k<=DefTaille; k++){         
        delete [] AdresseTableau[k];
    }
    delete []  AdresseTableau;
    
/////////////////////////////////////////////////

    //system("pause");
    return 0;
}