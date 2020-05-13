#include <iostream>
#include <stdlib.h>  ///fonction random///
#include <time.h>   ///fonction random///
using namespace std;

int tailleTab (int *DefTaille){

    cout<<"Choisir la taille du tableau, au moins 4"<<"\n";
    cin>>*DefTaille;

    while (*DefTaille < 4){  // Vérifie que l'utilisateur ait au moins un tableau 4*4
        cout<<"Valeur trop faible"<<"\n"; 
        cin>>*DefTaille;

    }
   
    return *DefTaille;
}

//////////////////////////////////////

int** creaTableaux (int DefTaille){ 
    
    int** AdresseTableau;  //Pointeur vers l'adresse du tableaux (premierre valeur) || Pointeur de pointeur !!!

    AdresseTableau = new int *[DefTaille];    // AdresseTableau = pointeur vers la mémoire du tableau ||| *DefTaille =  nombres  de pointeurs qui renvoye vers un tableaux 
   
    for (int i = 0; i<DefTaille; i++){          // Boucle qui créé le tableau en deux dimension   
        AdresseTableau[i] = new int[DefTaille]; 
    }

    return  AdresseTableau;

}   

//////////////////////////////////////

void printTab  (int** AdresseTableau, int DefTaille){

    for (int i = 0; i <DefTaille; i++){    //Affiche le tableaux
        cout<<"\n";
        
        for (int j = 0; j <DefTaille; j++){
            
            cout<<AdresseTableau[i][j];
            //*(*(AdresseTableau + i) + j)<<" "
        }
    }
}

//////////////////////////////////////

void remplisTableau (int** AdresseTableau, int DefTaille){
    int compteur;
    srand (time(NULL));

     for (int i=0; i <DefTaille; i++){      // Remplis le tableaux  
        compteur = 0;
        for (int  j=0; j <DefTaille; j++){ 
            if (j>1 && AdresseTableau[i][j-1] == AdresseTableau[i][j-2]){  //colones : pas + de  deux chifres égaux côte à côte
                if (AdresseTableau[i][j-1] == 0){
                    AdresseTableau[i][j] = 1;
                    compteur +=1;
                }
                else{
                    AdresseTableau[i][j] = 0;
                    compteur -=1;
                }
            }
            else if (i>1 && AdresseTableau[i-1][j] == AdresseTableau[i-2][j]){  //lignes : pas + de  deux chifres égaux côte à côte
                if (AdresseTableau[i-1][j] == 0){
                    AdresseTableau[i][j] = 1;
                    compteur +=1;
                }
                else{
                    AdresseTableau[i][j] = 0;
                    compteur -=1;
                }
            }
            else{
                if (compteur == 0){
                    AdresseTableau[i][j] = rand() %2;
                    if (AdresseTableau[i][j] = 1){
                        compteur +=1;
                    }
                    else{
                        compteur-=1;
                    }
                }
                else if (compteur > 0){
                    AdresseTableau[i][j] = 0;
                    compteur -=1;
                }
                else{
                    AdresseTableau[i][j] = 1;
                    compteur +=1;
                }
            }
        }
    }
    printTab(AdresseTableau, DefTaille);  //print le tableaux
}


////////////////////

void saisirValeur (int** AdresseTableau, int DefTaille) {
int i, j, valeur;

    cout<<"Saisir valeur ligne : "; 
    cin>>i;
    cout<<"Saisir valeur colonne : ";
    cin>>j;
    cout<<"Saisir valeur 0 ou 1 : "; 
    cin>>valeur;

    AdresseTableau[i][j] = {valeur} ;

}
