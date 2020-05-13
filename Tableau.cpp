#include <iostream>
#include <stdlib.h>  ///fonction random///
#include <time.h>   ///fonction random///
using namespace std;

                                                        /*
                                                            Dans MAIN : 
                                                                tailleTab(&DefTaille);  -> définire la taille du tableaux
                                                                remplisTableaux(creaTableaux(DefTaille), DefTaille);  -> crée et affiche le tableaux
                                                        */

int tailleTab (int *DefTaille){

    cout<<"Choisir la taille du tableau, au moins 4, et pair."<<"\n";
    cin>>*DefTaille;

    while (*DefTaille < 4 || *DefTaille % 2 != 0){  // Vérifie que l'utilisateur ait au moins un tableau 4*4
        cout<<"Valeur éronné"<<"\n"; 
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

void printSeparateur(int DefTaille){

    for (int i = 0; i < DefTaille; i++){
        cout<<"+---";
    }
    cout<<"+"<<"\n";
}

//////////////////////////////////////

void printTab  (int** AdresseTableau, int DefTaille){

    for (int i = 0; i <DefTaille; i++){    //Affiche le tableaux
        
        printSeparateur(DefTaille);
        
        for (int j = 0; j <DefTaille; j++){

            cout<<"|  "<<AdresseTableau[i][j];
        }
        cout<<"|"<<"\n";
    }
    printSeparateur(DefTaille);
}


//////////////////////////////////////

/*void remplisTableau (int** AdresseTableau, int DefTaille){
    int CompteurLigne;
    int CompteurColone;
    srand (time(NULL));

     for (int i=0; i <DefTaille; i++){      // Remplis le tableaux  
        CompteurLigne = 0;
        for (int  j=0; j <DefTaille; j++){ 

            CompteurColone = 0;

            for(int k=0; k<i; k++){
                if (AdresseTableau[k][j] == 0){
                    CompteurColone -= 1;
                }
                else{
                    CompteurColone += 1;
                }
                }

            if (j>1 && AdresseTableau[i][j-1] == AdresseTableau[i][j-2]){  //colones : pas + de  deux chifres égaux côte à côte
                if (AdresseTableau[i][j-1] == 0){
                    AdresseTableau[i][j] = 1;
                    CompteurLigne +=1;
                }
                else{
                    AdresseTableau[i][j] = 0;
                    CompteurLigne -=1;
                }
            }
            else if (i>1 && AdresseTableau[i-1][j] == AdresseTableau[i-2][j]){  //lignes : pas + de  deux chifres égaux côte à côte
                if (AdresseTableau[i-1][j] == 0){
                    AdresseTableau[i][j] = 1;
                    CompteurLigne +=1;
                }
                else{
                    AdresseTableau[i][j] = 0;
                    CompteurLigne -=1;
                }
            }
            else{
                if (CompteurColone == 0 && CompteurLigne == 0 || j<(DefTaille/2)-1 &&  i<(DefTaille/2)-1){
                    //AdresseTableau[i][j] = rand() %2;
                    AdresseTableau[i][j] = 0;
                    if (AdresseTableau[i][j] = 1){
                        CompteurLigne +=1;
                    }
                    else{
                        CompteurLigne-=1;
                    }
                }
                else if (CompteurLigne > 0 || CompteurColone > 0){
                    AdresseTableau[i][j] = 0;
                    CompteurLigne -=1;
                }
                else{
                    AdresseTableau[i][j] = 1;
                    CompteurLigne +=1;
                }
            }
        }
    }
    printTab(AdresseTableau, DefTaille);  //print le tableaux
}*/

void remplisTableau (int** AdresseTableau, int DefTaille){
    int CompteurLigne;
    int CompteurColone;

    for (int i =  0; i<DefTaille; i++){
        CompteurColone  = 0;
        for (int j = 0; j<DefTaille; j++){
            CompteurLigne = 0;
            if (CompteurColone == 0 && CompteurLigne == 0){
                AdresseTableau[i][j] = rand() %2;
                if (AdresseTableau[i][j] = 1){
                    //CompteurLigne +=1;
                }
                else{
                    //CompteurLigne-=1;
                }
            }
        }

    }


}

