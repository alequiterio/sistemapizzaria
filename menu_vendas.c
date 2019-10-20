#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#include "modulo_vendas.h"

venda *menu_venda(venda *V, produto *P, cliente *C, funcionario *F){
	char op;
	
	do{
	system("cls");
	printf(">> VENDA <<\n");
	printf("\n1 - Delivery");
    printf("\n2 - Relatorio");
    printf("\n3 - Sair");
    
   	printf("\n\nDigite a opcao desejada: ");
	
	op = getche();
	
	switch(op){               
               case '1':
					V = delivery(V, P, C);
               break;
               case '2':
					relatorio_venda(V, P, C);
			   break;
			   case '3':
					return V;
			   break;
			   default : puts("Digite uma opção válida!"); Sleep(3); 
			}
	}while(op!='3');  
	       
	
}
