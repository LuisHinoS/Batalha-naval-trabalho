// :)

#include <stdio.h>
#define Tamanho_do_barco 10

void inicializarTabuleiro(char tabuleiro[][Tamanho_do_barco], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

void exibirTabuleiro(char tabuleiro[][Tamanho_do_barco], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(char tabuleiro[][Tamanho_do_barco], int tamanho, int linha, int coluna) {
    if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
        tabuleiro[linha][coluna] = 'X';
    } else {
        printf("Coordenadas erradas. Tente novamente.\n");
    }
}

void atirar(char tabuleiroAtaque[][Tamanho_do_barco], char tabuleiroDefesa[][Tamanho_do_barco], int tamanho, int linha, int coluna) {
    if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
        if (tabuleiroDefesa[linha][coluna] == 'X') {
            printf("Você acertou um navio!\n");
            tabuleiroAtaque[linha][coluna] = 'H'; 
            tabuleiroDefesa[linha][coluna] = 'H';
        } else if (tabuleiroAtaque[linha][coluna] == 'M' || tabuleiroAtaque[linha][coluna] == 'H') {
            printf("Você já atirou nessa posição.\n");
        } else {
            printf("Você atingiu a água.\n");
            tabuleiroAtaque[linha][coluna] = 'M'; 
        }
    } else {
        printf("Coordenadas de tiro inválidas. Tente novamente.\n");
    }
}

int main() {
    char tabuleiroJogador1[Tamanho_do_barco][Tamanho_do_barco];
    char tabuleiroJogador2[Tamanho_do_barco][Tamanho_do_barco];
    char tabuleiroAtaqueJogador1[Tamanho_do_barco][Tamanho_do_barco];
    char tabuleiroAtaqueJogador2[Tamanho_do_barco][Tamanho_do_barco];

    inicializarTabuleiro(tabuleiroJogador1, Tamanho_do_barco);
    inicializarTabuleiro(tabuleiroJogador2, Tamanho_do_barco);
    inicializarTabuleiro(tabuleiroAtaqueJogador1, Tamanho_do_barco);
    inicializarTabuleiro(tabuleiroAtaqueJogador2, Tamanho_do_barco);

    printf("Bem-vindo à Batalha Naval!\n");

    printf("Jogador 1, posicione seus navios:\n");

    int linha, coluna;
    for (int i = 1; i <= 5; i++) {
        printf("Navio %d: Digite as coordenadas (linha e coluna) separadas por espaço: ", i);
        scanf("%d %d", &linha, &coluna);
        posicionarNavio(tabuleiroJogador1, Tamanho_do_barco, linha, coluna);
    }

    printf("Tabuleiro do jogador 1 com navios:\n");
    exibirTabuleiro(tabuleiroJogador1, Tamanho_do_barco);

    printf("Jogador 2, posicione seus navios:\n");

    for (int i = 1; i <= 5; i++) {
        printf("Navio %d: Digite as coordenadas (linha e coluna) separadas por espaço: ", i);
        scanf("%d %d", &linha, &coluna);
        posicionarNavio(tabuleiroJogador2, Tamanho_do_barco, linha, coluna);
    }

    printf("Tabuleiro do jogador 2 com navios:\n");
    exibirTabuleiro(tabuleiroJogador2, Tamanho_do_barco);

    int jogador1Venceu = 0;
    int jogador2Venceu = 0;

    while (!jogador1Venceu && !jogador2Venceu) {
  
        printf("Jogador 1, é sua vez de atirar:\n");
        printf("Digite as coordenadas (linha e coluna) separadas por espaço: ");
        scanf("%d %d", &linha, &coluna);
        atirar(tabuleiroAtaqueJogador1, tabuleiroJogador2, Tamanho_do_barco, linha, coluna);


        jogador1Venceu = 1;
        for (int i = 0; i < Tamanho_do_barco; i++) {
            for (int j = 0; j < Tamanho_do_barco; j++) {
                if (tabuleiroJogador2[i][j] == 'X') {
                    jogador1Venceu = 0;
                    break;
                }
            }
            if (!jogador1Venceu) {
                break;
            }
        }


        printf("Tabuleiro de ataque do jogador 1:\n");
        exibirTabuleiro(tabuleiroAtaqueJogador1, Tamanho_do_barco);


        if (jogador1Venceu) {
            break;
        }


        printf("Jogador 2, é sua vez de atirar:\n");
        printf("Digite as coordenadas (linha e coluna) separadas por espaço: ");
        scanf("%d %d", &linha, &coluna);
        atirar(tabuleiroAtaqueJogador2, tabuleiroJogador1, Tamanho_do_barco, linha, coluna);


        jogador2Venceu = 1;
        for (int i = 0; i < Tamanho_do_barco; i++) {
            for (int j = 0; j < Tamanho_do_barco; j++) {
                if (tabuleiroJogador1[i][j] == 'X') {
                    jogador2Venceu = 0;
                    break;
                }
            }
            if (!jogador2Venceu) {
                break;
            }
        }

        printf("Tabuleiro de ataque do jogador 2:\n");
            exibirTabuleiro(tabuleiroAtaqueJogador2, Tamanho_do_barco);

        if (jogador2Venceu) {
            break;
        }
    }



    if (jogador1Venceu) {
        printf("Jogador 1 venceu!o cara é brabo msm.\n");
    } else if (jogador2Venceu) {
        printf("Jogador 2 venceu! parabens nem parece que voce viu tudo.\n");
    } else {
        printf("O jogo terminou em empate, é o esperado.\n");
    }

    return 0;
}
