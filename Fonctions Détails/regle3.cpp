void regle3 (){
int resultat(0), erreurR3(0);

    cout<<"Regle 3 : Deux lignes ou deux colonnes ne peuvent pas etre identiques"<<endl;
	
	for (int i=0; i<=3; i++)
    {        
        resultat = 0;

        for (int j=0; j<4; j++)
        {
            if (tableauTest[i][j] == tableauTest[i+1][j])
            {
            	resultat++;
            }
            
            if (i==0 && resultat==4)
            {
                cout<<"Lignes 0 et 1 identiques"<<endl;
                erreurR3++;
            }

            if (i==1 && resultat==4)
            {
                cout<<"Lignes 1 et 2 identiques"<<endl;
                erreurR3++;
            }

            if (i==2 && resultat==4)
            {
                cout<<"Lignes 2 et 3 identiques"<<endl;
                erreurR3++;
            }            
        }
    }

    for (int i=0; i<=2; i++)
    {        
        resultat = 0;

        for (int j=0; j<4; j++)
        {
            if (tableauTest[i][j] == tableauTest[i+2][j])
            {
            	resultat++;
            }
            
            if (i==0 && resultat==4)
            {
                cout<<"Lignes 0 et 2 identiques"<<endl;
                erreurR3++;
            }

            if (i==1 && resultat==4)
            {
                cout<<"Lignes 1 et 3 identiques"<<endl;
                erreurR3++;
            }
        }
    }

    for (int i=0; i<=1; i++)
    {        
        resultat = 0;

        for (int j=0; j<4; j++)
        {
            if (tableauTest[i][j] == tableauTest[i+3][j])
            {
            	resultat++;
            }
            
            if (i==0 && resultat==4)
            {
                cout<<"Lignes 0 et 3 identiques"<<endl;
                erreurR3++;
            }
            
        }
    }

    for (int j=0; j<=3; j++)
    {        
        resultat = 0;

        for (int i=0; i<4; i++)
        {
            if (tableauTest[i][j] == tableauTest[i][j+1])
            {
            	resultat++;
            }
            
            if (j==0 && resultat==4)
            {
                cout<<"Colonnes 0 et 1 identiques"<<endl;
                erreurR3++;
            }

            if (j==1 && resultat==4)
            {
                cout<<"Colonnes 1 et 2 identiques"<<endl;
                erreurR3++;
            }
            
            if (j==2 && resultat==4)
            {
                cout<<"Colonnes 2 et 3 identiques"<<endl;
                erreurR3++;
            } 
            
        }
    }

    for (int j=0; j<=2; j++)
    {        
        resultat = 0;

        for (int i=0; i<4; i++)
        {
            if (tableauTest[i][j] == tableauTest[i][j+2])
            {
            	resultat++;
            }
            
            if (j==0 && resultat==4)
            {
                cout<<"Colonnes 0 et 2 identiques"<<endl;
                erreurR3++;
            }

            if (j==1 && resultat==4)
            {
                cout<<"Colonnes 1 et 3 identiques"<<endl;
                erreurR3++;
            }
            
        }
    }

    for (int j=0; j<=1; j++)
    {        
        resultat = 0;

        for (int i=0; i<4; i++)
        {
            if (tableauTest[i][j] == tableauTest[i][j+3])
            {
            	resultat++;
            }
            
            if (j==0 && resultat==4)
            {
                cout<<"Colonnes 0 et 3 identiques"<<endl;
                erreurR3++;
            }   
        }
    }
  
    if (erreurR3==0 || erreurR3==1)
        cout<<"Vous avez fait "<<erreurR3<<" erreur"<<endl;
    else
        cout<<"Vous avez fait "<<erreurR3<<" erreurs"<<endl;

}
