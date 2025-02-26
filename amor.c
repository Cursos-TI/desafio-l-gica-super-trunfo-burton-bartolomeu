#include <stdio.h>

void menu();
void iniciarQuiz();
void sair();

int main() {
    menu();
    return 0;
}

void menu() {
    int escolha;
    do {
        printf("1. Iniciar o quiz <3\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                iniciarQuiz();
                break;
            case 2:
                sair();
                break;
            default:
                printf("oce digitou algu erradu, quer recomeçar? (S/N): ");
                char resposta;
                scanf(" %c", &resposta);
                if (resposta == 'N') {
                    return;
                }
        }
    } while (escolha != 1 && escolha != 2);
}

void iniciarQuiz() {
    char resposta1, resposta2, resposta3;

    printf("YEEEEEE okay,\n");
    printf("Eu sou o amor da sua vida? (S/N): ");
    scanf(" %c", &resposta1);
    printf("Oce me ama? (S/N): ");
    scanf(" %c", &resposta2);
    printf("Oce é a coisa mais perfeita do mundo? (S/N): ");
    scanf(" %c", &resposta3);

    if (resposta1 == 'S' && resposta2 == 'S' && resposta3 == 'S') {
        printf("YEEEEEEEEEEEEEEEEEE EU TE AMO MAIX QUI TUDU MEUH AMOR<3\n");
    } else if (resposta1 == 'N' && resposta2 == 'N' && resposta3 == 'N') {
        printf("NHAAAAAAAAAA PUQUEEEEEEE, MIM ESTA TISTIIIII ;(\n");
    } else if (resposta1 == 'S' && resposta2 == 'N' && resposta3 == 'N') {
        printf("YEEEE MIM SER SEUH AMOR... maix naum mi ama? NHIIIIIII... E OCE É SIIII!!!\n");
    } else if (resposta1 == 'N' && resposta2 == 'S' && resposta3 == 'N') {
        printf("NHIIII NAUM SOUH SEU AMOR?... maix oce mia ama hihihih... OCE È SIIIII È PERFEITA!!!\n");
    } else if (resposta1 == 'N' && resposta2 == 'N' && resposta3 == 'S') {
        printf("NHIIIII NAUM SOUH? PUQUEEEEEE NHII NAUM MI AMA, NHAAAAAA... hihihi maix é perfeita mesmo, minha deusa incrivel\n");
    } else if (resposta1 == 'S' && resposta2 == 'N' && resposta3 == 'S') {
        printf("YEEEEEEEE SOUH SEUH AMOR, E SIM OCE É A MAIS PURA PERFEIÇÃO... MAIX PUQUE NAUN MI AMA? NHIIIIIIII\n");
    } else if (resposta1 == 'N' && resposta2 == 'S' && resposta3 == 'N') {
        printf("NHIIIIIII NAUM SOUH SEU AMOR... MAIX MI AMA YEE... È PERFETITA SIIIIIIIIIIII NHAAAAAAAAAA\n");
    } else if (resposta1 == 'S' && resposta2 == 'S' && resposta3 == 'N') {
        printf("YEEEEEEEEEEEEEE MI AMA I SOUH U AMOR DA SUA VIDAAAAAAAAAA.... MAS È PERFEITA SIIIIIIII É INCRIVEL E MINHA DEUSA!\n");
    }
}

void sair() {
    char confirmacao;
    do {
        printf("Tem certeza? (S/N): ");
        scanf(" %c", &confirmacao);
        if (confirmacao == 'N') {
            menu();
            return;
        }
    } while (confirmacao != 'N');
}