#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "modulo_cliente.h"

cliente * carregardosarquivos(){

FILE *arq;
arq = fopen("cliente.txt", "r");

cliente * lala;
cliente * retorno;
rewind(arq);
lala = (cliente *)malloc(sizeof(cliente));
fread(lala,sizeof(cliente),1,arq);
rewind(arq);
retorno = (cliente *)malloc(sizeof(cliente)*lala[0].numero_cadastro+1);
fread(retorno,sizeof(cliente),lala[0].numero_cadastro+1,arq);
fclose(arq);

return retorno;

}

void salvar_arquivo(cliente *C){
     int i;
     FILE *C_arq;
     C_arq = fopen("cliente.txt", "w");
     if(!C_arq){
          puts("arquivo não localizado");
     }
     else{
        i = fwrite(C, sizeof(cliente), C[0].numero_cadastro, C_arq);
        printf("\n\n\n gravaçoes %d", i); getche();
     }
     fclose(C_arq);
     
}

cliente *cadastro_cliente(cliente *C){
	cliente *C_aux;
	int i,erro;
	char resp = 's',conf = 'n';
	char aux_nome[MAX],aux_endereco[MAX],aux_telefone[MAX_TELEFONE];
	int aux_codigo;
	
	C_aux = (cliente *) malloc(5 * sizeof(cliente));
	
//ALOCAÇÃO DE MEMÓRIA
	
	for(i = 0; i <= C[0].numero_cadastro+1; i++){
		strcpy(C_aux[i].nome,C[i].nome);
		strcpy(C_aux[i].endereco,C[i].endereco);
		strcpy(C_aux[i].telefone, C[i].telefone); 
		C_aux[i].codigo = C[i].codigo;
	}
	C_aux[0].numero_cadastro = C[0].numero_cadastro;
	C_aux[0].buffer = C[0].buffer;			
	
		
	if(!C_aux){
		puts("Memória insuficiente!\n");
	} else {
			do{	
				system("cls");
				setlocale(LC_ALL, "Portuguese");
				
			   	do{
					if(erro==1){
     					system("cls");
     					printf("Digite novamente os dados !!\n\n");
					}
					printf(">> CADÁSTRO DE CLIENTES\n\n");
					puts("Nome do cliente:");
					fflush(stdin);
					gets(aux_nome);
					puts("Endereço do cliente:");
					fflush(stdin);
					gets(aux_endereco);
					puts("Telefone do Cliente:");
					gets(aux_telefone);							
		
					printf("Confirma dados cadastrais?(S/N): ");
  	    			fflush(stdin);
   					conf = getche();
   					
   					if(toupper(conf) == 'S'){ 
    		     		erro=0;
                        strcpy(C_aux[C_aux[0].numero_cadastro].nome,aux_nome);
                        strcpy(C_aux[C_aux[0].numero_cadastro].endereco,aux_endereco);
                        strcpy(C_aux[C_aux[0].numero_cadastro].telefone,aux_telefone);
                        C_aux[C_aux[0].numero_cadastro].codigo = C_aux[0].numero_cadastro+1;
                        C_aux[0].numero_cadastro++;//incrementa +1 em numero_cadastro
				    /*struct recebe os dados das variaveis auxiliares*/
                   /* contador é incrementado*/
                    }
					
					if(toupper(conf) == 'N'){
					erro = 1;
					}
				}while(toupper(conf) == 'N');
//REALOCAÇÃO E EXCLUSÃO FISICA

				if(C_aux[0].numero_cadastro == C_aux[0].buffer*5+1){					
					C_aux[0].buffer++;
					C_aux = realloc(C_aux, C_aux[0].buffer*5);
					
					for(i = 0; i <= C[0].numero_cadastro; i++){
                         
                        if(C_aux[i].codigo != 0)
                        {   
						    strcpy(C_aux[i].nome,C[i].nome);
						    strcpy(C_aux[i].endereco,C[i].endereco);
						    strcpy(C_aux[i].telefone, C[i].telefone); 
						    C_aux[i].codigo = C[i].codigo;
                        }
					}
					
				}
				
				
				
				printf("\nDeseja cadastrar mais um cliente? (S/N)");
				fflush(stdin);
				resp = getche();
				
 			} while(toupper(resp) == 'S');
 			salvar_arquivo(C);
 			return C_aux;			
	}				
}




