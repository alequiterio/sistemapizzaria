#include "modulo_cliente.h"
#include "modulo_produto.h"
#include "modulo_funcionarios.h"

typedef struct{
    float valor_total;
	int codigo,numero_venda,buffer,codigo_cliente,codigo_produto[5],quantidade_do_produto[5],quantidade_de_produtos;  
} venda;

venda *menu_venda(venda *V, produto *P, cliente *C, funcionario *F);

void relatorio_venda(venda *V, produto *P, cliente *C);

venda *delivery(venda *V, produto *P, cliente *C);
