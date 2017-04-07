/**
 * LISTA ESTÁTICA SEQUENCIAL COMPLETA
 *
 * UNIPE - CENTRO UNIVERSITÁRIO DE JOÃO PESSOA
 * CURSO: CIÊNCIA DA COMPUTAÇÃO - 3° PERÍODO - 2017.1
 * MATÉRIA: ESTRUTURA DE DADOS I
 * PROFESSOR: WALLACE BONFIM
 * ALUNO: ALVARO PHILIPE ANDRADE DOS SANTOS
 * MATRÍCULA: 1610015475
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 100

// Tipo base dos elementos da lista 
typedef struct elemento {
	char nome[255];
	int idade;
}t_elemento;

// Estrutura lista
typedef struct lista {
	t_elemento vetor[MAX];
	int n;
}t_lista;

/**
 * Protótipos de Funções
 */

// Cria uma nova lista.
void criarLista(t_lista *lista);
// Verifica se a lista esta vazia ou nao.
int isVazia(t_lista * lista);
// Verifica se a lista esta cheia ou nao.
int isCheia(t_lista * lista);
// Obtem o tamanho atual da lista, nao o tamanho maximo.
int getTamanho(t_lista * lista);
// Destruir lista.
void destruirLista(t_lista * lista);
// Desloca os elementos da lista para a direita a partir de pos.
int deslocaDireita(t_lista * lista, int pos);
// Desloca os elementos da lista para a esquerda a partir de pos.
int deslocaEsquerda(t_lista * lista, int pos);
// Inserir no final.
int inserirFinal(t_lista * lista, t_elemento dado);
// Inserir na posição.
int inserirPosicao(t_lista * lista, int pos, t_elemento dado);
// Inserir no início
int inserirInicio(t_lista * lista, t_elemento dado);
//Acessar a partir do início.
t_lista * acessarApartirInicio(t_lista * lista, int pos);
//Acessar a partir do fim.
t_lista *acessarApartirFim(t_lista * lista, int pos);
// Listar do início ao fim
void listarInicioaoFim(t_lista * lista);
// Listar do fim ao inicio
void listarFimaoInicio(t_lista * lista);
// Eliminar pela posicao
int eliminarPosicao(t_lista * lista, int pos);
// Buscar endereço por nome e retornar endereço.
t_lista * buscarEnderecoNome(t_lista * lista, char nome[]); 
// Buscar endereço por nome e retornar posicao.
int buscarPosicao(t_lista * lista, char nome[]);
 
