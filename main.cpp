#include <stdio.h>
#include <windows.h>


#define SIZECLI 200
#define SIZEPROD 200
#define SIZEMOV 200



//declarando as variaveis globais
//da funcao cadastro de clientes
char nomeCliente[SIZECLI][50];
char moradaCliente[SIZECLI][50];
int contactoCliente[SIZECLI];


//declarando as variaveis globais auxiliares
int totalCadCliente;
int totalCadProduto;


//declarando as variaveis globais
//da funcao cadastro de produtos
char descricaoProduto[SIZEPROD][50];
int quantidadeProduto[SIZEPROD];
int precoUnitario[SIZEPROD];

int saida[SIZEPROD];

//declarando as variaveis globais
//da funcao movimentacao
char nomeClienteMoviment[SIZEMOV][50];
char descricaoProdutoMoviment[SIZEMOV][50];
int quantidadeProdutoMoviment[SIZEMOV];
int precoProdutoMoviment[SIZEMOV];
int totalProdutoMoviment[SIZEMOV];
int totalGeralProdutoMoviment[SIZEMOV];




//DECLARANDO AS VARIAS GLOBAIS AUXILIARES
int opc;
bool cont;


//declarando as funcoes do programa
//area de cadastramentos
void cadastramento();

void cadastroCliente();
void listarCliente();

void cadastroProduto();
void listarProduto();
//fim da area de cadastramentos

//area movimentacao
int movimentacao();
int movimentVenda();

//area de gestao
int gestao();
int gestCliente();
int gestProduto();
//fim da area de gestao

int main(void) {
	int esc;
	bool run;

	do {
		Sleep(1000);
		system("cls");
		printf("\nSISTEMA DE VENDAS - MENU PRINCIPAL");
		Sleep(744);
		printf("\n[1] - Cadastramentos\n[2] - Movimentacoes\n[3] - Gestao\n[0] - Sair do Sistema");
		Sleep(267);
		printf("\n>_ ");
		scanf("%i", &esc);

		switch(esc) {
			case 1:
				Sleep(100);
				printf("Cadastramentos");
				Sleep(2000);
				cadastramento();
				run=true;
				break;
			case 2:
				Sleep(100);
				printf("Movimentacoes");
				Sleep(2000);
				movimentacao();
				run=true;
				break;
			case 3:
				Sleep(100);
				printf("Gestao");
				Sleep(2000);
				gestao();
				run=true;
				break;
			case 0:
				Sleep(100);
				printf("\n\nSaindo do Sistema...");
				Sleep(3700);
				exit(1);
				run=false;
				break;
			default:
				Sleep(1000);
				printf("Opcao Invalida");
				break;
		}
	} while(run==true);

}

void cadastramento() {
	int esc;
	bool run;

	do {
		system("cls");
		Sleep(1000);
		printf("\nMENU DE CADASTRAMENTO");
		Sleep(1000);
		printf("\n[1] - Cadastramento de Clientes\n[2] - Cadastramento de Produtos\n[0] - Voltar");
		Sleep(1000);
		printf("\n>_ ");
		scanf("%i", &esc);

		switch(esc) {
			case 1:
				Sleep(100);
				printf("Cadastramento de Clientes");
				Sleep(2000);
				cadastroCliente();
				run=true;
				break;
			case 2:
				Sleep(100);
				printf("Cadastramento de Produtos");
				Sleep(2000);
				cadastroProduto();
				run=true;
				break;
			case 0:
				Sleep(100);
				printf("Voltando...");
				Sleep(2000);
				system("cls");
				run=false;
				break;
			default:
				Sleep(1000);
				printf("Opcao Invalida!");
				break;
		}
	} while(run==true);
}

