#include <iostream>
using namespace std;
#include "fonctions.cpp"
#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl


int main()
{
    cout<<endl;
    cout<<endl;
    cout<<"Debut de la partie :"<<endl;

    // choix taille tableau
    // création tableau semi-rempli

    printTab();
    
    cout<<endl;
    cout<<"Attention ! La premiere ligne/colonne commence a 0"<<endl<<endl;

    saisirValeur();
    
    while(regle1()!=true || regle2()!=true || regle3()!=true)
    {
        regle1();
        cout<<endl;
        regle2();
        cout<<endl;
        regle3();
        cout<<endl;
        saisirValeur();
    }

    cout<<endl<<"VICTOOOOOOOOOIRE ! BIEN JOUE !"<<endl;
    system("pause");
    return 0;
}
