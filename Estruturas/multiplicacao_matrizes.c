/**
 * @file multiplicacao_matrizes.c
 * @brief Algoritmo para multiplicação de matrizes (A * B = C).
 * * O programa valida a compatibilidade das dimensões (Colunas de A == Linhas de B)
 * e realiza o cálculo através de uma função.
 */

 #include <stdio.h>

 int multiplicar_matrizes(int A[][6], int B[][10], int C[][10], int al, int ac, int bl, int bc) {
     if (ac != bl) {
         return 0; 
     }
 
     for (int i = 0; i < al; i++) {
         for (int j = 0; j < bc; j++) {
             C[i][j] = 0; // Inicializa a célula destinataria
             for (int k = 0; k < ac; k++) {
                 C[i][j] += A[i][k] * B[k][j];
             }
         }
     }
     return 1;
 }
 
 int main() {
     int i, j;
     int A[4][6], B[6][10], C[4][10];
 
     // Entrada de dados (Matriz A)
     printf("Preenchimento da Matriz A (4x6):\n");
     for (i = 0; i < 4; i++) {
         for (j = 0; j < 6; j++) {
             printf("A[%d][%d]: ", i, j);
             scanf("%d", &A[i][j]);
         }
     }
 
     // Entrada de dados(Matriz B)
     printf("\nPreenchimento da Matriz B (6x10):\n");
     for (i = 0; i < 6; i++) {
         for (j = 0; j < 10; j++) {
             printf("B[%d][%d]: ", i, j);
             scanf("%d", &B[i][j]);
         }
     }
 
     // Processamento e Saída
     if (multiplicar_matrizes(A, B, C, 4, 6, 6, 10)) {
         printf("\n--- Matriz A ---\n");
         for (i = 0; i < 4; i++) {
             for (j = 0; j < 6; j++) printf("%4d ", A[i][j]);
             printf("\n");
         }
 
         printf("\n--- Matriz B ---\n");
         for (i = 0; i < 6; i++) {
             for (j = 0; j < 10; j++) printf("%4d ", B[i][j]);
             printf("\n");
         }
 
         printf("\n--- Matriz Resultado (C) ---\n");
         for (i = 0; i < 4; i++) {
             for (j = 0; j < 10; j++) printf("%4d ", C[i][j]);
             printf("\n");
         }
     } else {
         printf("\nErro: Operação inválida! Dimensões incompatíveis.\n");
     }
 
     return 0;
 }