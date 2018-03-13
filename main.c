/**
	Autor: Igortheminer
	Data: 13/03/2018
	Descricao:
**/
#include "login.h"
#include "login.c"


char keyboard[BUFSIZ];/** para limpeza de buffer ... setbuf(stdin, keyboard); **/

int main(){
	int retorno_login;

	cria_arq_senha();

	do{
	retorno_login = gera_login();
	}while(retorno_login != 1);

	printf("\n\n\t\tACESSO ACEITO\n\n\n");

	modf_arq_senha();

	return 0;
}
