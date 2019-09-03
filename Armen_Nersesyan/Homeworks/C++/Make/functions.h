typedef enum TrimMode {
    FULL_TRIM,
    START_TRIM,
    END_TRIM
} TrimMode;

_Bool is_equal(char *str1, char* str2);
char *trim(char *str, char *symbols, TrimMode mode, char *trailing_token);