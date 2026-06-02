//Questão 06. Escreva um programa em C que apresente uma árvore de Natal como
//a do exemplo abaixo. Para isso deverá pedir ao usuário o valor de B que representa
//o número de asteriscos (*) na base da árvore. O valor de B deverá ser
//obrigatoriamente ímpar e maior ou igual 3. Deverá pedir também o valor de L e A
//que representam, respectivamente a largura e a altura do tronco da árvore. A
//largura do tronco L deverá ser pelo menos 1 asterisco, deverá ser obrigatoriamente
//impar e não poderá ultrapassar metade de B, isto é metade do número de asteriscos
//da base. A altura do tronco A deverá ser pelo menos 2 asteriscos e não deverá
//ultrapassar metade de B. Em caso de valores inválidos o programa deverá
//apresentar um erro e voltar a pedi-los.
//O exemplo da árvore em baixo tem uma base com B = 13 asteriscos, um tronco
//com largura L = 3 asteriscos e altura A = 4 asteriscos.
//
//               *
//              ***
//             *****
//            *******
//           *********
//          ***********
//         *************
//              ***
//              ***
//              ***
//              ***

#include <stdio.h>

int main(){
    int B, L, A;

    while(1){
        printf("Digite a base B (ímpar >= 3), largura L (ímpar e menor que a metade de B) e altura A (>= 2 e menor que a metade de B): ");
        scanf("%d %d %d", &B, &L, &A);

        if (B >= 3 && B % 2 != 0 && 
            L >= 1 && L % 2 != 0 && L <= B / 2 && 
            A >= 2 && A <= B / 2) {
            break;
        }
        printf("Valores inválidos. Tente novamente.\n");
    }

    for (int i = 1; i <= B; i += 2) {
        for (int j = 0; j < (B - i) / 2; j++) printf(" ");
        for (int j = 0; j < i; j++) printf("*");
        printf("\n");
    }

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < (B - L) / 2; j++) printf(" ");
        for (int j = 0; j < L; j++) printf("*");
        printf("\n");
    }

    return 0;
}
