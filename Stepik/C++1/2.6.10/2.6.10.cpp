#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size) {
    unsigned limit = new_size < size ? new_size : size;
    char *new_str = new char[new_size];
    for (int i = 0; i < limit; ++i) {
        new_str[i] = str[i];
    }
    delete[] str;
    return new_str;
}

char *getline() {
    unsigned size = 256;
    char *line = new char[size + 1];

    unsigned count = 0;
    char c = '\0';
    while (cin.get(c)) {
        if (c == '\n') break;

        if (count == size) {
            line = resize(line, size, size * 2 + 1);
            size *= 2;
        }
        line[count++] = c;
    }
    line[count] = '\0';
    return line;
}
