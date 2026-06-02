//Questão 04. Implemente um programa que desenhe o losango abaixo na tela. O
//usuário deve informar a largura central do losango.
//         X
//        XXX
//       XXXXX
//      XXXXXXX
//     XXXXXXXXX
//      XXXXXXX
//       XXXXX
//        XXX
//         X

#include <stdio.h>
int main(){
    int largura, i, j;
    
    printf("Digite a largura central do losango (ímpar e >= 3):");
    scanf("%d", &largura);

    while(largura < 3 || largura % 2 == 0){
        printf("Valor inválido!Digite um numero ímpar maior ou igual a 3:");
        scanf("%d", &largura);
    }

    for(i = 1; i <= largura; i += 2){
        for (j = 1; j <= (largura - i) / 2; j++){
            printf(" ");
        }
        for (j = 1; j <= i; j++){
            printf("X");
        }
        printf("\n");
    }
    
    for(i = largura - 2; i >= 1; i -= 2){
        for (j = 1; j <= (largura - i) / 2; j++){
            printf(" ");
        }

        for(j = 1; j <= i; j++){
            printf("X");
        }
        printf("\n");
    }

    return 0;
}