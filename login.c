/**
	Autor: Igortheminer
	Data: 13/03/2018
	Descricao:
**/
#include "login.h"

char keyboard[BUFSIZ];/** para limpeza de buffer ... setbuf(stdin, keyboard); **/

void cria_arq_senha(void){/** CASO NAO EXISTA O ARQUIVO "senha.dat" ESSA FUNCAO IRA CRIAR UM COM A SENHA PADRAO "123" **/
	FILE *arq = fopen("senha.dat", "rb");
	unsigned int senha_padrao = SENHA_PADRAO;
	int verifica;

	if(arq == NULL){/** VERIFICA SE O ARQUIVO EXISTE, E CASO NAO EXISTA E CRIADO UM **/
		arq = fopen("senha.dat", "wb");
		verifica = fwrite(&senha_padrao, sizeof(unsigned int), 1, arq);
		if(verifica != 1){/** CASO OCORRA UM PROBLEMA EXECUTA ISSO **/
			perror("ERRO NA ESCRITA DO ARQUIVO <senha.dat>");
			getch();
			exit(1);
		}
	}
	fclose(arq);
}

void modf_arq_senha(void){/** MUDA A SENHA SALVA EM "senha.dat" **/
	unsigned int nova_senha;
	int verifica;
	FILE *arq = fopen("senha.dat", "wb");

	printf("\nDIGITE A NOVA SENHA (apenas numeros): ");
	setbuf(stdin, keyboard);
	scanf("%u", &nova_senha);
	verifica = fwrite(&nova_senha, sizeof(unsigned int), 1, arq);
	if(verifica != 1){/** CASO OCORRA UM PROBLEMA EXECUTA ISSO **/
		perror("ERRO NA ESCRITA DO ARQUIVO <senha.dat>");
		getch();
		exit(1);
	}
	fclose(arq);
}

int gera_login(void){/** FAZ LOGIN, CASO A SENHA DIGITADA SEJA INCORRETA RETORNA "0", SE CORRETA RETORNA "1" **/
	int verifica;
	unsigned int senha_arq;
	unsigned int senha_digitada;
	FILE *arq = fopen("senha.dat", "rb");

	if(arq == NULL){
		perror("ERRO NA LEITURA DO ARQUIVO <senha.dat>");
		getch();
		exit(2);
	}

	verifica = fread(&senha_arq, sizeof(unsigned int), 1, arq);
	if(verifica != 1){/** ASSEGURA QUE O ARQUIVO ENHA SIDO LIDO CORETAMENTE **/
		perror("ERRO NA LEITURA DO ARQUIVO <senha.dat>");
		getch();
		exit(2);
	}

	printf("\n\n\n\t\tDIGITE A SENHA PARA ACESSAR O SISTEMA: ");
	setbuf(stdin, keyboard);
	scanf("%u", &senha_digitada);
	if(senha_digitada != senha_arq){
		printf("\n\n\n\t\t\t___ACESSO_NEGADO___\n\t\t\t___SENHA_INCORRETA___\n\n");
		getch();
		return 0;
	}
	return 1;
}

