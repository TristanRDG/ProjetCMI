#include <iostream>
using namespace std;

//////////////
// Tableau //
////////////

int tableauTest[4][4] = 
{
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {1, 1, 0, 0},
    {1, 1, 0, 0}
} ;

///////////////////////////////////////
// Afficher tableau sur le terminal //
/////////////////////////////////////

void printTab () {
    
    for (int i = 0; i <= 3; i++)
    {
        cout<<"\n";
        for (int j = 0; j <=3; j++)
        {
            cout<<tableauTest[i][j]<<" ";
        }
    }
    cout<<endl;
}

////////////////////////////
// Saisir Valeur Tableau //
//////////////////////////

void saisirValeur () {
int i, j, valeur;

    cout<<"Saisir valeur ligne : "; 
    cin>>i;
    cout<<"Saisir valeur colonne : ";
    cin>>j;
    cout<<"Saisir valeur 0 ou 1 : "; 
    cin>>valeur;

    tableauTest[i][j] = {valeur} ;

}
