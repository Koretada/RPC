#include "substring.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    CLIENT *clnt;
    char *server, *chaine1, *chaine2, *chaine3;
    char *input_string;
    int length;

    if (argc != 6) {
        fprintf(stderr, "Usage: %s <server_host> <string_length> <chaine_1> <chaine_2> <chaine_3>\n", argv[0]);
        exit(1);
    }

    server = argv[1];
    length = atoi(argv[2]);
    chaine1 = argv[3];
    chaine2 = argv[4];
    chaine3 = argv[5]; 

    clnt = clnt_create(server, STRING_GENERATOR, STRING_GENERATOR_V1, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(server);
        exit(1);
    }

    // Generate string without forbidden substrings
    char **result = generate_string_without_substrings_1(length, chaine1, chaine2, chaine3, clnt);
    if (result == NULL) {
        clnt_perror(clnt, server);
        exit(1);
    }

    printf("Generated string: %s\n", *result);

    clnt_destroy(clnt);
    return 0;
}
