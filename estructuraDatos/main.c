#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
	int elemento;
	struct Nodo *siguiente;
	struct Nodo *anterior;
}Nodo;
typedef struct{
	struct Nodo* cabeza;
	struct Nodo* final;
}Cola;
void menu();
void mostrar(Cola *,int*);
void insertar(Cola*,int*);
void eliminar(Cola *,int*);
void ordenar_ascendente(Cola *,int*);


int main(int argc,char *argv[]){
	menu();
	return 0;
}

void menu(){
	int tamanio=0;	
	Cola cola;
	cola.cabeza = (struct Nodo*)malloc(sizeof (struct Nodo));
	cola.cabeza->siguiente = NULL;
	cola.cabeza->anterior = NULL;
	cola.final = cola.cabeza;
	int salir=0;
	int opcion=0;
	while(salir==0){		
		printf("Bienvenido a nuestro programa de cola\n");
		printf("1)Mostrar cola\n");
		printf("2)Insertar elemento en cola\n");
		printf("3)Eliminar elemento en cola\n");
		printf("4)Ordenar ascendente en cola\n");
		printf("5)Salir\n");
		printf("Ingrese su opcion:");
		scanf("%i",&opcion);
		switch(opcion){			
			case 1:
				mostrar(&cola,&tamanio);
				break;
			case 2:
				insertar(&cola,&tamanio);
				break;
			case 3:
				eliminar(&cola,&tamanio);
				break;
			case 4:
				ordenar_ascendente(&cola,&tamanio);
				break;
			case 5:
				salir=1;
				printf("Saliendo...");
			default:
				printf("Opcion incorrecta\n");
		}
	}
}

//Desarrollar la funcion de mostrar
void mostrar(Cola *cola,int *tamanio){
	if(*tamanio == 0){
		printf("La cola esta vacia\n");
	}
	else{
		struct Nodo *apuntador;
		apuntador = cola->cabeza;
		while(apuntador != NULL){
			printf("%i ",apuntador->elemento);
			apuntador = apuntador->siguiente;
		}
		printf("\n");
	}
}

//Desarrollar la funcion de insertar
void insertar(Cola *cola,int *tamanio){
	int elemento;
	printf("Inserte el nuevo elemento:");
	scanf("%i",&elemento);
	if(*tamanio == 0){
		cola->cabeza->elemento=elemento;
		cola->cabeza->siguiente = NULL;
		cola->cabeza->anterior = NULL;
	}
	else{
		struct Nodo *nuevo;
		nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
		nuevo->elemento = elemento;
		nuevo->siguiente = NULL;
		nuevo->anterior = cola->final;
		cola->final->siguiente = nuevo;
		cola->final = nuevo;
	}
	(*tamanio)++;
}

void eliminar(Cola *cola,int *tamanio){
	if(*tamanio == 0){
		printf("La pila esta vacia\n");
	}
	else{
		Nodo *apuntador;
		apuntador = cola->cabeza;
		cola->cabeza = cola->cabeza->siguiente;
		cola->cabeza->anterior = NULL;
		free(apuntador);
		(*tamanio)--;
	}
	return ;
}

//Pila invertida rompiendo su funcionamiento
void ordenar_ascendente(Cola *cola,int *tamanio){
	if(*tamanio == 0){
		printf("La pila esta vacia\n");
	}
	else{	
		int	aux;
		struct Nodo *puntero,*siguiente;
		puntero = cola->cabeza;
		int i=0,a=0;
		for(i=0;i<*tamanio;i++){
			for(a=0;a<*tamanio-1;a++){
				siguiente = puntero->siguiente;
				if(puntero->elemento > siguiente->elemento){
					aux = puntero->elemento;
					puntero->elemento = siguiente->elemento;
					siguiente->elemento = aux;
				}
				puntero = puntero->siguiente;
			}
			puntero = cola->cabeza;
		}
	}
	return ;
}