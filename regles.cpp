#include <iostream>
using namespace std;

////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// Autant de 1 et de 0 sur chaque lignes / colonnes //
/////////////////////////////////////////////////////
////////////////////////////////////////////////////

bool regle1_1 (int** AdresseTableau, int DefTaille){  //lignes
    int compteur = 0;
    for (int i=0; i<DefTaille; i++){
        if (compteur !=0){
            break;
        }
        compteur = 0;                       // on réinnitialise 0 a chaque nouvelle ligne/colone
        for (int j=0; j<DefTaille; j++){
            //cout<<AdresseTableau[i][j]<<"\n";                          //!
            if (AdresseTableau[i][j] == 1){
                compteur +=1;               // compteur prend + 1 pour chaque 1 et -1 pour chaque 0
            }
            else {
                compteur -=1;
            }
        }
    }
    return compteur == 0;
}

bool regle1_2 (int** AdresseTableau, int DefTaille){  //colones
    int compteur = 0;
    for (int i=0; i<DefTaille; i++){
        if (compteur !=0){
            break;
        }
        compteur = 0;                       // on réinnitialise 0 a chaque nouvelle ligne/colone
        for (int j=0; j<DefTaille; j++){
            if (AdresseTableau[j][i] == 1){
                compteur +=1;               // compteur prend + 1 pour chaque 1 et -1 pour chaque 0
            }
            else {
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

bool regle3 (int** AdresseTableau, int DefTaille){

    for (int i = 0; i  <= DefTaille-2; i++){           ///Lignes///
        cout<<"i = "<<i<<"\n";

        for (int j = i+1; j <= DefTaille-1; j++){
            cout<<" j = "<<j<<"\n";

            for (int k = 0; k <= DefTaille-1; k++){
                cout<<"  k = "<<k<<"\n";
                if (AdresseTableau[i][k] != AdresseTableau[j][k]){
                    cout<<"BREAK!"<<"\n";
                    break;
                }
                else if (k == 3 && AdresseTableau[i][k] == AdresseTableau[j][k]){
                    return false;
                    cout<<"Erreur "<<"\n";
                }
            }
        }
    }

    for (int i = 0; i  <= DefTaille-2; i++){           ///colones///
        cout<<"i = "<<i<<"\n";

        for (int j = i+1; j <= DefTaille-1; j++){
            cout<<" j = "<<j<<"\n";

            for (int k = 0; k <= DefTaille-1; k++){
                cout<<"  k = "<<k<<"\n";
                if (AdresseTableau[k][i] != AdresseTableau[k][j]){
                    cout<<"BREAK!"<<"\n";
                    break;
                }
                else if (k  == 3 && AdresseTableau[k][i] == AdresseTableau[k][j]){
                    return false;
                    cout<<"Erreur "<<"\n";
                }
            }
        }
    }      
    return true;
}