void cadastroCliente() {
	static int cod;
	bool run;

	do {
		system("cls");
		Sleep(1000);
		printf("\nCadastramento de Clientes");
		Sleep(1000);
		printf("\nNome: ");
		scanf("%s",&nomeCliente[cod]);
		Sleep(1000);
		printf("Morada: ");
		scanf("%s",&moradaCliente[cod]);
		Sleep(1000);
		printf("Telefone: ");
		scanf("%d",&contactoCliente[cod]);
		Sleep(1000);
		printf("\nDigite 1 para continuar\nO para terminar >_ ");
		scanf("%d",&opc);

		switch(opc) {
			case 1:
				Sleep(1000);
				run=true;
				break;
			case 0:
				Sleep(1000);
				run=false;
				break;
			default:
				Sleep(1000);
				run=false;
				printf("Opcao Invalida");
				break;
		}
		Sleep(1000);
		cod++;
		totalCadCliente++;
	} while(run==true);
}

void listarCliente() {
	int i;
	system("cls");
	Sleep(1000);
	for(i=0; i<SIZECLI; i++) {
		Sleep(1000);
		if(contactoCliente[i]>0) {
			printf("\nNome: %s\nMorada: %s\nTelefone: %d\n\n", nomeCliente[i], moradaCliente[i], contactoCliente[i]);
		} else {
			break;
		}
	}
	Sleep(2000);
	printf("Total de Clientes Cadastrados --> %d\n", totalCadCliente);
	Sleep(700);
	system("pause");
}

void cadastroProduto() {
	static int cod;
	bool run;

	do {
		system("cls");
		Sleep(1000);
		printf("\nCadastramento de Produtos");
		printf("\nDescricao: ");
		scanf("%s",&descricaoProduto[cod]);
		Sleep(1000);
		printf("Quantidade: ");
		scanf("%d",&quantidadeProduto[cod]);
		Sleep(1000);
		printf("Preco Unitario: ");
		scanf("%d",&precoUnitario[cod]);
		Sleep(1000);
		printf("\nDigite 1 para continuar\nO para terminar >_ ");
		scanf("%d",&opc);

		switch(opc) {
			case 1:
				Sleep(1000);
				run=true;
				break;
			case 0:
				Sleep(1000);
				run=false;
				break;
			default:
				Sleep(1000);
				run=false;
				printf("Opcao Invalida");
				break;
		}
		Sleep(1000);
		cod++;
		totalCadProduto++;
	} while(run==true);
}

void listarProduto() {
	int i;
	system("cls");
	Sleep(1000);
	for(i=0; i<SIZEPROD; i++) {
		if(precoUnitario[i]>0) {
			printf("\nDescricao: %s\nQuantidade: %d\nPreco Unitario: %d\n\n", descricaoProduto[i], quantidadeProduto[i], precoUnitario[i]);
		} else {
			break;
		}
	}
	Sleep(1000);
	printf("Total de Produtos Cadastrados --> %d", totalCadProduto);
	Sleep(700);
	system("pause");
}

int movimentacao() {
	int esc;
	bool run;

	do {
		system("cls");
		Sleep(1000);
		printf("\nMENU DE MOVIMENTACAO DO SISTEMA");
		Sleep(1000);
		printf("\n[1] - Vendas\n[0] - Voltar");
		Sleep(1000);
		printf("\n>_ ");
		scanf("%i", &esc);

		switch(esc) {
			case 1:
				Sleep(100);
				printf("Vendas");
				Sleep(1000);
				movimentVenda();
				run=true;
				break;
			case 0:
				Sleep(100);
				printf("Voltando...");
				Sleep(1000);
				system("cls");
				run=false;
				break;
			default:
				Sleep(1000);
				printf("Opcao Invalida!");
				break;
		}
	} while(run==true);
}

