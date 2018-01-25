void swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void rotate(int * a, unsigned size) {
    for (int j = 0; j < size - 1; ++j) {
        swap(a + j, a + (j + 1) % size);
    }
}

void rotate(int * a, unsigned size, int shift) {
    for (int i = 0; i < shift; ++i) {
        rotate(a, size);
    }    
}


