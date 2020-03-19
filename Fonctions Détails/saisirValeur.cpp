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
