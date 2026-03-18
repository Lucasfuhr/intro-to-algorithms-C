/**
 * @file gestao_logistica.c
 * @brief Sistema de gestão de entregas e análise de rentabilidade.
 * * O software calcula o balanço financeiro diário de uma frota, considerando:
 * - Distância percorrida (ida e volta).
 * - Consumo de combustível e preço por litro.
 * - Margem de ganho sobre o valor da carga.
 * - Identificação das entregas de maior e menor performance.
 */

 #include <stdio.h>

 // Protótipos das funções
 void ler_dados_entregas(float *distancias, float *valores, int total);
 float calcular_balanco_diario(float *dist, float *val, int total, float km_litro, float preco, float margem, int *melhor_id, int *pior_id);
 
 int main() {
     int n, melhor_id, pior_id;
     float consumo_kml, preco_combustivel, margem_percentual;
     float balanco_total;
 
     // Quantidade de operações do dia
     if (scanf("%d", &n) != 1 || n <= 0) return 1;
 
     // Alocação de vetores
     float vet_distancias[n];
     float vet_valores_carga[n];
 
     ler_dados_entregas(vet_distancias, vet_valores_carga, n);
 
     if (scanf("%f %f %f", &consumo_kml, &preco_combustivel, &margem_percentual) != 3) return 1;
 
     balanco_total = calcular_balanco_diario(vet_distancias, vet_valores_carga, n, 
                                             consumo_kml, preco_combustivel, margem_percentual, 
                                             &melhor_id, &pior_id);
 
     // Saída de dados formatada
     printf("Balanco do dia: R$ %.2f\n", balanco_total);
     printf("Melhor entrega: %d\n", melhor_id);
     printf("Pior entrega: %d\n", pior_id);
 
     return 0;
 }
 
 /**
  * Coleta os dados de entrada para cada entrega realizada.
  */
 void ler_dados_entregas(float *distancias, float *valores, int total) {
     for (int i = 0; i < total; i++) {
         scanf("%f %f", &distancias[i], &valores[i]);
     }
 }
 
 /**
  * Processa a rentabilidade individual e global.
  * @return Soma total do lucro líquido do dia.
  */
 float calcular_balanco_diario(float *dist, float *val, int total, float km_litro, float preco, float margem, int *id_m, int *id_p) {
     float soma_total = 0;
     float max_lucro, min_lucro;
 
     for (int i = 0; i < total; i++) {
         // Cálculo de percurso (ida e volta)
         float distancia_total = dist[i] * 2.0;
         float gasto_combustivel = (distancia_total / km_litro) * preco;
         
         // Receita: margem sobre a carga + valor fixo por km rodado
         float ganho_bruto = (val[i] * (margem / 100.0)) + distancia_total;
         
         // Lucro líquido da operação (individual)
         float lucro_liq = ganho_bruto - gasto_combustivel;
         soma_total += lucro_liq;
 
         // Análise comparativa final (performance)
         if (i == 0) {
             max_lucro = lucro_liq;
             min_lucro = lucro_liq;
             *id_m = 1;
             *id_p = 1;
         } else {
             if (lucro_liq > max_lucro) {
                 max_lucro = lucro_liq;
                 *id_m = i + 1; 
             }
             if (lucro_liq < min_lucro) {
                 min_lucro = lucro_liq;
                 *id_p = i + 1;
             }
         }
     }
     return soma_total;
 }