#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define NODES_LENGTH 5

typedef struct Node {
	int v;
	struct Node ** aristas;
} Node;

typedef struct Graph{
	// edges es un arreglo de punteros
	struct Node ** edges;
} Graph;


int main (void){
	//creamos el grafo 1 el cual es un arreglo con x * NODES_LENGTH bytes para almacenar los vertices
	Graph * g1 = (Graph *) malloc(sizeof(Graph) * NODES_LENGTH);
	
	// definimos que la propiedad edges es un arreglo de punteros
	g1->edges = (Node **) malloc(sizeof(Node *) * NODES_LENGTH);
	
	for(size_t i = 0; i < NODES_LENGTH; i++){
		// creamos un vertice
		Node * edge = (Node *) malloc(sizeof(Node));
		printf("\nEscribe el vertice nro.%i: \n", i+1);
		int v;
		scanf("%i", &v);
		edge->v = v;
		
		// asignamos el vertice en la posicion i
		g1->edges[i] = edge;
	}
	
	

	printf("\n\nVertices: \n\n");
	for(size_t i = 0; i < NODES_LENGTH; i++){
		// accedemos al valor del vertice en la posicion i
		printf("%i ", g1->edges[i]->v);
	}
	
	printf("\n");
	free(g1);
	system("PAUSE");
	return 0;
}  