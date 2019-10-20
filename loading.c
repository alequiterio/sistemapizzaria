#include <stdio.h>
#include <windows.h>


 
int tela_loading(void)
{    
   int i, j;
    
   system ("cls");
printf("\n\n\n\n            ____    _    ____    ____    _____    _____    _    _____\n");
printf("           | __ |  | |  |__  |  |__  |  |  _  |  |  __ |  | |  |  _  |\n");
printf("           |  __|  | |    / /     / /   | |_| |  |    _|  | |  | |_| |\n");
printf("           | |     | |   / /_    / /_   |  _  |  | |\\ \\   | |  |  _  |\n");
printf("           |_|     |_|  |____|  |____|  |_| |_|  |_| \\_\\  |_|  |_| |_|\n\n\n");
printf("                                  Pizza Pim                        \n");
    
   printf ("\n\n\n\n\n                            Carregando Base de Dados: \n\n");          
   
   for (i = 0; i <= 50; i++)
   {                      
	  printf ("  %d%%\r", i*2);
      fflush (stdout);                      
          
      for (j = 0; j < i; j++)
      {
         if (!j)
         printf ("             ");
            
         printf ("%c", 219);
         Sleep(0.9);
      }                      
   }
           
   printf("\n\n\n                                   Carregado!\n");
           puts("                 Aperte qualquer tecla para continuar a execucao!");
   getche();
    
   return 0;
}
