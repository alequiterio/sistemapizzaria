#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main (){
 
char nome[100][100],nome2[100],nomeP[100][100],nome2P[100],endereco[100][100],desc[100][100],endereco2[100],ch = 's'; //DECLARAR CERTO
int op1,op2,op3,p1,p2,x,l=0,fone[100],fone2;
float valor[100],valor2;
    do{
        system ("cls");
        printf("\n _______________________________");
        puts("\n \n MENU - PIZZARIA ");
        printf("\n _______________________________");
        puts("\n \n 1- Clientes");
        puts("\n 2- Produtos");
        puts("\n 3- Cardapio");
        puts("\n 4- Fornecedores");
        puts("\n 5- Funcionarios");
        puts("\n 6- Configurações de Usuario");
        puts("\n 7- Executar Venda");
        puts("\n 8- SAIR");
        printf("\n _______________________________");
        printf("\n \n Escolha um opcao: ");
        scanf("%d", &op1);
       
 
    switch (op1){

    //------------------------------------------------------------------Menu Clientes

     case 1:

          do{
               system("cls");
               printf("\n _______________________________");
               puts("\n \n MENU - Clientes ");
               printf("\n _______________________________");
               puts("\n \n 1- Cadastro");
               puts("\n 2- Consulta");
               puts("\n 3- Relatorio");
               puts("\n 4- SAIR");
               printf("\n _______________________________");
               printf("\n \n Escolha um opcao: ");
               scanf("%d", &op2);
 
               switch (op2){

                    case 1:system("cls");
                          while(ch=='s'){
      
                               puts("\n\n CADASTRO CLIENTE");
       
                               printf("\n Nome: ");
                               fflush(stdin);
                               gets(nome[l]);
       
                               printf("\n Endereco: Rua. ");
                               fflush(stdin);
                               gets(endereco[l]);
       
                               printf("\n Fone: ");
                               scanf("%d", &fone[l]);
                               l++;
                               puts("Deseja Inserir outro Cliente?(s/n)");
                               ch = getch();
                               system ("cls");
                          }
                    break;
                    			
                    
                    case 2: do{
                              system("cls");
                              puts("\n 1 - Nome");
                              puts("\n 2 - Endereco");
                              puts("\n 3 - Fone");
                              puts("\n 4 - SAIR");
                              printf("\n Escolha o que voce deseja consultar : ");
                              scanf("%d", &op3);
 

                              switch(op3){
                                  case 1: system("cls");
        
                                     printf("\n Digite o nome desejado: ");
                                     fflush(stdin);
                                     gets(nome2);
                                     for (x=0;x<l;x++){
                                        if (strcmp (nome[x] , nome2) == 0){
                                           printf("\n Nome = %s ",nome[x]);
                                           printf("\n Endereco = %s",endereco[x]);
                                           printf("\n Fone = %d",fone[x]);
    
                                        }
        
                                     }
                                     getch(); 
                                  break;
      
                                  case 2: system("cls"); 
                                         printf("Digite o endereco desejado: ");
                                         fflush(stdin);
                                         gets(endereco2); //TROCAR por gets(endereco2);
            
                                         for (x=0;x<l;x++){
                                             if  (strcmp(endereco[x],endereco2)==0){   //USAR STRCMP
                                                 printf("\n Nome = %s ",nome[x]);
                                                 printf("\n Endereco = Rua. %s",endereco[x]);
                                                 printf("\n Fone = %d",fone[x]);
                                             }
                                         }
                                         getch();
        
                                   break;

                                    case 3: system("cls");
                                         printf("Digite o fone desejado: ");
                                         scanf("%d", &fone2);
  
                                         for (x=0;x<l;x++){
                                            if  (fone[x] == fone2){
                                                 printf("\n Nome = %s ",nome[x]);
                                                 printf("\n Endereco = Rua. %s",endereco[x]);
                                                 printf("\n Fone = %d",fone[x]);
         
                                             }
                                          }
                                       getch();
      
                                   break;
        
        
        
        //------------------------------------------------------------------------------------------------------------------
        
        
        
        
        
                                	case 4: 
                                        break;
                              }//fim switch op3 
                            }while(op3!=4);
     
                 break;  
    
                case 3: system("cls");
                          printf("\n RELATORIO");
                          printf("\n _______________________________");
                          for (x=0;x<l;x++){
                              printf("\n\n Nome = %s", nome[x]);
                              printf("\n Endereco = Rua. %s", endereco[x]);
                              printf("\n Fone =  %d \n", fone[x]);
                              printf("\n _______________________________");
                              
                              }
                              getch();
                        break;
} 

            }while(op2!=4);
        break;
//-----------------------------------------------------------Menu Produtos
 

        case 2:
             do{
               system("cls");
               printf("\n _______________________________");
               puts("\n \n MENU - Produtos ");
               printf("\n _______________________________");
               puts("\n \n 1- Cadastro");
               puts("\n 2- Consulta");
               puts("\n 3- Relatorio");
               puts("\n 4- SAIR");
               printf("\n _______________________________");
               printf("\n \n Escolha um opcao: ");
               scanf("%d", &op2); 
               switch (op2){

                    case 1:system("cls");
                           while(ch=='s'){
       
                               puts("\n\n CADASTRO PRODUTO");
       
                               printf("\n Nome: ");
                               fflush(stdin);
                               gets(nomeP[l]);
       
                               printf("\n Descricao: ");
                               fflush(stdin);
                               gets(desc[l]);
       
                               printf("\n Valor: R$ ");
                               scanf("%f", &valor[l]);
                               l++;
                               puts("Deseja Inserir outro Produto?(s/n)");
                               ch = getch();
                               system ("cls");
                           }
                    break;
            
                    case 2: system("cls");
    
                            do{
                               system("cls");
                               puts("\n 1 - Nome");
                               puts("\n 2 - Valor");
                               puts("\n 3 - SAIR");
                               printf("\n Escolha o que voce deseja consultar: ");
                               scanf("%d", &op3); 

                               switch(op3){
                                    case 1: system("cls");
                                            printf("\n Digite o nome desejado: ");
                                             fflush(stdin);
                                             gets(nome2P);
                                             for (x=0;x<l;x++){
                                                if (strcmp(nomeP[x] , nome2P) == 0){
                                                    printf("\n Nome = %s ",nomeP[x]);
                                                    printf("\n Descricao = %s",desc[x]);
                                                    printf("\n Valor = R$ %.2f",valor[x]);
                                                 }
                                             }
                                     getch(); 
                                     break;
          
                                     case 2: system("cls");
                                             printf("Digite o valor desejado: ");
                                             scanf("%f", &valor2);
  
                                             for (x=0;x<l;x++){
                                                if  (valor[x] == valor2){
                                                    printf("\n Nome = %s ",nomeP[x]);
                                                    printf("\n Descricao = %s",desc[x]);
                                                    printf("\n Valor = R$ %.2f",valor[x]);
             
                                                }
                                             }
                                             getch();
                                      break;
            
                                      case 3: 
                                      break;
                                 }//---op3
                            }while(op3!=3);
                    break;  
         
                    case 3: system("cls");
                           printf("\n RELATORIO");
                           printf("\n _______________________________");
                            for (x=0;x<l;x++){
                                printf("\n\n Nome = %s", nomeP[x]);
                                printf("\n Descricao = %s", desc[x]);
                                printf("\n Valor = R$ %.2f \n", valor[x]);
                                printf("\n _______________________________");
                            }
                           getch();
                     break;
 
                    case 4: system("cls"); 
                            break;
                }// ---op2
            }while(op2!=4);
        break;
        //-----------------------------------------------Cardapio
        case 3: system ("cls");
        printf("\n RELATORIO");
        printf("\n _______________________________");
        for (x=0;x<l;x++){
			printf("Nome                     Descrição                 Preço");
        	printf("\n %s", nomeP[x],"           %s", desc[x],"                 R$ %.2f", valor[x]);
        }
        puts("Digite qualquer tecla para sair.");
        getch();
             
        break;
             
             

        //-----------------------------------------------Sair
        case 8: system("cls"); 
        break;
    }
    //----op1

    }while(op1!=8);
    
}
