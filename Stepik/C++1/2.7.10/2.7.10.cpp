#include <algorithm>

void swap_min(int *m[], unsigned rows, unsigned cols) {
    int row_min = 0;
    int min = m[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (m[i][j] < min) {
                min = m[i][j];
                row_min = i;
            }
        }
    }

    std::swap(m[0], m[row_min]);
}
