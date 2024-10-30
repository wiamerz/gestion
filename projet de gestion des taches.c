#include <stdio.h>
#include <string.h>

// D�claration des structures
typedef struct {
    int jour;
    int mois;
    int annee;
} date;

// Structure imbriqu�e
typedef struct {
    char name[30];
    char description[100];
    char priorite[30];
    date date;
} tache;

// Fonction de cr�ation des t�ches
void creation(tache tab[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Entrer le titre de cette tache: ");
        scanf(" %[^\n]", tab[i].name); // Utilisation de %[^\n] pour lire l'espace est afficher la phrase complet
        printf("Entrer une description pour cette tache: ");
        scanf(" %[^\n]", tab[i].description);
        printf("Entrer le jour: ");
        scanf("%d", &tab[i].date.jour);
        printf("Entrer le mois: ");
        scanf("%d", &tab[i].date.mois);
        printf("Entrer l'annee: ");
        scanf("%d", &tab[i].date.annee);
        printf("Entrer la priorite de cette tache: ");
        scanf(" %[^\n]", tab[i].priorite);
    }
}
// fonction d'affichade d'une tache
void affichage(tache tab[],int n){
    int i;

    for (i = 0; i < n; i++) {
      printf("Tritre:%s\n",tab[i].name);
      printf("description:%s\n",tab[i].description);
      printf("date: %d/ %d/ %d\n",tab[i].date.jour,tab[i].date.mois,tab[i].date.annee);
      printf("priorite:%s\n",tab[i].priorite);

}}

// fonction de modification d'une tache
void modification(tache tab[], int n) {
    int i, choice = 0;

    printf("Entrer l'indice de la t�che que vous voulez modifier: ");
    scanf("%d", &i);

    // V�rification de la validit� de l'indice
    if (i <= 0 || i > n) {
        printf("Indice non trouv�, veuillez entrer un indice valide.\n");
        return;
    }

    while (choice != 6) {
        printf("\n~~~~~~~~~~LISTE~~~~~~~~~~~~~~~\n");
        printf("1. Nom\n");
        printf("2. Description\n");
        printf("3. Date\n");
        printf("4. Priorit�\n");
        printf("5. Modifier tous\n");
        printf("6. Retour au menu\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrer le nouveau nom: ");
                scanf(" %[^\n]", tab[i - 1].name);
                break;
            case 2:
                printf("Entrer la nouvelle description: ");
                scanf(" %[^\n]", tab[i - 1].description);
                break;
            case 3:
                printf("Entrer la nouvelle date (jour mois annee): ");
                scanf("%d/%d/%d", &tab[i - 1].date.jour, &tab[i - 1].date.mois, &tab[i - 1].date.annee);
                break;
            case 4:
                printf("Entrer la nouvelle priorit�: ");
                scanf("%d", &tab[i - 1].priorite); // On suppose que la priorit� est un entier
                break;
            case 5:
                printf("Entrer un autre titre pour cette t�che: ");
                scanf(" %[^\n]", tab[i - 1].name);
                printf("Entrer une autre description pour cette t�che: ");
                scanf(" %[^\n]", tab[i - 1].description);
                printf("Entrer la nouvelle date (jour mois annee): ");
                scanf("%d/%d/%d", &tab[i - 1].date.jour, &tab[i - 1].date.mois, &tab[i - 1].date.annee);
                printf("Entrer la priorit� de cette t�che: ");
                scanf("%d", &tab[i - 1].priorite);
                break;
            case 6:
                printf("Quitter la liste.\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    }
}


   /* if (i<=0||i>n) //l'indice il faut pas depasse n et pas moins ou egale  0
        printf("Indice non trouve, veuillez entrer un autre :");
    else {
         printf("Entrer un autre titre pour cette tache: ");
        scanf(" %[^\n]", tab[i-1].name);
        printf("Entrer une autre description pour cette tache: ");
        scanf(" %[^\n]", tab[i-1].description);
        printf("Entrer le jour: ");
        scanf("%d", &tab[i-1].date.jour);
        printf("Entrer le mois: ");
        scanf("%d", &tab[i-1].date.mois);
        printf("Entrer l'annee: ");
        scanf("%d", &tab[i-1].date.annee);
        printf("Entrer la priorite de cette tache: ");
        scanf(" %[^\n]", tab[i-1].priorite);
    }
}
*/


// fonction de supression d'une tache
void supression(tache tab[],int n){
       int pos,i;
       printf ("entrer la position de la tache que vouler supprimer :");
       scanf ("%d",&pos);

    if ( pos <= 0 || pos > n ){
        printf("Position non trouve, veuillez entrer une autre ");
        } else {
           for (i =pos-1 ; i<n-1 ; i++){
            tab[i]=tab[i+1];
           }
           n--;
        printf("La tache a ete supprimee avec succes.\n");
        printf("Les taches restantes sont :\n");
        affichage(tab, n);
    }
}
// Fonction de filtrage par priorit�
void filtragepriorite(tache tab[], int n) {
    char priorite;
    int i;
    printf("Entrer une priorit� : 'H' pour high, 'L' pour low : ");
    scanf(" %c", &priorite);  // Utiliser %c pour un char
    switch (priorite) {
        case 'L':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].priorite, "low") == 0) {  // pour comparer la cha�ne de caract�res stock�e dans tab[i].priorite avec la cha�ne "low".
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorit� : %s\n", tab[i].priorite);
                } else {
                printf("on a aucune tache avec cette priorite\n.");
                }
            }
            break;

        case 'H':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].priorite, "high") == 0) {  // pour comparer la cha�ne de caract�res stock�e dans tab[i].priorite avec la cha�ne "high".
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorit� : %s\n", tab[i].priorite);
                } else {
                printf("on a aucune tache avec cette priorite\n.");
                }
            }
            break;

        default:
            printf("Priorit� non reconnue. Veuillez entrer 'H' ou 'L'.\n");
    }

}


int main() {
    tache tab[100];
    int choix , n ;

    printf("Combien des taches voulez-vous creer ?: ");
    scanf("%d", &n);

    while (choix != 6) {
        printf("\n~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n");
        printf("1. Creer\n");
        printf("2. Afficher\n");
        printf("3. Modifier\n");
        printf("4. Supprimer\n");
        printf("5. Filtrer par priorite\n");
        printf("6. Quitter\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creation(tab, n);
                break;
            case 2:
               affichage(tab,n);
               break;
            case 3:
                modification(tab,n);
            break;
            case 4:
                supression(tab,n);
             break;
            case 5:
                filtragepriorite(tab,n);
            break;
            case 6:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    }

    return 0;
}
