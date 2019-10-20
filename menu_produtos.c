#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "modulo_produto.h"

produto *menu_produto(produto *P){
	char op;
	
	do{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	printf(">> PRODUTOS <<\n");
	printf("\n1 - Cadastrar");
	printf("\n2 - Buscar");
    printf("\n3 - Listar");
    printf("\n4 - Excluir");
    printf("\n5 - Sair");
    
   	printf("\n\nDigite a opcao desejada: ");
	
	op = getche();
	
	switch(op){               
               case '1':
				 	P = cadastro_produto(P);
       		   break;
               case '2':
					busca_produto(P);
               break;
               case '3':
					relatorio_produto(P);
			   break;
			   case '4':
					excluir_produto(P);
			   break;
			   case '5':
					return P;
			   break;
			   
			   default : puts("digite uma opção válida");
			}
	}while(op!=5);  
	       
	
}
