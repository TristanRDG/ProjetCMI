bool regle2(int** AdresseTableau, int DefTaille) {

    for (int i=0; i<DefTaille; i++)
    {
        for (int j=0; j<DefTaille-2; j++)
        {
            if (AdresseTableau[i][j] == AdresseTableau[i][j+1] && AdresseTableau[i][j+1] == AdresseTableau[i][j+2])
            {
                return false;
            }  
        }
    }
    
    for (int j=0; j<DefTaille; j++)
    {
        for (int i=0; i<DefTaille-2; i++)
        {
            if (AdresseTableau[i][j] == AdresseTableau[i+1][j] && AdresseTableau[i+1][j] == AdresseTableau[i+2][j])
            {
                return false;
            }  
        }
    }

    return true;    
}
