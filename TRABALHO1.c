#include <stdio.h>
#include <locale.h>
#include "vetores.h"
#include <windows.h>
#include <stdlib.h>

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	
	setlocale (LC_ALL, "Portuguese");
	float VetorInicial[10], VetorCopia[10];
	int ec, vExiste = 0, ve = 0, cExiste = 0;
	
	do{
		printf("*************************************************\n");
		printf("0 - SAIR DA APLICAÇÃO\n");
		printf("1 - INICIALIZAR O VETOR DE 10 POSIÇÕES\n");
		printf("2 - EXIBIR O VETOR COMPLETO\n");
		printf("3 - EXIBIR O VETOR EM ORDEM INVERSA\n");
		printf("4 - EXIBIR O ELEMENTO DE UMA POSIÇÃO DO VETOR\n");
		printf("5 - SUBSTITUIR O ELEMENTO DE UMA POSIÇÃO DO VETOR\n");
		printf("6 - EXIBIR O MAIOR NÚMERO DO VETOR E SUA POSIÇÃO\n");
		printf("7 - EXIBIR O MENOR NÚMERO DO VETOR E SUA POSIÇÃO\n");
		printf("8 - RETORNAR A MÉDIA DOS NÚMEROS DO VETOR\n");
		printf("9 - RETORNAR A QUANTIDADE DE NÚMEROS DENTRO DE UM INTERVALO KI E KJ\n");
		printf("10 - RETORNAR A POSIÇÃO DO MAIOR NÚMERO A PARTIR DE UMA POSIÇÃO N INFORMADA\n");
		printf("11 - RETORNAR A POSIÇÃO DO MENOR NÚMERO A PARTIR DE UMA POSIÇÃO N INFORMADA\n");
		printf("12 - PERMUTAR DUAS POSIÇÕES DO VETOR\n");
		printf("13 - CRIAR UMA CÓPIA DO VETOR\n");
		printf("14 - RESTAURAR A CÓPIA DO VETOR\n");
		printf("15 - ORDENAR O VETOR\n");
		printf("16 - SOBRE");

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
							printf("\nSeleçãoo invalida.\n");
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
					media_elementos(VetorInicial);	
				}
				system("pause");
				break;

			case 10: 
				if(verificar_vetor(vExiste)){
					maior_elementoN(VetorInicial);
				}
				system("pause");
				break;

			case 11: 
				if(verificar_vetor(vExiste)){
					menor_elementoN(VetorInicial);
				}
				system("pause");
				break;
			case 12: 
				if(verificar_vetor(vExiste)){
					permutar_vetor(VetorInicial);
				}
				system("pause");
				break;
			case 13: 
				if(verificar_vetor(vExiste)){
					copiar_vetor(VetorInicial, VetorCopia);
				}
				system("pause");
				break;
			case 14: 
				if(verificar_vetor(vExiste)){
					if (cExiste == 1){
						restaurar_copia(VetorCopia, VetorInicial);
					} else {
						printf("O vetor copia nao foi inicializado.");
					}
				}
				system("pause");
				break;
			case 16:
				sobre();
				system("pause");
				break;
			case 0:
				break;
			default: printf("Não implementado.\n\n");
				system("pause");
		}
	} while (ec != 0);
	return 0;
}
