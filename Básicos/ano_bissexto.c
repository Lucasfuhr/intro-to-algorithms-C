/**
 * @file ano_bissexto.c
 * @brief Verificador de anos bissextos seguindo o calendário Gregoriano.
 * * A lógica implementada verifica as regras de divisibilidade:
 * 1. Divisível por 400 OU
 * 2. Divisível por 4 e NÃO divisível por 100.
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    int ano;

    // Interface de entrada
    printf("Informe o ano: ");
    if (scanf("%d", &ano) != 1) {
        printf("Erro: Entrada inválida.\n");
        return 1;
    }

    /**
     * Validação da regra de bissexto:
     * O uso de parênteses explicita a precedência lógica, garantindo 
     * que a verificação (4 e !100) seja tratada como um bloco único.
     */
    bool eh_divisivel_400 = (ano % 400 == 0);
    bool regra_padrao = (ano % 4 == 0 && ano % 100 != 0);

    if (eh_divisivel_400 || regra_padrao) {
        printf("eh bissexto\n");
    } else {
        printf("nao eh bissexto\n");
    }

    return 0;
}