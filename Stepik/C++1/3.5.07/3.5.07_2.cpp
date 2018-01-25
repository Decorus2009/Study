/*
 * Класс Cls определен точно таким образом:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *
 */

 struct MyCls {
     MyCls() {}

     MyCls(char c, double d, int i) {}

     char c;
     double d;
     int i;
 };

 // Эта функция должна предоставить доступ к полю c объекта cls.
 // Обратите внимание, что возвращается ссылка на char, т. е.
 // доступ предоставляется на чтение и запись.
 char &get_c(Cls &cls) {
     return ((MyCls *) &cls)->c;
 }

 // Эта функция должна предоставить доступ к полю d объекта cls.
 // Обратите внимание, что возвращается ссылка на double, т. е.
 // доступ предоставляется на чтение и запись.
 double &get_d(Cls &cls) {
     return ((MyCls *) &cls)->d;
 }

 // Эта функция должна предоставить доступ к полю i объекта cls.
 // Обратите внимание, что возвращается ссылка на int, т. е.
 // доступ предоставляется на чтение и запись.
 int &get_i(Cls &cls) {
     return ((MyCls *) &cls)->i;
 }