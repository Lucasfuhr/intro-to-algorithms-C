/**
 * @file aposentadoria.c
 * @brief Sistema de verificação de requisitos para aposentadoria.
 * * Regras aplicadas: 
 * - Homens: 65 anos / 35 serviço / 95 pontos.
 * - Mulheres: 60 anos / 30 serviço / 85 pontos.
 */

 #include <stdio.h>

 int main() {
     int idade, tempo_servico, soma_pontos;
     char sexo;
 
     // Entrada de dados
     printf("Informe a idade: ");
     scanf("%d", &idade);
 
     printf("Informe o sexo (m/f): ");
     scanf(" %c", &sexo); 
 
     printf("Informe o tempo de servico: ");
     scanf("%d", &tempo_servico);
 
     soma_pontos = idade + tempo_servico;
 
     // Validação da lógica para o sexo masculino
     if (sexo == 'm') {
         if (idade >= 65 || tempo_servico >= 35 || soma_pontos >= 95) {
             printf("Apto para se aposentar\n");
         } else {
             printf("aposentadoria negada\n");
         }
     } 
     // Validação da lógica para o sexo feminino
     else if (sexo == 'f') {
         if (idade >= 60 || tempo_servico >= 30 || soma_pontos >= 85) {
             printf("Apto para se aposentar\n");
         } else {
             printf("aposentadoria negada\n");
         }
     }
 
     return 0;
 }