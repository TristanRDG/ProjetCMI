#include <iostream>
using namespace std;
#include "fonctions.cpp"
#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl


int main()
{
    printTab();
    max2cac();
    return 0;
}