int main() {
	
	printf("Lista Sequencial Estatica Completa\n\n");
	
	t_lista mLista;
	t_elemento dado;
	t_elemento *retornoDado;
		
	int op = 0, pos;
	char nome[255];
	
	criarLista(&mLista);
	
	do {
		printf("1 - Criar Lista\n");
		printf("2 - Inserir Inicio\n");
		printf("3 - Inserir Final\n");
		printf("4 - Inserir Posicao\n");
		printf("5 - Acessar a partir inicio\n");
		printf("6 - Acessar a partir fim\n");
		printf("7 - Listar do inicio ao fim\n");
		printf("8 - Listar do fim ao inicio\n");
		printf("9 - Eliminar\n");
		printf("10 - Buscar nome retorna endereco\n");
		printf("11 - Buscar nome retorna posicao\n");
		printf("12 - Tamanho da lista\n");
		printf("13 - Destruir\n");
		printf("14 - Sair\n");
		
		printf("Opcao: ");
		scanf("%d", &op);
		
		switch (op) {
			case 1:
				criarLista(&mLista);
				system("cls || clear");
				break;
			case 2:
				printf("Nome: ");
				scanf("%s", dado.nome);
				printf("Idade: ");
				scanf("%d", &dado.idade);
				inserirInicio(&mLista, dado);
				system("cls || clear");
				break;
			case 3:
				printf("Nome: ");
				scanf("%s", dado.nome);
				printf("Idade: ");
				scanf("%d", &dado.idade);
				inserirFinal(&mLista, dado);
				system("cls || clear");
				break;
			case 4:
				printf("Nome: ");
				scanf("%s", dado.nome);
				printf("Idade: ");
				scanf("%d", &dado.idade);
				printf("Posicao: ");
				scanf("%d", &pos);
				inserirPosicao(&mLista, pos, dado);
				system("cls || clear");
				break;
			case 5:
				printf("Posicao: ");
				scanf("%d", &pos);
				retornoDado = acessarApartirInicio(&mLista, pos);
				if (retornoDado != NULL) {
					printf("Nome: %s\n", retornoDado->nome);
					printf("Idade: %d\n\n", retornoDado->idade);
				} else {
					printf("Posicao nao existe.");
				}
				getch();
				system("cls || clear");
				break;
			case 6:
				printf("Posicao: ");
				scanf("%d", &pos);
				retornoDado = acessarApartirFim(&mLista, pos);
				if (retornoDado != NULL) {
					printf("Nome: %s\n", retornoDado->nome);
					printf("Idade: %d\n\n", retornoDado->idade);
				} else {
					printf("Posicao nao existe.");
				}
				getch();
				system("cls || clear");
				break;
			case 7:
				listarInicioaoFim(&mLista);
				getch();
				system("cls || clear");
				break;
			case 8:
				listarFimaoInicio(&mLista);
				getch();
				system("cls || clear");
				break;
			case 9:
				printf("Posicao: ");
				scanf("%d", &pos);
				eliminarPosicao(&mLista, pos);
				getch();
				system("cls || clear");
				break;
			case 10:
				printf("Nome: ");
				scanf("%s", &nome);
				retornoDado = buscarEnderecoNome(&mLista, nome);
				if (retornoDado != NULL) {
					printf("Nome: %s\n", retornoDado->nome);
					printf("Idade: %d\n\n", retornoDado->idade);
				} else {
					printf("Nome nao existe.");
				}
				getch();
				system("cls || clear");
				break;
			case 11:
				printf("Nome: ");
				scanf("%s", &nome);
				pos = buscarPosicao(&mLista, nome);
				if (pos >= 0) {
					printf("Posicao: %d\n", pos);
					retornoDado = acessarApartirInicio(&mLista, pos);
					printf("Nome: %s\n", retornoDado->nome);
					printf("Idade: %d\n\n", retornoDado->idade);
				} else {
					printf("Nome nao existe.");
				}
				getch();
				system("cls || clear");
				break;
			case 12:
				printf("Tamanho da lista: %d", getTamanho(&mLista));
				getch();
				system("cls || clear");
				break;
			case 13:
				destruirLista(&mLista);
				system("cls || clear");
				break;
			case 14:
				exit(0);
				break;
			
		}
	} while (op != 14);
	
	return 0;
}

/**
 * Funções
 */

/**
 * Cria uma nova lista, inicializa o n.
 *
 *@param lista ponteiro para lista
 */
void criarLista(t_lista * lista) {
	lista->n = 0;
}

/**
 * Verifica se a lista esta vazia ou nao.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a lista estiver vazia, ou falso (0) caso contrario
 */
int isVazia(t_lista * lista) {
    return (lista->n == 0);
}

/**
 * Verifica se a lista esta cheia ou nao.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a lista estiver cheia, ou falso (0) caso contrario
 */
int isCheia(t_lista * lista) {
    return (lista->n == MAX-1);
}

/**
 * Obtem o tamanho atual da lista, nao o tamanho maximo.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @return o quantidade de elementos que estao na lista
 */
int getTamanho(t_lista * lista) {
    return lista->n;
}

/**
 * Destruir lista.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 */
 void destruirLista(t_lista * lista) {
 	lista->n = 0;
 }
 
/**
 * Desloca os elementos da lista para a direita a partir de pos
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param pos   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return Falso(0) se a posição for invalida ou se a lista estiver cheia, caso contrario, retorna Verdadeiro(1)
 */
int deslocaDireita(t_lista * lista, int pos) {
    int i;

    for (i=lista->n + 1; i>pos; i--)
        lista->vetor[i] = lista->vetor[i-1];

    return 1;
}

/**
 * Desloca os elementos da lista para a esquerda a partir de pos
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 * @param pos   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return 0 se a posição for invalida ou se a lista estiver cheia, caso contrario, retorna 1
 */
int deslocaEsquerda(t_lista * lista, int pos) {
    int i;

    for (i=pos; i<(lista->n); i++)
        lista->vetor[i] = lista->vetor[i+1];

    return 1;
}
 
/**
 * Inserir no final.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @param dado variavel do tipo t_elemento
 *
 * @return Verdadeiro (1) se conseguir inserir, ou falso (0) caso contrario
 */
int inserirFinal(t_lista * lista, t_elemento dado) {
	if (isCheia(lista)) {
    	return 0;
    } else {
 		lista->vetor[lista->n] = dado;
 		lista->n = lista->n + 1;
 		return 1;
 	}
 }
 
