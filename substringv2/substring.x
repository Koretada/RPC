/*
 * substring.x
 */

program SUBSTRING {
    version V1 {
        int is_forbidden_substring(string, string) = 1;
        char generate_next_char(string, int, string) = 2;
        void generate_string_without_substrings(int, char, string) = 3;
    } = 1;
} = 0x12345678;
