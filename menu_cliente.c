#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "modulo_cliente.h"

cliente *menu_cliente(cliente *C){
	char op;
	
	do{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	printf(">> Clientes <<\n");
	printf("\n1 - Cadastrar");
	printf("\n2 - Buscar");
    printf("\n3 - Listar");
    printf("\n4 - Excluir");
    printf("\n5 - Sair");
    
   	printf("\n\nDigite a opção desejada: ");
	
	op = getche();
	
	switch(op){               
    	case '1':
			C = cadastro_cliente(C);
       	break;        
		case '2':
			busca_cliente(C);
        break;        
		case '3':
			relatorio_cliente(C);
		break;		
		case '4':
			excluir_cliente(C);
		break;		
		case '5':
			return C;
		break;		
		default : puts("digita a porra da opção certa");
		}
	}while(op!=5);  	
}
