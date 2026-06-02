//Questão 02. Escreva um programa em C que apresente uma pirâmide de números
//como a que se segue. Para isso deverá pedir ao utilizador o valor de N que deverá
//ser obrigatoriamente maior ou igual 2. A pirâmide apresentada é o exemplo para N
//= 5.
//            1
//          1 2 1
//        1 2 3 2 1
//      1 2 3 4 3 2 1
//    1 2 3 4 5 4 3 2 1

#include <stdio.h>
int main(){
    int N, i, j;

    printf("Digite o valor de N (N >= 2):");
    scanf("%d", &N);

    while (N < 2){
        printf("Valor inválido!Digite um valor maior ou igual a 2:");
        scanf("%d", &N);
    }

    for (i = 1; i <= N; i++){
        for (j = 1; j <= N - i; j++){
            printf("  ");
        }
        for (j = 1; j <= i; j++){
            printf("%d ", j);
        }
        for (j = i - 1; j >= 1; j--){
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}