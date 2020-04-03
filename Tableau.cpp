#include <iostream>
#include <stdlib.h>  ///fonction random///
#include <time.h>   ///fonction random///
using namespace std;
int  DefTaille;  //Taille du tableaux ||VARIABLE GLOBAL||

                                                        /*
                                                            Dans MAIN : 
                                                                tailleTab(&DefTaille);  -> définire la taille du tableaux
                                                                remplisTableaux(creaTableaux(DefTaille), DefTaille);  -> crée et affiche le tableaux
                                                        */

int tailleTab (int *DefTaille){

    cout<<"pour un tableaux en 4x4 taper 1,"<<"\n"<<"Pour un tableaux en 6x6 taper 2."<<"\n"; //TEMPORAIRE, Demande a l'uttilisateur la taille du tableaux qu'il souhaite
    cin>>*DefTaille;
    while (*DefTaille >2 || *DefTaille < 1){  //Vérifie la réponse de l'utilisateur
        cout<<"Valeurs éronné recomencer "<<"\n"; 
        cin>>*DefTaille;

    }
    if (*DefTaille == 1){   //en fonction de la réponse de l'utilisateur DefTaille prend la valeurs choisis
        *DefTaille = 4;
    }
    else {
        *DefTaille = 6;
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
    for (int k=0; k<=DefTaille; k++){         //supresion du  tableau de la mémoire
        delete [] AdresseTableau[k];
    }
    delete []  AdresseTableau;
}

//////////////////////////////////////

void remplisTableaux (int** AdresseTableau, int DefTaille){
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
                }
                else if (compteur > 0){
                    AdresseTableau[i][j] = 0;
                }
                else{
                    AdresseTableau[i][j] = 1;
                }
            }
        }
    }

    printTab(AdresseTableau, DefTaille);  //print le tableaux
}

