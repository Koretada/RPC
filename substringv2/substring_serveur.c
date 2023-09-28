#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 26

// Fonction pour vérifier si une sous-chaîne donnée est interdite
int * is_forbidden_substring_1_svc(char* temp, char forbidden[3][4], struct svc_req *rqstp) {
    // Parcourir toutes les sous-chaînes interdites
    for (int j = 0; j < 3; j++) {
        // Si la sous-chaîne est trouvée, retourner 1
        if (strstr(temp, forbidden[j]) != NULL) {
            return (int *) 1;  
        }
    }
    // Si aucune sous-chaîne interdite n'est trouvée, retourner 0
    return (int *) 0;  
}

// Fonction pour générer le prochain caractère de la chaîne finale
char * generate_next_char_1_svc(char* result, int i, char forbidden[3][4], struct svc_req *rqstp) {
    // Définir l'alphabet complet
    char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";
    char temp[4];  // Chaîne temporaire pour stocker les caractères en cours de traitement
    int next_char_index;  // Index du prochain caractère à ajouter
    int end;  // Limite pour construire la chaîne temporaire

    // Déterminer la limite en fonction de la position actuelle dans la chaîne finale
    if (i < 3) {
        end = i;
    } else {
        end = 2;
    }

    // Boucle pour générer un caractère qui ne crée pas de sous-chaîne interdite
    while (1) {
        // Générer un index aléatoire pour le prochain caractère
        next_char_index = rand() % ALPHABET_SIZE;

        // Construire la chaîne temporaire pour vérification
        for (int j = 0; j <= end; j++) {
            if (j < end) {
                temp[j] = result[i - (end - j)];
            } else {
                temp[j] = alphabet[next_char_index];
            }
        }
        temp[end + 1] = '\0';  // Assurer que la chaîne est bien terminée

        // Si la chaîne temporaire n'est pas interdite, sortir de la boucle
        if (!is_forbidden_substring_1_svc(temp, forbidden, rqstp)) {
            char *ptr = (char*) malloc(sizeof(char));
            *ptr = alphabet[next_char_index];
            return ptr;
        }
    }
}

// Fonction pour générer la chaîne finale sans sous-chaînes interdites
void * generate_string_without_substrings_1_svc(int length, char forbidden[3][4], char* result, struct svc_req *rqstp) {
    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Générer chaque caractère de la chaîne finale
    for (int i = 0; i < length; i++) {
        result[i] = *(generate_next_char_1_svc(result, i, forbidden, rqstp));
    }
    result[length] = '\0';  // Assurer que la chaîne est bien terminée
}

// int main() {
//     // Définir les sous-chaînes interdites
//     char forbidden[3][4] = {"abc", "def", "ghi"};
//     char result[21];  // Chaîne finale à générer
//     int length = 20;

//     // Générer la chaîne finale
//     generate_string_without_substrings_1_svc(length, forbidden, result);

//     // Afficher la chaîne finale
//     printf("%s\n", result);

//     return 0;
// }
