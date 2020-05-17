#include <iostream>
#include <stdlib.h>  // fonction random
#include <time.h>   // fonction random
#include <string>
#include <windows.h>
using namespace std;

////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// Autant de 1 et de 0 sur chaque lignes / colonnes //
/////////////////////////////////////////////////////
////////////////////////////////////////////////////

bool regle1_1 (int** AdresseTableau, int DefTaille) {       //lignes
int compteur = 0;
    
    for (int i=0; i<DefTaille; i++)
    {
        if (compteur !=0)
        {
            break;
        }

        compteur = 0;                       // on réinnitialise 0 a chaque nouvelle ligne
        
        for (int j=0; j<DefTaille; j++)
        {
            if (AdresseTableau[i][j] == 1)
            {
                compteur +=1;               // compteur prend + 1 pour chaque 1 et -1 pour chaque 0
            }

            else 
            {
                compteur -=1;
            }
        }
    }

    return compteur == 0;

}

bool regle1_2 (int** AdresseTableau, int DefTaille) {       //colones
int compteur = 0;

    for (int i=0; i<DefTaille; i++)
    {
        if (compteur !=0)
        {
            break;
        }

        compteur = 0;                       // on réinnitialise 0 a chaque nouvelle colone
        
        for (int j=0; j<DefTaille; j++)
        {
            if (AdresseTableau[j][i] == 1)
            {
                compteur +=1;               // compteur prend + 1 pour chaque 1 et -1 pour chaque 0
            }

            else 
            {
                compteur -=1;
            }
        }
    }

    return compteur == 0;

}

////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// Pas plus de deux chiffres identiques côte à côte //
/////////////////////////////////////////////////////
////////////////////////////////////////////////////

bool regle2(int** AdresseTableau, int DefTaille) {

    for (int i=0; i<DefTaille; i++)
    {
        for (int j=0; j<DefTaille-2; j++)
        {
            if (AdresseTableau[i][j] == AdresseTableau[i][j+1] && AdresseTableau[i][j+1] == AdresseTableau[i][j+2])
            {
                return false;
            }  
        }
    }
    
    for (int j=0; j<DefTaille; j++)
    {
        for (int i=0; i<DefTaille-2; i++)
        {
            if (AdresseTableau[i][j] == AdresseTableau[i+1][j] && AdresseTableau[i+1][j] == AdresseTableau[i+2][j])
            {
                return false;
            }  
        }
    }

    return true;    
}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Deux lignes ou deux colonnes ne peuvent pas etre identiques //
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

