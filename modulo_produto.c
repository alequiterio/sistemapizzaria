#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include <locale.h>

#include "modulo_produto.h"

produto *cadastro_produto(produto *P){
	produto *P_aux;	
	int i, erro;
	char resp = 'S', conf = 'n';
	
	char aux_descricao[MAX];
	float aux_preco;
	
		
	P_aux = (produto *) malloc(5 * sizeof(produto));

	
	
	for(i = 0; i <= P[0].numero_cadastro+1; i++){
		strcpy(P_aux[i].descricao, P[i].descricao);
		P_aux[i].preco = P[i].preco; 
		P_aux[i].codigo = P[i].codigo;
	}
	P_aux[0].numero_cadastro = P[0].numero_cadastro;
	P_aux[0].buffer = P[0].buffer;			
	
		
	if(!P_aux){
		puts("Memória insuficiente!\n");
	} else {
			do{	
                setlocale(LC_ALL, "Portuguese");
				system("cls");
				
			
				do{
					if(erro==1){
		 				system("cls");
		 				printf("Digite novamente os dados !!\n\n");
					}
					printf(">> CADÁSTRO DE PRODUTOS\n\n");
					puts("Descrição do produto:");
					fflush(stdin);
					gets(aux_descricao);
					puts("Preço:");
					scanf("%f",&aux_preco);							
					
					printf("Confirma dados cadastrais?(S/N): ");
  	    			fflush(stdin);
   					conf = getche();
   					
   					if(toupper(conf) == 'S'){ 
    		     		erro=0;
                        strcpy(P_aux[P_aux[0].numero_cadastro].descricao,aux_descricao);
                        P_aux[P_aux[0].numero_cadastro].preco = aux_preco;
                        P_aux[P_aux[0].numero_cadastro].codigo = P_aux[0].numero_cadastro+1;
						P_aux[0].numero_cadastro++;//incrementa +1 em numero_cadastro
				    /*struct recebe os dados das variaveis auxiliares*/
                   /* contador é incrementado*/
                    }
					
					
					if(toupper(conf) == 'N'){
					erro = 1;
					}
					
				}while(toupper(conf) == 'N');
				
				
				
				
				if(P_aux[0].numero_cadastro == P_aux[0].buffer*5+1){					
					P_aux[0].buffer++;
					P_aux = realloc(P_aux, P_aux[0].buffer*5);
					
					for(i = 0; i <= P[0].numero_cadastro; i++){
                          
                          if(P_aux[i].codigo != 0)
                          {
                                             
						      strcpy(P_aux[i].descricao,P[i].descricao);
						      P_aux[i].preco = P[i].preco; 
						      P_aux[i].codigo = P[i].codigo;
                          }
					}
					
				}
			
				printf("\nDeseja cadastrar mais um produto? (S/N)");
				fflush(stdin);
				resp = getche();
				
 			} while(toupper(resp) == 'S');
 			return P_aux;			
	}				
}

void busca_produto(produto *P){
     int achou,comparador,i;
     char resp, op = '0', descricao[MAX];
    do{ 
    system("cls");
    setlocale(LC_ALL, "Portuguese");
	printf(">> BUSCA DE PRODUTOS\n");
	printf("\n1 - Por descrição");
	printf("\n2 - Por codigo");
    printf("\n3 - Voltar");
    
	printf("\n\nDigite a opção desejada: ");
	
	op = getche(); 
     
	     switch(op){
	     
 	
	 	case '1':
			do{
	        	system("cls");
	        	fflush(stdin);
	        	printf("Entre com a descrição do produto para consulta: "); 
	        	gets(descricao);
	        	achou = 0;  
	        	i = 0; 
	        	
	        	while (i <= P[0].numero_cadastro+1 && achou == 0) {
		              if (strcmp(descricao, P[i].descricao)==0){ 
		                 achou = 1;
		                 printf("\nDescr...: %s", P[i].descricao);
		                 printf("\nCodigo..: %d", P[i].codigo);
						 printf("\nPreço...: %.2f", P[i].preco);						 						 
		              }
		              i++; 
		    	} 
	 
	 			if (achou == 0)printf("Produto não encontrado!"); 
	 
	 			printf("\nDeseja consultar mais um produto? (S/N)"); 
	 			resp = getche(); 
	 		} while (toupper(resp) == 'S');     
	 		break;
	 		
		    case '2':
	 			do{
	        	system("cls");
	        	printf("Entre com o codigo do produto para consulta: "); 
	        	scanf("%d", &comparador);
	        	achou = 0;  
	        	i = 0; 
	        	if(!P)printf("Nenhum registro foi criado!");
	        	while (i <= P[0].numero_cadastro+1 && achou == 0) {
		        	if (comparador == P[i].codigo){ 
		           		achou = 1;
		           		printf("Desc....: %s\n",P[i].descricao);
		                printf("Codigo..: %d\n",P[i].codigo);
          				printf("Preço...: %.2f\n",P[i].preco);
          									 	 
		              } 
		              i++; 
		    	} 
	 
	 			if (achou == 0)printf("Codigo não encontrado!"); 
	 
	 			printf("\nDeseja consultar mais um produto? (S/N)"); 
	 			resp = getche(); 
	 		} while (toupper(resp) == 'S');     
	 		break;
	 		
	 		default : puts("Digite uma opção valida");
	 		
		}
	}while(op != '3');
}