/**
 * Inserir na posição.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @param pos variavel do tipo int que guarda o numero da posição
 *
 * @param dado variavel do tipo t_elemento
 *
 * @return Verdadeiro (1) se conseguir inserir, ou falso (0) caso contrario
 */
 int inserirPosicao(t_lista * lista, int pos, t_elemento dado) {
 	int i;
 	if (isCheia(lista) || (pos > lista->n + 1) || (pos < 0) ) {
 		return 0;
 	} else {
		deslocaDireita(lista, pos);
 		lista->vetor[pos] = dado;
 		lista->n = lista->n + 1;
 		return 1;
 	}
 }
 
/**
 * Inserir no início.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @param dado variavel do tipo t_elemento
 *
 * @return Verdadeiro (1) se conseguir inserir, ou falso (0) caso contrario
 */
 int inserirInicio(t_lista * lista, t_elemento dado) {
	if (isCheia(lista)) {
    	return 0;
	} else {
 		inserirPosicao(lista, 0, dado);
 		return 1;
 	}
 	
 }
 
/**
 * Acessar a partir do início.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @param pos variavel do tipo int que guarda o numero da posição
 *
 * @param dado variavel do tipo t_elemento
 *
 * @return NULL caso não encontre a posição
 */
 t_lista * acessarApartirInicio(t_lista * lista, int pos) {
 	if (pos > lista->n + 1 || (pos < 0) ) {
 		return NULL;
 	} else {
 		return &(lista->vetor[pos]);
 	}
 }
 
/**
 * Acessar a partir do fim.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 * @param pos variavel do tipo int que guarda o numero da posição
 *
 * @param dado variavel do tipo t_elemento
 *
 * @return NULL caso não encontre a posição
 */
 t_lista *acessarApartirFim(t_lista * lista, int pos) {
 	if (pos > lista->n + 1 || (pos < 0) ) {
		return NULL;
 	} else {
 		return &(lista->vetor[pos-1]);
 	}
 }
 
/**
 * Listar do início ao fim.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 */
 void listarInicioaoFim(t_lista * lista) {
 	int i;
 	t_elemento dado;
 	for (i = 0; i < lista->n; i++) {
 		dado = lista->vetor[i];
 		printf("Nome: %s\n", dado.nome);
 		printf("Idade: %d\n\n", dado.idade);
 	}
 }
 
/**
 * Listar do fim ao nício.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 */
 void listarFimaoInicio(t_lista * lista) {
 	int i;
 	t_elemento dado;
 	for (i = lista->n - 1; i >= 0; i--) {
 		dado = lista->vetor[i];
 		printf("Nome: %s\n", dado.nome);
 		printf("Idade: %d\n\n", dado.idade);
 	}
 }
 
/**
 * Buscar endereço por nome e retornar endereço.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 *@param nome variavel char para o nome a ser pesquisado
 *
 *@return NULL caso não encontre o nome
 */
 t_lista * buscarEnderecoNome(t_lista * lista, char nome[]) { 	
 	int i;
 	for (i = 0; i < lista->n; i++) {
		if (strcmp(nome, lista->vetor[i].nome) == 0) {
			return &lista->vetor[i];
		} else {
			return NULL;
		}
 	}
 }
 
/**
 * Buscar endereço por nome e retornar posicao.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 *@param nome variavel char para o nome a ser pesquisado
 *
 *@return NULL caso não encontre o nome
 */
int buscarPosicao(t_lista * lista, char nome[]) {
 	int i;
 	for (i = 0; i < lista->n; i++) {
		if (strcmp(nome, lista->vetor[i].nome) == 0) {
			return i;
		} else {
			return -1;
		}
 	}
 }
 
/**
 * Eliminar pela posição.
 * 
 * @param lista ponteiro para a lista, a lista ja deve ter sido inicializada
 *
 *@param pos variavel int para a posição a ser eliminada
 *
 * @return Verdadeiro (1) se conseguir eliminar, ou falso (0) caso contrario
 */ 
int eliminarPosicao(t_lista * lista, int pos) {
	int i;
	
	if (pos > lista->n + 1 || pos < 0) {
		return 0;
	} else {
	
		if (pos == (lista->n-1)) {
			lista->n = lista->n-1;
		} else {
			 deslocaEsquerda(lista, pos);
			lista->n = lista->n - 1;
		}
		return 1;
	}
}
