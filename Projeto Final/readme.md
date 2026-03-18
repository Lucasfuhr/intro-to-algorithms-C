# 🚚 Sistema de Gestão de Logística (Trabalho Final)

Este projeto consiste em um simulador de gestão financeira para uma empresa de entregas, desenvolvido como projeto de conclusão da disciplina de Algoritmos e Estrutura de Dados 1. 

O software processa o fluxo de trabalho de uma frota, calculando o balanço líquido entre receitas de frete e custos operacionais de combustível, identificando as operações de maior e menor performance.

## 📖 Enunciado e Regras de Negócio
O sistema recebe informações sobre a quantidade de entregas, distâncias (km), valor das encomendas (R$), consumo do veículo (km/L), preço do combustível e margem de lucro.

### Critérios de Cálculo:
* **Custo de Combustível:** Calculado sobre a distância de **ida e volta** de cada entrega.
* **Receita por Entrega:**
    * `Percentual de Lucro` aplicado sobre o valor da carga.
    * `Taxa de Entreagem:` R$ 2,00 por quilômetro rodado (apenas ida).
* **Balanço do Dia:** Diferença entre o valor total recebido e o gasto total com combustível.

## 🛠️ Requisitos Técnicos Implementados
O projeto foi construído respeitando as restrições acadêmicas e utilizando conceitos avançados da linguagem C:
- **Variáveis Homogêneas:** Uso de vetores para persistência de dados de múltiplas entregas.
- **Modularização:** - `preencher_dados`: Função responsável exclusivamente pela entrada de dados.
    - `processar_dia`: Função principal de lógica de negócios que calcula o balanço global.
- **Ponteiros (Passagem por Referência):** Utilizados na função de processamento para retornar simultaneamente os IDs da melhor e da pior entrega para a função `main`.

## 🚀 Como Utilizar

1. **Compilação:**
   ```bash
   gcc trabalho_final.c -o gestao_entregas