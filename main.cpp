#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C:\Users\leo31\Documents\ProjetCMI\fonctions.cpp"

using namespace std;
#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl

int main() {

    cout<<"Debut de la partie :"<<endl;
    
    int** AdresseTableau;  // Pointeur vers l'adresse du tableaux (premierre valeur) || Pointeur de pointeur
    int  DefTaille;  // Taille du tableau
    int compteur = 0;
    
    clock_t temps;
    srand(time(NULL));

    tailleTab(&DefTaille);
    cout<<endl<<endl;
    AdresseTableau = creaTableaux(DefTaille);
    remplisTableau(AdresseTableau, DefTaille);
    remplisTableauVide(AdresseTableau, DefTaille);
    printTab(AdresseTableau, DefTaille);

    cout<<endl<<endl;
    cout<<"Attention ! La premiere ligne/colonne commence a 0 " <<endl;
    cout<<"Pour ne pas se tromper :"<<endl;
    cout<<"- Regarder le nombre de case pleine au dessus de celle desiree pour les lignes" <<endl;
    cout<<"- Et sur la gauche pour les colonnes"<<endl<<endl;
    cout<<"Vous pouvez saisir n'importe quelle valeur, mais lorsque 0 ou 1 sont saisis, c'est definitif !"<<endl<<endl;
   

    while(regle1_1(AdresseTableau, DefTaille)!=true || regle1_2(AdresseTableau, DefTaille)!=true || regle2(AdresseTableau, DefTaille)!=true || regle3(AdresseTableau, DefTaille)!=true)
    {
       if(compteur > 8)
        {
            cout<<"Vous n'y arrivez pas ? Vous pouvez recommencer avec une nouvelle grille en saisisant une lettre" <<endl<<endl;
        }

        saisirValeur(AdresseTableau, DefTaille);
        printTab(AdresseTableau, DefTaille);
        cout<<endl<<endl;
        compteur++;

    }

    verif(AdresseTableau, DefTaille);
    cout<<endl;
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;
    cout<<"!!! !!!  VICTOIRE  !!! !!!"<<endl<<endl;
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;

    temps = clock();
    cout<<"Vous avez mis " << (double) temps/CLOCKS_PER_SEC << " seconndes"<<endl;
    cout<<"Pour " << compteur << " etapes"<<endl;


    if((double) temps/CLOCKS_PER_SEC < 60)
    {
        cout<<"INCROYABLE !"<<endl<<endl;
    }
    if((double) temps/CLOCKS_PER_SEC < 90 && (double) temps/CLOCKS_PER_SEC > 60)
    {
        cout<<"TRES BIEN !"<<endl<<endl;
    }
    if((double) temps/CLOCKS_PER_SEC < 120 && (double) temps/CLOCKS_PER_SEC > 90)
    {
        cout<<"BIEN !"<<endl<<endl;
    }
    if((double) temps/CLOCKS_PER_SEC > 120)
    {
        cout<<"TU PEUX MIEUX FAIRE !"<<endl<<endl;
    }
    
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
