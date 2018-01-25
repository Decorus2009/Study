int strstr(const char *text, const char *pattern)
{
    if (*pattern == '\0') return 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        bool contains = true;
        for (int j = 0; pattern[j] != '\0'; ++j) {
            if (text[i + j] == '\0') return -1;
            if (text[i + j] != pattern[j]) {
                contains = false;
                break;
            }
        }
        if (contains) return i;
    }
    return -1;
}
