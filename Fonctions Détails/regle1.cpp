bool autant01LIGNE2 (int** AdresseTableau, int DefTaille){
    int compteur = 0;
    for (int i=0; i<DefTaille; i++){
        if (compteur !=0){
            break;
        }
        compteur = 0;                       //on réinnitialise 0 a chaque nouvelle ligne/colone
        for (int j=0; j<DefTaille; j++){
            if (AdresseTableau[i][j] == 0){
                compteur +=1;               //compteur prend + 1 pour chaque 0 et -1 pour chaque 1
            }
            else {
                compteur -=1;
            }
        }
    }
    return compteur == 0;
}

bool autant01COLLONE2 (int** AdresseTableau, int DefTaille){
    int compteur = 0;
    for (int i=0; i<DefTaille; i++){
        if (compteur !=0){
            break;
        }
        compteur = 0;                       //on réinnitialise 0 a chaque nouvelle ligne/colone
        for (int j=0; j<DefTaille; j++){
            if (AdresseTableau[j][i] == 0){
                compteur +=1;               //compteur prend + 1 pour chaque 0 et -1 pour chaque 1
            }
            else {
                compteur -=1;
            }
        }
    }
    return compteur == 0;
}
