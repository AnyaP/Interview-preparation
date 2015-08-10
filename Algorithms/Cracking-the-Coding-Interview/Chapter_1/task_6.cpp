# include "../../testing.h"
# include <iostream>
# include <vector>

void Rotate(std::vector<std::vector<int>>& matrix) {
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

int main(){
    std::vector<std::vector<int>> even_matrix(2, std::vector<int>(2));
    even_matrix[0][0] = 1;
    even_matrix[0][1] = 2;
    even_matrix[1][0] = 3;
    even_matrix[1][1] = 4;

    std::cout << even_matrix;
    Rotate(even_matrix);
    std::cout << even_matrix << std::endl;


    std::vector<std::vector<int>> odd_matrix(3, std::vector<int>(3));
    odd_matrix[0]= {1, 2, 3};
    odd_matrix[1]= {4, 5, 6};
    odd_matrix[2]= {7, 8, 9};

    std::cout << odd_matrix;
    Rotate(odd_matrix);
    std::cout << odd_matrix << std::endl;

    return 0;
}
