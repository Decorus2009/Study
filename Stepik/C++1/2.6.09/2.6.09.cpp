char *resize(const char *str, unsigned size, unsigned new_size) {
    unsigned limit = new_size < size ? new_size : size;
    char *new_str = new char[new_size];
    for (int i = 0; i < limit; ++i) {
        new_str[i] = str[i];
    }
    delete[] str;
    return new_str;
}
