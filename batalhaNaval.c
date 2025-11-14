#include <stdio.h>

#define TAM_TABULEIRO 10   // tamanho fixo 10x10
#define TAM_NAVIO     3    // cada navio ocupa 3 casas
#define AGUA          0    // valor que representa água
#define NAVIO         3    // valor que representa parte de navio

int main(void) {
    /* ---------- 1. Declaração do tabuleiro ---------- */
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    /* ---------- 2. Declaração dos navios (vetores) ---------- */
    // Cada navio é representado por um vetor de 3 posições com o valor 3
    int navioHorizontal[TAM_NAVIO] = { NAVIO, NAVIO, NAVIO };
    int navioVertical[TAM_NAVIO]   = { NAVIO, NAVIO, NAVIO };

    /* ---------- 3. Coordenadas iniciais dos navios ---------- */
    // Coordenadas escolhidas diretamente no código (0 a 9)
    // Navio horizontal: começa na linha 2, coluna 1 (3ª linha, 2ª coluna)
    int linhaIniHorizontal = 2;
    int colunaIniHorizontal = 1;

    // Navio vertical: começa na linha 5, coluna 7 (6ª linha, 8ª coluna)
    int linhaIniVertical = 5;
    int colunaIniVertical = 7;

    /* ---------- 4. Validação das coordenadas ---------- */
    int coordenadasValidas = 1; // assume que está tudo ok, e vamos testando

    // Validação do navio horizontal (deve caber na linha e não sair do tabuleiro)
    if (linhaIniHorizontal < 0 || linhaIniHorizontal >= TAM_TABULEIRO ||
        colunaIniHorizontal < 0 || (colunaIniHorizontal + TAM_NAVIO) > TAM_TABULEIRO) {
        printf("Coordenadas do navio horizontal INVALIDAS!\n");
        coordenadasValidas = 0;
    }

    // Validação do navio vertical (deve caber na coluna e não sair do tabuleiro)
    if (linhaIniVertical < 0 || linhaIniVertical + TAM_NAVIO > TAM_TABULEIRO ||
        colunaIniVertical < 0 || colunaIniVertical >= TAM_TABULEIRO) {
        printf("Coordenadas do navio vertical INVALIDAS!\n");
        coordenadasValidas = 0;
    }

    /* ---------- 5. Posicionamento dos navios ---------- */
    if (coordenadasValidas) {
        int i;

        // Posiciona o navio horizontal no tabuleiro
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaIniHorizontal][colunaIniHorizontal + i] = navioHorizontal[i];
        }

        // Antes de posicionar o navio vertical, checa se vai sobrepor o horizontal
        int sobrepoe = 0;
        for (i = 0; i < TAM_NAVIO; i++) {
            int linhaAlvo  = linhaIniVertical + i;
            int colunaAlvo = colunaIniVertical;

            if (tabuleiro[linhaAlvo][colunaAlvo] != AGUA) {
                sobrepoe = 1;
            }
        }

        if (sobrepoe) {
            printf("Erro: navio vertical sobrepoe outro navio. Nao sera posicionado.\n");
        } else {
            // Posiciona o navio vertical no tabuleiro
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaIniVertical + i][colunaIniVertical] = navioVertical[i];
            }
        }
    } else {
        printf("Nao foi possivel posicionar os navios devido a coordenadas invalidas.\n");
    }

    /* ---------- 6. Exibição do tabuleiro ---------- */
    printf("\nTABULEIRO 10x10 (0 = agua, 3 = navio)\n\n");

    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nPosicionamento concluido.\n");
    return 0;
}