//Questão 05. Triângulo de Pascal é um triângulo aritmético infinito onde são
//dispostos os coeficientes das expansões binominais. Abaixo o exemplo de um
//Triângulo de Pascal até a linha 7 de altura.
//               1
//              1 1  
//           1   2   1
//          1   3 3   1
//          1  4  6  4   1
//        1  5  10 10 5  1
//      1   6  15  20 15  6  1
//O primeiro e último número de cada linha deve ser 1. Cada número do triângulo de
//Pascal é igual à soma do número imediatamente acima e do antecessor do número
//de cima, conforme o gif abaixo demostra.

#include <stdio.h>
int main(){
    int altura, i, j;

    printf("Digite a altura do Triângulo de Pascal: ");
    scanf("%d", &altura);

    int triangulo[altura][altura];
    for (i = 0; i < altura; i++) {
        for (j = 0; j < altura - i; j++) {
            printf("  ");
        }

        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangulo[i][j] = 1;
            } else {
                triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
            }
            printf("%4d", triangulo[i][j]);
        }
        printf("\n");
    }

    return 0;
}