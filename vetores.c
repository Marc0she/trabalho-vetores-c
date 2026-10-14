#include <stdio.h>
#include "vetores.h"

int verificar_vetor(int v){
    if (v == 1){
        return 1;
    } else {
        printf("Não foi criado um vetor.\n\n");
        return 0;
    }
}

void limpaBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void sobre(void){
	printf("Desenvolvido por:\nDaniel de Oliveira Silva\nMarcos Henrique Alves da Silva Souza\n\n");
}

void preencher_vetor(float vetor[10]) {
	int i;
	for(i = 0; i < 10; i++){
		printf("Posição %d: ", i);
		scanf("%f", &vetor[i]);
	}
}

void exibir_vetor(float v[10]){
    int i;
    printf("Vetor = { ");
    for(i=0;i<9;i++){
        printf("%g ; ", v[i]);
    }
    printf("%g }\n\n", v[9]);
}

void vetor_inverso(float v[10]){
    int i;
    printf("Vetor Inverso = { ");
    for(i=9;i>0;i--){
        printf("%g ; ", v[i]);
    }
    printf("%g }\n\n", v[0]);
}

void vetor_elemento(float v[10], int n){
    printf("Elemento %d do vetor = %g.\n\n", n, v[n]);
}

void maior_elemento(float v[10]){
    int i, posicao;
    float maior = v[0];
    for(i = 0; i < 10; i++ ){
        if(v[i] >= maior){
            maior = v[i];
            posicao = i;
        }
    }
    printf("O maior elemento do vetor é: %g, sua posicao é: %d.\n\n", maior, posicao);
}

void menor_elemento(float v[10]){
    int i, posicao;
    float menor = v[0];
    for(i = 0; i < 10; i++ ){
        if(v[i] <= menor){
            menor = v[i];
            posicao = i;
        }
    }
    printf("O menor elemento do vetor é: %g, sua posicao é: %d.\n\n", menor, posicao);
}

void substituir_elemento(float v[10], int pos, float new){
    v[pos] = new;
}

void media_elementos(float v[10]){
    int i;
    float media = 0;
    float soma = 0;
    for(i = 0; i < 10; i++ ){
       soma += v[i];
        }
        media = soma/10;
        printf("A média dos elementos do vetor é: %g\n\n", media);
    }

void maior_elementoN(float v[10]){
    int posicao_inicial;
    printf("Indique a partir de qual posição pretende comparar os elementos (0 a 9): \n");
    scanf("%d", &posicao_inicial);
    if(posicao_inicial < 0 || posicao_inicial >= 10){
        printf("Posição inválida! Escolha um número entre 0 e 9.\n\n");
        return;
    }

    float maior = v[posicao_inicial];
    int posicao_maior = posicao_inicial;
    int i;

    for(i = posicao_inicial + 1; i < 10; i++){
        if(v[i] > maior){
            maior = v[i];
            posicao_maior = i;
        }
    }
    printf("A partir da posição %d, o maior elemento é: %g (no indice %d ou %d, o elemento do vetor).\n\n", 
           posicao_inicial, maior, posicao_maior, posicao_maior + 1);
}


void menor_elementoN(float v[10]){
    int posicao_inicial;
    printf("Indique a partir de qual posição pretende comparar os elementos (0 a 9): \n\n");
    scanf("%d", &posicao_inicial);

    float menor = v[posicao_inicial]; 
    int posicao_menor = posicao_inicial;
	int i; 
    for(i = posicao_inicial + 1; i < 10; i++){
        if(v[i] < menor){
            menor = v[i];
            posicao_menor = i;
        }
    }
    
    printf("\n\nO menor elemento do vetor a partir da posição %d é: %g, e sua posição (indice) é: %d.\n\n", 
           posicao_inicial, menor, posicao_menor);
}

void permutar_vetor(float v[10]){
    int i, j;
    printf("\nDigite a primeira posição que deseja permutar (0 - 9): \n");
    scanf("%d", &i);
    printf("\nDigite a segunda posição que deseja permutar (0 - 9): \n");
    scanf("%d", &j);
    float aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void copiar_vetor(float v[10], float copia[10]){
    int i;
    for(i = 0; i < 9; i++){
    copia[i] = v[i];
    }
}
void restaurar_copia(float v[10], float copia[10]){
    copiar_vetor(v, copia);
}