bool regle3 (int** AdresseTableau, int DefTaille) {

    for (int i = 0; i  <= DefTaille-2; i++)         //lignes
    {           
        for (int j = i+1; j <= DefTaille-1; j++)
        {
            for (int k = 0; k <= DefTaille-1; k++)
            {
                if (AdresseTableau[i][k] != AdresseTableau[j][k])
                {
                    break;
                }

                else if (k == 3 && AdresseTableau[i][k] == AdresseTableau[j][k])
                {
                    return false;
                }
            }
        }
    }

    for (int i = 0; i  <= DefTaille-2; i++)         //colones
    {   
        for (int j = i+1; j <= DefTaille-1; j++)
        {
            for (int k = 0; k <= DefTaille-1; k++)
            {
                if (AdresseTableau[k][i] != AdresseTableau[k][j])
                {
                    break;
                }

                else if (k  == 3 && AdresseTableau[k][i] == AdresseTableau[k][j])
                {
                    return false;
                }
            }
        }
    } 

    return true;
}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void couleur(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int tailleTab (int *DefTaille) {

    cout<<"Choisir la taille du tableau pair, entre 4 et 16."<<"\n";
    cout<<"A partir de 6, le temps de chargement peut etre tres tres long"<<"\n";
    cin>>*DefTaille;

   /* while (*DefTaille < 4 || *DefTaille > 16 || *DefTaille % 2 != 0){  // Vérifie que l'utilisateur ait au moins un tableau 4*4
        cout<<"Nonon, re-essayez !"<<endl; 
        cin>>*DefTaille;

    }*/

    while(*DefTaille < 4 || *DefTaille > 16 || *DefTaille % 2 != 0)
    {
        cout<<"Nonon, re-essayez !"<<endl;
        cin>>*DefTaille;

    }

    return *DefTaille;

}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int** creaTableaux (int DefTaille) { 
    
    int** AdresseTableau;  //Pointeur vers l'adresse du tableaux (premierre valeur) || Pointeur de pointeur !!!

    AdresseTableau = new int *[DefTaille];    // AdresseTableau = pointeur vers la mémoire du tableau ||| *DefTaille =  nombres  de pointeurs qui renvoye vers un tableaux 
   
    for (int i = 0; i<DefTaille; i++){          // Boucle qui créé le tableau en deux dimension   
        AdresseTableau[i] = new int[DefTaille]; 
    }

    return  AdresseTableau;

} 

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void printSeparateur(int DefTaille) {
    
    couleur(12,0);

    for (int i = 0; i < DefTaille; i++){
        cout<<"+---";
    }
    cout<<"+"<<"\n";

    couleur(15,0);
}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void printTab  (int** AdresseTableau, int DefTaille) {

    for (int i = 0; i <DefTaille; i++){    //Affiche le tableaux
        
        printSeparateur(DefTaille);
        
        for (int j = 0; j <DefTaille; j++){

            couleur(12,0);
            cout<<"|  ";
            couleur(15,0);
            cout<<AdresseTableau[i][j];
        }

        couleur(12,0);
        cout<<"|"<<"\n";
        couleur(15,0);
    }

    printSeparateur(DefTaille);

}


///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void remplisTableau (int** AdresseTableau, int DefTaille) {

    srand(time(NULL));

    while(regle1_1(AdresseTableau, DefTaille)!=true || regle1_2(AdresseTableau, DefTaille)!=true || regle2(AdresseTableau, DefTaille)!=true || regle3(AdresseTableau, DefTaille)!=true)
    {
        for (int i =  0; i<DefTaille; i++)
        {
            for (int j = 0; j<DefTaille; j++)
            {
                int nombre = rand();

                if(nombre & 1)
                {
                    AdresseTableau[i][j] = 1; 
                }

                else 
                {
                    AdresseTableau[i][j] = 0;
                }
            }
        }
    }
}

void remplisTableauVide (int** AdresseTableau, int DefTaille) { //remplace par 7 tt les nombres randoms impaires

    srand(time(NULL));

    for (int i =  0; i<DefTaille; i++)
    {
        for (int j = 0; j<DefTaille; j++)
        {
            int nombre = rand();
            if(nombre>16383)
            {
                AdresseTableau[i][j] = 7; 
            }
        }
    }
}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void saisirValeur (int** AdresseTableau, int DefTaille) {
int i, j, valeur;

    cout<<"Saisir valeur ligne : "; 
    cin>>i;
    cout<<"Saisir valeur colonne : ";
    cin>>j;

    if(AdresseTableau[i][j] != 0 && AdresseTableau[i][j] != 1)
    {
        cout<<"Saisir valeur : "; 
        cin>>valeur;
        cout<<endl<<endl;
        AdresseTableau[i][j] = {valeur} ;
    }

    else 
    {
        cout<<endl;
        cout<<"Vous ne pouvez pas modifier cette casse"<<endl;
        cout<<endl<<endl;
    }

}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void verif (int** AdresseTableau, int DefTaille) {
    for (int i = 0; i <DefTaille; i++)
    {
        for (int j = 0; j <DefTaille; j++)
        {
            if(AdresseTableau[i][j] != 0 && AdresseTableau[i][j] != 1)
            {
                saisirValeur(AdresseTableau, DefTaille);
                printTab(AdresseTableau, DefTaille);
                cout<<endl<<endl;
            }
        }
    }
}
