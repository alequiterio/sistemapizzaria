#define MAX 100	
#define MAX_TELEFONE 20

typedef struct {	
	char nome[MAX], endereco[MAX], telefone[MAX_TELEFONE];
	int numero_cadastro, codigo, buffer;
	} cliente;
	
cliente * carregardosarquivos();

void salvar_arquivo(cliente *C);	

cliente *cadastro_cliente(cliente *C);

void busca_cliente(cliente *C);

void relatorio_cliente(cliente *C);

cliente *excluir_cliente(cliente *C);