void busca_cliente(cliente *C){
     int achou,i;
     char resp, op = '0', nome[MAX], telefone[MAX_TELEFONE];
    do{ 
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    
	printf("Busca de Clientes\n");
	printf("\n1 - Por Telefone");
	printf("\n2 - Por nome");
    printf("\n3 - Voltar");
    
	printf("\n\nDigite a opção desejada: ");
	
	op = getche(); 
     
	     switch(op){
	     
	     case '1':
	     	do{
	        	system("cls");
	        	printf("Entre com o telefone do cliente para consulta: "); 
	        	gets(telefone);
	        	achou = 0;  
	        	i = 0; 
	        	if(!C)printf("Nenhum registro foi criado!");
	        	while (i <= C[0].numero_cadastro+1 && achou == 0) {
		        	if (strcmp(telefone, C[i].telefone)==0){ 
		           		achou = 1;
		                printf("Codigo..: %d\n",C[i].codigo);
          				printf("Nome....: %s\n",C[i].nome);
          				printf("Endereço: %s\n",C[i].endereco);
          				printf("Telefone: %s \n\n",C[i].telefone);
						 	 
		              } 
		              i++; 
		    	} 
	 
	 			if (achou == 0)printf("Telefone não encontrado!"); 
	 
	 			printf("\nDeseja consultar mais um cliente? (S/N)"); 
	 			resp = getche(); 
	 		} while (toupper(resp) == 'S');     
	 		break;
	 	
	 	case '2':
			do{
	        	system("cls");
	        	fflush(stdin);
	        	printf("Entre com o Nome do cliente para consulta: "); 
	        	gets(nome);
	        	achou = 0;  
	        	i = 0; 
	        	
	        	while (i <= C[0].numero_cadastro+1 && achou == 0) {
		              if (strcmp(nome, C[i].nome)==0){ 
		                 achou = 1;
                         printf("Codigo..: %d\n",C[i].codigo);
          				 printf("Nome....: %s\n",C[i].nome);
          				 printf("Endereço: %s\n",C[i].endereco);
          				 printf("Telefone: %s \n\n",C[i].telefone);						 						 
		              }
		              i++; 
		    	} 
	 
	 			if (achou == 0)printf("Cliente não encontrado!"); 
	 
	 			printf("\nDeseja consultar mais um cliente? (S/N)"); 
	 			resp = getche(); 
	 		} while (toupper(resp) == 'S');     
	 		break;
	 		
		}
	}while(op != '3');
}

void relatorio_cliente(cliente *C){
   
    int i;
    
    system("cls");
    printf(">> REGISTROS DE CLIENTES\n\n"); 
    
    if(C[0].numero_cadastro==0){
     printf("\nNenhum Cliente cadastrado ou buffer incompleto!!\n");
    }
    
    else{
    
        for(i=0 ;i <= C[0].numero_cadastro-1;i++){
          if(C[i].codigo!=0){
          printf("Codigo..: %d\n",C[i].codigo);
          printf("Nome....: %s\n",C[i].nome);
          printf("Endereço: %s\n",C[i].endereco);
          printf("Telefone: %s \n\n",C[i].telefone);
          }
        }
    
    }
    
    printf("\n\n");
    system("pause");
} 

cliente *excluir_cliente(cliente *C){ 
   
    int i,j;
    int achou,auxcod;
    char auxnome[30],conf='s';
    char op;
    
    do{
	    achou=0;
	    system("cls");
	    printf(">> EXCLUSÃO DE CLIENTES\n\n"); 
	    printf("1 - Descrição\n");
	    printf("2 - Codigo\n");
	    printf("3 - Voltar\n");
	    printf("\nDigite a opção desejada: ");
	    
	    op = getche();
	    
	    switch(op)
	    {
	              case '1':
	              		system("cls");
	                    printf("\nDigite o nome do cliente: ");
	                    fflush(stdin);
	                    gets(auxnome);
	                    
	                    for(i=0;i<=C[0].numero_cadastro;i++){
	                      if(strcmp (auxnome,C[i].nome) == 0 ){
	                        printf("\n\nCLIENTE ENCONTRADO!\n\n");
	                        printf("Codigo..: %d\n",C[i].codigo);
	                        printf("Nome....: %s\n",C[i].nome);
	                        printf("Endereço: %s\n",C[i].endereco);
	                        printf("Telefone: %s\n\n",C[i].telefone);
	                        achou=1;
	                        printf("DESEJA MESMO EXCLUIR %s? (s/n): ",auxnome);
	                        scanf("%c",&conf);
	                        if(conf=='s'){ 
	                        	strcpy(C[i].nome,"0");
		                    	strcpy(C[i].endereco,"0");
		                    	strcpy(C[i].telefone, "0");
		                    	C[i].codigo = 0;
	                          }
	                      }
	                   }
	                    
	                    if(achou==0){ 
	                     printf("\n>> CLIENTE '%s' NÃO ENCONTRADO\n\n",auxnome);
	                    }
	                    
	              break;
	              
	              case '2':
	                    system("cls");
	                    printf("\nDigite o codigo: ");
	                    fflush(stdin);
	                    scanf("%d",&auxcod);
	                    
	                    for(i=0;i<=C[0].numero_cadastro;i++){
	                      	if(auxcod==C[i].codigo){
	                        	printf("\n\nCLIENTE ENCONTRADO!\n\n");
	                        
		                        printf("Codigo..: %d\n",C[i].codigo);
		                        printf("Nome....: %s\n",C[i].nome);
		                        printf("Endereco: %s\n",C[i].endereco);
		                        printf("Telefone: %s\n\n",C[i].telefone);
	                        
		                        achou=1;
		                        printf("DESEJA MESMO EXCLUIR O CLIENTE DE CODIGO  '%d?' (s/n): ",auxcod);
		                        fflush(stdin);
		                        scanf("%c",&conf);
		                    	if(conf=='s'){ 
		                        	strcpy(C[i].nome,"0");
		                            strcpy(C[i].endereco,"0");
		                            strcpy(C[i].telefone, "0");
		                            C[i].codigo = 0;
		                        }
	                    	}
	                    }
	                    
	                    if(achou==0){ 
	                    printf("\nNENHUM CLIENTE COM CODIGO '%d' ENCONTRADO\n\n",auxcod);
	                    }
	              		
	              break;
	              
	              case '3':
				  break;
	              
	              default: puts("Digite uma opção válida!");
	              
	    }
                   
	}while(op!='3');

} 
