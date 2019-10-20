#define MAX 100	
#define MAX_TELEFONE 20

typedef struct {	
	char nome[MAX], endereco[MAX],telefone[MAX_TELEFONE];
	int numero_cadastro,codigo,buffer;
	float salario,comissao;
	} funcionario;
	
funcionario *cadastro_funcionarios(funcionario *F);

void busca_funcionarios(funcionario *F);

void relatorio_funcionarios(funcionario *F);

funcionario *excluir_funcionario(funcionario *F);	

