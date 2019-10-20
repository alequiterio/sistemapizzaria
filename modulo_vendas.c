#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#include "modulo_vendas.h"

//---------------------------------------------------DELIVERY---------------------------------------------------------------

venda *delivery(venda *V, produto *P, cliente *C){
 
	venda *D_aux;
	int i,j,comparador,achou;
	char resp = 'S',op;
	char cad_cliente, telefone[20], cad_produto = 's';
	

	D_aux = (venda *) malloc(5 * sizeof(venda));//------------MALLOC-------------

	//REALOC
	for(i = 0; i <=V[0].numero_venda; i++){
		
		D_aux[i].valor_total = V[i].valor_total;
		D_aux[i].codigo_cliente = V[i].codigo_cliente;
		D_aux[i].quantidade_de_produtos = V[i].quantidade_de_produtos;
		D_aux[i].codigo = V[i].codigo;
		for(j=0;j<=D_aux[i].quantidade_de_produtos;j++){
			
			D_aux[i].codigo_produto[j] = V[i].codigo_produto[j];
			D_aux[i].quantidade_do_produto[j] = V[i].quantidade_do_produto[j];
		} 	
	} 
	D_aux[0].numero_venda = V[0].numero_venda;
	D_aux[0].buffer = V[0].buffer;
	
	if(!D_aux){
		puts("Memória insuficiente!\n");
	}else{
		do{	
			system("cls");
			puts("Digite o telefone do cliente ou '0' para sair:");
			fflush(stdin);
			gets(telefone);
			if(strcmp(telefone,"0")==0)break;
        	achou = 0;  
        	i = 0; 
			
			D_aux[D_aux[0].numero_venda].quantidade_de_produtos = 0;
			D_aux[D_aux[0].numero_venda+1].quantidade_de_produtos = 0;
			//BUSCA DE CLIENTE POR TELEFONE
			
        	if(!C)printf("Nenhum registro foi criado!");
        	while (i <= C[0].numero_cadastro+1 && achou == 0) {
	        	if (strcmp(telefone,C[i].telefone)== 0){ 
	           		achou = 1;
	           		D_aux[D_aux[0].numero_venda].codigo_cliente = i;
	           		
	           		printf("CLIENTE ENCONTRADO!!\n\n");
	                printf("Codigo..: %d\n",C[i].codigo);
      				printf("Nome....: %s\n",C[i].nome);
      				printf("Endereço: %s\n",C[i].endereco);
      				
      				system("pause");
				} 
	            i++; 
	    	} 
 			//CASO O CLIENTE NÃO EXISTA -> visualizar lista
 			if (achou == 0){
				printf("Cliente não encontrado, deseja visualizar o relatório de clientes? (S/N)");
				cad_cliente = getche();
				if(toupper(cad_cliente) == 'S'){
					relatorio_cliente(C);
					break;
				}else{
					break;
				} 			
 			}else{//FIM DA BUSCA E CADASTRO POR CLIENTE E COMEÇO DOS PRODUTOS 
				achou = 0;
				i = 0;
				j = 0;
				do{
					system("cls");
					printf("Entre com o codigo do produto para consulta: ");
        			scanf("%d", &comparador);
        			achou = 0;  
        			i = 0;
        			if(!P)printf("Nenhum registro foi criado!");
        			while (i <= P[0].numero_cadastro+1 && achou == 0){
	        			if (comparador == P[i].codigo){
	           			achou = 1;
	           			D_aux[D_aux[0].numero_venda].quantidade_de_produtos++;
	           			D_aux[D_aux[0].numero_venda].codigo_produto[j] = i;

      					printf("Desc....: %s\n",P[i].descricao);
      					printf("Preço...: %.2f\n",P[i].preco);
      					
      					printf("\nDigite a quantidade de %s:",P[i].descricao);
						scanf("%d",&D_aux[D_aux[0].numero_venda].quantidade_do_produto[j]);
	           			D_aux[D_aux[0].numero_venda].valor_total = D_aux[D_aux[0].numero_venda].valor_total 
						   										   + (P[i].preco * D_aux[D_aux[0].numero_venda].quantidade_do_produto[j]);
      					j++;
	  		            }
	              	i++; 
	    			}
 
			 		if (achou == 0){
						printf("Produto não encontrado!");
						printf("\nDeseja consultar o relatório de produtos?(S/N)");
			 			cad_produto = getche();
			 			if(toupper(cad_produto) == 'S'){
							relatorio_produto(P);
			 			}else{
							break;
			 			}
			 		}
			 		
			 		printf("\nDeseja inserir/procurar outro produto? (S/N)");
			 		cad_produto = getche();
					
 				} while (toupper(cad_produto) == 'S');	
 			}
 			
 			D_aux[D_aux[0].numero_venda].codigo = D_aux[0].numero_venda+1;//incremente o codigo da venda
 			
 			//RESUMO DA VENDA!!
			system("cls");
			printf("Cliente:  %s\n",C[D_aux[D_aux[0].numero_venda].codigo_cliente].nome);
			printf("Endereço: %s\n",C[D_aux[D_aux[0].numero_venda].codigo_cliente].endereco);
			printf("Telefone: %s\n\n",C[D_aux[D_aux[0].numero_venda].codigo_cliente].telefone);
			
			printf("Código da Venda: %d\n\n",D_aux[D_aux[0].numero_venda].codigo);
			
			for(j=0;j<D_aux[D_aux[0].numero_venda].quantidade_de_produtos;j++){
				printf("Produto: %s\n",P[D_aux[D_aux[0].numero_venda].codigo_produto[j]].descricao);
				printf("Quantidade: %d unidade(s)\n",D_aux[D_aux[0].numero_venda].quantidade_do_produto[j]);
				printf("Valor:                        R$ %.2f\n\n",P[D_aux[D_aux[0].numero_venda].codigo_produto[j]].preco
																 * D_aux[D_aux[0].numero_venda].quantidade_do_produto[j]);
				
			}
			printf("\nO total da venda é de:        R$ %.2f",D_aux[D_aux[0].numero_venda].valor_total);
			
			D_aux[0].numero_venda++;//incrementa +1 em numero_cadastro
			
			if(D_aux[0].numero_venda == D_aux[0].buffer*5+1){
				D_aux[0].buffer++;
				D_aux = realloc(D_aux, D_aux[0].buffer*5);
				
				for(i = 0; i <= V[0].numero_venda; i++){
					D_aux[i].valor_total = V[i].valor_total;
					D_aux[i].codigo_cliente = V[i].codigo_cliente;
					D_aux[i].quantidade_de_produtos = V[i].quantidade_de_produtos;
					D_aux[i].codigo = V[i].codigo;
					for(j=0;j<=V[i].quantidade_de_produtos;j++){
						D_aux[i].codigo_produto[j] = V[i].codigo_produto[j];
						D_aux[i].quantidade_do_produto[j] = V[i].quantidade_do_produto[j];
					} 	
				}
				
			}
			
			
			if(resp == 'n')return D_aux;
			printf("\nDeseja efetuar mais uma venda? (S/N)");
			fflush(stdin);
			resp = getche();
			 
		} while(toupper(resp) == 'S');
		return D_aux;	
	}					
}


