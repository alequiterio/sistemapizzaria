#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#include "modulo_funcionarios.h"

funcionario *cadastro_funcionarios(funcionario *F){
	funcionario *F_aux;	
	int i;
	char resp = 'S';
		
	F_aux = (funcionario *) malloc(5 * sizeof(funcionario));

	
	
	for(i = 0; i <= F[0].numero_cadastro+1; i++){
		strcpy(F_aux[i].nome,F[i].nome);
		strcpy(F_aux[i].endereco,F[i].endereco);
		strcpy(F_aux[i].telefone,F[i].telefone); 
		F_aux[i].codigo = F[i].codigo;
		F_aux[i].salario = F[i].salario;
		F_aux[i].comissao = F[i].comissao;
	}
	F_aux[0].numero_cadastro = F[0].numero_cadastro;
	F_aux[0].buffer = F[0].buffer;			
	
		
	if(!F_aux){
		puts("Memória insuficiente!\n");
	} else {
			do{	
				system("cls");
				puts("Nome do funcionarios:");
				fflush(stdin);
				gets(F_aux[F_aux[0].numero_cadastro].nome);
				puts("Endereço do funcionarios:");
				fflush(stdin);
				gets(F_aux[F_aux[0].numero_cadastro].endereco);
				puts("Telefone do funcionarios:");
				gets(F_aux[F_aux[0].numero_cadastro].telefone);
				puts("Salario:");
				scanf("%f", &F_aux[F_aux[0].numero_cadastro].salario);
				F_aux[F_aux[0].numero_cadastro].comissao = 0.00;
				                
                							
				F_aux[F_aux[0].numero_cadastro].codigo = F_aux[0].numero_cadastro+1;
				
				
				F_aux[0].numero_cadastro++;//incrementa +1 em numero_cadastro
				
				if(F_aux[0].numero_cadastro == F_aux[0].buffer*5+1){					
					F_aux[0].buffer++;
					F_aux = realloc(F_aux, F_aux[0].buffer*5);
					
					for(i = 0; i <= F[0].numero_cadastro; i++){
                          
                          if(F_aux[i].codigo != 0)
                          {                                           
                               strcpy(F_aux[i].nome,F[i].nome);
                               strcpy(F_aux[i].endereco,F[i].endereco);
						       strcpy(F_aux[i].telefone,F[i].telefone); 
				               F_aux[i].codigo = F[i].codigo;
						       F_aux[i].salario = F[i].salario;
						       F_aux[i].comissao = F[i].comissao;
                          }
					}
					
				}
				
				
				
				printf("\nDeseja cadastrar mais um funcionario? (S/N)");
				fflush(stdin);
				resp = getche();
				
 			} while(toupper(resp) == 'S');
 			return F_aux;			
	}				
}




void busca_funcionarios(funcionario *F){
     int achou,i;
     char resp, op = '0', nome[MAX],comparador[MAX_TELEFONE];
    do{ 
    system("cls");
	printf("Busca de Funcionarios\n");
	printf("\n1 - Por Telefone");
	printf("\n2 - Por nome");
    printf("\n3 - Voltar");
    
	printf("\n\nDigite a opcao desejada: ");
	
	op = getche(); 
     
	     switch(op){
	     
	     case '1':
	     	do{
	        	system("cls");
	        	printf("Entre com o telefone do cliente para consulta: "); 
	        	gets(comparador);
	        	achou = 0;  
	        	i = 0; 
	        	if(!F)printf("Nenhum registro foi criado!");
	        	while (i <= F[0].numero_cadastro+1 && achou == 0) {
		        	if (strcmp(comparador,F[i].telefone)==0){ 
		           		achou = 1;
		                printf("\nCodigo...: %d\n",F[i].codigo);
          				printf("Nome.....: %s\n",F[i].nome);
          				printf("Endereco.: %s\n",F[i].endereco);
          				printf("Telefone.: %s \n\n",F[i].telefone);
          				printf("Telefone.: %f \n\n",F[i].salario);
          				printf("Telefone.: %f \n\n",F[i].comissao);
						 	 
		              } 
		              i++; 
		    	} 
	 
	 			if (achou == 0)printf("Telefone nao encontrado!"); 
	 
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
	        	
	        	while (i <= F[0].numero_cadastro+1 && achou == 0) {
		              if (strcmp(nome, F[i].nome)==0){ 
		                 achou = 1;
						 printf("\nCodigo...: %d\n",F[i].codigo);
          				 printf("Nome.....: %s\n",F[i].nome);
          				 printf("Endereco.: %s\n",F[i].endereco);
          				 printf("Telefone.: %s \n\n",F[i].telefone);
          				 printf("Telefone.: %f \n\n",F[i].salario);
          				 printf("Telefone.: %f \n\n",F[i].comissao); 
						 
		              }
		              i++; 
		    	} 
	 
	 			if (achou == 0)printf("Cliente nao encontrado!"); 
	 
	 			printf("\nDeseja consultar mais um cliente? (S/N)"); 
	 			resp = getche(); 
	 		} while (toupper(resp) == 'S');     
	 		break;
	 		
		}
	}while(op != '3');
}

