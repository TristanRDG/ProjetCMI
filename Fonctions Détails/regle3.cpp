bool regle3 (int** AdresseTableau, int DefTaille){
    int erreur3 = 0;

    for (int i = 0; i  <= DefTaille-2; i++){           ///Lignes///j < (4*4 - ((i+1)*4))-1///
        cout<<"i = "<<i<<"\n";

        for (int j = i+1; j <= DefTaille-1; j++){
            cout<<" j = "<<j<<"\n";

            for (int k = 0; k <= DefTaille-1; k++){
                cout<<"  k = "<<k<<"\n";
                if (AdresseTableau[i][k] != AdresseTableau[j][k]){
                    cout<<"BREAK!"<<"\n";
                    break;
                }
                else if (k == 3 && AdresseTableau[i][k] == AdresseTableau[j][k]){
                    return false;
                    cout<<"Erreur "<<"\n";
                }
            }
        }
    }


        for (int i = 0; i  <= DefTaille-2; i++){           ///colones///
        cout<<"i = "<<i<<"\n";

        for (int j = i+1; j <= DefTaille-1; j++){
            cout<<" j = "<<j<<"\n";

            for (int k = 0; k <= DefTaille-1; k++){
                cout<<"  k = "<<k<<"\n";
                if (AdresseTableau[k][i] != AdresseTableau[k][j]){
                    cout<<"BREAK!"<<"\n";
                    break;
                }
                else if (k  == 3 && AdresseTableau[k][i] == AdresseTableau[k][j]){
                    return false;
                    cout<<"Erreur "<<"\n";
                }
            }
        }
    }
            
    return true;
}
