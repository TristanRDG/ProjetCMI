#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////

// Tableaux //
int Tableaux[4][4] =
    {
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {1, 1, 0, 1}
    } ;
////////////////////////////////////////////////////////////////////////

// Afficher tableau sur le terminal //
void printTab ()
{
    for (int i = 0; i <= 3; i++)
    {
        cout<<"\n";
        for (int j = 0; j <=3; j++)
        {
            cout<<Tableaux[i][j]<<" ";
        }
    }
}
////////////////////////////////////////////////////////////////////////

// Saisir Valeur Tableau //
void saisirvaleur () 
{
    int valeur, i, j;

    cout<<"Saisir valeur ligne : "; 
    cin>>i;
    cout<<"Saisir valeur colonne : ";
    cin>>j;
    cout<<"Saisir valeur 0 ou 1 : "; 
    cin>>valeur;

    Tableaux[i][j] = {valeur} ;

    printTab();
}
////////////////////////////////////////////////////////////////////////

// Pas plus de deux chiffres identiques côte à côte //
void max2cac () 
{
int erreur=0;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<2; j++)
        {
            if (Tableaux[i][j] == Tableaux[i][j+1] && Tableaux[i][j+1] == Tableaux[i][j+2])
            {
                erreur++;
            }  
        }
    }
    
    for (int j=0; j<4; j++)
    {
        for (int i=0; i<2; i++)
        {
            if (Tableaux[i][j] == Tableaux[i+1][j] && Tableaux[i+1][j] == Tableaux[i+2][j])
            {
                erreur++;
            }  
        }
    }

    if (erreur==0)
        cout<<"VICTOIRE CHACAL"<< endl;
    if (erreur==1)
        cout<<"Vous avez fait "<<erreur<<" erreur"<< endl;
    else
        cout<<"Vous avez fait "<<erreur<<" erreurs"<< endl;
    while (erreur!=0)
    {
        saisirvaleur();
        max2cac();
        break;
    }
}
////////////////////////////////////////////////////////////////////////

// Autant de 0 et de 1 sur les colonnes //
bool autantDe01SurColones (){
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

// Autant de 0 et de 1 sur les lignes //
bool autantDe01SurLignes (){
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
////////////////////////////////////////////////////////////////////////
