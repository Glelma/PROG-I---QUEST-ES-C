//Questão 03. Faça um programa em C que apresente um triângulo como o do
//exemplo abaixo. O usuário deve informar qual a altura ele deseja para o triângulo e
//se ele gostaria que o triângulo fosse apresentado vazado ou preenchido.

#include <stdio.h>

int main(){
    int linhas, resposta, i, j;

    printf("Digite a altura do triângulo:");
    scanf("%d", &linhas);
    
    printf("Você deseja o triângulo PREENCHIDO ou VAZADO? Digite 1 para preenchido e 2 para vazado\nresposta:");
    scanf("%d", &resposta);
    
    if(resposta == 1){
    for (i = 1; i <= linhas; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n"); 
    }}
    
    else if (resposta == 2){
    for (i = 1; i <= linhas; i++){
        for (j = 1; j <= i; j++){
            if (j == 1 || j == i || i == linhas){
                printf("*");}
            else{
                printf(" ");}
            
        }
        printf("\n");
    }}
    
    return 0;
}
