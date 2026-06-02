//Questão 07. Escreva um programa em C que apresente uma espiral quadrada de
//números na tela. O usuário deve informar o valor de N, que define uma matriz N
//por N, sendo N obrigatoriamente maior ou igual a 3. A matriz deve ser preenchida
//com os números de 1 até N ao quadrado, dispostos em forma de espiral partindo do
//canto superior esquerdo e movendo-se no sentido horário em direção ao centro. Os
//números devem ser alinhados em colunas com largura suficiente para acomodar o
//maior valor. Em caso de valor inválido, o programa deverá apresentar uma
//mensagem de erro e solicitar novamente.
//O exemplo abaixo mostra a espiral para N = 4.
//
//   1 2 3 4
//12 13 14 5
//11 16 15 6
// 10 9 8 7
//
//E para N = 6.
//
//     1 2 3 4 5 6
//20 21 22 23 24 7
//19 32 33 34 25 8
//18 31 36 35 26 9
//17 30 29 28 27 10
//16 15 14 13 12 11

#include <stdio.h>

int main(){
    int N;

    while (1){
        printf("Informe o valor de N (N >= 3): ");
        if (scanf("%d", &N) == 1 && N >= 3){
            break;
        }
        printf("Erro: Valor invalido.\n");
        while(getchar() != '\n'); 
    }

    int matriz[N][N];
    int valor = 1;
    int inicio_linha = 0, fim_linha = N - 1;
    int inicio_col = 0, fim_col = N - 1;

    while (valor <= N * N){
        for (int i = inicio_col; i <= fim_col; i++)
            matriz[inicio_linha][i] = valor++;
        inicio_linha++;

        for (int i = inicio_linha; i <= fim_linha; i++)
            matriz[i][fim_col] = valor++;
        fim_col--;

        if (inicio_linha <= fim_linha) {
            for (int i = fim_col; i >= inicio_col; i--)
                matriz[fim_linha][i] = valor++;
            fim_linha--;
        }

        if (inicio_col <= fim_col) {
            for (int i = fim_linha; i >= inicio_linha; i--)
                matriz[i][inicio_col] = valor++;
            inicio_col++;
        }
    }

    printf("\nEspiral para N = %d:\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matriz[i][j]); 
        }
        printf("\n");
    }

    return 0;
} 