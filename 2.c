#include <stdio.h>

// Define the maximum size of the matrix
#define MAX_SIZE 100

// Function to multiply two matrices A and B
void multiply(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
    int temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < size; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = temp[i][j];
        }
    }
}

// Function to raise a matrix A to the power of N
void matrixPower(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int size, int N) {
    // Initialize the result matrix to the identity matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                B[i][j] = 1;
            } else {
                B[i][j] = 0;
            }
        }
    }

    // Perform matrix exponentiation
    while (N > 0) {
        if (N % 2 == 1) {
            multiply(B, A, B, size);
        }
        multiply(A, A, A, size);
        N /= 2;
    }
}

int main() {
    int T; // Number of test cases
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int M, N; // Matrix size and exponent
        scanf("%d %d", &M, &N);

        int A[MAX_SIZE][MAX_SIZE]; // Input matrix A
        int B[MAX_SIZE][MAX_SIZE]; // Result matrix B

        // Input matrix A
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &A[i][j]);
            }
        }

        // Calculate B = A^N
        matrixPower(A, B, M, N);

        // Output the result matrix B
        printf("Case %d:\n", caseNum);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d", B[i][j]);
                if (j < M - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
