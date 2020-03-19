void regle1() {
int erreurR11(0), erreurR12(0);

    for (int i=0; i<4; i++)
    {
        if (erreurR11 != 0)
        {
            break;
        }
        
        erreurR11 = 0;                           //on réinnitialise 0 a chaque nouvelle ligne/colone
        
        for (int j=0; j<4; j++)
        {
            if (tableauTest[i][j] == 0)         //compteur prend + 1 pour chaque 0 et -1 pour chaque 1
            {
                erreurR11++;               
            }
            
            else 
            {
                erreurR11--;
            }
        }
    }

    for (int i=0; i<4; i++)
    {
        if (erreurR12 !=0)
        {
            break;
        }

        erreurR12 = 0;                       //on réinnitialise 0 a chaque nouvelle ligne/colone
        
        for (int j=0; j<4; j++)
        {
            if (tableauTest[j][i] == 0)
            {
                erreurR12++;               //compteur prend + 1 pour chaque 0 et -1 pour chaque 1
            }

            else {
                erreurR12--;
            }
        }
    }

    cout<<"Regle 1 : Autant de 1 et de 0 sur chaque lignes/colonnes"<<endl;

    if (erreurR11==0 || erreurR12==0)
        cout<<"Vous n'avez pas fait d'erreur"<<endl;
    else
        cout<<"Vous avez fait des erreurs"<<endl;
}
