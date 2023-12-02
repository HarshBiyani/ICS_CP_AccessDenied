#include <stdio.h>
#include <stdlib.h>
void Name(){
    printf("\033[1;32m");
    printf("\033[1m");
    printf("\t\t                     ___                  \n");
    printf("\t\t|V| _ _|_ __ o        |  _  _  |  |  o _|_\n");
    printf("\t\t| |(_| |_ |  | ><     | (_)(_) |  |< |  |_\n");
    printf("\033[0m");
    printf("\033[0m");


return;
}
int determinant(int x, int mat[x][x]) {
    if (x == 1) {
        return mat[0][0];
    }
    int det = 0;
    int submatrix[x - 1][x - 1];
    int sign = 1;
    for (int i = 0; i < x; i++) {
        int subi = 0;
        for (int row = 1; row < x; row++) {
            int subj = 0;
            for (int col = 0; col < x; col++) {
                if (col == i) {
                    continue;
                }
                submatrix[subi][subj] = mat[row][col];
                subj++;
            }
            subi++;
        }
        det = det + sign * mat[0][i] * determinant(x - 1, submatrix);
        sign = -sign;
    }
    return det;
}

void transpose(int m, int n, int matrix[m][n], int result[n][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void checksymmetricity(int x, int mat[x][x]) {
    int result[x][x];
    transpose(x, x, mat, result);
    int symmetric = 1;
    int skew_symmetric = 1;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (mat[i][j] != result[i][j]) {
                symmetric = 0;
                break;
            }

            if (mat[i][j] != -result[i][j]) {
                skew_symmetric = 0;
                break;
            }
        }
    }
    printf("\033[0;36m");
    if (symmetric) {
        printf("The given matrix is symmetric.\n");
    } else if (skew_symmetric) {
        printf("The given matrix is skew-symmetric.\n");
    } else {
        printf("The given matrix is neither symmetric nor skew-symmetric.\n");
    }printf("\033[0m");
}

void adjoint(int x, int mat[x][x], int result[x][x]) {
    int sign = 1;
    int submatrix[x - 1][x - 1];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            int subi = 0;
            for (int row = 0; row < x; row++) {
                int subj = 0;
                for (int col = 0; col < x; col++) {
                    if (row == i || col == j) {
                        continue;
                    }
                    submatrix[subi][subj] = mat[row][col];
                    subj++;
                }
                if (row != i) {
                    subi++;
                }
            }
            result[i][j] = sign * determinant(x - 1, submatrix);
            sign = -sign;
        }
    }
}

void inverse(int x, int mat[x][x], float result[x][x]) {
    float det = determinant(x, mat);
    if (det == 0) {
        printf("The matrix is singular. Inverse does not exist.\n");
        return;
    }

    int adj[x][x];
    adjoint(x, mat, adj);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            result[i][j] = adj[i][j] / det;
        }
    }
}