void relatorio_funcionarios(funcionario *F){
   
    int i;
    
    system("cls");
    printf("REGISTROS DE FUNCIONARIOS\n\n"); 
    
    if(F[0].numero_cadastro==0){
     printf("\nNenhum Funcionario cadastrado ou buffer incompleto!!\n");
    }
    
    else{
    
        for(i=0 ;i <= F[0].numero_cadastro;i++){
          if(F[i].codigo!=0){
          printf("Codigo...: %d\n",F[i].codigo);
          printf("Nome.....: %s\n",F[i].nome);
          printf("Endereco.: %s\n",F[i].endereco);
          printf("Telefone.: %s \n\n",F[i].telefone);
          printf("Salario.: %.2f \n\n",F[i].salario);
          printf("Comissao.: %.2f \n\n",F[i].comissao);
          }
        }
    
    }
    
    printf("\n\n");
    system("pause");
} 

funcionario *excluir_funcionario(funcionario *F){ 
   
    int i,j;
    int achou,auxcod;
    char auxnome[30],conf='s';
    char op;
    
    do{
	    achou=0;
	    system("cls");
	    printf(">> EXCLUSAO DE FUNCIONARIOS\n\n"); 
	    printf("1 - Descricao\n");
	    printf("2 - Codigo\n");
	    printf("3 - Voltar\n");
	    printf("\nDigite a opcao desejada: ");
	    
	    op = getche();
	    
	    switch(op){
	              case '1':
	              		system("cls");
	                    printf("\nDigite o nome do cliente: ");
	                    fflush(stdin);
	                    gets(auxnome);
	                    
	                    for(i=0;i<=F[0].numero_cadastro;i++){
	                      if(strcmp (auxnome,F[i].nome) == 0 ){
	                        printf("\n\nFUNCIONARIO ENCONTRADO!\n\n");
	                        printf("Codigo: %d\n",F[i].codigo);
	                        printf("Nome: %s\n",F[i].nome);
	                        printf("Endereco: %s\n",F[i].endereco);
	                        printf("Telefone: %s\n\n",F[i].telefone);
	                        printf("Salario: %.2f\n\n",F[i].salario);
	                        printf("Comissao: %.2f\n\n",F[i].comissao);
	                        achou=1;
	                        printf("DESEJA MESMO EXCLUIR %s? (s/n): ",auxnome);
	                        scanf("%c",&conf);
	                        if(conf=='s'){ 
	                        	strcpy(F[i].nome,"0");
		                    	strcpy(F[i].endereco,"0");
		                    	strcpy(F[i].telefone,"0");
		                    	F[i].codigo = 0;
		                    	F[i].salario = 0;
		                    	F[i].comissao = 0;
	                          }
	                      }
	                   }
	                    
	                    if(achou==0){ 
	                     printf("\n>> FUNCIONARIO '%s' NAO ENCONTRADO\n\n",auxnome);
	                    }
	                    
	              break;
	              
	              case '2':
	                  	system("cls");
	                    printf("\nDigite o codigo: ");
	                    fflush(stdin);
	                    scanf("%d",&auxcod);
	                    
	                    for(i=0;i<=F[0].numero_cadastro;i++){
	                      	if(auxcod==F[i].codigo){
	                        	printf("\n\nFUNCIONARIO ENCONTRADO!\n\n");
	                        
		                        printf("Codigo: %d\n",F[i].codigo);
		                        printf("Nome: %s\n",F[i].nome);
		                        printf("Endereco: %s\n",F[i].endereco);
		                        printf("Telefone: %s\n\n",F[i].telefone);
		                        printf("Salario: %.2f\n\n",F[i].salario);
		                        printf("Comissao: %.2f\n\n",F[i].comissao);
	                        
		                        achou=1;
		                        printf("DESEJA MESMO EXCLUIR O FUNCIONARIO DE CODIGO  '%d?' (s/n): ",auxcod);
		                        fflush(stdin);
		                        scanf("%c",&conf);
		                    	if(conf=='s'){ 
		                        	strcpy(F[i].nome,"0");
		                            strcpy(F[i].endereco,"0");
		                            strcpy(F[i].telefone,"0");
		                            F[i].codigo = 0;
		                            F[i].salario = 0;
		                            F[i].comissao = 0;
		                            
		                          
		                        }
	                    	}
	                    }
	                    
	                    if(achou==0){ 
	                    printf("\nNENHUM CLIENTE COM CODIGO ""%d"" ENCONTRADO\n\n",auxcod);
	                    }
	              		
	              break;
	              
	              case '3':
				  break;
	              
	              default: puts("Digite uma opção válida!");
	              
	    }
                   
    
    }while(op!='3');

} 
