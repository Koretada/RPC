/*
 * substring.x
 */

struct StringArray {
    string forbidden_strings<3>;
};

program SUBSTRING {
    version V1 {
        int is_forbidden_substring(string) = 1;
        string generate_next_char(string, int, StringArray) = 2;
        string generate_string_without_substrings(int, StringArray) = 3;
    } = 1;
} = 0x12345678;
