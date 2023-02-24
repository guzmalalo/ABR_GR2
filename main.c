#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition d'un noeud
typedef struct N
{
    // clé
    int n;

    // Information à stocker
    char nom[50];

    // Lien d'hierarchie
    struct N *sag; // Noued à gauche
    struct N *sad; // Noued à droit

} Node ;

void creerNoued(Node **arbre_n, int n, char *str)
{

    // Allocation de memoire (Creation du noued)
    // et recuperation de son adresse
    (*arbre_n) = (Node *)malloc(sizeof(Node));

    // Initialisation du noued
    (*arbre_n)->n = n;
    strcpy((*arbre_n)->nom, str);

    // Initialisation des noueds fils
    (*arbre_n)->sad = NULL;
    (*arbre_n)->sag = NULL;

    return;
}

void ajouterNoued(Node **p_arbre, int n, char *str)
{
    // Creation d'un pointeur temporaire vers
    // le sous-arbre
    Node *arbre = *p_arbre;

    if (arbre == NULL)
    {
        creerNoued(p_arbre, n, str);
    }
    else if (n < arbre->n)
    {
        ajouterNoued(&(arbre->sag), n, str);
    }
    else if (n > arbre->n)
    {
        ajouterNoued(&(arbre->sad), n, str);
    }
    else
    {
        printf("Clé existante");
    }
}



void libereArbre(Node ** arbre){
    if(*arbre == NULL){
        return;
    }
    libereArbre(&(*arbre)->sag);
    libereArbre(&(*arbre)->sad);
    free(*arbre);
}


void afficheInfixe(Node * arbre){

    if (arbre == NULL)
        return;
    afficheInfixe(arbre->sag);
    printf("%d: %s\t", arbre->n,arbre->nom );
    afficheInfixe(arbre->sad);
}



int main()
{
    // Initialisation de l'arbre
    Node *arbre = NULL;

    // Creation du premier noued (racine)
    ajouterNoued(&arbre, 10, "A");

    // Ajout des noueds a trier
    ajouterNoued(&arbre, 42, "B");
    ajouterNoued(&arbre, 1, "C");
    ajouterNoued(&arbre, 80, "D");

    // Affichage
    printf(" \n Infixe \n");
    afficheInfixe(arbre);
    printf(" \n Prefixe \n");
    printf(" \n Postfixe \n");

    libereArbre(&arbre);

    return 0;
}
