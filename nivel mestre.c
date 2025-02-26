#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4];
    char nome[50];
    float pontos_turisticos;
    float populacao;
    float area;
    float pib;
} Cidade;

void exibirMenuAtributos() {
    printf("Escolha um atributo para comparar:\n");
    printf("1. Pontos turísticos\n");
    printf("2. População\n");
    printf("3. Área\n");
    printf("4. PIB\n");
}

int obterAtributoEscolhido(int escolhido) {
    int atributo;
    do {
        exibirMenuAtributos();
        scanf("%d", &atributo);
        if (atributo == escolhido) {
            printf("Atributo já escolhido. Escolha outro.\n");
        }
    } while (atributo == escolhido);
    return atributo;
}

float obterValorAtributo(Cidade cidade, int atributo) {
    switch (atributo) {
        case 1: return cidade.pontos_turisticos;
        case 2: return cidade.populacao;
        case 3: return cidade.area;
        case 4: return cidade.pib;
        default: return 0;
    }
}

void compararCartas(Cidade cidade1, Cidade cidade2, int atributo1, int atributo2) {
    float valor1_attr1 = obterValorAtributo(cidade1, atributo1);
    float valor1_attr2 = obterValorAtributo(cidade1, atributo2);
    float valor2_attr1 = obterValorAtributo(cidade2, atributo1);
    float valor2_attr2 = obterValorAtributo(cidade2, atributo2);

    int pontos_cidade1 = (valor1_attr1 > valor2_attr1 ? 1 : (valor1_attr1 < valor2_attr1 ? -1 : 0)) +
                         (valor1_attr2 > valor2_attr2 ? 1 : (valor1_attr2 < valor2_attr2 ? -1 : 0));
    int pontos_cidade2 = (valor2_attr1 > valor1_attr1 ? 1 : (valor2_attr1 < valor1_attr1 ? -1 : 0)) +
                         (valor2_attr2 > valor1_attr2 ? 1 : (valor2_attr2 < valor1_attr2 ? -1 : 0));

    float soma_cidade1 = valor1_attr1 + valor1_attr2;
    float soma_cidade2 = valor2_attr1 + valor2_attr2;

    printf("Comparação entre %s e %s:\n", cidade1.nome, cidade2.nome);
    printf("Atributo 1: %d, Atributo 2: %d\n", atributo1, atributo2);
    printf("%s - Atributo 1: %.2f, Atributo 2: %.2f, Soma: %.2f\n", cidade1.nome, valor1_attr1, valor1_attr2, soma_cidade1);
    printf("%s - Atributo 1: %.2f, Atributo 2: %.2f, Soma: %.2f\n", cidade2.nome, valor2_attr1, valor2_attr2, soma_cidade2);

    if (soma_cidade1 > soma_cidade2) {
        printf("Vencedor: %s\n", cidade1.nome);
    } else if (soma_cidade1 < soma_cidade2) {
        printf("Vencedor: %s\n", cidade2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Cidade cidades[] = {
        {"A01", "Esmeraldas, Minas Gerais", 15, 0.07, 908.50, 1.20},
        {"A02", "Belo Horizonte, Minas Gerais", 20, 2.52, 331.40, 94.30},
        {"A03", "Betim, Minas Gerais", 10, 0.43, 345.90, 20.10},
        {"A04", "Montes Claros, Minas Gerais", 12, 0.41, 3569.30, 12.70}
    };

    int cidade1, cidade2, atributo1, atributo2;

    printf("Escolha duas cidades para comparar (1-4):\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, cidades[i].nome);
    }

    scanf("%d %d", &cidade1, &cidade2);
    cidade1--; cidade2--;

    atributo1 = obterAtributoEscolhido(-1);
    atributo2 = obterAtributoEscolhido(atributo1);

    compararCartas(cidades[cidade1], cidades[cidade2], atributo1, atributo2);

    return 0;
}