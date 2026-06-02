//Foi minha melhor tentativa!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Definição do tamanho da matriz de caracteres
#define TAMANHO 80
char matriz[TAMANHO][TAMANHO];

// Limpa a tela preenchendo a matriz com espaços em branco
void inicializarMatriz() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = ' ';
        }
    }
}

// Imprime a matriz resultante na tela
void desenharMatriz() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            putchar(matriz[i][j]);
        }
        putchar('\n');
    }
}

// Coloca um asterisco em uma coordenada válida da matriz
void plotarPonto(int x, int y) {
    if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
        matriz[y][x] = '*';
    }
}

// Algoritmo de Bresenham para traçar retas na matriz ASCII
void desenharLinha(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        plotarPonto(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// Função recursiva para gerar as curvas do Floco de Koch
void curvaKoch(double x1, double y1, double x5, double y5, int nivel) {
    if (nivel == 1) {
        desenharLinha((int)round(x1), (int)round(y1), (int)round(x5), (int)round(y5));
        return;
    }

    // Divide o segmento de reta em 3 partes iguais
    double x2 = x1 + (x5 - x1) / 3.0;
    double y2 = y1 + (y5 - y1) / 3.0;
    
    double x4 = x1 + 2.0 * (x5 - x1) / 3.0;
    double y4 = y1 + 2.0 * (y5 - y1) / 3.0;

    // Calcula o vértice do triângulo equilátero (ponta da estrela) rotacionando em 60 graus
    double angulo = -M_PI / 3.0; // 60 graus em radianos (negativo para subir no eixo Y invertido da tela)
    double x3 = x2 + (x4 - x2) * cos(angulo) - (y4 - y2) * sin(angulo);
    double y3 = y2 + (x4 - x2) * sin(angulo) + (y4 - y2) * cos(angulo);

    // Chamadas recursivas para os 4 novos segmentos
    curvaKoch(x1, y1, x2, y2, nivel - 1);
    curvaKoch(x2, y2, x3, y3, nivel - 1);
    curvaKoch(x3, y3, x4, y4, nivel - 1);
    curvaKoch(x4, y4, x5, y5, nivel - 1);
}

int main() {
    int nivel;

    // Laço para garantir que o programa repita em caso de erro, conforme solicitado
    while (1) {
        printf("Informe o nivel N do fractal Koch (entre 1 e 3): ");
        
        // Verifica se a entrada é um número e se está no intervalo correto [1, 3]
        if (scanf("%d", &nivel) != 1 || nivel < 1 || nivel > 3) {
            printf("Mensagem de erro: Valor invalido! Tente novamente.\n\n");
            // Limpa o buffer de entrada para evitar loops infinitos caso digitem letras
            while (getchar() != '\n'); 
            continue; 
        }
        break; // Entrada válida, sai do laço
    }

    inicializarMatriz();

    // Definição do triângulo base (Estrela de 6 pontas / Floco de Koch padrão)
    // Centralizado dinamicamente dentro do espaço de 80x80
    double cx = TAMANHO / 2.0;
    double cy = TAMANHO / 2.0 + 5; 
    double raio = 32.0; // Define o tamanho do fractal na tela

    // Três vértices do triângulo equilátero principal invertido (para formar a base do floco)
    double xA = cx + raio * cos(-M_PI / 2.0);
    double yA = cy + raio * sin(-M_PI / 2.0);
    
    double xB = cx + raio * cos(-M_PI / 2.0 + 2.0 * M_PI / 3.0);
    double yB = cy + raio * sin(-M_PI / 2.0 + 2.0 * M_PI / 3.0);
    
    double xC = cx + raio * cos(-M_PI / 2.0 + 4.0 * M_PI / 3.0);
    double yC = cy + raio * sin(-M_PI / 2.0 + 4.0 * M_PI / 3.0);

    // Aplica a curva de Koch nas 3 arestas do triângulo externo para fechar o floco completo
    curvaKoch(xA, yA, xB, yB, nivel);
    curvaKoch(xB, yB, xC, yC, nivel);
    curvaKoch(xC, yC, xA, yA, nivel);

    // Exibe o fractal renderizado na tela
    printf("\nResultado para N = %d:\n\n", nivel);
    desenharMatriz();

    return 0;
}
