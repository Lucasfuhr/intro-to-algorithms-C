/**
 * @file consumo_viagem.c
 * * Cálculo de consumo de combustível baseado em informações básicas.
 * * O algoritmo utiliza a relação entre tempo e velocidade média para determinar
 * a distância percorrida e, consequentemente, a autonomia necessária.
 */

 #include <stdio.h>

 /* Definição de constantes de hardware/veículo */
 #define CONSUMO_MEDIO_VEICULO 12.7  // Eficiência em km/l
 
 int main() {
     double tempo_viagem_horas;
     double velocidade_media_kmh;
     double distancia_total_km;
     double litros_necessarios;
 
     if (scanf("%lf %lf", &tempo_viagem_horas, &velocidade_media_kmh) != 2) {
         return 1; 
     }
 
     // Cálculo da cinemática escalar básica: d = v * t
     distancia_total_km = tempo_viagem_horas * velocidade_media_kmh;
 
     // Determinação do consumo
     litros_necessarios = distancia_total_km / CONSUMO_MEDIO_VEICULO;
 
     // Saída com precisão de 3 casas decimais conforme especificado pelo enunciado do exercício proposto pelo professor
     printf("%.3f\n", litros_necessarios);
 
     return 0;
 }