/**
 * EXERCÍCIO - PILHA
 *
 * UNIPE - CENTRO UNIVERSITÁRIO DE JOÃO PESSOA
 * CURSO: CIÊNCIA DA COMPUTAÇÃO - 3° PERÍODO - 2017.1
 * MATÉRIA: ESTRUTURA DE DADOS I
 * PROFESSOR: WALLACE BONFIM
 * ALUNO: ALVARO PHILIPE ANDRADE DOS SANTOS
 * MATRÍCULA: 1610015475
 */
 
/*

Você está na entrada de um beco comprido, estreito e sem saída, no qual carros entram e saem em fila única, pois não há espaço lateral para dois carros. 
Neste beco cabem três carros. Escreva um algoritmo em C que simula as seguintes situações:
	
a) três carros entram no beco e seu algoritmo registra (guarda) as placas dos carros que entraram;
b) mostra a placa do terceiro carro que entrou;
c) três carros saem do beco e seu algoritmo mostra a placa de cada carro que saiu.
d) mostra quantos carros ficaram no beco
 
(*) Escolher a estrutura de dados que melhor se adequa a esta situração; implementar uma função para cada item (a e c); os itens b) e d) são executados no main() de seu algoritmo.

*/

#include	<stdio.h>
#include	<stdlib.h>

#define MAX 3 // Número máximo de elementos da pilha

// Tipo base dos elementos da pilha
typedef struct elemento {
	char placa[24];
}t_elemento;

//Estrutura da pilha
typedef struct pilha {
	t_elemento vetor[MAX];
	int topo;
}t_pilha;

/**
 * Protótipos de funções
 */

// Verifica se a pilha esta vazia ou nao.
int isVazia(t_pilha * pilha);
// Verifica se a pilha esta cheia ou nao.
int isCheia(t_pilha * pilha);
// Cria uma nova pilha, aloca a sua regiao de memoria, inicializa o topo, e retorna a pilha criada.
t_pilha criar();
// Inserir um novo elemento no topo da pilha (empilhar).
int push(t_pilha *pilha, t_elemento valor);
// Remove o elemento do topo da pilha (desempilhar), retornando o elemento removido.
t_elemento pop(t_pilha * pilha);
// Entrada de dados
void entraCarros(t_pilha * pilha);
// Saída de dados
void sairCarros(t_pilha * pilha);

int main() {
	
	// Início do Programa
	
	printf("Exercicio - Pilha\n\n");
	
	// Cria pilha
	t_pilha mPilha = criar();
	
	printf("Situacao A:\n");
	printf("--------------------------------------------------------------\n");
	
	// Entrada de dados
	entraCarros(&mPilha);
	
	printf("\nSituacao B:\n");
	printf("--------------------------------------------------------------\n");
	
	int i;
	i = mPilha.topo;
	printf("Placa do ultimo carro a entrar no beco: %s\n", mPilha.vetor[i].placa);
	
	printf("\nSituacao C:\n");
	printf("--------------------------------------------------------------\n");
	
	// Saída de dados
	sairCarros(&mPilha);
	
	printf("\nSituacao D:\n");
	printf("--------------------------------------------------------------\n");
	
	printf("Carros que ficaram no beco: %d\n", mPilha.topo + 1 );	
	
	// Fim do Programa
	
	return 0;
}

/**
 * Funções
 */
 
 /**
 * Cria uma nova pilha, aloca a sua regiao de memoria,
 * inicializa o topo, e retorna a pilha criada.
 * 
 * @return Pilha inicializada
 */
t_pilha criar() {
    t_pilha pilha;

    pilha.topo = -1;

    return pilha;
}

/**
 * Verifica se a pilha esta vazia ou nao.
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a pilha estiver vazia, ou falso (0) caso contrario
 */
int isVazia(t_pilha * pilha) {
    return (pilha->topo == -1);
}

/**
 * Verifica se a pilha esta cheia ou nao.
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a pilha estiver cheia, ou falso (0) caso contrario
 */
int isCheia(t_pilha * pilha) {
    return (pilha->topo == MAX-1);
}

/**
 * Inserir um novo elemento no topo da pilha (empilhar).
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 * @param dado  elemento a ser inserido na pilha
 *
 * @return Falso(0) se a posição for invalida ou se a pilha estiver cheia, caso contrario, retorna Verdadeiro(1)
 */
int push(t_pilha *pilha, t_elemento valor) {
    if (isCheia(pilha))
        return 0; // erro

    pilha->vetor[++pilha->topo] = valor;

    return 1; // sucesso
}

/**
 * Remove o elemento do topo da pilha (desempilhar), retornando o elemento removido.
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Uma copia do elemento do topo
 */
t_elemento pop(t_pilha * pilha) {
    t_elemento vazio = { "" };

    if (isVazia(pilha))
        return vazio; // erro
    else
        return pilha->vetor[pilha->topo--];
}

/**
 * Entrada de dados.
 *
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 */
void entraCarros(t_pilha * pilha) {
	int i;
	t_elemento dados;
	
	for (i = 0; i < MAX; i++) {
		dados = pilha->vetor[i];
		printf("[%d] Placa do carro: ", i+1);
		scanf("%s", &dados.placa);
		push(pilha, dados);
	}
}

/**
 * Saída de dados.
 *
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 */
void sairCarros(t_pilha * pilha) {
	
	int i;
	for (i= 0; i < 3; i++) {
		t_elemento dados = pop(pilha);
		printf("[%d] carro a sair do beco: %s \n",i+1, dados.placa);
	}
	
}

