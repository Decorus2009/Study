#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
	void append(String &other) {
        char *res = new char[size + other.size + 1];
        strcpy(res, str);
        strcpy(res + size, other.str);
        delete [] str;
        str = res;

        size += other.size;
    }

	size_t size;
	char *str;
};
