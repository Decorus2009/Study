#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T> &array) {
    for (size_t i = 0; i < array.size(); ++i) {
        out << array[i] << ' ';
    }
    return out;
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out) {
    out << array;
}
