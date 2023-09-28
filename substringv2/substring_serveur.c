#include "substring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 26

int *
is_forbidden_substring_1_svc(char **temp, struct svc_req *rqstp) {
    static int result;
    char forbidden[3][4] = {"abc", "def", "ghi"};
    
    for (int j = 0; j < 3; j++) {
        if (strstr(*temp, forbidden[j]) != NULL) {
            result = 1;
            return &result;
        }
    }
    result = 0;
    return &result;
}

char **
generate_next_char_1_svc(char **result_str, int *pos, StringArray *forbidden, struct svc_req *rqstp) {
    static char result_char[2];
    char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";
    char temp[4];
    int next_char_index;
    int end;

    int i = *pos;

    if (i < 3) {
        end = i;
    } else {
        end = 2;
    }

    while (1) {
        next_char_index = rand() % ALPHABET_SIZE;

        for (int j = 0; j <= end; j++) {
            if (j < end) {
                temp[j] = (*result_str)[i - (end - j)];
            } else {
                temp[j] = alphabet[next_char_index];
            }
        }
        temp[end + 1] = '\0';

        int forbidden_check = *is_forbidden_substring_1_svc(&temp, rqstp);

        if (!forbidden_check) {
            result_char[0] = alphabet[next_char_index];
            result_char[1] = '\0';
            return &result_char;
        }
    }
}

char **
generate_string_without_substrings_1_svc(int *length, StringArray *forbidden, struct svc_req *rqstp) {
    static char result[1024];

    srand(time(NULL));

    for (int i = 0; i < *length; i++) {
        char *next_char = *generate_next_char_1_svc(&result, &i, forbidden, rqstp);
        result[i] = next_char[0];
    }
    result[*length] = '\0';
    return &result;
}
