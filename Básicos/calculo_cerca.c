/**
 * @file calculo_cerca.c
 * * Programa para estimativa de custo de cercamento de terrenos retangulares.
 * * O programa calcula o perímetro total com base nas dimensões fornecidas
 * e aplica o valor de mercado do metro linear da tela.
 */

 #include <stdio.h>

 int main() {
     double largura, comprimento;
     double preco_metro_tela;
     double custo_total;
 
     // Entrada de dados com interface amigável
     printf("Informe a largura do terreno (m): ");
     if (scanf("%lf", &largura) != 1 || largura <= 0) {
         printf("Erro: Dimensão inválida.\n");
         return 1;
     }
 
     printf("Informe o comprimento do terreno (m): ");
     if (scanf("%lf", &comprimento) != 1 || comprimento <= 0) {
         printf("Erro: Dimensão inválida.\n");
         return 1;
     }
 
     printf("Informe o preço do metro de tela (R$): ");
     if (scanf("%lf", &preco_metro_tela) != 1 || preco_metro_tela < 0) {
         printf("Erro: Preço inválido.\n");
         return 1;
     }
 
     // Cálculo do perímetro (2L + 2C) multiplicado pelo valor unitário
     // Mantendo a lógica linear para clareza técnica
     custo_total = (2 * largura + 2 * comprimento) * preco_metro_tela;
 
     // Saída formatada conforme requisito de precisão monetária
     printf("\nCusto de R$ %.2f\n", custo_total);
 
     return 0;
 }