#include <iostream>
using namespace std;

//////////////
// Tableau //
////////////

int tableauTest[4][4] = 
{
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {1, 1, 0, 0},
    {1, 1, 0, 0}
} ;

///////////////////////////////////////
// Afficher tableau sur le terminal //
/////////////////////////////////////

void printTab () {
    
    for (int i = 0; i <= 3; i++)
    {
        cout<<"\n";
        for (int j = 0; j <=3; j++)
        {
            cout<<tableauTest[i][j]<<" ";
        }
    }
    cout<<endl;
}

////////////////////////////
// Saisir Valeur Tableau //
//////////////////////////

void saisirValeur () {
int i, j, valeur;

    cout<<"Saisir valeur ligne : "; 
    cin>>i;
    cout<<"Saisir valeur colonne : ";
    cin>>j;
    cout<<"Saisir valeur 0 ou 1 : "; 
    cin>>valeur;

    tableauTest[i][j] = {valeur} ;

    printTab();
}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Deux lignes ou deux colonnes ne peuvent pas etre identiques //
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

bool regle3 (){
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
  
    if (erreurR3==0)
    {
        cout<<"Vous n'avez pas d'erreur"<<endl;
        return true;
    }

    if (erreurR3==1)
    {
        cout<<"Vous avez fait "<<erreurR3<<" erreur"<<endl;
        return false;
    }

    else
    {
        cout<<"Vous avez fait "<<erreurR3<<" erreurs"<<endl;
        return false;
    }

}

////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// Pas plus de deux chiffres identiques côte à côte //
/////////////////////////////////////////////////////
////////////////////////////////////////////////////

bool regle2() {
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
   
    if (erreurR2==0)
    {
        cout<<"Vous n'avez pas d'erreur"<<endl;
        return true;
    }

    if (erreurR2==1)
    {
        cout<<"Vous avez fait "<<erreurR2<<" erreur"<<endl;
        return false;
    }

    else
    {
        cout<<"Vous avez fait "<<erreurR2<<" erreurs"<<endl;
        return false;
    }
}

//////////////////////////////////////////////////////
/////////////////////////////////////////////////////
// Autant de 1 et de 0 sur chaque lignes/colonnes //
///////////////////////////////////////////////////
//////////////////////////////////////////////////

bool regle1() {
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

    cout<<endl<<"Regle 1 : Autant de 1 et de 0 sur chaque lignes/colonnes"<<endl;

    if (erreurR11==0 || erreurR12==0)
    {
        cout<<"Vous n'avez pas d'erreur"<<endl;
        return true;
    }
    else
        cout<<"Vous avez fait des erreurs"<<endl;
        return false;
}
