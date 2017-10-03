#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 4

typedef struct elemento {
	char matricula[10];
	char nome[100];
	char idade[3];
}t_elemento;

typedef struct lista {
	t_elemento vetor[MAX];
	int n;
}t_lista;

// Cria uma nova lista.
void criarLista(t_lista *lista);

// Listar do início ao fim
void listarInicioaoFim(t_lista * lista);

int main() {
	
  t_lista mLista;
  t_elemento dado;	
  
  criarLista(&mLista);
  
  FILE *arq;
  
  char Linha[100];
  
  char matriculaTemp[10];
  char nomeTemp[100];
  char idadeTemp[9];
  
  char temp;
  char *result;
  int i, ii;

  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("alunos.txt", "rt");

  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  i = 1;
  ii = 0;
  
  while (!feof(arq))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      
      
      
      while( (temp=fgetc(result))!= '\n' ){
      	
			if(temp != ','){
				
				matriculaTemp[i] = temp;
				i++;
				
			} else {
				
				elemento.nome[i] = '\0';
				
			}
			
		}
      
      
      
      
	  printf("Linha %d : %s",i,Linha);
	  
	  i++;
      
      
      
  }
  
  listarInicioaoFim(&mLista);
  
  fclose(arq);
  
  return 0;
}

/**
 * Cria uma nova lista, inicializa o n.
 *
 *@param lista ponteiro para lista
 */
void criarLista(t_lista * lista) {
	lista->n = 0;
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
