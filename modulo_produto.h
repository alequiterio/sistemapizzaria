#define MAX 100	

typedef struct {	
	char descricao[MAX];
	int numero_cadastro,codigo,buffer;
	float preco;
	} produto;
	
produto *cadastro_produto(produto *P);

void busca_produto(produto *P);

void relatorio_produto(produto *P);

produto *excluir_produto(produto *P);