void relatorio_produto(produto *P){
   
    int i;
    
    system("cls");
    printf(">> REGISTROS DE PRODUTOS\n\n"); 
    
    setlocale(LC_ALL, "Portuguese");
    
    if(P[0].numero_cadastro==0){
     printf("\nNenhum Produto cadastrado ou buffer incompleto!!\n");
    }else{
    
        for(i=0 ;i <= P[0].numero_cadastro-1;i++){
        	if(P[i].codigo!=0){
				printf("Descr...: %s\n",P[i].descricao);
        		printf("Codigo..: %d\n",P[i].codigo);
        		printf("Preço...: %.2f \n\n",P[i].preco);
          	}
          	
        }
    
    }
    
    printf("\n\n");
    system("pause");
    system("cls");
} 

produto *excluir_produto(produto *P){ 
   
    int i,j;
    int achou,auxcod;
    char auxnome[30],conf='s';
    char op;
    
    do{
	achou=0;
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    printf(">> EXCLUSÃO DE PRODUTOS\n\n"); 
    printf("1 - Codigo\n");
    printf("2 - Descrição\n");
    printf("3 - Voltar\n");
    printf("\nDigite a opção desejada: ");
    op = getche();
    
	    switch(op){
	              
              case '1':
                    system("cls");
                    printf("\nDigite o codigo: ");
                    fflush(stdin);
                    scanf("%d",&auxcod);
                    
                    for(i=0;i<=P[0].numero_cadastro;i++){
						
                      	if(auxcod==P[i].codigo){
							
                        	printf("\n\nPRODUTO ENCONTRADO!\n\n");
                        
	                        printf("Codigo..: %d\n",P[i].codigo);
	                        printf("Descr...: %s\n",P[i].descricao);
	                        printf("Preço...: %.2f\n\n",P[i].preco);
                        
	                        achou=1;
	                        printf("DESEJA MESMO EXCLUIR O PRODUTO DE CODIGO  '%d?' (s/n): ",auxcod);
	                        fflush(stdin);
	                        scanf("%c",&conf);
	                    	if(conf=='s'){ 
	                        	strcpy(P[i].descricao,"0");
	                            P[i].preco = 0;
	                            P[i].codigo = 0;

	                        }
                    	}
                    }
                    
                    if(achou==0){ 
                    	printf("\nNENHUM PRODUTO COM CODIGO '%d' ENCONTRADO\n\n",auxcod);
                    }
              		
              break;
              case '2':
					system("cls");
				  	printf("\nDigite a descrição do produto: ");
                    fflush(stdin);
                    gets(auxnome);
                    
                    for(i=0;i<=P[0].numero_cadastro;i++){
	                      if(strcmp (auxnome,P[i].descricao) == 0 ){
			                    printf("\n\nPRODUTO ENCONTRADO!\n\n");
			                    
			                    achou=1;
			                    printf("Codigo..: %d\n",P[i].codigo);
				                printf("Descr...: %s\n",P[i].descricao);
				            	printf("Preço...: %.2f\n\n",P[i].preco);
				            	
			                    printf("DESEJA MESMO EXCLUIR %s? (s/n): ",auxnome);
			                    scanf("%c",&conf);
			                    if(conf=='s'){ 
			                    	strcpy(P[i].descricao,"0");
				                    P[i].preco = 0;
				                    P[i].codigo = 0;
			                    }
	                      }
                   	}
                    
                	if(achou==0){ 
                     	printf("\n>> CLIENTE '%s' NÃO ENCONTRADO\n\n",auxnome);
                    }
                
          		break;		
          		
          		case'3':
				break;
			  
              	default : puts("Digite uma opção válida!");
	              
	    }	
	    
	}while(op!= '3');

} 
