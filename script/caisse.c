#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calcule_monnaie(double montant_paye, double valeur_a_payer) {
    return montant_paye - valeur_a_payer;
}

int main() {
    // Initialisation de la graine pour la génération aléatoire
    srand(time(NULL));
    
    // Génération d'un double aléatoire pour représenter la valeur à payer
    double valeur_a_payer = (double)rand() / RAND_MAX * 1000; // Vous pouvez ajuster la plage de valeurs si nécessaire
    
    printf("Valeur à payer : Rs%.2f\n", valeur_a_payer);
    
    double montant_paye;
    
    do {
        // Demander à l'utilisateur de saisir le montant payé
        printf("Entrez le montant que vous souhaitez payer : Rs");
        scanf("%lf", &montant_paye);
        
        // Vérifier si le montant payé est suffisant
        if (montant_paye < valeur_a_payer) {
            printf("Le montant payé est insuffisant. Veuillez saisir une valeur égale ou supérieure à Rs%.2f\n", valeur_a_payer);
        }
    } while (montant_paye < valeur_a_payer);
    
    // Calculer la monnaie à rendre en utilisant la fonction calcule_monnaie()
    double monnaie = calcule_monnaie(montant_paye, valeur_a_payer);
    printf("Merci pour votre paiement. Votre monnaie à rendre est Rs%.2f\n", monnaie);
    
    // Déterminer les billets et les pièces à rendre
    int billets_5000 = monnaie / 5000;
    monnaie -= billets_5000 * 5000;
    int billets_2000 = monnaie / 2000;
    monnaie -= billets_2000 * 2000;
    int billets_1000 = monnaie / 1000;
    monnaie -= billets_1000 * 1000;
    int billets_500 = monnaie / 500;
    monnaie -= billets_500 * 500;
    int billets_200 = monnaie / 200;
    monnaie -= billets_200 * 200;
    int billets_100 = monnaie / 100;
    monnaie -= billets_100 * 100;
    int billets_50 = monnaie / 50;
    monnaie -= billets_50 * 50;
    int billets_20 = monnaie / 20;
    monnaie -= billets_20 * 20;
    
    // Affichage des billets et pièces à rendre
    printf("Billets à rendre:\n");
    printf("Rs5000: %d\n", billets_5000);
    printf("Rs2000: %d\n", billets_2000);
    printf("Rs1000: %d\n", billets_1000);
    printf("Rs500: %d\n", billets_500);
    printf("Rs200: %d\n", billets_200);
    printf("Rs100: %d\n", billets_100);
    printf("Rs50: %d\n", billets_50);
    printf("Rs20: %d\n", billets_20);
    printf("Pièces à rendre:\n");
    printf("Rs%.2f\n", monnaie);
    
    return 0;
}
