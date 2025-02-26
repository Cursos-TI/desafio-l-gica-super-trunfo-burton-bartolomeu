#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4];
    char nome[50];
    int pontosTuristicos;
    float populacao; // em milhões
    float area; // em km²
    float pib; // em bilhões
    float densidadeDemografica; // calculada
} Cidade;

void calcularDensidadeDemografica(Cidade *cidade) {
    cidade->densidadeDemografica = cidade->populacao * 1000000 / cidade->area;
}

void exibirMenu() {
    printf("Escolha um atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    printf("Escolha uma opção: ");
}

void compararCidades(Cidade c1, Cidade c2, int opcao) {
    printf("Comparando %s e %s\n", c1.nome, c2.nome);
    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %.2f milhões\n", c1.nome, c1.populacao);
            printf("%s: %.2f milhões\n", c2.nome, c2.populacao);
            if (c1.populacao > c2.populacao) {
                printf("Vencedor: %s\n", c1.nome);
            } else if (c1.populacao < c2.populacao) {
                printf("Vencedor: %s\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", c1.nome, c1.area);
            printf("%s: %.2f km²\n", c2.nome, c2.area);
            if (c1.area > c2.area) {
                printf("Vencedor: %s\n", c1.nome);
            } else if (c1.area < c2.area) {
                printf("Vencedor: %s\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", c1.nome, c1.pib);
            printf("%s: %.2f bilhões\n", c2.nome, c2.pib);
            if (c1.pib > c2.pib) {
                printf("Vencedor: %s\n", c1.nome);
            } else if (c1.pib < c2.pib) {
                printf("Vencedor: %s\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("Atributo: Pontos turísticos\n");
            printf("%s: %d\n", c1.nome, c1.pontosTuristicos);
            printf("%s: %d\n", c2.nome, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos) {
                printf("Vencedor: %s\n", c1.nome);
            } else if (c1.pontosTuristicos < c2.pontosTuristicos) {
                printf("Vencedor: %s\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("Atributo: Densidade demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.nome, c1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", c2.nome, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica) {
                printf("Vencedor: %s\n", c1.nome);
            } else if (c1.densidadeDemografica > c2.densidadeDemografica) {
                printf("Vencedor: %s\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    Cidade cidades[] = {
        {"A01", "Esmeraldas, Minas Gerais", 15, 0.07, 908.50, 1.20, 0},
        {"A02", "Belo Horizonte, Minas Gerais", 20, 2.52, 331.40, 94.30, 0},
        {"A03", "Betim, Minas Gerais", 10, 0.43, 345.90, 20.10, 0},
        {"A04", "Montes Claros, Minas Gerais", 12, 0.41, 3569.30, 12.70, 0}
    };

    for (int i = 0; i < 4; i++) {
        calcularDensidadeDemografica(&cidades[i]);
    }

    char codigo1[4], codigo2[4];
    int opcao;

    printf("Digite o código da primeira cidade: ");
    scanf("%s", codigo1);
    printf("Digite o código da segunda cidade: ");
    scanf("%s", codigo2);

    Cidade *cidade1 = NULL, *cidade2 = NULL;
    for (int i = 0; i < 4; i++) {
        if (strcmp(cidades[i].codigo, codigo1) == 0) {
            cidade1 = &cidades[i];
        }
        if (strcmp(cidades[i].codigo, codigo2) == 0) {
            cidade2 = &cidades[i];
        }
    }

    if (cidade1 == NULL || cidade2 == NULL) {
        printf("Código de cidade inválido!\n");
        return 1;
    }

    exibirMenu();
    scanf("%d", &opcao);

    compararCidades(*cidade1, *cidade2, opcao);

    return 0;
}