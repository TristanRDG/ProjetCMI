#include <iostream>
using namespace std;
#include "Fonctions/Tableaux.cpp"
#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl


int main()
{
    EVAL(autantDe01SurColones());
    EVAL(autantDe01SurLignes());
    return 0;
}