void relatorio_venda(venda *V, produto *P, cliente *C){
	int i = 0,j;
	char posicao;
	
    system("cls");
    printf(">> REGISTROS DE VENDAS!!\n\n"); 
    
	if(V[0].numero_venda==0){
    printf("\nNenhum Venda efetuada ou buffer incompleto!!\n");
    }else{
        for(i=0;i<V[0].numero_venda;i++){
        	if(V[i].codigo!=0){
				printf("Cliente:  %s\n",C[V[i].codigo_cliente].nome);
				printf("Endereço: %s\n",C[V[i].codigo_cliente].endereco);
				printf("Telefone: %s\n\n",C[V[i].codigo_cliente].telefone);			
				printf("Código da Venda: %d\n\n",V[i].codigo);
				
				for(j=0;j<V[i].quantidade_de_produtos;j++){
					printf("Produto: %s\n",P[V[i].codigo_produto[j]].descricao);
					printf("Quantidade: %d unidade(s)\n",V[i].quantidade_do_produto[j]);
					printf("Valor:                        R$%.2f\n\n",P[V[i].codigo_produto[j]].preco
																	 * V[i].quantidade_do_produto[j]);
				}
				printf("\nO total da venda é de:        R$%.2f",V[i].valor_total);
				
				printf("\n\n___________________________________________________________________\n\n");
    		}
        }
    
    }
    
    printf("\n\n");
    system("pause");
} 


