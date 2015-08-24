# include "../../testing.h"
# include <iostream>
# include <vector>

using Matrix = std::vector<std::vector<int>>;

void Rotate(Matrix& matrix) {
    int N = matrix.size();
    for (int depth = 0; depth < N / 2; ++depth) {
        int start = depth;
        int stop = N - depth - 1;
        for (int i = start; i < stop; ++ i) {
            int tmp = matrix[depth][i];
            matrix[depth][i] = matrix[N - i - 1][depth];
            matrix[N - i - 1][depth] = matrix[N - depth - 1][N - i - 1];
            matrix[N - depth - 1][N - i - 1] = matrix[i][N - depth - 1];
            matrix[i][N - depth - 1] = tmp;
        }
    }
}

Matrix GenerateMatrix(int N) {
    Matrix matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = i*N + j;
        }
    }
    return matrix;
}

int main(){
    Matrix stress_matrix = GenerateMatrix(125);
    Matrix copy_stress_matrix = stress_matrix;
    for (int i = 0; i < 4; ++i) {
        Rotate(copy_stress_matrix);
    }
    //std::cout << stress_matrix;
    //std::cout << copy_stress_matrix << std::endl << std::endl;
    CHECK_EQUAL(stress_matrix, copy_stress_matrix);

    Matrix even_matrix(2, std::vector<int>(2));
    even_matrix = {
        {1, 2},
        {3, 4}
    };

    std::cout << even_matrix;
    Rotate(even_matrix);
    std::cout << even_matrix << std::endl;


    Matrix odd_matrix(3, std::vector<int>(3));
    odd_matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << odd_matrix;
    Rotate(odd_matrix);
    std::cout << odd_matrix << std::endl;

    return 0;
}
