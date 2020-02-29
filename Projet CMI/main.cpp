#include <iostream>
using namespace std;
#include "Fonctions/Tableaux.cpp"
#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl


int main()
{
    EVAL(autantDe01SurLigneColoneVARIANTE());
    return 0;
}