void Addition(int m, int n, int matrix1[m][n], int matrix2[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtraction(int m, int n, int matrix1[m][n], int matrix2[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void scalarmultiplication(int m, int n, int matrix[m][n], int result[m][n]) {
    int k;
    printf("Enter the value of the scalar: ");printf("\033[0;33m");
    scanf("%d", &k);printf("\033[0m");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = k * matrix[i][j];
        }
    }
}

void multiplication(int m, int n, int o, int p, int matrix1[m][n], int matrix2[n][o], int result[m][o]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int trace(int x, int mat[x][x]) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += mat[i][i];
    }
    return sum;
}





void singularity(int x, int mat[x][x]) {
    float result = determinant(x, mat);printf("\033[0;36m");
    if (result == 0) {
        printf("The given matrix is a singular matrix.\n");
    } else {
        printf("The given matrix is a non-singular matrix.\n");
    }printf("\033[0m");
}



int main() {

    int choice;

   
    char ch;
    do {
        //printf("\nMatrix Operations Menu:\n");
        Name();
        printf("\033[1;31m");
        printf("\n1) Determinant of a matrix\n");
        printf("2) Checking singularity of a matrix\n");
        printf("3) Checking whether the matrix is symmetric or skew symmetric\n");
        printf("4) Adjoint\n");
        printf("5) Inverse of matrix\n");
        printf("6) Addition of two matrices\n");
        printf("7) Subtraction of two matrices\n");
        printf("8) Scalar multiplication of matrix\n");
        printf("9) Multiplication of matrices\n");
        printf("10) Trace of a matrix\n");
        printf("11) Transpose of a matrix\n");
        printf("\033[0m");
        //printf("12) Exit\n");

        printf("\nEnter the index of the function you want to perform : ");
        printf("\033[0;33m");
        scanf("%d", &choice);
        printf("\033[0m");
        switch (choice) {
                        case 1: {
                int x;
                printf("Enter the order of the matrix: ");
                printf("\033[0;33m");
                scanf("%d", &x);printf("\033[0m");

                int mat[x][x];

                printf("Enter the elements in the matrix:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {printf("\033[0;33m");
                        scanf("%d", &mat[i][j]);printf("\033[0m");
                    }
                }

                int det = determinant(x, mat);printf("\033[0;36m");
                printf("Determinant of the matrix is: %d\n", det);printf("\033[0m");
                break;
            }

            case 2: {
                int x;
                printf("Enter the order of the matrix: ");
                printf("\033[0;33m");scanf("%d", &x);printf("\033[0m");

                int mat[x][x];

                printf("Enter the elements in the matrix:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {printf("\033[0;33m");
                        scanf("%d", &mat[i][j]);printf("\033[0m");
                    }
                }

                singularity(x, mat);
                break;
            }

            case 3: {
                int x;
                printf("Enter the order of the matrix: ");printf("\033[0;33m");
                scanf("%d", &x);printf("\033[0m");

                int mat[x][x];

                printf("Enter the elements in the matrix:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {printf("\033[0;33m");
                        scanf("%d", &mat[i][j]);printf("\033[0m");
                    }
                }

                checksymmetricity(x, mat);
                break;
            }

            case 4: {
                int x;
                printf("Enter the order of the matrix: ");printf("\033[0;33m");
                scanf("%d", &x);printf("\033[0m");

                int mat[x][x];
                int adj[x][x];

                printf("Enter the elements in the matrix:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {printf("\033[0;33m");
                        scanf("%d", &mat[i][j]);printf("\033[0m");
                    }
                }

                adjoint(x, mat, adj);printf("\033[0;36m");
                printf("Adjoint of the matrix is:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {
                        printf("%d ", adj[i][j]);
                    }
                    printf("\n");
                }printf("\033[0m");
                break;
            }

            case 5: {
                int x;
                printf("Enter the order of the matrix: ");printf("\033[0;33m");
                scanf("%d", &x);printf("\033[0m");

                int mat[x][x];
                float result[x][x];

                printf("Enter the elements in the matrix:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {printf("\033[0;33m");
                        scanf("%d", &mat[i][j]);printf("\033[0m");
                    }
                }

                inverse(x, mat, result);printf("\033[0;36m");
                printf("Inverse of the matrix is:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {
                        printf("%f ", result[i][j]);
                    }
                    printf("\n");
                }printf("\033[0m");
                break;
            }
            case 6: {
                int m, n;
                printf("Enter the number of rows: ");printf("\033[0;33m");
                scanf("%d", &m);printf("\033[0m");
                printf("Enter the number of columns: ");printf("\033[0;33m");
                scanf("%d", &n);printf("\033[0m");

                int matrix1[m][n];
                int matrix2[m][n];
                int result[m][n];

                printf("Enter the values of elements in matrix1:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix1[i][j]);printf("\033[0m");
                    }
                }

                printf("Enter the values of elements in matrix2:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix2[i][j]);printf("\033[0m");
                    }
                }

                Addition(m, n, matrix1, matrix2, result);printf("\033[0;36m");
                printf("Addition of the matrices is:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }printf("\033[0m");
                break;
            }

            case 7: {
                int m, n;
                printf("Enter the number of rows: ");printf("\033[0;33m");
                scanf("%d", &m);printf("\033[0m");
                printf("Enter the number of columns: ");printf("\033[0;33m");
                scanf("%d", &n);printf("\033[0m");

                int matrix1[m][n];
                int matrix2[m][n];
                int result[m][n];

                printf("Enter the values of elements in matrix1:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix1[i][j]);printf("\033[0m");
                    }
                }

                printf("Enter the values of elements in matrix2:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix2[i][j]);printf("\033[0m");
                    }
                }

                subtraction(m, n, matrix1, matrix2, result);printf("\033[0;36m");
                printf("Subtraction of the matrices is:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }printf("\033[0m");
                break;
            }

            case 8: {
                int m, n;
                printf("Enter the number of rows: ");printf("\033[0;33m");
                scanf("%d", &m);printf("\033[0m");
                printf("Enter the number of columns: ");printf("\033[0;33m");
                scanf("%d", &n);printf("\033[0m");

                int matrix[m][n];
                int scalarproduct[m][n];

                printf("Enter the elements of the matrix:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix[i][j]);printf("\033[0m");
                    }
                }

                scalarmultiplication(m, n, matrix, scalarproduct);printf("\033[0;36m");
                printf("Scalar multiplication of the matrix is:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", scalarproduct[i][j]);
                    }
                    printf("\n");
                }printf("\033[0m");
                break;
            }

            case 9: {
                int m, n, o, p;
                printf("Enter the number of rows in the first matrix: ");printf("\033[0;33m");
                scanf("%d", &m);printf("\033[0m");
                printf("Enter the number of columns in the first matrix: ");printf("\033[0;33m");
                scanf("%d", &n);printf("\033[0m");
                printf("Enter the number of rows in the second matrix: ");printf("\033[0;33m");
                scanf("%d", &o);printf("\033[0m");
                printf("Enter the number of columns in the second matrix: ");printf("\033[0;33m");
                scanf("%d", &p);printf("\033[0m");

                if (n != o) {
                    printf("Multiplication of these matrices is not possible as the number of columns in the first matrix is not equal to the number of rows in the second matrix.\n");
                    break;
                }

                int matrix1[m][n];
                int matrix2[o][p];
                int result[m][p];

                printf("Enter the elements of the first matrix:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix1[i][j]);printf("\033[0m");
                    }
                }

                printf("Enter the elements of the second matrix:\n");
                for (int i = 0; i < o; i++) {
                    for (int j = 0; j < p; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix2[i][j]);printf("\033[0m");
                    }
                }

                multiplication(m, n, o, p, matrix1, matrix2, result);printf("\033[0;36m");
                printf("Multiplication of the matrices is:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < p; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }printf("\033[0m");
                break;
            }

            case 10: {
                int x;
                printf("Enter the order of the matrix: ");printf("\033[0;33m");
                scanf("%d", &x);printf("\033[0m");

                int mat[x][x];

                printf("Enter the elements in the matrix:\n");
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {printf("\033[0;33m");
                        scanf("%d", &mat[i][j]);printf("\033[0m");
                    }
                }

                int diagonalsum = trace(x, mat);printf("\033[0;36m");
                printf("Trace of the matrix is: %d\n", diagonalsum);printf("\033[0m");
                break;
            }

            case 11: {
                int m, n;
                printf("Enter the number of rows: ");printf("\033[0;33m");
                scanf("%d", &m);printf("\033[0m");
                printf("Enter the number of columns: ");printf("\033[0;33m");
                scanf("%d", &n);printf("\033[0m");

                int matrix[m][n];
                int TP[n][m];

                printf("Enter the elements in the matrix:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {printf("\033[0;33m");
                        scanf("%d", &matrix[i][j]);printf("\033[0m");
                    }
                }

                transpose(m, n, matrix, TP);printf("\033[0;36m");
                printf("Transpose of the matrix is:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", TP[i][j]);
                    }
                    printf("\n");
                }printf("\033[0m");
                break;
            }

            default: {
                printf("Invalid input. Please enter a valid option.\n");
                break;
            }
        }
        printf("\n\nIf you want to exit the program type 'e' otherwise type anything:-");printf("\033[0;33m");
        scanf(" %c",&ch);printf("\033[0m");

        if(ch =='e'){printf("\033[0;35m");
            printf("\n\n");
            printf("\t\t___               \\ /          | \n");
            printf("\t\t | |_  _ __  |     Y  _        | \n");
            printf("\t\t | | |(_|| | |<    | (_)|_|    o \n");

            printf("\033[0m");
        }

    }while(ch != 'e');

    return 0;
}