/**
 * @file simetria_matriz.c
 * @brief Verificador de simetria em matrizes quadradas.
 * O algoritmo otimiza a verificação percorrendo apenas a triangular superior.
 */

 #include <stdio.h>

 int main() {
     // Definição das dimensões da matriz(no caso, 5x5)
     int linhas = 5, colunas = 5;
     int i, j;
     int e_simetrica = 1; // Flag: assume inicialmente que a matriz é simétrica
     int matriz[5][5];
 
     printf("Insira os elementos da matriz %dx%d:\n", linhas, colunas);
 
     // Leitura dos dados
     for (i = 0; i < linhas; i++) {
         for (j = 0; j < colunas; j++) {
             if (scanf("%d", &matriz[i][j]) != 1) {
                 return 1; // Se der erro na leitura
             }
         }
     }
 
     // lógica de verificacao:

     for (i = 0; i < linhas - 1; i++) {
         for (j = i + 1; j < colunas; j++) {
             if (matriz[i][j] != matriz[j][i]) {
                 e_simetrica = 0; // Se houver uma irregularidade, nao e simetrica
                 break;           // Otimização
             }
         }
         if (!e_simetrica) break; // Otimização: sai do loop externo
     }
 
     // Saída baseada no estado da flag
     if (e_simetrica) {
         printf("\nA matriz eh simetrica\n");
     } else {
         printf("\nA matriz nao eh simetrica\n");
     }
 
     return 0;
 }