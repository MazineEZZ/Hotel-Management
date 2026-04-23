#include <stdio.h>

#define nmax 100
#define charmax 50


int main() {
    // To prevent garbage leftovers
    int chamNum[nmax] = {0}, chamType[nmax] = {0}, chamTarif[nmax] = {0}, chamEqui[nmax] = {0}, chamDispo[nmax] = {0};
    int reserNum[nmax] = {0}, reserDate[nmax] = {0}, reserSejour[nmax] = {0}, reserNbrPerso[nmax] = {0}, reserNumCham[nmax] = {0}, reserClient[nmax] = {0};
    char cliNom[nmax][charmax] = {0}, cliPrenom[nmax][charmax] = {0}, cliAdresse[nmax][charmax] = {0};
    long cliCIN[nmax] = {0}, cliCordonnes[nmax] = {0};

    int choix;
    int repeter, repeter_sec; // seconde
    int stop = 0, retour = 0;
    int correcte = 1, existe;
    int curr;

    chamNum[0] = 101;
    chamType[0] = 1;
    chamTarif[0] = 1500;
    chamEqui[0] = 1;
    chamDispo[0] = 1;

    reserNum[0] = 100;
    reserDate[0] = 2512;
    reserSejour[0] = 4;
    reserNbrPerso[0] = 2;  
    reserNumCham[0] = 101;

    // Hub
    repeter = 1;
    do {
        if (repeter) {
            printf("============MENU PRINCIPALE============\n");
            printf("Choisissez ce que vous souhaitez gérer:\n");
            printf("1 - Chambre\n");
            printf("2 - Reservation\n");
            printf("3 - Clients\n");
            printf("4 - Factures\n");
            printf("0 - Pour Quitter\n");
        }
        scanf("%d", &choix);

        switch (choix) {
            // Gestion des Chambres
            case 1:
                repeter_sec = 1;
                retour = 0;
                do {
                    if (repeter_sec) {
                        printf("============GESTION DES CHAMBRES============\n");
                        printf("Choisissez ce que vous voulez faire :\n");
                        printf("1 - Ajouter une nouvelle chambre\n");
                        printf("2 - Consulter les chambres\n");
                        printf("0 - Retourner\n");
                    }
                    scanf("%d", &choix);
    
                    switch (choix)
                    {
                    // Ajouter une nouvelle chambre / Adding
                    case 1:
                        int prix = 0;

                        curr = 0;
                        while ( curr < nmax && chamNum[curr] != 0 ) {
                            curr++;
                        }

                        int num, numExiste;
                        do {
                            numExiste = 0;
                            printf("Veuillez saisir le numéro de la chambre: \n");
                            scanf("%d", &num);

                            for (int i = 0; i < nmax; i++) {
                                if (chamNum[i] == num && chamNum[i] != 0) {
                                    numExiste = 1;
                                    printf("Erreur: La chambre %d existe déjà! Veuillez choisir un autre numéro.\n", num);
                                    break; 
                                }
                            }
                        } while (num <= 0 || num > 1000 || numExiste == 1);
                        chamNum[curr] = num;

                        int type;
                        do {
                            printf("Choisissez le type de chambre: \n");
                            printf("1 - Standard [1500 DH]\n");
                            printf("2 - Suite [2000 DH]\n");
                            printf("3 - Deluxe [3000 DH]\n");
                            scanf("%d", &type);
                        } while (type <= 0 || type > 3);
                        chamType[curr] = type;
                        
                        int choixEqui;
                        do {
                            printf("Veuillez choisir le niveau d'équipement de cette chambre: \n");
                            printf("1 - Standard (TV, Wifi Gratuit)\n");
                            printf("2 - Premium (TV, Wifi, Balcon, Mini-bar) [+150 DH]\n");
                            printf("3 - VIP (Premium + Jacuzzi + Vue sur mer) [+400 DH]\n");
                            scanf("%d", &choixEqui);
                        } while ( choixEqui <= 0 || choixEqui > 3 );
                        chamEqui[curr] = choixEqui;
                        
                        switch (type) {
                            case 1:
                                prix = 1500;
                                break;
                            case 2:
                                prix = 2000;
                                break;
                            case 3:
                                prix = 3000;
                                break;
                        }
                        switch (choixEqui) {
                            case 2:
                                prix += 150;
                                break;
                            case 3:
                                prix += 400; 
                                break;
                        }

                        chamTarif[curr] = prix;

                        int dispo;
                        do {
                            printf("Cette chambre est-elle disponible ?\n");
                            printf("1 - Oui\n");
                            printf("2 - Non\n");
                            scanf("%d", &dispo);
                        } while ( dispo <= 0 || dispo > 2);
                        chamDispo[curr] = dispo;
                        break;
                    // Voir les chambres / Viewing
                    case 2:
                        existe = 0;
                        do {
                            printf("Veuillez saisir un numéro de chambre:\n");
                            scanf("%d", &num);
    
                            for (int i = 0; i < nmax; i++) {
                                if ( chamNum[i] == num ) {
                                    curr = i;
                                    existe = 1;
                                    break;
                                }
                            }
                        } while (!existe);

                        printf("Les Informations concernant cette chambre:\n");
                        printf("Le numero de la chambre: %d\n", chamNum[curr]);
                        printf("Le type de la chambre: ");
                        switch (chamType[curr]) {
                            case 1:
                                printf("Standard");
                                break;
                            case 2:
                                printf("Suite");
                                break;
                            case 3:
                                printf("Deluxe");
                                break;
                        }
                        printf("\n");

                        printf("Le tarif par nuit: %d\n", chamTarif[curr]);
                        printf("Les equipements disponibles: ");
                        switch (chamEqui[curr]) {
                            case 1:
                                printf("Standard");
                                break;
                            case 2:
                                printf("Premium");
                                break;
                            case 3:
                                printf("VIP");
                                break;
                        }
                        printf("\n");

                        printf("La disponibilité: ");
                        switch(chamDispo[curr]) {
                            case 1:
                                printf("Oui");
                                break;
                            case 2:
                                printf("Non");
                                break;
                        }
                        printf("\n");

                        break;
                    case 0:
                        retour = 1;
                        break;
                    default:
                        printf("S'ils vous plaît! Veuillez choisir un nombre entre 0 et 2!\n");
                        repeter_sec = 0;
                        break;
                    }
                } while (!retour);
                break;
            // Gestion des Reservation
            case 2:
                repeter_sec = 1;
                retour = 0;
                do {
                    if (repeter_sec) {
                        printf("============GESTION DES RESERVATION============\n");
                        printf("Choisissez ce que vous voulez faire :\n");
                        printf("1 - Ajouter une nouvelle reservation\n");
                        printf("2 - Consulter les reservations\n");
                        printf("0 - Retourner\n");
                    }
                    scanf("%d", &choix);
    
                    switch (choix)
                    {
                    // Ajouter une nouvelle reservation / Adding
                    case 1:
                        int prix = 0;

                        curr = 0;
                        while ( curr < nmax && reserNum[curr] != 0 ) {
                            curr++;
                        }

                        int num, numExiste;
                        do {
                            numExiste = 0; 
                            printf("Veuillez saisir le numéro de la reservation: \n");
                            scanf("%d", &num);

                            for (int i = 0; i < nmax; i++) {
                                if (reserNum[i] == num && reserNum[i] != 0) {
                                    numExiste = 1;
                                    printf("Erreur: La réservation %d existe déjà! Veuillez choisir un autre numéro.\n", num);
                                    break;
                                }
                            }

                        } while (num <= 0 || num > 1000 || numExiste == 1);
                        reserNum[curr] = num;

                        int date;
                        do {
                            printf("Veuillez saisir la date de la réservation (ex: 2512 pour 25 Decembre): \n");
                            scanf("%d", &date);
                        } while (date <= 0 || date > 3212);
                        reserDate[curr] = date;
                        
                        int nuits;
                        do {
                            printf("Veuillez saisir la duree du sejour (nombre de nuits): \n");
                            scanf("%d", &nuits);
                        } while ( nuits <= 0 );
                        reserSejour[curr] = nuits;

                        int pers;
                        do {
                            printf("Veuillez saisir le nombre de personnes: \n");
                            scanf("%d", &pers);
                        } while (pers <= 0);
                        reserNbrPerso[curr] = pers;

                        int chamValide = 0, chamAssigne;
                        do {
                            printf("Veuillez saisir le numero de la chambre a reserver: \n");
                            scanf("%d", &chamAssigne);

                            for (int i = 0; i < nmax; i++) {
                                if (chamNum[i] == chamAssigne && chamDispo[i] == 1) {
                                    chamValide = 1;
                                    break;
                                }
                            }
                        } while (!chamValide);
                        reserNumCham[curr] = chamAssigne;

                        int clientValide = 0, clientAssigne;
                        do {
                            printf("Veuillez saisir le CIN du client (en chiffres ex: 12345): \n");
                            scanf("%d", &clientAssigne);

                            for (int i = 0; i < nmax; i++) {
                                if (cliCIN[i] == clientAssigne) {
                                    clientValide = 1;
                                    clientAssigne = i;
                                    break;
                                }
                            }
                        } while (!clientValide);
                        reserClient[curr] = clientAssigne;

                        printf("Succes ! Reservation %d ajoutee. La chambre %d est maintenant occupee.\n", num, chamAssigne);
                        break;
                    // Voir les reservations / Viewing
                    case 2:
                        existe = 0;
                        do {
                            printf("Veuillez saisir un numéro de reservation:\n");
                            scanf("%d", &num);
    
                            for (int i = 0; i < nmax; i++) {
                                if ( reserNum[i] == num ) {
                                    curr = i;
                                    existe = 1;
                                }
                            }
                        } while (!existe);

                        int jour = reserDate[curr]/100, mois = reserDate[curr]%100;

                        printf("Les Informations concernant cette reservation:\n");
                        printf("Le numero de la reservation: %d\n", reserNum[curr]);
                        printf("La date de reservation: %d/%d\n", jour, mois);
                        printf("Les dates de sejour: %d\n", reserSejour[curr]);
                        printf("Les nombre de personnes: %d\n", reserNbrPerso[curr]);
                        printf("Le numero de la chambre reservée: %d\n", reserNumCham[curr]);
                        printf("Les infos du clients:\n");
                        printf("CIN       : %d\n", cliCIN[reserClient[curr]]);
                        printf("Nom       : %s\n", cliNom[reserClient[curr]]);
                        printf("Prenom    : %s\n", cliPrenom[reserClient[curr]]);
                        printf("Adresse   : %s\n", cliAdresse[reserClient[curr]]);
                        printf("Telephone : %d\n", cliCordonnes[reserClient[curr]]);
                        break;
                    case 0:
                        retour = 1;
                        break;
                    default:
                        printf("S'ils vous plaît! Veuillez choisir un nombre entre 0 et 2!\n");
                        repeter_sec = 0;
                        break;
                    }
                } while (!retour);
                break;
            // Gestion des Clients
            case 3:
                repeter_sec = 1;
                retour = 0;
                do {
                    if (repeter_sec) {
                        printf("============GESTION DES CLIENTS============\n");
                        printf("Choisissez ce que vous voulez faire :\n");
                        printf("1 - Ajouter un nouveau client\n");
                        printf("2 - Consulter un client\n");
                        printf("0 - Retourner\n");
                    }
                    scanf("%d", &choix);

                    switch (choix) {
                        // Ajouter un client
                        case 1: {
                            int cCurr = 0;
                            
                            // Chercher la premiere case vide
                            while (cCurr < nmax && cliCIN[cCurr] != 0) {
                                cCurr++;
                            }

                            int cin;
                            int cinExiste;
                            do {
                                cinExiste = 0;
                                printf("Veuillez saisr le CIN du client (en chiffres ex: 12345): \n");
                                scanf("%d", &cin);

                                // Verifier si le CIN existe deja
                                for (int i = 0; i < nmax; i++) {
                                    if (cliCIN[i] == cin && cliCIN[i] != 0) {
                                        cinExiste = 1;
                                        printf("Erreur: Ce client (CIN %d) existe deja!\n", cin);
                                        break;
                                    }
                                }
                            } while (cinExiste || cin <= 0);
                            cliCIN[cCurr] = cin;

                            printf("Veuillez saisir le nom du client (un seul mot): \n");
                            scanf("%s", cliNom[cCurr]); 

                            printf("Veuillez saisir le prenom du client (un seul mot): \n");
                            scanf("%s", cliPrenom[cCurr]);

                            printf("Veuillez saisir la ville ou l'adresse (un seul mot): \n");
                            scanf("%s", cliAdresse[cCurr]);

                            printf("Veuillez saisir le numero de telephone: \n");
                            scanf("%d", &cliCordonnes[cCurr]);

                            printf("\nSucces ! Client %s %s ajoute a la base de donnees.\n\n", cliPrenom[cCurr], cliNom[cCurr]);
                            break;
                        }
                        
                        // Consulter un client
                        case 2: {
                            int cin;
                            int clientValide = 0;
                            int curr = -1;

                            do {
                                printf("Veuillez saisir le CIN du client a rechercher (ou 0 pour annuler): \n");
                                scanf("%d", &cin);

                                if (cin == 0) break;

                                for (int i = 0; i < nmax; i++) {
                                    if (cliCIN[i] == cin && cliCIN[i] != 0) {
                                        curr = i;
                                        clientValide = 1;
                                        break;
                                    }
                                }

                                if (!clientValide && cin != 0) {
                                    printf("Erreur : Client introuvable. Verifiez le CIN.\n");
                                }
                            } while (!clientValide);

                            if (clientValide) {
                                printf("\n--- Informations du Client ---\n");
                                printf("CIN       : %d\n", cliCIN[curr]);
                                printf("Nom       : %s\n", cliNom[curr]);
                                printf("Prenom    : %s\n", cliPrenom[curr]);
                                printf("Adresse   : %s\n", cliAdresse[curr]);
                                printf("Telephone : %d\n", cliCordonnes[curr]);
                                printf("------------------------------\n\n");
                            }
                            break;
                        }
                        case 0:
                            retour = 1;
                            break;
                        default:
                            printf("S'ils vous plait! Veuillez choisir un nombre entre 0 et 2!\n");
                            repeter_sec = 0;
                            break;
                    }
                } while (!retour);
                break;
            // Gestion des Factures
            case 4:
                printf("============GESTION DES FACTURES============\n");
                int num, numValide = 0, cCurr = 0, rCurr = 0;
                do {
                    printf("Veuillez saisir le numéro de la réservation: \n");
                    scanf("%d", &num);

                    for (int i = 0; i < nmax; i++) {
                        if (reserNum[i] == num && reserNum[i] != 0) {
                            rCurr = i;
                            numValide = 1;
                            break;
                        }
                    }

                    if (!numValide) {
                        printf("Erreur : Reservation introuvable. Veuillez reessayer.\n");
                    }
                } while (!numValide);

                for (int i = 0; i < nmax; i++ ) {
                    if (chamNum[i] == reserNumCham[rCurr]) {
                        cCurr = i;
                    }
                }

                int prix = reserSejour[rCurr]*chamTarif[cCurr];

                printf("Les Informations sur la chambre reservée:\n");
                printf("Le numero de la chambre: %d\n", chamNum[cCurr]);
                printf("Le type de la chambre: ");
                switch (chamType[cCurr]) {
                    case 1:
                        printf("Standard");
                        break;
                    case 2: 
                        printf("Suite");
                        break;
                    case 3:
                        printf("Deluxe");
                        break;

                }
                printf("\n");
                printf("Le tarif par nuit: %d\n", chamTarif[cCurr]);
                printf("Les equipements disponibles: ");
                switch (chamEqui[cCurr]) {
                    case 1:
                        printf("Standard");
                        break;
                    case 2:
                        printf("Premium");
                        break;
                    case 3:
                        printf("VIP");
                        break;
                }
                printf("\n");
                printf("La durée du sejour: %d\n", reserSejour[rCurr]);
                printf("Les infos du clients:\n");
                printf("CIN       : %d\n", cliCIN[reserClient[curr]]);
                printf("Nom       : %s\n", cliNom[reserClient[curr]]);
                printf("Prenom    : %s\n", cliPrenom[reserClient[curr]]);
                printf("Adresse   : %s\n", cliAdresse[reserClient[curr]]);
                printf("Telephone : %d\n", cliCordonnes[reserClient[curr]]);
                printf("------------Le prix final %d-----------\n", prix);

                int mode;
                do {
                    printf("Choisissez le mode de paiement que vous souhaitez utiliser: \n");
                    printf("1 - Espèce\n");
                    printf("2 - Carte de Crédit\n");
                    printf("3 - Virement Bancaire\n");
                    scanf("%d", &mode);
                } while (mode <= 0 || mode > 3);

                printf("Succès! La facture a été payée par ");
                switch (mode) {
                    case 1:
                        printf("espèce");
                        break;
                    case 2:
                        printf("carte de crédit");
                        break;
                    case 3:
                        printf("virement bancaire");
                        break;
                }
                printf(".\n");
                
                chamDispo[cCurr] = 1;
                break;
            case 0:
                stop = 1;
                break;
            default:
                printf("S'ils vous plaît! Veuillez choisir un nombre entre 0 et 4!\n");
                repeter = 0;
                break;
            }
    } while (!stop);
    


    return 0;
}