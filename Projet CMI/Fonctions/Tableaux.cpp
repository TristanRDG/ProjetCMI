#include <iostream>
using namespace std;

    // Tableaux //

    int Tableaux[4][4] =  {
        {0, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 1, 0},
        {1, 0, 0, 1}
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

bool autantDe01SurColones (){  //Variante de la même  fonctions (FONCTIONELLE)
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
            if (Tableaux[j][i] == 0){
                NombreZero += 1;            
            }
            //cout<<"colone "<<j<<", Nombre de zero = "<<NombreZero<<"\n"; //debug
        }
    }
    return NombreZeroPremiereLigne == NombreZero;
}


bool autantDe01SurLignes (){  //Variante de la même  fonctions (FONCTIONELLE)
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