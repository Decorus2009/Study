// Определите шаблон SameType с двумя типовыми
// параметрами. В шаблоне должна быть определена
// одна статическая константа типа bool с именем
// value
template<typename T, typename U>
struct SameType {
    static const bool value = false;
};

template<typename T>
struct SameType<T, T> {
    static const bool value = true;
};
