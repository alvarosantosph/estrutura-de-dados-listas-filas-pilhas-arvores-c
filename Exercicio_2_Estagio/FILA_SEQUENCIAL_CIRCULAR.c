/**
 * EXERCÍCIO - Fila Sequencial Circular
 *
 * UNIPE - CENTRO UNIVERSITÁRIO DE JOÃO PESSOA
 * CURSO: CIÊNCIA DA COMPUTAÇÃO - 3° PERÍODO - 2017.1
 * MATÉRIA: ESTRUTURA DE DADOS I
 * PROFESSOR: WALLACE BONFIM
 * ALUNO: ALVARO PHILIPE ANDRADE DOS SANTOS
 * MATRÍCULA: 1610015475
 */
 
#include	<stdio.h>
#include	<stdlib.h>
 
// Tamanho maximo da fila
#define MAX 5

// Tipo base dos elementos da fila 
typedef struct elementos {
    char nome[50];	
} t_elemento;

typedef struct fila {
    t_elemento vetor[MAX]; // Vetor que armazena a fila
    int inicio; // Posicao do primeiro elemento
    int fim; // Posicao do ultimo elemento
    int quant_element; // Numero de elementos da fila
} t_fila;

/**
 * Protótipos de funções
 */

// Criar fila.
t_fila criar();

// Verificar se a fila esta vazia.
int isVazia(t_fila * fila);

// Verificar se a fila esta cheia.
int isCheia(t_fila * fila);

// Inserir dados na fila.
int inserir(t_fila * fila, t_elemento valor);

// Remover dados da fila.
t_elemento remover(t_fila * fila);

// Exibir fila.
void exibir(t_fila * fila);

/****************************************************************/

int main() {
	
	printf("Exercicio - FILA SEQUENCIAL CIRCULAR\n");
		
	/*
	 * Opcao A 
	*/
	
	// Cria e inicializa fila.
	t_fila mFila = criar();
	
	int i = 0;
	
	t_elemento dado;
	
	/*
	 * Opcao B
	*/
	
	for (i = 0; i < 4; i++) {
		printf("\nDigite um nome: ");
		scanf("%s", dado.nome);
		inserir(&mFila, dado); 
		exibir(&mFila);
	}
	
	/*
	 * Opcao C
	*/
	
	printf("\n\nNome Removido: %s\n", remover(&mFila).nome);
	printf("Nome Removido: %s\n", remover(&mFila).nome);
	printf("Nome Removido: %s\n\n", remover(&mFila).nome);
	
	/*
	 * Opcao D 
	*/
	
	for (i = 0; i < 4; i++) {
		printf("\nDigite um nome: ");
		scanf("%s", dado.nome);
		inserir(&mFila, dado); 
		exibir(&mFila);
	}
	
	return 0;
}

/****************************************************************/

/**
 * Cria uma nova fila, aloca a sua regiao de memoria,
 * inicializa o inicio, fim e a quantidade de elementos.
 * Por fim, retorna a fila criada.
 *
 * @return Fila inicializada
 */
t_fila criar() {
    t_fila fila;

    fila.inicio = 0;
    fila.fim = -1;
    fila.quant_element = 0;
    
    return fila;
}

/**
 * Verifica se a fila esta vazia ou nao.
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a fila estiver vazia, ou falso (0) caso contrario.
 */
int isVazia(t_fila * fila) {
    return (fila->quant_element == 0);
}

/**
 * Verifica se a fila esta cheia ou nao.
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a fila estiver cheia, ou falso (0) caso contrario.
 */
int isCheia(t_fila * fila) {
    return (fila->quant_element == MAX);
}

/**
 * Insere um elemento (valor) no final da fila.
 * 
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 * @param valor elemento a ser inserido na fila
 *
 * @return Falso(0) se a fila estiver cheia, caso contrario, retorna Verdadeiro(1)
 */
int inserir(t_fila * fila, t_elemento valor) {
    if (isCheia(fila))
        return 0;

    (fila->quant_element)++;
    fila->fim = (fila->fim + 1) % MAX;
    fila->vetor[fila->fim] = valor;
    return 1;
}

/**
 * Remove um elemento do inicio da fila.
 * 
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return o elemento removido.
 */
t_elemento remover(t_fila * fila) {
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor; // Erro: fila vazia

    valor = fila->vetor[fila->inicio];
    fila->vetor[fila->inicio].nome[0] = '\0';// zera, opcional
    (fila->quant_element)--;
    fila->inicio = (fila->inicio + 1) % MAX;
    return valor;
}

/**
 * Exibe todos os elementos da fila
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 */
void exibir(t_fila * fila) {
    int i;
    if (isVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    printf("\nExibindo fila:\n");
    printf("inicio: %d\n", fila->inicio);
    printf("fim:    %d\n", fila->fim);
    for (i = fila->inicio ; i != (fila->fim+1) % MAX; i = (i + 1) % MAX) {
        printf("%d::%s\n", i, fila->vetor[i].nome);        
    }
}
