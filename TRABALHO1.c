//Daniel de Oliveira Silva
//Marcos Henrique Alves da Silva Souza
#include <stdio.h>
#include <locale.h>
#include "vetores.h"
#include <windows.h>
#include <stdlib.h>

int main(){
	setlocale (LC_ALL, ".UTF-8"); //o .utf-8 serve para permitir a exibição de caracteres especiais, tanto no github desktop quanto no terminal.
	float VetorInicial[10], VetorCopia[10];
	int ec, vExiste = 0, ve = 0, cExiste = 0;
	
	do{
		printf("*************************************************\n"
		"0 - SAIR DA APLICAÇÃO\n" //feito
		"1 - INICIALIZAR O VETOR DE 10 POSIÇÕES\n" //feito
		"2 - EXIBIR O VETOR COMPLETO\n" //feito
		"3 - EXIBIR O VETOR EM ORDEM INVERSA\n" //feito
		"4 - EXIBIR O ELEMENTO DE UMA POSIÇÃO DO VETOR\n" //feito
		"5 - SUBSTITUIR O ELEMENTO DE UMA POSIÇÃO DO VETOR\n" //feito
		"6 - EXIBIR O MAIOR NÚMERO DO VETOR E SUA POSIÇÃO\n" //feito
		"7 - EXIBIR O MENOR NÚMERO DO VETOR E SUA POSIÇÃO\n" //feito
		"8 - RETORNAR A MÉDIA DOS NÚMEROS DO VETOR\n" //feito
		"9 - RETORNAR A QUANTIDADE DE NÚMEROS DENTRO DE UM INTERVALO KI E KJ\n" //feito
		"10 - RETORNAR A POSIÇÃO DO MAIOR NÚMERO A PARTIR DE UMA POSIÇÃO N INFORMADA\n" //feito
		"11 - RETORNAR A POSIÇÃO DO MENOR NÚMERO A PARTIR DE UMA POSIÇÃO N INFORMADA\n" //feito
		"12 - PERMUTAR DUAS POSIÇÕES DO VETOR\n" //feito
		"13 - CRIAR UMA CÓPIA DO VETOR\n" //feito
		"14 - RESTAURAR A CÓPIA DO VETOR\n" //feito
		"15 - ORDENAR O VETOR\n" //feito
		"16 - SOBRE"); //feito

		do { //validação de entrada, caso o usuário digite "abc" por exemplo.
			printf("\nDIGITE A OPÇÃO DESEJADA: ");
			ve = scanf("%d", &ec); //scanf retorna 0 caso não consiga ler um número
			if (ve != 1){
				printf("\nSeleção invalida.\n");
				limpaBuffer();
			}
		} while (ve != 1);

		printf("*************************************************\n\n");
		
		switch(ec){
			case 1:
				preencher_vetor(VetorInicial);
				vExiste = 1;
				printf("\nConcluído.\n");
				system("pause");
				break;

			case 2:
				if (verificar_vetor(vExiste)){
					exibir_vetor(VetorInicial);
				}
				system("pause");
				break;

			case 3:
				if (verificar_vetor(vExiste)){
					vetor_inverso(VetorInicial);
				}
				system("pause");
				break;

			case 4:
				if (verificar_vetor(vExiste)){
					int teste, q;
					do { //validação de entrada
						printf("Selecione um valor de 0 a 9.\n");
						teste = scanf("%d", &q);
						if (teste != 1 || q<0 || q>9){
							printf("Seleção invalida.\n\n");
							limpaBuffer();
						}
					} while (teste != 1 || q<0 || q>9);
					vetor_elemento(VetorInicial, q);
				}
				system("pause");
				break;

			case 5:
				if (verificar_vetor(vExiste)){
					int t, pos;
					float val;
					do { //validação de entrada das posições.
						printf("escolha uma posição do vetor (0 a 9): ");
						t = scanf("%d", &pos);
						if (t != 1 || pos<0 || pos>9){
							printf("\nSeleção invalida.\n");
							limpaBuffer();
						}
					} while (t != 1 || pos<0 || pos>9);
					do{ //validação de entrada dos valores.
						printf("\nescolha o novo valor para esta posição: ");
						t = scanf("%f", &val);
						if (t != 1){
							printf("\nSeleção invalida.\n");
							limpaBuffer();
						}	
					} while (t != 1);
					substituir_elemento(VetorInicial, pos, val);
					printf("Concluído.\n");
				}
				system("pause");
				break;

			case 6: 
				if(verificar_vetor(vExiste)){
					maior_elemento(VetorInicial);					
				}
				system("pause");
				break;

			case 7:
				if(verificar_vetor(vExiste)){
					menor_elemento(VetorInicial);
				}
				system("pause");
				break;

			case 8:
				if(verificar_vetor(vExiste)){
					printf("A média dos elementos do vetor é: %.2f.\n", media_elementos(VetorInicial));	
				}
				system("pause");
				break;

			case 9:
				if(verificar_vetor(vExiste)){
					float ki, kj;
					int t, quant;

					do { //validação de entrada KI.
					printf("Insira o valor de KI.\n");
					t = scanf("%f", &ki);
					if (t != 1){
						printf("Valor inválido.\n");
						limpaBuffer();
					}
					} while (t != 1);

					do { //validação de entrada KJ.
					printf("Insira o valor de KJ maior que KI.\n");
					t = scanf("%f", &kj);
					if (t != 1 || kj <= ki){
						printf("Valor inválido.\n");
						limpaBuffer();
					} 
					} while (t != 1 || kj <= ki);
					quant = intervalo_kikj(VetorInicial, ki, kj);
					if (quant != 1){
						printf("\nExistem %d números dentro do intervalo KI:%g e KJ:%g\n", quant, ki, kj);
					} else {
						printf("\nExiste %d número dentro do intervalo KI:%g e KJ:%g", quant, ki, kj);
					}
				}
				system("pause");
				break;

			case 10: 
				if(verificar_vetor(vExiste)){
					int n, t;
					do{ //loop de validação de entrada de N
					printf("Indique a partir de qual posição pretende comparar os elementos (0 a 9).\n");
					t = scanf("%d", &n);
					if(t != 1 || n < 0 || n > 9){
						printf("Posição inválida! Escolha um número entre 0 e 9.\n");
						limpaBuffer();
					}
					} while (t != 1 || n < 0 || n > 9);

					printf("\nA partir da posição %d, o maior elemento está na posição: %d.\n", n, pos_maior(VetorInicial, n));
				}
				system("pause");
				break;

			case 11: 
				if(verificar_vetor(vExiste)){
					int n, t;
					do{ //loop de validação de entrada de N
						printf("Indique a partir de qual posição pretende comparar os elementos (0 a 9): \n");
						t = scanf("%d", &n);
						if(t != 1 || n < 0 || n > 9){
							printf("Posição inválida! Escolha um número entre 0 e 9.\n");
							limpaBuffer();
						}
					} while(t != 1 || n < 0 || n > 9);

					printf("\nA partir da posição %d, o menor elemento está na posição: %d.\n", n, pos_menor(VetorInicial, n));
				}
				system("pause");
				break;

			case 12: 
				if(verificar_vetor(vExiste)){
					int i, j, t;
					do{ //validação de entrada do valor I.
						printf("Digite a primeira posição que deseja permutar (0 - 9): \n");
						t = scanf("%d", &i);
						if(t != 1 || i < 0 || i > 9){
								printf("Posição inválida! Escolha um número entre 0 e 9.\n");
								limpaBuffer();
							}
					} while(t != 1 || i < 0 || i > 9);

					do{//validação de entrada do valor J
						printf("Digite a segunda posição que deseja permutar (0 - 9): \n");
						t = scanf("%d", &j);
						if(t != 1 || j < 0 || j > 9){
								printf("Posição inválida! Escolha um número entre 0 e 9.\n");
								limpaBuffer();
							}
					} while(t != 1 || j < 0 || j > 9);

					permutar_vetor(VetorInicial, i, j);
					printf("Concluído.\n");
				}
				system("pause");
				break;

			case 13: 
				if(verificar_vetor(vExiste)){
					copiar_vetor(VetorInicial, VetorCopia);
					printf("Concluído.\n");
					cExiste = 1;
				}
				system("pause");
				break;

			case 14: 
				if(verificar_vetor(vExiste)){
					if (cExiste == 1){
						restaurar_copia(VetorCopia, VetorInicial);
						printf("Concluído.\n");
					} else {
						printf("O vetor cópia não foi inicializado.\n\n");
					}
				}
				system("pause");
				break;

			case 15:
				if (verificar_vetor(vExiste)){
					char c;
					int t = 0;
					printf("Esta função irá alterar permamentemente todos os valores do vetor.\n"
						"É recomendável fazer uma cópia antes de prosseguir.\n"
						"Deseja continuar? s/n\n");
					scanf(" %1c", &c);	
					if (c != 's' && c != 'S'){
						system("pause");
						break;
					}
					ordenar_vetor(VetorInicial);
					printf("Concluído.\n");
				}
				system("pause");
				break;

			case 16:
				sobre();
				system("pause");
				break;

			case 0:
				break;

			default: printf("Número Inválido.\n\n");
				system("pause");
		}
	} while (ec != 0);
	return 0;
}
