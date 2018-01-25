unsigned strlen(const char *str)
{
    const char * p = str;
    int length = 0;
    while (*p != '\0') {
        ++length;
        p++;
    }
    return length;
}

