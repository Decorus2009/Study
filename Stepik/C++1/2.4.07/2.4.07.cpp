void strcat(char *to, const char *from)
{
    char * to_ptr = to;
    const char * from_ptr = from;
    int to_length = 0;
    while (*to_ptr != '\0') {
        ++to_length;
        ++to_ptr;
    }
    while (*from_ptr != '\0') {
        *to_ptr = *from_ptr;
        ++from_ptr;
        ++to_ptr;
    }
    *to_ptr = '\0';
}
