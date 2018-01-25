#include <cstddef> // size_t

template<typename T, size_t Size>
size_t array_size(T (&array)[Size]) {
    return Size;
}
