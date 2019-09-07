#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef enum TrimMode {
    FULL_TRIM,
    START_TRIM,
    END_TRIM
} TrimMode;

bool is_equal(char *str1, char* str2);
char *trim(char *str, char *symbols, TrimMode mode, char *trailing_token);
