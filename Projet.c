#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    int day;
    int month;
    int year;
}birth;


typedef struct {
    int numero_unique;
    char nom[50];
    char prenom[50];
    birth date_de_naissance;
    char departement[20];
    float note_generale;
}informations;

void choix_departement();
void nouveau_etudiant();
void supprimer_un_etudiant();
void Afficher_les_details_d_un_etudiant();
void afficher_menu();
void Modifier_un_etudiant();
void moyenne_generale_de_chaque_departement();
void moyenne_generale_d_universite();
void nombre_totale_d_etudiant();
void nombre_d_etudiants_dans_chaque_departement();

informations stock[1000];
int counter;


int main (){
    int choix,choix1,choix2;
    do{
      afficher_menu();
      printf("\nEntrer votre choix : ");
      scanf("%d",&choix);
      switch(choix){
       case 1:
           nouveau_etudiant();
           break;
       case 2:
           printf("1. modifier \n");
           printf("2. supprimer \n");
           printf("Entrer votre choix : ");
           scanf("%d",&choix1);
           switch(choix1){
               case 1:
                   Modifier_un_etudiant();
                   break;
               case 2:
                   supprimer_un_etudiant();
                   break;
               default:
                printf("\nVotre choix non valide\n");
           }break;
       case 3:
           Afficher_les_details_d_un_etudiant();
           break;
       case 4:
           moyenne_generale_de_chaque_departement();
           break;
       case 5:
           moyenne_generale_d_universite();
           break;
       case 6:
           printf("1. Afficher le nombre total d'étudiants inscrits. \n");
           printf("2. Afficher le nombre d'étudiants dans chaque département. \n");
           printf("Entrer votre choix : ");
           scanf("%d",&choix1);
           switch(choix1){
               case 1:
                   nombre_totale_d_etudiant();
                   break;
               case 2:
                   nombre_d_etudiants_dans_chaque_departement();
                   break;
               default:
                printf("\nVotre choix non valide\n");
           }
           break;

       case 7:
           printf("Au revoir!");
       }

    }while(choix!=7);

    return 0;

}

void choix_departement(){
   int choix;
        printf("\nChoisie le departement de letudiant : \n ");
        printf("1- Math \n");
        printf(" 2- Physique \n");
        printf(" 3- Informatique \n");
        printf(" 4- Geologie \n");
        printf(" 5- Biologie \n");
        printf("\nEntrer votre choix : ");
        scanf("%d",&choix);
    switch(choix){

        case 1:
            strcpy(stock[counter].departement,"Math");
            break;
        case 2:
            strcpy(stock[counter].departement,"Physique");
            break;
        case 3:
            strcpy(stock[counter].departement,"Informatique");
            break;
        case 4:
            strcpy(stock[counter].departement,"Geologie");
            break;
        case 5:
            strcpy(stock[counter].departement,"Biologie");
            break;

        default:
            printf("le choix non valide. \n ");

            }
}

void nouveau_etudiant(){
    int choix;
    stock[counter].numero_unique = counter + 324257;
    printf("ID de l'etudiant est : %d",stock[counter].numero_unique);
    printf("\nEntrer le nom de letudiant : ");
    scanf(" %[^\n]",stock[counter].nom);
    printf("Entrer le prenom de letudiant : ");
    scanf(" %[^\n]",stock[counter].prenom);
    printf("Entrer la date de naissance  de letudiant : \n ");
    printf("Jour : ");
    scanf( "%d", &stock[counter].date_de_naissance.day);
    printf(" Mois : ");
    scanf( " %d",&stock[counter].date_de_naissance.month);
    printf(" Annee : ");
    scanf( " %d",&stock[counter].date_de_naissance.year);

    choix_departement();

    printf("Entrer la note generale de letudiant : ");
    scanf("%f",&stock[counter].note_generale);
    printf("l'etudiant est enregistre. \n ");

    counter++;
    }

void Modifier_un_etudiant(){
      int etudiant_cible;
      printf("\nEntrer le numero unique detudiant que vous voulez modifier :");
      scanf("%d",&etudiant_cible);
     for (int i=0;i<counter;i++){
      if(stock[i].numero_unique == etudiant_cible){
        printf("Entrer l'element que vous pouvez modifier : ");
        printf("1- Nom \n ");
        printf("2- prenom \n ");
        printf("3- Date de naissance \n ");
        printf("4- Departement \n ");
        printf("5- Note generale: \n ");
        int ask ;
        printf("Entrer votre choix : ");
        scanf("%d",&ask);
        switch (ask){
        case 1:
            printf("Entrer le nouveau nom : ");
            scanf("%s",stock[i].nom);
            break;
        case 2:
            scanf("%s",stock[i].prenom);
            break;
        case 3:
            printf("jour : ");
            scanf( "%d",&stock[i].date_de_naissance.day);
            printf(" mois : ");
            scanf( " %d",&stock[i].date_de_naissance.month);
            printf("annee : ");
            scanf( " %d",&stock[i].date_de_naissance.year);
            break;
        case 4:
            printf("1- Math \n");
            printf(" 2- Physique \n");
            printf(" 3- Informatique \n");
            printf(" 4- Geologie \n");
            printf(" 5- Biologie \n");
            printf("\nEntrer votre choix : ");
            scanf("%d",&stock[i].departement);
            break;
        case 5:
            printf("entrer la nouvelle note generale");
            scanf("%d",&stock[i].note_generale);
            break;

        default:
            break;
            }

       } else{
      printf("le choix non valide. \n ");
         }
    }
      printf("les modification sont enregistre. \n ");
}

