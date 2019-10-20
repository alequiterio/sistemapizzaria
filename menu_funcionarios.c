#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "modulo_funcionarios.h"

funcionario *menu_funcionarios(funcionario *F){
	char op;
	
	do{
	system("cls");
	printf(">>FUNCIONARIOS\n");
	printf("\n1 - Cadastrar");
	printf("\n2 - Buscar");
    printf("\n3 - Listar");
    printf("\n4 - Excluir");
    printf("\n5 - Sair");
    
   	printf("\n\nDigite a opcao desejada: ");
	
	op = getche();
	
	switch(op){               
               case '1':
					F = (funcionario *) cadastro_funcionarios(F);
       		   break;
               case '2':
					busca_funcionarios(F);
               break;
               case '3':
					relatorio_funcionarios(F);
			   break;
			   case '4':
					excluir_funcionario(F);
			   break;
			   case '5':
					return F;
			   break;
			}
	}while(op!=5);  
	       
	
}
