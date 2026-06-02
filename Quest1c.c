//Questão 01. Faça um programa em C que apresente um quadrado como o do
//exemplo abaixo. O usuário deve informar qual a altura ele deseja para o retângulo e
//se ele gostaria que o retângulo fosse apresentado vazado ou preenchido.


#include <stdio.h>

int main() {
    int linhas, colunas, resposta;
    
    printf("Insira a quantidade de linhas que deseja:");
    scanf("%d", &linhas);
    
    printf("Insira a quantidade de colunas que deseja:");
    scanf("%d", &colunas);
    
    printf("Você deseja o retângulo PREENCHIDO ou VAZADO? Digite 1 para preenchido e 2 para vazado\nresposta:");
    scanf("%d", &resposta);
    
    if(resposta == 1){
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("*");
        }
        printf("\n");}
    }
    
    else if(resposta == 2){
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (i == 0 || i == linhas - 1 || j == 0 || j == colunas - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");}
    }
    
    return 0;
}