void supprimer_un_etudiant(){
    int numero_unique_supp;
    printf("\nEntrer le numero unique d'etudiant que vous voulez supprimer : ");
    scanf("%d",&numero_unique_supp);
    for (int i=0;i<counter;i++){
        if(numero_unique_supp==stock[i].numero_unique){
            for(int j=i;j<counter-1;j++){
                stock[j]=stock[j+1];
            }

        counter--;
        printf("L'etudiant est supprime.\n");
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}

void Afficher_les_details_d_un_etudiant(){
    int id_saisie;
    printf("Entrer le Numero unique d'etudiants : ");
    scanf("%d",&id_saisie);
    for(int i=0;i<counter;i++){
            if(id_saisie == stock[i].numero_unique){
                printf("le nom de letudiant : %s \n ",stock[i].nom);
                printf("le prenom  de letudiant : %s \n",stock[i].prenom);
                printf("la date de naissance de l'etudiant : \n");
                printf("jour : %d \n",stock[i].date_de_naissance.day);
                printf("mois : %d \n",stock[i].date_de_naissance.month);
                printf("annee : %d \n",stock[i].date_de_naissance.year);
                printf("le departement de letudiant :  %s \n",stock[i].departement);
                printf("la note generale de letudiant : %.2f \n",stock[i].note_generale);
        }else{
            printf("l'etudiant non trouve");
        }
    }
}

void afficher_menu(){
    printf("\n--- Menu Principal ---\n");
    printf("1. Ajouter un etudiant\n");
    printf("2. Modifier ou supprimer un etudiant\n");
    printf("3. Afficher les details d'un etudiant\n");
    printf("4. Calculer la moyenne generale de chaque departement\n");
    printf("5. Calculer la moyenne generale de l'universite\n");
    printf("6. Afficher les statistiques de l'universite\n");
    printf("7. Quitter\n");
    printf("----------------------\n");

}

void moyenne_generale_de_chaque_departement() {
    int choix;
    float somme[5];
    int count = 0;
    float moyenne = 0;
       for(int i=0; i<counter; i++){
                if(strcmp(stock[i].departement,"Math")==0){
                    somme += stock[i].note_generale;
            }else{
                if (strcmp(stock[i].departement,"Physique")==0){
                    somme += stock[i].note_generale;
                    count++;

            }else{
                if(strcmp(stock[i].departement,"Informat")==0){
                    somme+=stock[i].note_generale;
                    count++;
             }
            }
            if(count>0){
                moyenne=somme/count;
                printf("La moyenne generale du departement d'Informatique est : %.2f\n", moyenne);
            }else{
                printf("Aucun etudiant dans le departement d'Informatique.\n");
            }
            break;
        case 4:
            for(int i=0;i<counter;i++){
                if(strcmp(stock[i].departement,"Geologie")==0){
                    somme+=stock[i].note_generale;
                    count++;
              }
            }
            if(count>0){
                moyenne=somme/count;
                printf("La moyenne generale du departement de Geologie est : %.2f\n", moyenne);
            }else{
                printf("Aucun etudiant dans le departement de Geologie.\n");
            }
            break;
        case 5:
            for(int i=0;i<counter;i++) {
                if(strcmp(stock[i].departement,"Biologie")==0){
                    somme+=stock[i].note_generale;
                    count++;
              }
            }
            if(count>0){
                moyenne=somme/count;
                printf("La moyenne generale du departement de Biologie est : %.2f\n",moyenne);
            }else{
                printf("Aucun etudiant dans le departement de Biologie.\n");
            }
            break;
        default:
            printf("Le choix n'est pas valide.\n");
    }
}

void moyenne_generale_d_universite(){
    float somme_totale = 0;
    int count_total = 0;
    float moyenne_totale = 0;
    for(int i=0;i<counter;i++){
        somme_totale += stock[i].note_generale;
        count_total++;
    }
    if (count_total>0){
        moyenne_totale=somme_totale/count_total;
        printf("La moyenne generale de tous les departements est : %.2f\n", moyenne_totale);
    }else{
        printf("Aucun etudiant n'est enregistre.\n");
        }
}

void nombre_totale_d_etudiant() {
    printf("Nombre total d'etudiants inscrits : %d\n",counter);
}

void nombre_d_etudiants_dans_chaque_departement(){
     int countMath=0,countPhysique=0,countInformatique=0,countGeologie=0,countBiologie=0;
    for (int i=0;i<counter;i++){
        if (strcmp(stock[i].departement,"Math")==0){
            countMath++;
        }else
        if(strcmp(stock[i].departement,"Physique")==0) {
            countPhysique++;
        }else
        if (strcmp(stock[i].departement,"Informatique")==0){
            countInformatique++;
        }else
        if (strcmp(stock[i].departement,"Geologie")==0) {
            countGeologie++;
        }else
        if (strcmp(stock[i].departement,"Biologie")==0) {
            countBiologie++;
     }
    }
    printf("Nombre d'étudiants dans chaque département :\n");
    printf("Math : %d\n",countMath);
    printf("Physique : %d\n",countPhysique);
    printf("Informatique : %d\n",countInformatique);
    printf("Geologie : %d\n",countGeologie);
    printf("Biologie : %d\n",countBiologie);
}


