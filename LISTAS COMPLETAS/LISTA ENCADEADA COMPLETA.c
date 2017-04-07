/***************************************************************************

O código completo de uma Lista Encadeada (ligada) com as seguintes funções:

Inserir um nó na primeira posição
Insere um nó na ultima posição
Imprimir os valores de todos os nós
Remover todos os nós da Lista
Remover todos os nós com determinado valor
Remover o primeiro nó da Lista
Remover o ultimo nó da Lista
Remover o nó de uma posição dada
Inserir um nó com determinado valor em determinada posição
Verificar se a lista está ordenada
Retornar o numero de nós que são multiplos de determinado valor
Remover todos os nós pares 

***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
enum boolean
{
    true = 1, false = 0
};
typedef enum boolean bool;
 
 
typedef struct Node{
    int info;
    struct Node *proximo;
}No;
 
No *primeiro = NULL;
 
void inserirPrimeiro(int valor);//Insere um nó na primeira posição
 
void inserirUltimo(int valor);//Insere um nó na ultina posição
 
void imprimir();//Imprime os valores de todos os nós
 
void limpar();//Remove todos os nós da Lista
 
void removerValor(int valor);//Remove todos os nós com info = valor
 
void removerPrimeiro();//Remove o primeiro nó da Lista
 
void removerUltimo();//Remove o ultimo nó da Lista
 
void removerPosicao(int i);//Remove o nó da posição i
 
int tamanho();//Retona o numeros de nós da Lista
 
void inserirPosicao(int i, int valor);//Insere um nó com info = valor na posição i
 
bool estaOrdenada();//Retorna se a lista está em ordem crescente
 
int multiplos(int valor);//Retorna o numero de nós que são multiplos de valor
 
int removerPares();//Remove todos os nós pares, e retorna o número de nós excluidos
 
int main()
{
    //ALGUNS TESTES JÁ FEITOS.
    inserirPrimeiro(60);
    inserirPrimeiro(50);
    inserirPrimeiro(40);
    inserirPrimeiro(30);
    inserirPrimeiro(20);
    inserirPrimeiro(10);
    removerPares();
    imprimir();
    int x = 3;
    printf("Sao %d multiplos de %d.", multiplos(x), x);
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    removerPosicao(3);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    inserirPosicao(3,99);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    inserirUltimo(22);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    return 0;
}
 
void inserirPrimeiro(int valor)
{
    No *no = (No*) malloc (sizeof(No));
    no->info = valor;
    no->proximo = primeiro;
    primeiro = no;
}
 
void imprimir()//Imprime os valores de todos os nós
{
    if (primeiro == NULL)
    {
        printf("A lista esta vazia!");
        return;
    }
    No *no = primeiro;
    while (no != NULL)
    {
        printf("%d ", no->info);
        no = no->proximo;
    }
}
 
void limpar()//Remove todos os nós da Lista
{
    No *no = primeiro, *aux;
    while (no != NULL)
    {
        aux = no;
        no = no->proximo;
        free (aux);
    }
    primeiro = NULL;
}
 
void removerValor(int valor)//Remove todos os nós com info = valor
{
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo, *anterior = NULL;
        while (aux != NULL)
        {
            if (no == primeiro)
            {
                if (no->info == valor)
                {
                    primeiro = aux;
                    free(no);
                    no = primeiro;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
            else
            {
                if (no->info == valor)
                {
                    anterior->proximo = aux;
                    free(no);
                    no = aux;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
        }
        //condição para o último nó
        if (no->info == valor)
        {
            if (tamanho > 1)
            {
                anterior->proximo = NULL;
                free(no);
            }
            else
            {
                free(no);
                primeiro = NULL;
            }
        }
    }
}
 
void removerPrimeiro()//Remove o primeiro nó da Lista
{
    if (primeiro != NULL)
    {
        No *no = primeiro;
        primeiro = no->proximo;
        free(no);
    }
}
 
void removerUltimo()//Remove o ultimo nó da Lista
{
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo;
        while(aux->proximo != NULL)
        {
            no = no->proximo;
            aux = aux->proximo;
        }
        free(aux);
        no->proximo = NULL;
    }
}
 
void removerPosicao(int i)//Remove o nó da posição i
{
    if (i < 0)
        return;
    if ((primeiro != NULL) && (tamanho() >= i))
    {
        No *no = primeiro, *aux, *anterior;
        int cont = 0;//para contagem da posição a partir de 0
        while (cont < i)
        {
            anterior = no;
            no = no->proximo;
            cont++;
        }
        aux = no->proximo;
        free(no);
        anterior->proximo = aux;
    }
}
 
int tamanho()//Retona o numeros de nós da Lista
{
    int cont = 0;
    No *no = primeiro;
    while (no != NULL)
    {
        no = no->proximo;
        cont++;
    }
    return cont;
}
 
void inserirPosicao(int i, int valor)//Insere um nó com info = valor na posição i
{
    if (i < 0)
        return;
    if (i == 0)
    {
        inserirPrimeiro(valor);
        return;
    }
    if (tamanho() >= i)
    {
        No *no = primeiro, *aux, *novo;
        novo = (No*) malloc (sizeof(No));
        novo->info = valor;
        int cont = 0;//para contagem da posição a partir de 0
        while (cont < i-1)//i-1 para parar uma posição antes de i, para fazer a inserção na posição certa
        {
            no = no->proximo;
            cont++;
        }
        aux = no->proximo;
        no->proximo = novo;
        novo->proximo = aux;
    }
}
 
void inserirUltimo(int valor)//Insere um nó na ultina posição
{
    if (primeiro == NULL)
    {
        inserirPrimeiro(valor);
        return;
    }
    No *no = primeiro, *novo;
    while (no->proximo != NULL)
    {
        no = no->proximo;
    }
    novo = (No*) malloc (sizeof(No));
    novo->info = valor;
    novo->proximo = NULL;
    no->proximo = novo;
}
 
bool estaOrdenada()//Retorna se a lista está em ordem crescente
{
    if (primeiro != NULL)
    {
        No *no = primeiro;
        while (no->proximo != NULL)
        {
            if (no->info > no->proximo->info)
                return false;
            no = no->proximo;
        }
    }
    return true;
}
 
int multiplos(int valor)//Retorna o numero de nós que são multiplos de valor
{
    int cont = 0;
    if (primeiro != NULL)
    {
        No *no = primeiro;
        while (no != NULL)
        {
            if ((no->info % valor) == 0)
                cont++;
            no = no->proximo;
        }
    }
    return cont;
}
 
int removerPares()//Remove todos os nós pares, e retorna o número de nós excluidos
{
    int cont = 0;
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo, *anterior;
        while (aux != NULL)
        {
            if (no == primeiro)
            {
                if ((no->info % 2) == 0)
                {
                    primeiro = aux;
                    free(no);
                    no = primeiro;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
            else
            {
                if ((no->info % 2) == 0)
                {
                    anterior->proximo = aux;
                    free(no);
                    no = aux;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
        }
        //condição para o último nó
        if ((no->info % 2) == 0)
        {
            if (tamanho() > 1)
            {
                anterior->proximo = NULL;
                free(no);
            }
            else
            {
                free(no);
                primeiro = NULL;
            }
        }
    }
    return cont;
}