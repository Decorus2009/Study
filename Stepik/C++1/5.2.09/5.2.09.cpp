#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    struct IndexedString {
        IndexedString(const String &s, size_t from) : s(s), from(from) {}

        String operator[](size_t to) const {
            if (from == to) {
                return "";
            }
            return String(s.str + from, to - from);
        }

        const String &s;
        size_t from;
    };

    String(char *str, size_t n) : size(n), str(new char[size + 1]) {
        strncpy(this->str, str, n);
        str[size] = '\0';
    }

    IndexedString operator[](size_t from) const {
        return IndexedString(*this, from);
    }


	String(const char *str = "");
	String(size_t n, char c);
	~String();

    String(const String &other);
    String &operator=(const String &other);

	void append(const String &other);

	size_t size;
	char *str;
};
