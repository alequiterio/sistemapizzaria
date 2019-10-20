#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>


#include "modulo_vendas.h"

int main(){
  
     
    cliente *C;
    C = (cliente*)malloc(sizeof(cliente));
	C[0].numero_cadastro = 0;
	C[0].buffer = 1;
		
	produto *P;	
	P = (produto*)malloc(sizeof(produto));
	P[0].numero_cadastro = 0;
	P[0].buffer = 1;
    

	funcionario *F;
	F = (funcionario*)malloc(sizeof(funcionario));
	F[0].numero_cadastro = 0;
	F[0].buffer = 1;
	
	venda *V;
	V = (venda*)malloc(sizeof(venda));
	V[0].numero_venda = 0;
	V[0].quantidade_de_produtos = 0;
	V[0].buffer = 1;

	
	char op,op2;
	
	tela_loading();
	
	
	do{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	printf("             BEM VINDO \n");
	printf("         P I Z Z A P I M\n\n");
	printf("Sistema Integrado de Gerenciamento\n");
	printf("__________________________________\n\n");

	printf("\n1 - Clientes");
	printf("\n2 - Produtos");
    	printf("\n3 - Vendas");
    	printf("\n4 - Funcionarios");
    	printf("\n5 - Sair");
    
   	printf("\n\nDigite a opção desejada: ");
	
	op = getche();
	
	switch(op){               
               case '1':
	       	    C = (cliente *) menu_cliente(C);
 		    break;
               case '2':
                    P = (produto *) menu_produto(P);
               	    break;
               case '3':
	       	    V = (venda *) menu_venda(V, P, C, F);
		    break;
 	       case '4':
	       	    F = (funcionario *) menu_funcionarios(F);
		    break;
               case '5':	
	       	    printf("\nTem certeza que deseja fechar o sistema? (S/N)");
 		    op2 = getche();
		    if (toupper(op2) == 'S'){
	    	       system("CLS");
	    	       printf("Fechando o sistema!");
	     	       exit(1);
	            }else{
     	    	       break;
		    }
 		    break;
               default : puts("digite uma opï¿½ï¿½o valida");
			
	}
	}while(op!='5');	
}
