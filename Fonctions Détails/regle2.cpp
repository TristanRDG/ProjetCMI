void regle2() {
int erreurR2=0;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<2; j++)
        {
            if (tableauTest[i][j] == tableauTest[i][j+1] && tableauTest[i][j+1] == tableauTest[i][j+2])
            {
                erreurR2++;
            }  
        }
    }
    
    for (int j=0; j<4; j++)
    {
        for (int i=0; i<2; i++)
        {
            if (tableauTest[i][j] == tableauTest[i+1][j] && tableauTest[i+1][j] == tableauTest[i+2][j])
            {
                erreurR2++;
            }  
        }
    }

    cout<<"Regle 2 : Pas plus de deux chiffres cote a cote"<<endl;
   
    if (erreurR2==0 || erreurR2==1)
        cout<<"Vous avez fait "<<erreurR2<<" erreur"<<endl;
    else
        cout<<"Vous avez fait "<<erreurR2<<" erreurs"<<endl;
}
