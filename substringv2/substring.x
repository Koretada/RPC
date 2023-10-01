program STRING_GENERATOR {
    version STRING_GENERATOR_V1 {
        int is_forbidden_substring(string, string, string, string) = 1;
        string generate_next_char(string, string, string, string, int) = 2;
        string generate_string_without_substrings(int, string, string, string) = 3;
    } = 1;
} = 0x20000001;
