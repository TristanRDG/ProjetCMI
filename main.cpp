#include <iostream>
using namespace std;
#include "Fonctions/Tableaux.cpp"
#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl


int main()
{
    printTab();
    EVAL(autantDe01SurColones());
    EVAL(autantDe01SurLignes());
    max2cac();
    return 0;
}
