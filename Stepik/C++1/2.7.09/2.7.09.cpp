int **const create_array_2d(unsigned a, unsigned b) {
    int **const arr = new int *[a];
    arr[0] = new int[a * b];

    for (int i = 1; i < a; ++i) {
        arr[i] = arr[i - 1] + b;
    }
    return arr;
}

void free_array_2d(const int *const *const arr, unsigned a) {
    delete[] arr[0];
    delete[] arr;
}


int **transpose(const int *const *m, unsigned rows, unsigned cols) {
    int **const transposed = create_array_2d(cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = m[i][j];
        }
    }

    return transposed;
}
