#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "substring.h"

int main(int argc, char *argv[]) {
    
    if (argc != 5) {
        printf("Utilisation : %s <SERVEUR_RPC> <sous-chaine interdite 1> <sous-chaine interdite 2> <sous-chaine interdite 3>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *forbiddenSubstr1 = argv[2];
    char *forbiddenSubstr2 = argv[3];
    char *forbiddenSubstr3 = argv[4];
    int maxLength = 10;
    char *generatedString;

    CLIENT *clnt = clnt_create(host, SUBSTRING, V1, "tcp");
    if (clnt == (CLIENT *) NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

    do {
        generatedString = *(generaterandomstring_1(maxLength, clnt));
    } while (containsforbiddensubstr_1(generatedString, forbiddenSubstr1, forbiddenSubstr2, forbiddenSubstr3, clnt));

    printf("Chaîne générée : %s\n", generatedString);
    free(generatedString);

    return 0;
}