int movimentVenda() {
	int i;
	int ii;

	int esc;
	bool run = true;

	char nomeClienteMov[50];
	char produtoMov[50];
	int quantidadeMov;
	int totalMov;
	int totalGeralMov=0;
	int saidaMov;

	Sleep(1000);
	system("cls");
	printf("Nome do cliente: ");
	scanf("%s", &nomeClienteMov);
	Sleep(1000);
	for(i=0; i<SIZECLI; i++) {
		if(strcmp(nomeCliente[i],nomeClienteMov)==0) {

			if(contactoCliente[i]>0) {
				do {
					Sleep(1000);
					printf("Produto: ");
					scanf("%s", &produtoMov);
					Sleep(1000);
					for(ii=0; ii<SIZEPROD; ii++) {
						if(strcmp(descricaoProduto[ii],produtoMov)==0) {
							Sleep(1000);
							printf("Quantidade: ");
							scanf("%d", &quantidadeMov);
							Sleep(1000);
							printf("Preco Unitario: %d", precoUnitario[ii]);

							totalMov = quantidadeMov * precoUnitario[ii];
							Sleep(1000);
							printf("\nTotal: %d", totalMov);
							totalGeralMov = totalGeralMov + totalMov;
							printf("\nTotal geral: %d"), totalGeralMov;
						}
					}

					Sleep(1000);
					printf("\n\n[1] - Continuar\t[0] - Terminar\n>_ ");
					scanf("%i", &esc);

					switch(esc) {
						case 1:
							Sleep(1000);
							run=true;
							break;
						case 0:
							Sleep(750);
							printf("Total geral: %d"), totalGeralMov;
							Sleep(2000);
							system("cls");
							run=false;
							break;
						default:
							Sleep(1000);
							printf("Opcao Invalida!");
							break;
					}
				} while(run==true);
			} else {
				break;
			}
		} else {
			break;
		}
	}

	Sleep(1000);
	printf("\n\n");
	system("pause");
}

int gestao() {
	int esc;
	bool run;

	do {
		system("cls");
		Sleep(1000);
		printf("\nMENU DE GESTAO DO SISTEMA");
		Sleep(1000);
		printf("\n[1] - Gestao de Cliente\n[2] - Gestao de Produtos\n[0] - Voltar");
		Sleep(1000);
		printf("\n>_ ");
		scanf("%i", &esc);

		switch(esc) {
			case 1:
				Sleep(100);
				printf("Gestao de Clientes");
				Sleep(1000);
				gestCliente();
				run=true;
				break;
			case 2:
				Sleep(100);
				printf("Gestao de Produtos");
				Sleep(1000);
				gestProduto();
				run=true;
				break;
			case 0:
				Sleep(100);
				printf("Voltando...");
				Sleep(1000);
				system("cls");
				run=false;
				break;
			default:
				Sleep(1000);
				printf("Opcao Invalida!");
				break;
		}
	} while(run==true);
}

int gestCliente() {
	int esc;
	bool run;

	do {
		system("cls");
		Sleep(1000);
		printf("\nMENU DE GESTAO DOS CLIENTES");
		Sleep(1000);
		printf("\n[1] - Pesquisar Clientes\n[2] - Listar Todos Os Clientes\n[0] - Voltar");
		Sleep(1000);
		printf("\n>_ ");
		scanf("%i", &esc);

		switch(esc) {
			case 1:
				Sleep(1000);
				printf("Area em construcao.\nConsulte o desenvolvidor...\n\n");
				system("pause");
				run=true;
				break;
			case 2:
				Sleep(100);
				printf("Listar Todos Os Clientes");
				Sleep(1000);
				listarCliente();
				run=true;
				break;
			case 0:
				Sleep(100);
				printf("Voltando...");
				Sleep(1000);
				system("cls");
				run=false;
				break;
			default:
				Sleep(1000);
				printf("Opcao Invalida!");
				break;
		}
	} while(run==true);
}

int gestProduto() {
	int esc;
	bool run;

	do {
		system("cls");
		Sleep(1000);
		printf("\nMENU DE GESTAO DO PRODUTOS");
		Sleep(1000);
		printf("\n[1] - Pesquisar Produtos\n[2] - Listar Todos Os Produtos\n[0] - Voltar");
		Sleep(1000);
		printf("\n>_ ");
		scanf("%i", &esc);

		switch(esc) {
			case 1:
				Sleep(1000);
				printf("Area em construcao.\nConsulte o desenvolvidor...\n\n");
				system("pause");
				run=true;
				break;
			case 2:
				Sleep(1000);
				printf("Listar Todos Os Produtos");
				Sleep(1000);
				listarProduto();
				run=true;
				break;
			case 0:
				Sleep(100);
				printf("Voltando...");
				Sleep(1000);
				system("cls");
				run=false;
				break;
			default:
				Sleep(1000);
				printf("Opcao Invalida!");
				break;
		}
	} while(run==true);
}

