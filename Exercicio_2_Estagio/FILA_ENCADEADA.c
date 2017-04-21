/**
 * EXERCÍCIO - Fila Encadeada
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

// Tipo base dos elementos da fila 
typedef struct elementos {
	char nome[50];
}t_elemento;

typedef struct no {
	t_elemento dado;
	struct no *prox;
}t_no;

typedef struct fila {
	t_no *inicio;
	int quant_element;
	t_no *final;
}t_fila;

/**
 * Protótipos de funções
 */
 
// Cria Fila.
t_fila * criaCabeca();

// Cria Nó.
t_no * criaNo();

// Verificar se a fila está vazia.
int isVazia (t_fila * fila);

// Inserir dados na fila.
int inserir (t_fila *fila, t_elemento valor);

// Exibir dados da fila 
void exibir (t_fila *fila);

/****************************************************************/

int main() {
	
	printf("Exercicio - FILA ENCADEADA\n");
	
	// Cria e inicializa fila.
	t_fila * mFila = criaCabeca();
	
	int i;
	
	t_elemento dado;
	
	for (i = 0; i < 4; i++) {
		printf("\nDigite um nome: ");
		scanf("%s", dado.nome);
		inserir(mFila, dado); 
		exibir(mFila);
	}
	
	return 0;
}

/****************************************************************/

/**
 * Cria uma fila vazia, ou seja um no cabeca.
 * inicializa os ponteiros ini e fim para NULL,
 * e seta quant_element para zero.
 * 
 * @return no cabeca alocado e inicializado
 */
t_fila * criaCabeca() {
    t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

    if (fila) {
        fila->inicio = fila->final = NULL;
        fila->quant_element=0;
    }
    return fila;
}

/**
 * Cria um novo no, aloca a sua regiao de memoria,
 * inicializa o ponteiro prox, e retorna o ponteiro para a pilha criada.
 * 
 * @return No alocada e inicializada
 */
t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    // verifica se houve memoria suficiente para alocar
    if (no)
        no->prox = NULL;

    return no;
}

/**
 * Verifica se a fila esta vazia ou nao. Isto so acontece quando ela eh nula
 * 
 * @param fila ponteiro para a fila
 *
 * @return Verdadeiro (1) se a fila estiver vazia, ou falso (0) caso contrario.
 */
int isVazia (t_fila * fila) {
    return (fila->quant_element == 0);
}

/**
 * Insere um elemento (valor) no fim da fila.
 * 
 * @param fila ponteiro para a fila
 * @param valor  elemento a ser inserido na fila
 *
 * @return Falso(0) se a fila estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int inserir (t_fila * fila, t_elemento valor) {
    t_no *novo;
    novo = criaNo();
    if (novo == NULL)
        return 0; // Erro: memoria insuficiente
    novo->dado = valor;
    if (isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;
    fila->final = novo;
    fila->quant_element++;
    return 1;
}

/**
 * Exibe dados da fila.
 * 
 * @param fila ponteiro para a fila
 */

void exibir (t_fila *fila){       
  t_no * mfila;       
  int i;       
  mfila = fila->inicio;       

  for(i=0; i < fila->quant_element; ++i){       
    printf("%s ", mfila->dado.nome);       
    mfila = mfila->prox;       
  }       
}
