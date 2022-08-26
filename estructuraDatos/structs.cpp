#include <stdio.h>
#include <stdlib.h>
#include<string.h>  
#define MAX 70

typedef struct Node {
	int v;
	struct Node * next;
} Node;

Node * crearNodo(const int, Node *);
Node * agregarNodo(Node *, const int);
Node * eliminarNodo(Node *);
void imprimirLista(Node *);
int buscarNodo( Node *, const int);

int main (void){
	Node * raiz = crearNodo(0, NULL);
	
	for(size_t i=1; i <= MAX; i++){
		raiz = agregarNodo(raiz, i);
	}
	
	
	
	raiz = eliminarNodo(raiz);
	imprimirLista(raiz);
	
	
	printf("\n\n");
	int encontrado = buscarNodo(raiz, 60);
	
	if(encontrado != NULL){
		printf("Se encontro el nodo %i \n", encontrado);
	}else{
		printf("No se encontro el numero\n");
	}

	free(raiz);
	
	return 0;
}

Node * agregarNodo(Node * raiz, const int v){
	Node * aux = crearNodo(v, raiz);
	return aux;
}

Node * crearNodo(const int v, Node * next){
	Node * node = (Node *) malloc(sizeof(Node));
	node->v = v;
	node->next = next;
	
	return node;
}

Node * eliminarNodo(Node * lista){
	if(lista == NULL){
		printf("La lista esta vacia\n");
		return NULL;
	}
	Node * aux = lista;
	aux = aux->next;
	return aux;
}

int buscarNodo( Node * lista, const int v){
	Node * aux = lista;
	bool flag = true;
	
	while(aux != NULL && flag){
		if(aux->v == v){
			int v =  aux->v;
			free(aux);
			return v;
		}
		aux=aux->next;
	}
	free(aux);
	return NULL;
}

void imprimirLista(Node * lista){
	Node * aux = lista;
	
	while(aux != NULL){
		printf("%i ", aux->v);
		aux=aux->next;
	}
	
	free(aux);
}
