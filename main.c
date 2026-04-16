#include <stdio.h>

#define nmax 100

int main() {
    int chamNum[nmax], chamType[nmax], chamTarif[nmax], chamEqui[nmax], chamDispo[nmax];
    int reserNum[nmax], reserDate[nmax], reserSejour[nmax], reserNbrPerso[nmax], reserNumCham[nmax], reserInfo[nmax];
    int cliCIN[nmax], cliNom[nmax], cliPrenom[nmax], cliAdresse[nmax], cliCordonnes[nmax];
    int facNum[nmax], facInfoChambre[nmax], facDuree[nmax], facPrix[nmax], facInfoCli[nmax], facMode[nmax];
    int choix, chambre_choix, reser_choix, clients_choix, factures_choix;
    int repeter, repeter_cham;
    int stop = 0, retour_cham = 0;
    int correcte = 1;
    int chamCurr;

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
                repeter_cham = 1;
                do {
                    if (repeter_cham) {
                        printf("============GESTION DES CHAMBRES============\n");
                        printf("Choisissez ce que vous voulez faire :\n");
                        printf("1 - Ajouter une nouvelle chambre\n");
                        printf("2 - Consulter les chambres\n");
                        printf("0 - Retourner\n");
                    }
                    scanf("%d", &chambre_choix);
    
                    switch (chambre_choix)
                    {
                    case 1:
                        for (int i = 0; i < nmax - 1; i++) {
                            if ( chamNum[i] != 0 ) {
                                chamCurr = 0;
                            }
                            chamCurr++;
                        }
                        chamCurr = nmax-chamCurr;

                        do {
                            printf("Veuillez saisir le numéro de la chambre: ");
                            scanf("%d", &chamNum[chamCurr]);
                            //
                        } while (0<chamNum[chamCurr] && chamNum[chamCurr]<1000);

                        break;
                    case 2:
                        break;
                    case 0:
                        retour_cham = 1;
                        break;
                    default:
                        printf("S'ils vous plaît! Veuillez choisir un nombre entre 0 et 2!");
                        repeter_cham = 0;
                        break;
                    }
                } while (!retour_cham);
                break;
            // Gestion des Reservation
            case 2:
                printf("============GESTION DES RESERVATION============\n");
                break;
            // Gestion des Clients
            case 3:
                printf("============GESTION DES CLIENTS============\n");
                break;
            // Gestion des Factures
            case 4:
                printf("============GESTION DES FACTURES============\n");
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