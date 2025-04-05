#include <stdio.h>

int main() {
    // Declaração das variáveis para as cartas
    char estado1[3], codigo1[5], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidadePop1, pibPerCapita1;
    int pontosTuristicos1;

    char estado2[3], codigo2[5], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidadePop2, pibPerCapita2;
    int pontosTuristicos2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Informe o estado da Carta 1: ");
    scanf("%s", estado1);
    printf("Informe o código da Carta 1: ");
    scanf("%s", codigo1);
    printf("Informe o nome da cidade da Carta 1: ");
    scanf(" %[^\n]", cidade1);
    printf("Informe a população da Carta 1: ");
    scanf("%lu", &populacao1);
    printf("Informe a área (em km²) da Carta 1: ");
    scanf("%f", &area1);
    printf("Informe o PIB (em bilhões de reais) da Carta 1: ");
    scanf("%f", &pib1);
    printf("Informe o número de pontos turísticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculo da Densidade Populacional e PIB per Capita para a Carta 1
    densidadePop1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1e9) / populacao1;

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Informe o estado da Carta 2: ");
    scanf("%s", estado2);
    printf("Informe o código da Carta 2: ");
    scanf("%s", codigo2);
    printf("Informe o nome da cidade da Carta 2: ");
    scanf(" %[^\n]", cidade2);
    printf("Informe a população da Carta 2: ");
    scanf("%lu", &populacao2);
    printf("Informe a área (em km²) da Carta 2: ");
    scanf("%f", &area2);
    printf("Informe o PIB (em bilhões de reais) da Carta 2: ");
    scanf("%f", &pib2);
    printf("Informe o número de pontos turísticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da Densidade Populacional e PIB per Capita para a Carta 2
    densidadePop2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Escolha do atributo para comparação (População neste exemplo)
    printf("\nComparação de Cartas (Atributo: População):\n");

    // Exibição dos dados das cartas
    printf("Carta 1 - %s (%s): %lu\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu\n", cidade2, estado2, populacao2);

    // Lógica para determinar a carta vencedora
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}