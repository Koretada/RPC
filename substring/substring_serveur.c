#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "substring.h"

bool_t * containsforbiddensubstr_1_svc(char *str, char *forbiddenSubstr1, char *forbiddenSubstr2, char *forbiddenSubstr3, struct svc_req *rqstp) {
    int state1 = 0, state2 = 0, state3 = 0;
    int strLen = strlen(str);
    int subStrLen1 = strlen(forbiddenSubstr1);
    int subStrLen2 = strlen(forbiddenSubstr2);
    int subStrLen3 = strlen(forbiddenSubstr3);

    for (int i = 0; i < strLen; i++) {
        char c = str[i];

        // Vérifie si le caractère actuel correspond au début d'une sous-chaîne interdite
        if (c == forbiddenSubstr1[state1]) {
            state1++;
            if (state1 == subStrLen1) {
                return (bool_t *) true;  // La chaîne contient la sous-chaîne interdite 1
            }
        } else {
            state1 = 0;  // Réinitialise l'état si le caractère ne correspond pas
        }

        if (c == forbiddenSubstr2[state2]) {
            state2++;
            if (state2 == subStrLen2) {
                return (bool_t *) true;  // La chaîne contient la sous-chaîne interdite 2
            }
        } else {
            state2 = 0;  // Réinitialise l'état si le caractère ne correspond pas
        }

        if (c == forbiddenSubstr3[state3]) {
            state3++;
            if (state3 == subStrLen3) {
                return (bool_t *) true;  // La chaîne contient la sous-chaîne interdite 3
            }
        } else {
            state3 = 0;  // Réinitialise l'état si le caractère ne correspond pas
        }
    }

    return (bool_t *) false;  // La chaîne est valide
}

char **generaterandomstring_1_svc(int length, struct svc_req *rqstp) {
    srand(time(NULL));
    char *result = (char *)malloc((length + 1) * sizeof(char));
    char charset[] = "abcdefghijklmnopqrstuvwxyz";
    int charsetLength = strlen(charset);

    for (int i = 0; i < length; i++) {
        result[i] = charset[rand() % charsetLength];
    }

    result[length] = '\0';

    // Allouer et renvoyer un pointeur vers le résultat
    char **p_result = (char **)malloc(sizeof(char *));
    *p_result = result;

    return p_result;
}
