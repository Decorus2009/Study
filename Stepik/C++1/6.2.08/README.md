Реализуйте шаблонную функцию minimum, которая находит минимальный элемент, который хранится в экземпляре шаблонного класса Array, при этом типовой параметр шаблона Array может быть произвольным. Чтобы сравнивать объекты произвольного типа, на вход функции также будет передаваться компаратор, в качестве компаратора может выступать функция или объект класса с перегруженным оператором "()". Примеры вызова функции minimum:
```
bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };
```

```
Array<int> ints(3);
ints[0] = 10;
ints[1] = 2;
ints[2] = 15;
int min = minimum(ints, less); // в min должно попасть число 2
int max = minimum(ints, Greater()); // в max должно попасть число 15
```