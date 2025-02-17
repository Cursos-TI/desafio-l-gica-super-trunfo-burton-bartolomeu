#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4];
    char nome[50];
    char estado[50];
    int pontosTuristicos;
    float populacao;
    float area;
    float pib;
} Cidade;

void cadastrarCidade(Cidade *cidade) {
    printf("Digite o código da cidade: ");
    scanf("%s", cidade->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade->nome);
    printf("Digite o estado da cidade: ");
    scanf(" %[^\n]s", cidade->estado);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontosTuristicos);
    printf("Digite a população (em milhões): ");
    scanf("%f", &cidade->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &cidade->pib);
}

void compararCidades(Cidade cidade1, Cidade cidade2) {
    printf("Comparando %s e %s:\n", cidade1.nome, cidade2.nome);

    if (cidade1.populacao > cidade2.populacao) {
        printf("Cidade 1 tem maior população.\n");
    } else {
        printf("Cidade 2 tem maior população.\n");
    }

    if (cidade1.area > cidade2.area) {
        printf("Cidade 1 tem maior área.\n");
    } else {
        printf("Cidade 2 tem maior área.\n");
    }

    if (cidade1.pib > cidade2.pib) {
        printf("Cidade 1 tem maior PIB.\n");
    } else {
        printf("Cidade 2 tem maior PIB.\n");
    }

    if (cidade1.pontosTuristicos > cidade2.pontosTuristicos) {
        printf("Cidade 1 tem mais pontos turísticos.\n");
    } else {
        printf("Cidade 2 tem mais pontos turísticos.\n");
    }
}

int encontrarCidadePorCodigo(Cidade cidades[], int tamanho, char codigo[]) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(cidades[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Cidade cidades[4] = {
        {"A01", "Esmeraldas", "Minas Gerais", 15, 0.07, 908.50, 1.20},
        {"A02", "Belo Horizonte", "Minas Gerais", 20, 2.52, 331.40, 94.30},
        {"A03", "Betim", "Minas Gerais", 10, 0.43, 345.90, 20.10},
        {"A04", "Montes Claros", "Minas Gerais", 12, 0.41, 3569.30, 12.70}
    };

    char codigo1[4], codigo2[4];
    printf("Digite o código da primeira cidade (A01-A04): ");
    scanf("%s", codigo1);
    printf("Digite o código da segunda cidade (A01-A04): ");
    scanf("%s", codigo2);

    int cidade1 = encontrarCidadePorCodigo(cidades, 4, codigo1);
    int cidade2 = encontrarCidadePorCodigo(cidades, 4, codigo2);

    if (cidade1 == -1 || cidade2 == -1) {
        printf("Código de cidade inválido.\n");
    } else {
        compararCidades(cidades[cidade1], cidades[cidade2]);
    }

    return 0;
}