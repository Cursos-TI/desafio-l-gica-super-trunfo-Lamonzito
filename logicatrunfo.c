#include <stdio.h>

#define MAX_CARTAS 2 // aqui eu limito a quantidade de cartas em dois//

void compararcartas(float valor1, float valor2, char nomeatributo[], int *pontos1, int *pontos2) // criando a função que compara os atributos das cartas//
{
    if (valor1 > valor2)
    {
        printf("A primeira carta ganha em '%s'!\n", nomeatributo);
        (*pontos1)++;
    }
    else if (valor1 < valor2)
    {
        printf("A segunda carta ganha em '%s'!\n", nomeatributo);
        (*pontos2)++;
    }
    else
    {
        printf("As duas cartas empatam em '%s'!\n", nomeatributo);
    }
}
void compararcartas_densidade(float valor1, float valor2, char nomeatributo[], int *pontos1, int *pontos2) // a densidade deve pontuar de maneira "oposta", isso é, quando um numero é inferior ao outro//
{
    if (valor1 < valor2)
    {
        printf("A primeira carta ganha em '%s'!\n", nomeatributo);
        (*pontos2)++;
    }
    else if (valor1 > valor2)
    {
        printf("A segunda carta ganha em '%s'!\n", nomeatributo);
        (*pontos1)++;
    }
    else
    {
        printf("As duas cartas empatam em '%s'!\n", nomeatributo);
    }
}
struct Carta // estrutura da carta//
{
    char estado[2];
    int id;
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float pib_per_capita;
    float densidade_pop;
};

int main()
{
    struct Carta cartas[MAX_CARTAS]; // aqui eu puxo a informação do limite de cartas e as introduzo na aplicação//
    int pontos[2] = {0, 0};          // aqui eu determino que ambos as cartas começam com zero pontos, e as introduzo na aplicação//

    printf("OLA, BEM VINDO AO CADASTRO DE CARTAS DO SUPER TRUNFO!\n\n"); // formalidade//
    for (int i = 0; i < MAX_CARTAS; i++)
    {
        printf("[CARTA #%d]!\n", i + 1);

        printf("Por favor, insira uma letra referente a oito estados (entre A - H): ");
        scanf("%1s", cartas[i].estado);

        printf("Insira o ID desta carta (1, 2, 3, 4): ");
        scanf("%d", &cartas[i].id);
        getchar();
        printf("Insira o nome da cidade: ");
        scanf("%49s", cartas[i].cidade);

        printf("Quantos habitantes moram em %s? ", cartas[i].cidade);
        scanf("%d", &cartas[i].populacao);

        printf("Qual a área da cidade de %s? (em km²): ", cartas[i].cidade);
        scanf("%f", &cartas[i].area);

        printf("Qual o PIB desta cidade? ");
        scanf("%f", &cartas[i].pib);

        printf("Quantos pontos turísticos existem em %s? ", cartas[i].cidade);
        scanf("%d", &cartas[i].pontos_turisticos);

        printf("\n");
    }

    printf("\n=========[CARTAS CADASTRADAS]=========\n");
    for (int i = 0; i < MAX_CARTAS; i++) // laço que acessa varias vezes o valor MAX_CARTAS, limitando a criação das cartas pra duas, começando com 0<2 e 1<2 que e verdade, e depois 2<2 que se torna mentira e fecha o laço//
    {
        printf("\n[CARTA #%d]\n", i + 1);
        printf("ID da cidade = %s%02d \n", cartas[i].estado, cartas[i].id);
        printf("Nome da cidade = %s \n", cartas[i].cidade);
        printf("População = %d habitantes\n", cartas[i].populacao);
        printf("Área = %.1f km²\n", cartas[i].area);
        printf("PIB = %.2f\n", cartas[i].pib);
        printf("Pontos turísticos = %d\n", cartas[i].pontos_turisticos);
        printf("PIB per capita = %f\n", cartas[i].pib_per_capita = cartas[i].pib / cartas[i].populacao);        // aqui eu faço a conta necessaria pra conseguir o pib per capita e a densidade populacional//
        printf("Densidade populacional= %f\n", cartas[i].densidade_pop = cartas[i].populacao / cartas[i].area); // aqui eu faço a conta necessaria pra conseguir o pib per capita e a densidade populacional//
        printf("\n\n");
    }
    printf("\n=======[Comparação dos Atributos]=======\n\n\n"); // nesta area acontece a comparação dos atributos, eu puxo a função de comparação e a aplico nos numeros que o usuario deu//
    compararcartas(cartas[0].populacao, cartas[1].populacao, "população", &pontos[0], &pontos[1]);
    compararcartas(cartas[0].area, cartas[1].area, "área", &pontos[0], &pontos[1]);
    compararcartas(cartas[0].pib, cartas[1].pib, "PIB", &pontos[0], &pontos[1]);
    compararcartas(cartas[0].pontos_turisticos, cartas[1].pontos_turisticos, "pontos turísticos", &pontos[0], &pontos[1]);
    compararcartas(cartas[0].pib_per_capita, cartas[1].pib_per_capita, "PIB per capita", &pontos[0], &pontos[1]);
    compararcartas_densidade(cartas[0].densidade_pop, cartas[1].densidade_pop, "Densidade populacional", &pontos[0], &pontos[1]);

    printf("\n\n\n");
    printf("=========[RESULTADO DA PARTIDA]=========\n\n\n");
    printf("Pontos da carta #1 '%s': %d\n", cartas[0].cidade, pontos[0]);
    printf("Pontos da carta #2 '%s': %d\n", cartas[1].cidade, pontos[1]);

    if (pontos[0] > pontos[1])
        printf("A primeira carta venceu!\n");
    else if (pontos[0] < pontos[1])
        printf("A segunda carta venceu!\n");
    else
        printf("As cartas empataram!\n");

    return 0;
}