#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

bool containsforbiddensubstr_1_svc(const char *str, const char *forbiddenSubstr1, const char *forbiddenSubstr2, const char *forbiddenSubstr3) {
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
                return true;  // La chaîne contient la sous-chaîne interdite 1
            }
        } else {
            state1 = 0;  // Réinitialise l'état si le caractère ne correspond pas
        }

        if (c == forbiddenSubstr2[state2]) {
            state2++;
            if (state2 == subStrLen2) {
                return true;  // La chaîne contient la sous-chaîne interdite 2
            }
        } else {
            state2 = 0;  // Réinitialise l'état si le caractère ne correspond pas
        }

        if (c == forbiddenSubstr3[state3]) {
            state3++;
            if (state3 == subStrLen3) {
                return true;  // La chaîne contient la sous-chaîne interdite 3
            }
        } else {
            state3 = 0;  // Réinitialise l'état si le caractère ne correspond pas
        }
    }

    return false;  // La chaîne est valide
}

char *generaterandomstring_1_svc(int length) {
    char *result = (char *)malloc((length + 1) * sizeof(char));
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    const int charsetLength = strlen(charset);

    for (int i = 0; i < length; i++) {
        result[i] = charset[rand() % charsetLength];
    }

    result[length] = '\0';
    return result;
}


