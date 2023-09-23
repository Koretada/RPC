/*
 * substring.x
 */

program SUBSTRING {
    version V1 {
        string generaterandomstring(int) = 1;
        bool containsforbiddensubstr(string, string, string, string) = 2;
    } = 1;
} = 0x12345678;
