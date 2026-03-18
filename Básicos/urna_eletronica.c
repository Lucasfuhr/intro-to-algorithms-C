/**
 * @file urna_eletronica.c
 * @brief Sistema de apuração de votos com interface informativa de candidatos.
 * * O programa exibe os códigos de votação, processa as entradas dos eleitores
 * e gera relatórios estatísticos de votos totais e válidos.
 */

 #include <stdio.h>

 int main() {
     int eleitores;
     int voto, votosA = 0, votosB = 0, votosC = 0, votosD = 0, brancos = 0, nulos = 0;
     int i;
 
     printf("Informe a quantidade de eleitores: ");
     if (scanf("%d", &eleitores) != 1 || eleitores <= 0) {
         printf("Quantidade inválida.\n");
         return 1;
     }
 
     // Menu de referência para os eleitores
     printf("\n--- Opcoes de Voto ---\n");
     printf("Candidato A: 31\n");
     printf("Candidato B: 49\n");
     printf("Candidato C: 74\n");
     printf("Candidato D: 98\n");
     printf("Branco:       0\n");
     printf("Qualquer outro valor sera considerado NULO.\n");
     printf("----------------------\n\n");
 
     // Processamento da votação
     for (i = 1; i <= eleitores; i++) {
         printf("Eleitor %d - Informe seu voto: ", i);
         scanf("%d", &voto);
 
         if (voto == 31) {
             votosA++;
         } else if (voto == 49) {
             votosB++;
         } else if (voto == 74) {
             votosC++;
         } else if (voto == 98) {
             votosD++;
         } else if (voto == 0) {
             brancos++;
         } else {
             nulos++;
         }
     }
 
     int totalValidos = votosA + votosB + votosC + votosD;
 
     // Relatório de Votos Totais
     printf("\n--- ESTATISTICAS GERAIS ---\n");
     printf("Candidato A: %d (%.1f%%)\n", votosA, (votosA * 100.0) / eleitores);
     printf("Candidato B: %d (%.1f%%)\n", votosB, (votosB * 100.0) / eleitores);
     printf("Candidato C: %d (%.1f%%)\n", votosC, (votosC * 100.0) / eleitores);
     printf("Candidato D: %d (%.1f%%)\n", votosD, (votosD * 100.0) / eleitores);
     printf("Brancos:     %d (%.1f%%)\n", brancos, (brancos * 100.0) / eleitores);
     printf("Nulos:       %d (%.1f%%)\n", nulos, (nulos * 100.0) / eleitores);
 
     // Relatório de Votos Válidos
     if (totalValidos > 0) {
         printf("\n--- VOTOS VALIDOS ---\n");
         printf("Candidato A: %.1f%%\n", (votosA * 100.0) / totalValidos);
         printf("Candidato B: %.1f%%\n", (votosB * 100.0) / totalValidos);
         printf("Candidato C: %.1f%%\n", (votosC * 100.0) / totalValidos);
         printf("Candidato D: %.1f%%\n", (votosD * 100.0) / totalValidos);
     } else {
         printf("\nNao houve votos validos para calculo proporcional.\n");
     }
 
     return 0;
 }