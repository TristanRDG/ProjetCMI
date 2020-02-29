#include <iostream>
using namespace std;

    // Tableaux //

    int Tableaux[4][4] =  {
        {0, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    }  ;

    //          //

void printTab (){

    for (int i = 0; i <= 3; i++){
        cout<<"\n";
        for (int j = 0; j <=3; j++){
            cout<<Tableaux[i][j]<<" ";
        }
    }

}

bool autantDe01SurLigneColone (){  //Vérifie le nombre de 0 et de 1 du tableaux (autant de 1 et de 0 sur chaque ligne et sur chaque colonne = true, false sinon)
    int NombreZero = 0;            //(PAS FONCTIONELLE)

    for (int i = 0; i <= 3; i++){  
        cout<<"ligne "<<i<<"\n"; //debug         
        if (i>1 && NombreZero != 0){
            cout<<"False";
            break;
        }
        NombreZero = -NombreZero;                     
        for (int j = 0; j <=3; j++){
            if (Tableaux[i][j] == 0){
                NombreZero += 1;            
            }
            cout<<"colone "<<j<<", Nombre de zero = "<<NombreZero<<"\n"; //debug
        }
    }
    return true;
}


bool autantDe01SurLigneColoneVARIANTE (){  //Variante de la même  fonctions (FONCTIONELLE)
    int NombreZero, NombreZeroPremiereLigne;

    for (int i = 0; i <= 3; i++){  
        //cout<<"ligne "<<i<<"\n"; //debug 
        if (i==1){
            NombreZeroPremiereLigne = NombreZero;
        }
        if (i>1 && NombreZero != NombreZeroPremiereLigne){
            break;
        }
        NombreZero = 0;
        for (int j = 0; j <=3; j++){
            if (Tableaux[i][j] == 0){
                NombreZero += 1;            
            }
            //cout<<"colone "<<j<<", Nombre de zero = "<<NombreZero<<"\n"; //debug
        }
    }
    return NombreZeroPremiereLigne == NombreZero;
}