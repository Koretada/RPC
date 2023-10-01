#include "substring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * is_forbidden_substring_1_svc(char *temp, char *chaine1, char *chaine2, char *chaine3, struct svc_req *rqstp) {

    //
    // Fonction qui vérifie qu'il n'y a pas de sous chaîne identique
    //

    static int result;
    char *forbidden[] = {chaine1, chaine2, chaine3};
    
    for (int j = 0; j < 3; j++) {
        char *first_occurrence = strstr(temp, forbidden[j]);
        if (first_occurrence != NULL) {
            char *second_occurrence = strstr(first_occurrence + 1, forbidden[j]);
            if (second_occurrence != NULL) {
                result = 1; // Deuxième occurrence trouvée
                return &result;
            }
        }
    }
    result = 0; // Pas de deuxième occurrence trouvée
    return &result; 
}

char ** generate_next_char_1_svc(char *result_str, char *chaine1, char *chaine2, char *chaine3, int pos, struct svc_req *rqstp) {

    //
    // Fonction qui génère le prochain caractère, sans faire apparaître + 1 d'une fois une chaîne interdite
    //

    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char temp_result[256]; // Chaîne produite jusqu'ici
    int next_char_index; // Lettre que l'on va générer 

    while (1) {
        next_char_index = rand() % 26;
        strcpy(temp_result, result_str);
        temp_result[pos] = alphabet[next_char_index];
        temp_result[pos + 1] = '\0';

        int forbidden_check = *(is_forbidden_substring_1_svc(temp_result, chaine1, chaine2, chaine3, rqstp));

        if (forbidden_check == 0) { // Cela signifie qu'il n'y a pas de sous chaine identique
            char **result_char = (char **)malloc(sizeof(char *));
            result_char[0] = (char *)malloc(2 * sizeof(char));
            result_char[0][0] = alphabet[next_char_index];
            result_char[0][1] = '\0';
            return result_char;
        }
    }
}

char ** generate_string_without_substrings_1_svc(int length, char *chaine1, char *chaine2, char *chaine3, struct svc_req *rqstp) {

    ///
    // Fonction qui génère la chaîne finale
    //
    
    static char result[256];
    static char *result_ptr[1];

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        char *next_char = *generate_next_char_1_svc(result, chaine1, chaine2, chaine3, i, rqstp);
        result[i] = next_char[0];
    }
    result[length] = '\0';
    
    result_ptr[0] = result;
    return result_ptr;
}
