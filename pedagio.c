#include <stdio.h>

/*
 * CONTROLE DE FLUXO DO PEDAGIO
 * Le a quantidade de carros que passaram em cada dia da semana,
 * calcula total, media e dia de pico, e exibe um relatorio formatado.
 * Bonus: o dia de pico e destacado em negrito e cor no terminal.
 */

int main() {
    // Nomes dos dias (matriz de caracteres: 7 textos de ate 14 letras)
    char dias[7][15] = {"Segunda", "Terca", "Quarta", "Quinta",
                        "Sexta", "Sabado", "Domingo"};

    int carros[7];      // vetor: carros que passaram em cada dia
    int total = 0;      // soma de todos os carros da semana
    int diaPico = 0;    // indice do dia com maior movimento
    int i;              // indice dos lacos
    float media;        // media diaria de carros

    // ---------- Apresentacao ----------
    printf("==========================================\n");
    printf("        CONTROLE DE FLUXO DO PEDAGIO\n");
    printf("==========================================\n");
    printf("Informe quantos carros passaram em cada dia.\n\n");

    // ---------- 1) Leitura dos dados ----------
    // O mesmo indice i percorre o vetor carros e a matriz dias
    for (i = 0; i < 7; i++) {
        do {
            printf("Carros em %s: ", dias[i]);

            // Se nao for digitado um numero inteiro, limpa o buffer
            // e marca como invalido para repetir a pergunta
            if (scanf("%d", &carros[i]) != 1) {
                while (getchar() != '\n');
                carros[i] = -1;
            }

            if (carros[i] < 0) {
                printf("Valor invalido! Digite um numero inteiro maior ou igual a 0.\n");
            }
        } while (carros[i] < 0);   // repete ate receber um valor valido
    }

    // ---------- 2) Processamento ----------
    for (i = 0; i < 7; i++) {
        total += carros[i];             // acumula o total da semana

        if (carros[i] > carros[diaPico]) {
            diaPico = i;                // guarda o indice do maior movimento
        }
    }
    media = total / 7.0;                // divisao por real mantem as casas decimais

    // ---------- 3) Exibicao do relatorio ----------
    printf("\n------------------------------------------\n");
    printf("              RELATORIO SEMANAL\n");
    printf("------------------------------------------\n");

    for (i = 0; i < 7; i++) {
        if (i == diaPico && carros[diaPico] > 0) {
            // BONUS: dia de pico em negrito e vermelho (codigos ANSI)
            printf("\033[1;31m%-10s %5d carros  <- PICO\033[0m\n", dias[i], carros[i]);
        } else {
            printf("%-10s %5d carros\n", dias[i], carros[i]);
        }
    }

    printf("------------------------------------------\n");
    printf("Total da semana : %d carros\n", total);
    printf("Media diaria    : %.1f carros\n", media);

    if (carros[diaPico] > 0) {
        printf("Dia de pico     : %s (%d carros)\n", dias[diaPico], carros[diaPico]);
    } else {
        printf("Nenhum movimento registrado na semana.\n");
    }
    printf("==========================================\n");
    printf("Fim do relatorio. Obrigado por usar o sistema!\n");

    return 0;
}
