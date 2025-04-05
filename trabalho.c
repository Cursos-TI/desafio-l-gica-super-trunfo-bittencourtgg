#include <stdio.h>
#include <string.h>

int main() {
    char nomePais1[50], nomePais2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2, densidade1, densidade2;
    int pontosTuristicos1, pontosTuristicos2;
    int atributo1 = -1, atributo2 = -1;
    float valor1_c1 = 0, valor2_c1 = 0, valor1_c2 = 0, valor2_c2 = 0;
    float soma1 = 0, soma2 = 0;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", nomePais1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões R$): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);
    densidade1 = (area1 > 0) ? (populacao1 / area1) : 0;

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", nomePais2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões R$): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);
    densidade2 = (area2 > 0) ? (populacao2 / area2) : 0;

    // Menu de escolha dos atributos
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Erro: Atributo inválido.\n");
        return 1;
    }

    printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == atributo1) continue;
        switch (i) {
            case 1: printf("%d. População\n", i); break;
            case 2: printf("%d. Área\n", i); break;
            case 3: printf("%d. PIB\n", i); break;
            case 4: printf("%d. Pontos Turísticos\n", i); break;
            case 5: printf("%d. Densidade Demográfica\n", i); break;
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Erro: Atributo inválido ou repetido.\n");
        return 1;
    }

    // Função auxiliar interna: pega o valor do atributo para cada carta
    float getValor(int attr, int carta) {
        switch (attr) {
            case 1: return (carta == 1) ? populacao1 : populacao2;
            case 2: return (carta == 1) ? area1 : area2;
            case 3: return (carta == 1) ? pib1 : pib2;
            case 4: return (carta == 1) ? pontosTuristicos1 : pontosTuristicos2;
            case 5: return (carta == 1) ? densidade1 : densidade2;
            default: return 0;
        }
    }

    // Obter valores dos dois atributos para cada carta
    valor1_c1 = getValor(atributo1, 1);
    valor1_c2 = getValor(atributo1, 2);
    valor2_c1 = getValor(atributo2, 1);
    valor2_c2 = getValor(atributo2, 2);

    // Exibição detalhada
    char* nomeAtributo(int attr) {
        switch (attr) {
            case 1: return "População";
            case 2: return "Área";
            case 3: return "PIB";
            case 4: return "Pontos Turísticos";
            case 5: return "Densidade Demográfica";
            default: return "Desconhecido";
        }
    }

    printf("\n===== COMPARAÇÃO ENTRE CARTAS =====\n");
    printf("País 1: %s\n", nomePais1);
    printf("País 2: %s\n\n", nomePais2);

    // Comparar atributo 1
    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f\n", nomePais1, valor1_c1);
    printf("%s: %.2f\n", nomePais2, valor1_c2);
    if (atributo1 == 5) // Densidade: menor vence
        printf("-> %s venceu este atributo!\n\n", (valor1_c1 < valor1_c2) ? nomePais1 : (valor1_c2 < valor1_c1 ? nomePais2 : "Empate"));
    else
        printf("-> %s venceu este atributo!\n\n", (valor1_c1 > valor1_c2) ? nomePais1 : (valor1_c2 > valor1_c1 ? nomePais2 : "Empate"));

    // Comparar atributo 2
    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f\n", nomePais1, valor2_c1);
    printf("%s: %.2f\n", nomePais2, valor2_c2);
    if (atributo2 == 5) // Densidade: menor vence
        printf("-> %s venceu este atributo!\n\n", (valor2_c1 < valor2_c2) ? nomePais1 : (valor2_c2 < valor2_c1 ? nomePais2 : "Empate"));
    else
        printf("-> %s venceu este atributo!\n\n", (valor2_c1 > valor2_c2) ? nomePais1 : (valor2_c2 > valor2_c1 ? nomePais2 : "Empate"));

    // Soma dos atributos
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", nomePais1, soma1);
    printf("%s: %.2f\n", nomePais2, soma2);

    // Resultado final
    printf("\n===== RESULTADO FINAL =====\n");
    if (soma1 > soma2)
        printf("Resultado: Carta 1 (%s) venceu a rodada!\n", nomePais1);
    else if (soma2 > soma1)
        printf("Resultado: Carta 2 (%s) venceu a rodada!\n", nomePais2);
    else
        printf("Resultado: Empate!\n");

    return 0;
}
