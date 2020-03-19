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
    //while(erreurR1!=0 && erreurR2!=0 && erreurR3!=0)
    //{
        saisirValeur();
        printTab();
        regle1();
        regle2();
        regle3();
        //break;
    //}
    cout<<"VICTOOOOOOOOOIRE CHACAL ! BIEN OUEJ !"<<endl;
    system("pause");
    return 0;
}
